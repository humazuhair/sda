#ifndef __DYNAMIC_MAX_HEAP_HPP
#define __DYNAMIC_MAX_HEAP_HPP

#include"dynamic_heap.hpp"
#include"arraylist.hpp"

namespace structures {

  template <typename T>
  class DynamicMaxHeap: public DynamicHeap<T> {
  private:
    bool compare_elements(int pos1, int pos2){      
      return this->tree.get(pos1) > this->tree.get(pos2);
    }
  };
}//namespace structures
#endif
