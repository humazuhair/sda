#ifndef __BINARY_HEAP_HPP
#define __BINARY_HEAP_HPP

#include"heap.hpp"


namespace structures {

  template <typename T>
  class BinaryHeap: public Heap<T> {
  protected:
    virtual bool compare_elements(int pos1, int pos2) = 0;
    virtual void swap(int pos1, int pos2) = 0;
    virtual T get(int pos) = 0;
    
    
    void up_heap(){
      int pos = this->get_size() - 1;
      int pos_parent = (pos-1)/2;
      while( pos > 0 &&
	     compare_elements(pos, pos_parent) ){
	swap(pos, pos_parent);
	pos = pos_parent;
	pos_parent = (pos-1)/2;
      }
    }

    void down_heap(){
      size_t pos = 0;
      size_t child_pos = min_max_child(pos);
      while( child_pos>=0 &&
	     compare_elements(child_pos, pos) ){
	swap(pos, child_pos);
	pos = child_pos;
	child_pos = min_max_child(pos);
      }
    }

    inline int min_max_child(size_t pos){
      if( 2*pos+1 >= this->get_size() )
	return -1;
      if( 2*pos+2 >= this->get_size() )
	return 2*pos+1;  
      return ( compare_elements(2*pos+1,2*pos+2) )? 2*pos+1: 2*pos+2;
    }

  };
}//namespace structures

#endif
