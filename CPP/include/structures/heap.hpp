#ifndef __HEAP_HPP
#define __HEAP_HPP

namespace structures {
  
  template <typename T>
  class Heap{
  public:
    
    virtual T pop() = 0;
    virtual void push(const T & val) = 0;
    virtual size_t get_size() = 0;
    
  };
}//namespace structures

#endif
