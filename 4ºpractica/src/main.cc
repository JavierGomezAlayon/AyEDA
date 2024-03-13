#include <iostream>
#include "DispersionFunction/DispersionFunction.h"
#include "Nif/Nif.h"
#include "HashTable/HashTable.h"
#include "Sequence/Sequence.h"
#include "ExplorationFunction/ExplorationFunction.h"

int main() {
  Nif nif1;
  Nif nif2;
  Nif nif3;
  Nif nif4;
  Nif nif5;
  Nif nif6;
  Nif nif7;
  Nif nif8;
  Nif nif9;
  Nif nif10;

  std::cout << nif1.getOriginal() << std::endl;
  std::cout << nif1.getValue() << std::endl;
  std::cout << nif2.getOriginal() << std::endl;
  std::cout << nif2.getValue() << std::endl;
  std::cout << nif3.getOriginal() << std::endl;
  std::cout << nif3.getValue() << std::endl;
  std::cout << nif4.getOriginal() << std::endl;
  std::cout << nif4.getValue() << std::endl;
  std::cout << nif5.getOriginal() << std::endl;
  std::cout << nif5.getValue() << std::endl;
  std::cout << nif6.getOriginal() << std::endl;
  std::cout << nif6.getValue() << std::endl;
  std::cout << nif7.getOriginal() << std::endl;
  std::cout << nif7.getValue() << std::endl;
  std::cout << nif8.getOriginal() << std::endl;
  std::cout << nif8.getValue() << std::endl;
  std::cout << nif9.getOriginal() << std::endl;
  std::cout << nif9.getValue() << std::endl;
  std::cout << nif10.getOriginal() << std::endl;
  std::cout << nif10.getValue() << std::endl;
}