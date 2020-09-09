#ifndef __DYNAMIC_MIN_HEAP_HPP
#define __DYNAMIC_MIN_HEAP_HPP

#include"heap.hpp"
#include"arraylist.hpp"

namespace structures {

  /**
     Cette classe est un proxy pour les vecteurs, c'est à dire les tableaux dynamiques en C++.
     On utilise cette classe afin d'avoir le contrôle sur la gestion de la mémoire.
  */
  template <typename T>
  class DynamicMinHeap: public DynamicHeap{
  private:
    bool compare_elements(int pos1, int pos2){
      return this->tree.get(pos1) < this->tree.get(pos2);
    }
  };
}

#endif
