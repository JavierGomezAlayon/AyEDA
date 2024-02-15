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

/** Position::Position(const int)
  * @brief Crea el objeto de la clase Position.
  * @return objeto de la clase Position
  */
Position::Position(const int posicion) {
  this->posicion_ = posicion;
}

/** int Position::getPosition() const 
  * @brief Para obtener el valor del estado
  * @return El estado
  */
int Position::getPosition() const {
  return this->posicion_;
}

/** void Position::setPosition(const int estado)
  * @brief Pone como estado el valor dado
  * @param estado
  */
void Position::setPosition(const int position) {
  this->posicion_ = position;
}


#endif