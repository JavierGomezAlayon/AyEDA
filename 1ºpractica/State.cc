// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
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
#ifndef C_State_CC
#define C_State_CC

#include"State.h"

/** State::State()
  * @brief Constructor estandar de la clase State.
  * @note se pone el valor 0 por defecto
  * @return objeto de la clase State
  */
State::State() {
  this->setState(int{0});
}

/** State::State(const int)
  * @brief Constructor de la clase State.
  * @return objeto de la clase State
  */
State::State(const int estado) {
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
void State::setState(const int estado) {
  this->estado_ = estado;
}

#endif