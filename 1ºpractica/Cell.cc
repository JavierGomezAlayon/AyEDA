// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Cell.cc: Implementación de Cell
//        En este fichero se implementa las funciones de la clase Cell
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_Cell_CC
#define C_Cell_CC

#include"Cell.h"

/** Cell::Cell()
  * @brief Crea el objeto de la clase Cell.
  * @param pos, estado
  * @return objeto de la clase Cell
  */
Cell::Cell(const Position& pos, const State& estado) {

}

/** int nextState(const Lattice&) 
  * @brief determina el siguiente estado de la célula
  * @param lattice
  * @return el siguiente estado de la célula
  */
int Cell::nextState(const Lattice& lattice) {
  
}

/** void updateState()
  * @brief actualiza el estado de la célula
  */
void Cell::updateState() {

}

/** std::ostream& operator<<(std::ostream&, const Cell&)
  * @brief sobrecarga del operador <<
  * @param os, celula 
  * @return objeto ostream
  */
std::ostream& operator<<(std::ostream& os, const Cell& celula) {

}

#endif