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
#include "Funciones/Funciones.h"
#include "Sequence/Sequence.h"
#include "Nif/Nif.h"



int main(int argc, char *argv[]) {
  Dato datos;
  try {
    datos = leer_datos(argc, argv);
  } catch (std::string &error) {
    std::cerr << error << std::endl;
    return 1;
  }
  std::cout << "Datos leidos correctamente" << std::endl;
  Sequence<Nif>* secuencia;
  secuencia = new staticSequence<Nif>(datos.size);
  for (int i = 0; i < datos.size; i++) {
    secuencia->insert(Nif());
  }
  std::cout << *secuencia << std::endl;
  return 0;
}

