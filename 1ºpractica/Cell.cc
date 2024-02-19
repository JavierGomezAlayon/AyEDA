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
  * @brief determina el siguiente estado de la célula y lo guarda en siguiente_estado_
  * @param lattice
  */
void Cell::nextState(const Lattice& lattice) {
  int posicion_centro = this->posicion_.getPosition();
  // Determino las células de los lados y del centro
  int centro = this->estado_.getState(); // el centro siempre va a ser la celula que llama al metodo.
  int izquierda;
  int derecha;
  if (lattice.getFrontera() == periodica && posicion_centro == 0) {
    izquierda = lattice.getCell(lattice.getTamano() - 1).estado_.getState();
    derecha = lattice.getCell(posicion_centro + 1).estado_.getState();
  } else if (lattice.getFrontera() == periodica && posicion_centro == lattice.getTamano() - 1) {
    izquierda = lattice.getCell(posicion_centro - 1).estado_.getState();
    derecha = lattice.getCell(0).estado_.getState();
  } else {
    izquierda = lattice.getCell(posicion_centro - 1).estado_.getState();
    derecha = lattice.getCell(posicion_centro + 1).estado_.getState();
  }
  // Función de nextState
  int siguiente_estado = (centro + derecha + centro * derecha + izquierda * centro *
   derecha);
  // Según el int genero el siguiente estado
  if (siguiente_estado % 2 == 0) {
    this->siguiente_estado_.setState(muerto);
  } else {
    this->siguiente_estado_.setState(vivo);
  }
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