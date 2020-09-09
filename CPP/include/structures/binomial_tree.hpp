#ifndef __BINOMIAL_TREE_HPP
#define __BINOMIAL_TREE_HPP

#include<list>
#include<queue>
#include<iostream>

namespace structures {
  
  template <typename T>
  class BinomialTree{
  public:
    BinomialTree(const T & value_p){ value = value_p; }
    
    const size_t get_rank(){ return subTrees.size(); }
    inline T get_value(){ return value; } 
    std::list<BinomialTree<T> > & pop(){ return subTrees; }
    
    void addSubtree(BinomialTree bt){
      if(bt.get_rank() != get_rank())
	throw new std::runtime_error("Cannot add a binomial tree with a different rank");
      subTrees.push_back(bt);
    }
    
    friend std::ostream& operator<<(std::ostream& o,const BinomialTree<T> & a){
      std::queue<BinomialTree<T> > nodes;
      BinomialTree<T> current = a;
      int node = (1<<(a.subTrees.size())) -1;
      int node_child = node+1;
      nodes.push(a);
      o<<node<<" [label =\""<<current.value<<"\"];"<<std::endl;
      while(!nodes.empty()){
	current = nodes.front();
	nodes.pop();
	for(BinomialTree<T> subTree: current.subTrees){
	  //o<<current.value<<" -> "<<subTree.value<<"; ";
	  o<<node_child<<" [label =\""<<subTree.value<<"\"];";
	  o<<node<<" -> "<<node_child++<<"; "<<std::endl;
	  nodes.push(subTree);
	}
	node++;
      }
      return o;
    }    

  private:
    std::list<BinomialTree<T> > subTrees;
    T value;
    
  };

  
} //namespace structures
#endif
