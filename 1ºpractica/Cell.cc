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
  * @brief Constructor por defecto de la clase Cell.
  * @param pos, estado
  * @return objeto de la clase Cell
  */
Cell::Cell() {}

/** Cell::Cell(const Position& pos, const State& estado)
  * @brief Crea el objeto de la clase Cell.
  * @param pos, estado
  * @return objeto de la clase Cell
  */
Cell::Cell(const Position& pos, const State& estado) {
  this->posicion_ = pos;
  this->estado_ = estado;
  return;
}

/** int nextState(const Lattice&) 
  * @brief determina el siguiente estado de la célula
  * @param lattice
  * @return el siguiente estado de la célula
  */
int Cell::nextState(const Lattice& lattice) {
  // Con la función que hay en la practica
}

/** State getState() const;
  * @brief obtienes el estado de la celula
  * @return estado de la celula
  */
State Cell::getState() const {
  return this->estado_;
}

/** State setState(State);
  * @brief Pone como estado de la celula el valor dado
  * @param estado
  */
void Cell::setState(State estado) {
  this->estado_ = estado;
}
/** void updateState()
  * @brief actualiza el estado de la célula
  */
void Cell::updateState() {
  this->estado_ = this->siguiente_estado_;
}

/** std::ostream& operator<<(std::ostream&, const Cell&)
  * @brief sobrecarga del operador <<
  * @param os, celula 
  * @return objeto ostream
  */
std::ostream& operator<<(std::ostream& os, const Cell& celula) {
  // Necesito hacerlo con un struct
  os << celula.estado_;
  return os;
}

#endif