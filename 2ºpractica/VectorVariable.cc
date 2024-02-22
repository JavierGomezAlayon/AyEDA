// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/22/24
// Archivo VectorVariable.cc: Implementación de VectorVariable
//        En este fichero se implementa las funciones de la clase VectorVariable
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/22/24 - Creación (primera versión) del código
#ifndef C_VectorVariable_CC
#define C_VectorVariable_CC

#include"VectorVariable.h"

/** VectorVariable::VectorVariable()
  * @brief Crea el objeto de la clase VectorVariable.
  * @param 
  * @return objeto de la clase VectorVariable
  */
VectorVariable::VectorVariable() {

}

std::ostream &operator<<(std::ostream &os, const VectorVariable vector) {
  for (int i = 0; i < vector.vector_.size() - 1 ; i++) {
    os << vector.vector_.at(i) << " ";
  }
  os << vector.vector_.at(vector.vector_.size() - 1);
  return os;
}
#endif

