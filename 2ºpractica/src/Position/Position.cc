// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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

#include"Position.h"

/** Position::Position(const int, const int)
  * @brief Crea el objeto de la clase Position.
  * @param posicionX, posicionY
  * @return objeto de la clase Position
  */
Position::Position(const int posicionX, const int posicionY) {
  this->position_ = std::pair<int, int>(posicionX, posicionY);
}

/** Position::Position(const std::pair<int, int>)
  * @brief Crea el objeto de la clase Position.
  * @param posicion
  * @return objeto de la clase Position
  */
Position::Position(const std::pair<int, int> pair) {
  this->position_ = pair;
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

/** void Position::fix()
  * @brief Arregla la posición si es negativa
  * @param maximoX, maximoY Son los valores que se cuentan como fuera del tablero.
  */
void Position::fix(const int maximoX, const int maximoY) {
  if (this->position_.first < 0) {
    this->position_.first = 0;
  }
  if (this->position_.second < 0) {
    this->position_.second = 0;
  }
  if (this->position_.first > maximoX) {
    this->position_.first = maximoX;
  }
  if (this->position_.second > maximoY) {
    this->position_.second = maximoY;
  }
}

