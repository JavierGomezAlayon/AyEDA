// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo State.cc: Implementación de State
//        En este fichero se implementa las funciones de la clase State
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código

#include"State.h"

/** State::State(const int)
  * @brief Constructor de la clase State.
  * @return objeto de la clase State
  */
State::State(const estado estado) {
  this->setState(estado);
}


/** int State::getState() const 
  * @brief Para obtener el valor del estado
  * @return El estado
  */
int State::getState() const {
  return this->estado_;
}

/** void State::setState(const int estado)
  * @brief Pone como estado el valor dado
  * @param estado
  */
void State::setState(const estado estado) {
  this->estado_ = estado;
}

/** std::ostream &operator<<(std::ostream &os, const State &estado)
  * @brief Sobrecarga del operador <<
  * @param os, estado
  * @return os
  */
std::ostream &operator<<(std::ostream &os, const State &estado) {
  switch(estado.estado_) {
    case vivo:
      os << 'x';
      break;
    case muerto:
      os << ' ';
      break;
    default:
      os << "Error";
  }
  return os;
}


