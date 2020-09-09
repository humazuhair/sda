#ifndef __BOUNDED_MAX_HEAP_HPP
#define __BOUNDED_MAX_HEAP_HPP

#include"bounded_heap.hpp"
#include"arraylist.hpp"

namespace structures {

  template <typename T>
  class BoundedMaxHeap: public BoundedHeap<T> {
  public:
    BoundedMaxHeap(const int capacity_p) : BoundedHeap<T>(capacity_p) {}
    
  private:
    bool compare_elements(int pos1, int pos2){
      return this->tree[pos1] > this->tree[pos2];
    }
  };
}//namespace structures
#endif
