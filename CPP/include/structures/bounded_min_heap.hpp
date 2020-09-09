#ifndef __BOUNDED_MIN_HEAP_HPP
#define __BOUNDED_MIN_HEAP_HPP

#include"bounded_heap.hpp"
#include"arraylist.hpp"

namespace structures {

  template <typename T>
  class BoundedMinHeap: public BoundedHeap<T> {
  public:
    BoundedMinHeap(const int capacity_p) : BoundedHeap<T>(capacity_p) {}
    
  private:
    bool compare_elements(int pos1, int pos2){
      return this->tree[pos1] < this->tree[pos2];
    }
  };
}//namespace structures
#endif
