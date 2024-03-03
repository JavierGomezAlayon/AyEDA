// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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

#include"Cell.h"
#include "Lattice.h"

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
void Cell::nextState(Lattice& lattice) {
  std::pair<int,int> posicion_centro = this->posicion_.getPosition();
  // Determino las células de los lados y del centro
  int A_A = lattice.getCell(Position (posicion_centro.first - 1, posicion_centro.second - 1)).getState().getState();
  int B_A = lattice.getCell(Position (posicion_centro.first, posicion_centro.second - 1)).getState().getState();
  int C_A = lattice.getCell(Position (posicion_centro.first + 1, posicion_centro.second - 1)).getState().getState();
  int A_B = lattice.getCell(Position (posicion_centro.first - 1, posicion_centro.second)).getState().getState();
  int B_B = this->estado_.getState(); // el centro siempre va a ser la celula que llama al metodo.
  int C_B = lattice.getCell(Position (posicion_centro.first + 1, posicion_centro.second)).getState().getState();
  int A_C = lattice.getCell(Position (posicion_centro.first - 1, posicion_centro.second + 1)).getState().getState();
  int B_C = lattice.getCell(Position (posicion_centro.first , posicion_centro.second + 1)).getState().getState();
  int C_C = lattice.getCell(Position (posicion_centro.first + 1, posicion_centro.second + 1)).getState().getState();
  int suma = (A_A + B_A + C_A + A_B + C_B + A_C + B_C + C_C);
  if (B_B == 1 &&(suma == 2 || suma == 3)) {
    this->siguiente_estado_ = vivo;
  } else if (B_B == 0 && suma == 3) {
    this->siguiente_estado_ = vivo;
  } else {
    this->siguiente_estado_ = muerto;
  }
}

/** State getState() const;
  * @brief obtienes el estado de la celula
  * @return estado de la celula
  */
State Cell::getState() const {
  return this->estado_;
}

/** State getNextState() const;
  * @brief obtienes el siguiente estado de la celula
  * @return siguiente estado de la celula
  */
State Cell::getNextState() const {
  return this->siguiente_estado_;
}

/** Position getPosition() const;
  * @brief obtienes la posición de la celula
  * @return posición de la celula
  */
Position Cell::getPosition() const {
  return this->posicion_;
}

/** State setState(State);
  * @brief Pone como estado de la celula el valor dado
  * @param estado
  */
void Cell::setState(State estado) {
  this->estado_ = estado;
}

/** void setPosition(Position);
  * @brief Pone como posición de la celula el valor dado
  * @param posicion
  */
void Cell::setPosition(Position posicion) {
  this->posicion_ = posicion;
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
  os << celula.estado_;
  return os;
}