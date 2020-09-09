#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__
#include<queue>
#include<assert.h>

namespace structures{

#define __BLACK__ true
#define __RED__ false
#define __RED_BLACK_LEAF__ nullptr

  
template<typename T>
class RedBlackTree{
private:
  struct RedBlackNode{
    RedBlackNode * parent_n;
    RedBlackNode * left_n;
    RedBlackNode * right_n;
    bool color;
    T key;
    
    inline RedBlackNode * parent(){    
      return parent_n;
    }
    
    inline RedBlackNode * grand_parent(){
      RedBlackNode * p = parent();
      return (p == nullptr)?nullptr:p->parent();
    }
    
    inline RedBlackNode * sibling(){
      RedBlackNode * p = parent();
      if(p == nullptr)
	return nullptr;
      if(p->left_n == this)
	return p->right_n;
      return p->left_n;
    }
    
    inline RedBlackNode * uncle(){
      RedBlackNode * p = parent();
      if(p == nullptr)
	return nullptr;
      return (p->parent() == nullptr)? nullptr:p->sibling();
    }
    
    
    friend bool operator<(const RedBlackNode & rbn1, const RedBlackNode& rbn2)
    {
      return rbn1.key < rbn2.key; // keep the same order
    }
    
    RedBlackNode(const T & key_p, const bool color_p = __RED__):parent_n(nullptr),left_n(nullptr),right_n(nullptr),
								color(color_p),key(key_p){}
    
  };
  int size;
  RedBlackNode * root;


  RedBlackNode * brt_insert(const T & value){
    RedBlackNode ** tmp = &root;
    RedBlackNode * parent_node = nullptr;
    RedBlackNode * new_node = new RedBlackNode(value);
    while(*tmp != nullptr){
      parent_node = *tmp;
      if(*new_node < **tmp)
	tmp = &((*tmp)->left_n);
      else
	tmp = &((*tmp)->right_n);
    }
    *tmp = new_node;
    new_node->parent_n = parent_node;
    size++;
    return new_node;
  }

  void rotate_left(RedBlackNode * n, RedBlackNode * p){
    RedBlackNode * right_node = n->right_n;
    std::cerr<<"--------Rotate Left -------"<<std::endl;
    print();
    if(right_node != __RED_BLACK_LEAF__){
      n->right_n = right_node->left_n;
      right_node->left_n = n;
      n->parent_n = right_node;
      if(n->right_n != __RED_BLACK_LEAF__)
	n->right_n->parent_n = n;

      if (p != nullptr) {
	if (n == p->left_n) {
	  p->left_n = right_node;
	} else if (n == p->right_n) {
	  p->right_n = right_node;
	}
      }
      right_node->parent_n = p;
    } 
  }

  void rotate_right(RedBlackNode * n, RedBlackNode * p){
    RedBlackNode * nnew = n->left_n;
    assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
    // they cannot become internal nodes.
    
    n->left_n = nnew->right_n;
    nnew->right_n = n;
    n->parent_n = nnew;
    
    // Handle other child/parent pointers.
    if (n->left_n != nullptr) {
      n->left_n->parent_n = n;
    }
    
    // Initially n could be the root.
    if (p != nullptr) {
      if (n == p->left_n) {
	p->left_n = nnew;
      } else if (n == p->right_n) {
	p->right_n = nnew;
      }
    }
    nnew->parent_n = p;
  }


  inline void repair_upward(RedBlackNode * p, RedBlackNode * u, RedBlackNode * g){
    p->color = __BLACK__;
    u->color = __BLACK__;
    g->color = __RED__;
    repair_tree(g);
  }

  inline void repair_downward(RedBlackNode * n, RedBlackNode * p, RedBlackNode * g){
    //Step One
    if(g->left_n != nullptr && n == g->left_n->right_n){
      rotate_left(p,g);
      n = n->left_n;
    }else if(g->right_n != nullptr && n == g->right_n->left_n){
      rotate_right(p,g);
      n = n->right_n;
    }

    //Step Two
    p = n->parent();
    g = n->grand_parent();
    if (n == p->left_n)
      rotate_right(g, g->parent());
    else
      rotate_left(g, g->parent());
    p->color = __BLACK__;
    g->color = __RED__;
  }

  void repair_tree(RedBlackNode * new_node){
    RedBlackNode * p = new_node->parent();
    if(p == nullptr)
      new_node->color = __BLACK__;
    else if(p->color == __RED__){
      RedBlackNode * u = new_node->uncle();
      RedBlackNode * g = new_node->grand_parent();
      if( u != nullptr && u->color == __RED__)
	repair_upward(p,u,g);
      else
	repair_downward(new_node, p, g);
    }
  }

  void node_label(int node, RedBlackNode * current){
    std::cout<<node<<" [label =\""<<current->key<<"\"";
    if(current->color == __RED__)
      std::cout<<", color=\"white\", color =\"red\"];"<<std::endl;
    else
      std::cout<<", color=\"white\", color =\"grey\"];"<<std::endl;
  }

public:
  RedBlackTree():size(0),root(nullptr){}
  
  inline size_t get_size(){
    return size;
  }
  
  void insert(const T & value){
    RedBlackNode * new_node = brt_insert(value);
    print();
    std::cerr<<"-----------Repair----------"<<std::endl;
    repair_tree(new_node);    
  }

  

  void print(){
      std::queue<RedBlackNode *> nodes;
      RedBlackNode * current;
      int node = 0;
      int current_node = 1;
      nodes.push(root);
      std::cout<<"digraph {"<<std::endl;
      std::cout<<"node [ style = \"filled\" ];"<<std::endl;
      node_label(node,root);      
      while(!nodes.empty()){
	current = nodes.front();
	nodes.pop();
	if(current->left_n != nullptr){
	  node_label(current_node, current->left_n);
	  std::cout<<node<<" -> "<<current_node++<<"; left"<<std::endl;
	  nodes.push(current->left_n);
	}
	if(current->right_n != nullptr){
	  node_label(current_node, current->right_n);
	  std::cout<<node<<" -> "<<current_node++<<"; right"<<std::endl;
	  nodes.push(current->right_n);
	}
	node++;
      }
      std::cout<<"}"<<std::endl;
    }    

};

}
#endif
