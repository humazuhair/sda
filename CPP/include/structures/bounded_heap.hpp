#ifndef __BOUNDED_HEAP_HPP
#define __BOUNDED_HEAP_HPP

#include"binary_heap.hpp"
#include"arraylist.hpp"

namespace structures {

  template <typename T>
  class BoundedHeap : public BinaryHeap<T> {
  public:
    BoundedHeap(const int capacity_p){
      capacity = capacity_p;
      tree = new T[capacity];
      size = 0;
      swap_counter = 0;
    }
    
    /**
       Throws an axception if pos is out of bound.
    */
    T pop() {
      swap_counter = 0;
      if( size == 0 )
	throw new std::runtime_error("Cannot pop an empty heap");      
      T	result = tree[0];
      swap(0, size-1);
      size--;
      this->down_heap();
      return result;
    }
    
    void push(const T & val) {
      swap_counter = 0;
      if( size == capacity )
	throw new std::runtime_error("Cannot push value: heap is full");      
      tree[size++] = val;
      this->up_heap();
    }
    
    size_t get_size() {
      return size;
    }

    size_t get_swap_counter(){
      return swap_counter;
    }

    
  protected:
    T * tree;
    
  private:
    int size;
    int capacity;
    size_t swap_counter;

    void swap(const int pos1,const  int pos2){
      if( pos1 < 0 || pos1 > size)
	throw std::runtime_error(pos1+" is out of bound (Heap swap)");
      if( pos2 < 0 || pos2 > size)
	throw std::runtime_error(pos2+" is out of bound (Heap swap)");	    
      T tmp = tree[pos1];
      tree[pos1] = tree[pos2];
      tree[pos2] = tmp;
      swap_counter++;
    }


    /**
       Throws an axception if pos is out of bound.
     */
    inline T get(const int pos){
      if( pos < 0 || pos > size )
	throw std::runtime_error(pos+" is out of bound (Bounded Heap)");
      return tree[pos];
    }
    
  };
}//namespace structures

#endif
