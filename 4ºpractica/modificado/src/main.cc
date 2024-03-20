#include <iostream>
#include <string>
#include "Nif/Nif.h"
#include "HashTable/HashTable.h"
#include "Sequence/Sequence.h"
#include "DispersionFunction/DispersionFunction.h"
#include "ExplorationFunction/ExplorationFunction.h"
void menu(openHashTable<coche>& HashTable);
void menu(closedHashTable<coche>& HashTable);

int main(int argc, char* argv[]) {
  Dato argumentos;
  try {
    argumentos = leer_datos(argc, argv);
  } catch (std::string& error) {
    std::cerr << error << std::endl;
    exit(EXIT_FAILURE);
  }
  DispersionFunction<coche>* df;
  ExplorationFunction<coche>* ef;
  switch (argumentos.funcion_dispersion) { // elijo el tipo de función de dispersión
    case 1:
      df = new Modulo<coche>(argumentos.table_size);
      break;
    case 2:
      df = new PseudoRandom<coche>(argumentos.table_size);
      break;
    case 3:
      df = new Sum<coche>(argumentos.table_size);
      break;
    default:
      break;
  }
  if(argumentos.hash_type == 1) { // elijo el tipo de hash
    switch (argumentos.funcion_exploracion) { // elijo el tipo de exploración
      case 1:
        ef = new LinearExploration<coche>(*df);
        break;
      case 2:
        ef = new QuadraticExploration<coche>(*df);
        break;
      case 3:
        ef = new DoubleDispersion<coche>(*df);
        break;
      case 4:
        ef = new Redispersion<coche>(*df);
        break;
      default:
        break;
    }
    closedHashTable<coche> HashTable(argumentos.table_size, *df, *ef, argumentos.block_size);
    menu(HashTable);
  } else {
    openHashTable<coche> HashTable(argumentos.table_size, *df);
    menu(HashTable);
  }
  return 0;
}




void menu(closedHashTable<coche>& HashTable) {
  while (true) {
    std::cout << "Introduce uno de los siguientes parámetros:\n'x' para salir del programa\n'i' para insertar un coche en la tabla\n's' para buscar un coche en la tabla" << std::endl;
    char opcion;
    std::cin >> opcion;
    switch (opcion) {
      case 'i': {
        std::string cochito;
        std::cout << "Introduce la matrícula del coche a insertar: ";
        std::cin >> cochito;
        coche n(cochito);
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
        std::string cochito;
        std::cout << "Introduce el coche a buscar: ";
        std::cin >> cochito;
        coche n(cochito);
        if (HashTable.search(n)) {
          system("clear");
          std::cout << "El coche se encuentra en la tabla" << std::endl;
          std::cout << HashTable << std::endl;
        } else {
          system("clear");
          std::cout << "El coche no se encuentra en la tabla" << std::endl;
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

void menu(openHashTable<coche>& HashTable) {
  while (true) {
    std::cout << "Introduce uno de los siguientes parámetros:\n'x' para salir del programa\n'i' para insertar un coche en la tabla\n's' para buscar un coche en la tabla" << std::endl;
    char opcion;
    std::cin >> opcion;
    switch (opcion) {
      case 'i': {
        std::string matricula;
        std::cout << "Introduce la matricula a insertar: ";
        std::cin >> matricula;
        coche n(matricula);
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
        std::string matricula;
        std::cout << "Introduce el matricula a buscar: ";
        std::cin >> matricula;
        coche n(matricula);
        if (HashTable.search(n)) {
          system("clear");
          std::cout << "La matricula se encuentra en la tabla" << std::endl;
          std::cout << HashTable << std::endl;
        } else {
          system("clear");
          std::cout << "La matricula no se encuentra en la tabla" << std::endl;
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