#include "arraylist.h"
#include<stdio.h>
#include<stdlib.h>

arraylist_t * arraylist_create(){
  arraylist_t * res = (arraylist_t *) malloc( sizeof(arraylist_t) );
  res->data = (int *) malloc( sizeof(int) * 4 );
  res->capacity = 4;
  res->size = 0;
  return res;
}

void arraylist_destroy(arraylist_t * a){
  if( a != NULL ){
    if( a->data != NULL )
      free( a->data );
    free( a );
  }
}

char arraylist_append(arraylist_t * a, int x){
  char memory_allocation = FALSE;
  if( a!=NULL ){
    if( arraylist_enlarging_capacity(a) ){
      memory_allocation = TRUE;
      a->capacity *= 2;
      a->data = (int *) realloc(a->data, sizeof(int) * a->capacity);
    }
    a->data[a->size++] = x;
  }
  return memory_allocation;
}

char arraylist_pop_back(arraylist_t * a){
  char memory_reduction = FALSE;
  if( a!=NULL && a->size>0 ){
    if( arraylist_reducing_capacity(a) ){
      memory_reduction = TRUE;
      a->capacity /= 2; 
      a->data = (int *) realloc(a->data, sizeof(int) * a->capacity);
    }
    a->size--;
  }
  return memory_reduction;
}


int arraylist_get(arraylist_t * a, int pos){
  if( a != NULL && pos >0 && pos < a->size ){
    return a->data[pos];
  }
  printf("Wrong parameter pos=%d or NULL list", pos);
  return -1;
}

size_t arraylist_get_size(arraylist_t * a){
  return ( a!=NULL) ? a->size : -1;
}

char arraylist_enlarging_capacity(arraylist_t * a){
  return ( a->size >= (a->capacity * 3)/4 )? TRUE: FALSE;
}

char arraylist_reducing_capacity(arraylist_t * a){
  return ( a->size <= a->capacity/4 && a->size >4 )? TRUE: FALSE;
}
