#include <iostream>
#include "DispersionFunction/DispersionFunction.h"
#include "Nif/Nif.h"
#include "HashTable/HashTable.h"
#include "Sequence/Sequence.h"
#include "ExplorationFunction/ExplorationFunction.h"

int main() {
  std::cout << "pruebas de Nif: \n";
  Nif nif0;
  Nif nif1;

  std::cout << nif0.getValue() << std::endl;
  std::cout << nif0.getOriginal() << std::endl;
  std::cout << nif1.getOriginal() << std::endl;
  std::cout << nif1.getValue() << std::endl;

  std::cout << "\npruebas de Sequence: \n";
  std::cout << "pruebas de staticSequence: \n";
  staticSequence<Nif> sequence(3);
  std::cout << sequence.isFull() << std::endl;
  std::cout << sequence.insert(nif0) << std::endl;
  std::cout << sequence.search(nif1) << std::endl;
  std::cout << sequence.insert(nif1) << std::endl;
  std::cout << sequence.search(nif0) << std::endl;
  std::cout << sequence.search(nif1) << std::endl;
  std::cout << sequence.isFull() << std::endl;

  std::cout << "pruebas de dynamicSequence: \n";
  dynamicSequence<Nif> sequenced;
  std::cout << sequenced.insert(nif0) << std::endl;
  std::cout << sequenced.search(nif1) << std::endl;
  std::cout << sequenced.insert(nif1) << std::endl;
  std::cout << sequenced.search(nif0) << std::endl;
  std::cout << sequenced.search(nif1) << std::endl;
  
  std::cout << "\nprueba de DispersionFunction: \n";
  std::cout << "pruebas de Modulo: \n";
  DispersionFunction<Nif>* modulo = new Modulo<Nif>(3);
  std::cout << (*modulo)(nif0) << std::endl;
  std::cout << (*modulo)(nif1) << std::endl;

  std::cout << "pruebas de PseudoRandom: \n";
  DispersionFunction<Nif>* pseudoRandom = new PseudoRandom<Nif>(3);
  std::cout << (*pseudoRandom)(nif0) << std::endl;
  std::cout << (*pseudoRandom)(nif1) << std::endl;

  std::cout << "pruebas de Sum: \n"; 
  DispersionFunction<Nif>* sum = new Sum<Nif>(3);
  std::cout << (*sum)(nif0) << std::endl;
  std::cout << (*sum)(nif1) << std::endl;

  std::cout << "\nprueba de ExplorationFunction: \n";
  std::cout << "Todavía no se ha implementado de buena forma la función de exploración. \n";
  ExplorationFunction<Nif>* linearExploration = new LinearExploration<Nif>(*modulo);
  std::cout << (*linearExploration)(nif0, 2) << std::endl;
  std::cout << (*linearExploration)(nif1, 2) << std::endl;
  ExplorationFunction<Nif>* quadraticExploration = new QuadraticExploration<Nif>(*modulo);
  std::cout << (*quadraticExploration)(nif0, 3) << std::endl;
  std::cout << (*quadraticExploration)(nif1, 3) << std::endl;
  ExplorationFunction<Nif>* doubleDispersion = new DoubleDispersion<Nif>(*modulo);
  std::cout << (*doubleDispersion)(nif0, 2) << std::endl;
  std::cout << (*doubleDispersion)(nif1, 2) << std::endl;
  ExplorationFunction<Nif>* redispersion = new Redispersion<Nif>(*modulo);
  std::cout << (*redispersion)(nif0, 2) << std::endl;
  std::cout << (*redispersion)(nif1, 2) << std::endl;



  delete linearExploration;
  delete quadraticExploration;
  delete doubleDispersion;
  delete redispersion;

  delete modulo;
  delete pseudoRandom;
  delete sum;

  return 0;
}