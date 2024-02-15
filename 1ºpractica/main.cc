// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo main.cc: El programa cliente.
//        
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_main_CC
#define C_main_CC

#include"Lattice.h"
#include"Cell.h"
#include"funciones_main.h"

int main(int argc, char** argv) {
  State estate(vivo);
  Position posicion(0);
  Cell celula1(posicion,estate);
  Lattice lattice(8,abierta,"hola");
  lattice.inicializar();
  std::cout << celula1 << std::endl;
  Position posicion1(10);
  std::cout << lattice.getCell(posicion1) << std::endl;
  std::cout << lattice << std::endl;
  return 0;
}

#endif