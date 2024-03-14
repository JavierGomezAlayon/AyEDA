// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo DispersionFunction.h: Declaración de la clase DispersionFunction
//        En este fichero se declara la clase DispersionFunction
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_DispersionFunction_H
#define C_DispersionFunction_H
#include "../Funciones/Funciones.h"

template <typename Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key&) const = 0;
  virtual ~DispersionFunction() {}
 protected:
  int tableSize_;
};

template <typename Key>
class Modulo : public DispersionFunction<Key> {
 public:
  Modulo(int);
  unsigned operator()(const Key&) const override;
 private:
};

template <typename Key>
class PseudoRandom : public DispersionFunction<Key> {
 public:
  PseudoRandom(int);
  unsigned operator()(const Key&) const override;
 private:
};

template <typename Key>
class Sum : public DispersionFunction<Key> {
 public:
  Sum(int);
  unsigned operator()(const Key&) const override;
 private:
};

// -------------------------------------------------------------------------------------------------------------------------------- //

/** Modulo<Key>::Modulo(int tableSize)
 * @brief Construct a new Modulo< Key>:: Modulo object
 * @tparam Key 
 * @param tableSize 
 */
template<typename Key>
Modulo<Key>::Modulo(int tableSize) {
  this->tableSize_ = tableSize;
}

/** Modulo<Key>::operator()(const Key& k)
 * @brief Devuelve el resto de la división de la clave entre el tamaño de la tabla.
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<typename Key>
unsigned Modulo<Key>::operator()(const Key& k) const {
  return k.getValue() % this->tableSize_;
}

/** PseudoRandom<Key>::PseudoRandom(int tableSize)
 * @brief Construct a new Pseudo Random< Key>:: Pseudo Random object
 * @tparam Key 
 * @param tableSize 
 */
template<typename Key>
PseudoRandom<Key>::PseudoRandom(int tableSize) {
  this->tableSize_ = tableSize;
}

/** PseudoRandom<Key>::operator()(const Key& k)
 * @brief Devuelve el resto de la división de la clave entre el tamaño de la tabla.
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<typename Key>
unsigned PseudoRandom<Key>::operator()(const Key& k) const {
  return  numero_aleatorio(0, this->tableSize_ - 1, k.getValue());
}

/** Sum<Key>::Sum(int tableSize)
 * @brief Construct a new Sum< Key>:: Sum object
 * @tparam Key 
 * @param tableSize 
 */
template<typename Key>
Sum<Key>::Sum(int tableSize) {
  this->tableSize_ = tableSize;
}

/** Sum<Key>::operator()(const Key& k)
 * @brief Devuelve la suma de los dígitos de la clave.
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<typename Key>
unsigned Sum<Key>::operator()(const Key& k) const {
  unsigned sum = 0;
  unsigned aux = k.getValue();
  while (aux > 0) {
    sum += aux % 10;
    aux /= 10;
  }
  return (sum % this->tableSize_);
}




#endif