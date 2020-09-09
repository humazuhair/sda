#ifndef __STACK_HPP
#define __STACK_HPP

#include"arraylist.hpp"

namespace structures {

  /**
     Cette classe est un proxy pour les vecteurs, c'est à dire les tableaux dynamiques en C++.
     On utilise cette classe afin d'avoir le contrôle sur la gestion de la mémoire.
  */
  template <typename P>
  class Stack : public ArrayList<P> {
  public:
    inline void push(const P & x){
      this->append(x);
    }
    inline P pop(){
      this->pop_back();
      return this->data[this->size];
    }

  };
}// namespace structures


#endif
