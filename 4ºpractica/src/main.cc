#include <iostream>
#include <string>
#include "Nif/Nif.h"
#include "HashTable/HashTable.h"
#include "Sequence/Sequence.h"
#include "DispersionFunction/DispersionFunction.h"
#include "ExplorationFunction/ExplorationFunction.h"
#include "main.h"

int main(int argc, char* argv[]) {
  Dato argumentos;
  try {
    argumentos = leer_datos(argc, argv);
  } catch (std::string& error) {
    std::cerr << error << std::endl;
    exit(EXIT_FAILURE);
  }
  DispersionFunction<Nif>* df;
  ExplorationFunction<Nif>* ef;
  switch (argumentos.funcion_dispersion) { // elijo el tipo de función de dispersión
    case 1:
      df = new Modulo<Nif>(argumentos.table_size);
      break;
    case 2:
      df = new PseudoRandom<Nif>(argumentos.table_size);
      break;
    case 3:
      df = new Sum<Nif>(argumentos.table_size);
      break;
    default:
      break;
  }
  if(argumentos.hash_type == 1) { // elijo el tipo de hash
    switch (argumentos.funcion_exploracion) { // elijo el tipo de exploración
      case 1:
        ef = new LinearExploration<Nif>(*df);
        break;
      case 2:
        ef = new QuadraticExploration<Nif>(*df);
        break;
      case 3:
        ef = new DoubleDispersion<Nif>(*df);
        break;
      case 4:
        ef = new Redispersion<Nif>(*df);
        break;
      default:
        break;
    }
    closedHashTable<Nif> HashTable(argumentos.table_size, *df, *ef, argumentos.block_size);
    menu(HashTable);
  } else {
    openHashTable<Nif> HashTable(argumentos.table_size, *df);
    for (int i = 0; i < 10; i++) {
      HashTable.insertar(Nif());
    }
    std::cout << HashTable << std::endl;
  }
  return 0;
}

void menu(closedHashTable<Nif>& HashTable) {
  while (true) {
    std::cout << "Introduce uno de los siguientes parámetros:\n'x' para salir del programa\n'i' para insertar un Nif en la tabla\n's' para buscar un Nif en la tabla" << std::endl;
    char opcion;
    std::cin >> opcion;
    switch (opcion) {
      case 'i': {
        std::string nif;
        std::cout << "Introduce el Nif a insertar: ";
        std::cin >> nif;
        Nif n(nif);
        if (HashTable.insertar(n)) {
          system("clear");
          std::cout << "Insertado con éxito" << std::endl;
          std::cout << HashTable << std::endl;
        } else {
          system("clear");
          std::cout << "No se ha podido insertar" << std::endl;
          std::cout << HashTable << std::endl;
        }
        break;
      }
      case 's':{
        std::string nif;
        std::cout << "Introduce el Nif a buscar: ";
        std::cin >> nif;
        Nif n(nif);
        if (HashTable.search(n)) {
          system("clear");
          std::cout << "El Nif se encuentra en la tabla" << std::endl;
          std::cout << HashTable << std::endl;
        } else {
          system("clear");
          std::cout << "El Nif no se encuentra en la tabla" << std::endl;
          std::cout << HashTable << std::endl;
        }
        break;
      }
      case 'x':
        std::cout << "Saliendo del programa" << std::endl;
        return;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
}