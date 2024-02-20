// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Position.cc: Implementación de Position
//        En este fichero se implementa las funciones de la clase Position
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_Position_CC
#define C_Position_CC

#include"Position.h"

/** Position::Position(const int, const int)
  * @brief Crea el objeto de la clase Position.
  * @param posicionX, posicionY
  * @return objeto de la clase Position
  */
Position::Position(const int posicionX, const int posicionY) {
  this->position_ = std::pair<int, int>(posicionX, posicionY);
}

/** int Position::getPosition() const 
  * @brief Para obtener el valor del estado
  * @return La posición mediante un objeto pair
  */
std::pair<int, int> Position::getPosition() const {
  return this->position_;
}

/** void Position::setPosition(const int estado)
  * @brief Pone como estado el valor dado
  * @param PosicionX, PosicionY
  */
void Position::setPosition(const int posicionX,  const int posicionY) {
  this->position_ = std::pair<int, int>(posicionX, posicionY);
}


#endif