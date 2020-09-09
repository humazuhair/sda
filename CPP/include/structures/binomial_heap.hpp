#ifndef __BINOMIAL_HEAP_HPP
#define __BINOMIAL_HEAP_HPP

#include<list>
#include "binomial_tree.hpp"
#include "heap.hpp"

namespace structures {
  
  template <typename T>
  class BinomialHeap: public Heap<T> {
  public:
    BinomialHeap():size(0){}
    BinomialHeap(const T & val):size(0){
      push(val);
    }
    BinomialHeap(std::list<BinomialTree<T> > subTrees, size_t size_p):trees(subTrees),size(size_p){}
    
    T pop() {      
      auto it = trees.begin();
      auto it_min = it;
      for(it++; it != trees.end(); it++){
	if(it->get_value() < it_min->get_value())
	  it_min = it;
      }
      T res = it_min->get_value();
      int pop_size = (1<<it_min->get_rank()) -1;
      if(pop_size > 0){
	BinomialHeap subTrees(it_min->pop(), pop_size);
	trees.erase(it_min);
	if(pop_size > 0)
	  merge(subTrees);
      }else trees.erase(it_min);
      size--;
      return res;
    }

    void push(const T & val){
      if(trees.empty())
	trees.push_front(BinomialTree<T>(val));
      else{
	BinomialHeap bh(val);
	merge(bh);
      }
      size++;
    }
    
    size_t get_size(){ return size;}
    
    void merge(BinomialHeap & bh){
      auto local_it = trees.begin();
      auto retenue = trees.end();
      size += bh.size;
      while(local_it != trees.end() && !bh.empty()){
	//Both current trees have the same rank r -> merge into a tree of rank r+1
	if( bh.front().get_rank() == local_it->get_rank() ){
	  if( bh.front().get_value() < local_it->get_value() )
	    std::iter_swap(local_it, bh.trees.begin());
	  local_it->addSubtree(bh.front());
	  bh.trees.pop_front();
	  retenue = local_it;
	  local_it++;
	}
	else{
	  //Other tree has a lesser rank
	  if(bh.front().get_rank() < local_it->get_rank()){
	    if(retenue != trees.end() && bh.front().get_rank() == retenue->get_rank()){
	      if( bh.front().get_value() < retenue->get_value() )
		std::iter_swap(retenue, bh.trees.begin());
	      retenue->addSubtree(bh.front());//Merge it with the retenue
	    }
	    else{
	      trees.emplace(local_it, bh.front());//Add it to the list
	    }
	    bh.trees.pop_front();	    
	  }
	  //Tries to merge tree and retenue
	  if(retenue != trees.end() && retenue->get_rank() == local_it->get_rank()){
	    if( retenue->get_value() < local_it->get_value() )
	      std::iter_swap(local_it, retenue);
	    local_it->addSubtree(*retenue);
	    trees.erase(retenue);
	    retenue = trees.end();
	    local_it++;
	  }
	}
      }
      //Check last merge.
      if(local_it != trees.end() && retenue != trees.end()){
	while(local_it->get_rank() == retenue->get_rank()){
	  if( retenue->get_value() < local_it->get_value() )
	    std::iter_swap(local_it, retenue);
	  local_it->addSubtree(*retenue);
	  trees.erase(retenue);
	  retenue = local_it;
	  local_it++;
	}
      }
      if(!bh.empty()){
	while( retenue != trees.end() ){
	  if ( bh.front().get_value() < retenue->get_value() )
	    std::iter_swap(retenue, bh.trees.begin());
	  retenue->addSubtree(bh.front());
	  bh.trees.pop_front();
	}
	trees.splice(trees.end(),bh.trees);
      }
    }
    
    friend std::ostream& operator<<(std::ostream& o,const BinomialHeap<T> & bh){
      o<<"digraph{ ";
      for(BinomialTree<T> tree: bh.trees){
	o<<tree;
      }
      o<<"}";
      return o;
    }
    
  private:
    std::list<BinomialTree<T> > trees;
    size_t size;

    inline BinomialTree<T>& front() { return trees.front(); };
    inline bool empty(){
      return trees.empty();
    }
    
    
  };
}//namespace structures

#endif
