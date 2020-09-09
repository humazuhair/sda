#ifndef __DYNAMIC_HEAP_HPP
#define __DYNAMIC_HEAP_HPP

#include"binary_heap.hpp"
#include"arraylist.hpp"

namespace structures {

  template <typename T>
  class DynamicHeap : public BinaryHeap<T> {
  public:

    /**
       Throws an axception if pos is out of bound.
    */
    T pop() {
      int size = tree.get_size();
      if( size == 0 )
	throw new std::runtime_error("Cannot pop an empty heap");      
      T	result = tree.get(0);
      swap(0, size-1);
      tree.pop_back();
      this->down_heap();
      return result;
    }
    
    void push(const T & val) {
      tree.append(val);
      this->up_heap();
    }
    
    size_t get_size() {
      return tree.get_size();
    }

  protected:
    ArrayList<T> tree;
    
  private:

    void swap(const int pos1,const  int pos2){
      tree.swap(pos1, pos2);
    }

    /**
       Throws an axception if pos is out of bound.
     */
    inline T get(const int pos){
      return tree.get(pos);
    }
    
  };
}//namespace structures

#endif
