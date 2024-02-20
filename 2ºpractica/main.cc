
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

// algo copiado de internet para hacer las cosas más bonitas y pasar de generación en generación de una forma más cómoda.
#include <termios.h>
#include <unistd.h>
int getch() {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

int main(int argc, char* argv[]) {
  Dato datos = RecogerParametro(argc, argv);
  Lattice lattice(datos.tamano, datos.border_type, datos.fichero);
  if (datos.fichero == "") {
    lattice.inicializar();
  }
  // bucle para pasar de generación en generación
  while (getch()) {
    std::cout << lattice << std::endl;
    lattice.nextGeneration();
  }
  return 0;
}

#endif