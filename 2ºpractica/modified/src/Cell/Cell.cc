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
#include"../Lattice/Lattice.h"

/** Cell::Cell(const Position& pos, const State& estado)
  * @brief Crea el objeto de la clase Cell.
  * @param pos, estado
  * @return objeto de la clase Cell
  */
Cell::Cell(const Position& pos, const State& estado) {
  this->posicion_ = pos;
  this->estado_ = estado;
  this->siguiente_estado_ = muerto;
  return;
}
/** int nextState(const Lattice&) 
  * @brief determina el siguiente estado de la célula y lo guarda en siguiente_estado_
  * @param lattice
  */
void Cell::nextState(Lattice& lattice) {
  std::pair<int,int> posicion_centro = this->posicion_.getPosition();
  // Determino las células de los lados y del centro (antes de la modificación)
  //modificación
  int pos0 = this->estado_.getState();
  int pos1 = lattice.getCell(Position (posicion_centro.first - 2 , posicion_centro.second - 2 )).getState().getState();
  int pos2 = lattice.getCell(Position (posicion_centro.first - 2, posicion_centro.second )).getState().getState();
  int pos3 = lattice.getCell(Position (posicion_centro.first - 2, posicion_centro.second + 2)).getState().getState();
  int pos4 = lattice.getCell(Position (posicion_centro.first - 1, posicion_centro.second + 3)).getState().getState();
  int pos5 = lattice.getCell(Position (posicion_centro.first, posicion_centro.second + 2)).getState().getState();
  int pos6 = lattice.getCell(Position (posicion_centro.first + 1, posicion_centro.second + 3)).getState().getState();
  int pos7 = lattice.getCell(Position (posicion_centro.first + 2, posicion_centro.second + 2)).getState().getState();
  int pos8 = lattice.getCell(Position (posicion_centro.first + 2, posicion_centro.second)).getState().getState();
  int pos9 = lattice.getCell(Position (posicion_centro.first + 2, posicion_centro.second - 1)).getState().getState();
  int pos10 = lattice.getCell(Position (posicion_centro.first + 1, posicion_centro.second - 1)).getState().getState();
  int pos11 = lattice.getCell(Position (posicion_centro.first, posicion_centro.second - 1)).getState().getState();
  int suma = (pos0 + pos1 + pos2 + pos3 + pos4 + pos5 + pos6 + pos7 + pos8 + pos9 + pos10 + pos11);
  if (pos0 == 1 &&(suma == 2 || suma == 3)) {
    this->siguiente_estado_ = vivo;
  } else if (pos0 == 0 && suma == 3) {
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