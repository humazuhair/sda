#include<iostream>
#include <chrono>
#include<cstdlib>	
#include "structures/RedBlackTree.hpp"
#include "analysis/analyzer.hpp"

using namespace structures;
using namespace analysis;
using namespace std::chrono;

int main(int argc, char ** argv){
  int i;
  int max = 3;
  // Tas Binaire borné.
  RedBlackTree<int> dh;
  // Analyse du temps pris par les opérations.
  Analyzer time_analysis;
  high_resolution_clock::time_point before, after;

  for(i = 0; i < max ; i++){
    //double rand_value = rand() / (double) RAND_MAX;
    double rand_value = 0;
    if( dh.get_size() == 0 ||  rand_value < 0.49 ){
      int key = rand()%200;
      // Ajout d'un élément et mesure du temps pris par l'opération.
      before = high_resolution_clock::now();
      dh.insert(key);
      after = high_resolution_clock::now();
      dh.print();
      std::cerr<<"---------------------------"<<std::endl;
    }
    /*else{
      before = high_resolution_clock::now();
      dh.pop();
      after = high_resolution_clock::now();
      }*/
      
    // Enregistrement du temps pris par l'opération
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(after - before);    
    time_analysis.append(static_cast<double>(duration.count()));
    // Enregistrement du nombre de copies efféctuées par l'opération.
    // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
    //swap_analysis.append( dh.get_swap_counter() );
  }

  // Affichage de quelques statistiques sur l'expérience.
  /*std::cerr<<"Total cost :"<<time_analysis.get_total_cost()<<std::endl;
  std::cerr<<"Average cost :"<<time_analysis.get_average_cost()<<std::endl;
  std::cerr<<"Variance :"<<time_analysis.get_variance()<<std::endl;
  std::cerr<<"Standard deviation :"<<time_analysis.get_standard_deviation()<<std::endl;    
  */
  // Sauvegarde les données de l'expérience.
  //time_analysis.save_values("../plots/red_black_tree_rand_time_cpp.plot");
  dh.print();
  return 0;
}
  
