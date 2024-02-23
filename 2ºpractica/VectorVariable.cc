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

#include"VectorVariable.h"

/** VectorVariable::VectorVariable()
  * @brief Crea el objeto de la clase VectorVariable.
  * @param tamano
  * @return objeto de la clase VectorVariable
  */
template <class T>
VectorVariable<T>::VectorVariable(const int tamano) {
  // dimensiono el vector
  vector_.resize(tamano);
  // inicializo el vector con las celulas muertas
  return;
}

/** std::ostream &operator<<(std::ostream &os, const VectorVariable<T> vector)
  * @brief Sobrecarga del operador de salida
  * @param os
  * @param vector
  * @return os
  */
template <class T>
std::ostream &operator<<(std::ostream &os, const VectorVariable<T> vector) {
  for (int i = 0; i < vector.vector_.size() - 1 ; i++) {
    os << vector.vector_.at(i) << " ";
  }
  os << vector.vector_.at(vector.vector_.size() - 1);
  return os;
}


