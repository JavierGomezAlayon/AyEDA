// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo main.cc: programa cliente.
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <fstream>
#include "Funciones/Funciones.h"
#include "Sequence/Sequence.h"
#include "Nif/Nif.h"
#include "Metodos/Metodos.h"
#include "SortMethod/SortMethod.h"

void setInit(Dato& datos, staticSequence<Nif>* secuencia);

int main(int argc, char *argv[]) {
  Dato datos;
  try { // leer datos
    datos = leer_datos(argc, argv);
  } catch (std::string &error) {
    std::cerr << error << std::endl;
    return 1;
  }
  staticSequence<Nif>* secuencia;
  secuencia = new staticSequence<Nif>(datos.size);
  try { // init
  setInit(datos, secuencia);
  } catch (std::string &error) {
    std::cerr << error << std::endl;
    return 1;
  }
  SortMethod<Nif>* metodo;
  switch (datos.ordenacion) {
    case 1:
      metodo = new Seleccion<Nif>(secuencia,datos.trace);
      break;
    case 2:
      metodo = new QuickSort<Nif>(secuencia,datos.trace);
      break;
    case 3:
      metodo = new HeapSort<Nif>(secuencia,datos.trace);
      break;
    case 4:
      metodo = new ShellSort<Nif>(secuencia,datos.trace);
      break;
    case 5:
      metodo = new RadixSort<Nif>(secuencia,datos.trace);
      break;
    default:
      std::cerr << "(6) Error en la elección del método de ordenación" << std::endl;
      return 1;
  }
  metodo->sort();
  std::cout << *secuencia << std::endl;
  return 0;
}


void setInit(Dato& datos, staticSequence<Nif>* secuencia) {
  if (datos.init == 2) {  // init random
    for (int i = 0; i < datos.size; i++) {
      secuencia->insert(Nif());
    }
  } else if (datos.init == 1) {  // init manual
    for (int i = 0; i < datos.size; i++) {
      std::string nif;
      std::cout << "Introduce un NIF: ";
      std::cin >> nif;
      secuencia->insert(Nif(nif));
    }
  } else if (datos.init == 3) {  // init fichero
    std::ifstream file(datos.fichero);
    if (!file) {
      throw "(5) Error al abrir el fichero";
    }
    std::string nif;
    while (file >> nif) {
      secuencia->insert(Nif(nif));
    }
  }
}
