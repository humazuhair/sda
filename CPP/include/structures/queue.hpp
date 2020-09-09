#ifndef __STACK_HPP
#define __STACK_HPP

#include"arraylist.hpp"

namespace structures {

  /**
     Cette classe est un proxy pour les vecteurs, c'est à dire les tableaux dynamiques en C++.
     On utilise cette classe afin d'avoir le contrôle sur la gestion de la mémoire.
  */
  template <typename P>
  class Queue : public ArrayList<P> {
  public:
    Queue(){
      top = 0;
    }

    inline void push(const P & x){
      if( this->do_we_need_to_enlarge_capacity() )
	this->enlarge_capacity();
      this->data[( this->size + top ) % this->capacity] = x;
      this->size++;      
    }
    
    inline P pop(){
      if( this->size == 0 )
	throw std::runtime_error("Cannot pop an empty queue");
      P res = this->data[top];
      top = (top + 1) % this->capacity;
      this->size--;
      if( this->do_we_need_to_reduce_capacity() )
	this->reduce_capacity();
      return res;
    }
    
  private:
    int top;

    inline void realloc(int new_capacity){
      P * tmp = new P[new_capacity];
      if( (this->size + top) > this->capacity ){
	std::memcpy( tmp, &this->data[top], sizeof(P) * (this->capacity - top) );
	std::memcpy( &tmp[this->capacity - top], &this->data[0],
		     sizeof(P) * (this->size-(this->capacity - top)) );	  
      }
      else{
	std::memcpy( tmp, &this->data[top], sizeof(P) * this->size );
      }
      delete [] this->data;
      this->data = tmp;
      top = 0;
    }    
  };

}// namespace structures

#endif
