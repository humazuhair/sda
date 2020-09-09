#ifndef __BTREE__
#define __BTREE__


/**
   @ensures capacity of nodes >= order * size
 */
template <typename T>
class BTree{
public:
  BTree(int order){
    
  }
private:
  int order;
  std::vector<T> nodes;
  
};

#endif
