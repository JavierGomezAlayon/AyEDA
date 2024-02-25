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
#include"Cell.h"

/** VectorVariable::VectorVariable()
  * @brief Crea el objeto de la clase VectorVariable.
  * @param tamano
  * @return objeto de la clase VectorVariable
  * @note Se inicializa el vector con celulas muertas
  */
VectorVariable::VectorVariable(const int tamano) {
  this->referencia0_ = 0;
  // dimensiono el vector
  this->vector_.resize(tamano);
  // inicializo el vector con las celulas muertas
  for (int i = 0; i < tamano; i++) {
    this->vector_.at(i) = new Cell(Position(i), muerto); // se pone sin referencia0 debido a que al principio no hay ningúna célula en posición negativa.
  }
  return;
}
/** VectorVariable::~VectorVariable()
  * @brief Destructor de la clase VectorVariable
  */
VectorVariable::~VectorVariable() {
  for (int i = 0; i < this->vector_.size(); i++) {
    delete this->vector_.at(i);
  }
  this->vector_.clear();
  return;
}

/** VectorVariable::getCell()
  * @brief Devuelve la celula en la posicion dada
  * @param pos
  * @return vector_.at(pos)
  */
Cell &VectorVariable::getCell(const int pos) {
  return *this->vector_.at(this->referencia0_ + pos);
}
/** VectorVariable::getTamano()
  * @brief Devuelve el tamaño del vector
  * @return vector_.size()
  */
int VectorVariable::getTamano() const {
  return this->vector_.size();
}
/** VectorVariable::begin()
  * @brief Devuelve el principio del vector
  * @return La posición de la primera célula del vector
  */
int VectorVariable::begin() const {
  return this->vector_.at(0)->getPosition().getPosition().first;
}

/** VectorVariable::end()
  * @brief Devuelve el final del vector
  * @return La posición de la última célula del vector
  */
int VectorVariable::end() const {
  return this->vector_.at(this->vector_.size() - 1)->getPosition().getPosition().first;
}

/** VectorVariable::setCell()
  * @brief Pone como celula la dada
  * @param pos, cell
  */
void VectorVariable::setCell(const int pos, const Cell& cell) {
  vector_.at(this->referencia0_ + pos) = new Cell(cell);
  return;
}

/** VectorVariable::AumentarTamano()
  * @brief Aumenta el tamaño del vector.
  * @param bool Si dicho parámetro es true, se añadirá una célula muerta al final del vector. Si es false, se añadirá una célula muerta al principio del vector.
  * @note 0 añadir pos negativa, 1 añadir pos positiva.
  */
void VectorVariable::AumentarTamano(const bool final) {
//Si dicho parámetro es true, se añadirá una célula muerta al final del vector. Si es false, se añadirá una célula muerta al principio del vector.
  if (final) {
    vector_.push_back(new Cell(Position(vector_.size() - 1 - referencia0_), muerto));
  } else {
    vector_.insert(vector_.begin(), new Cell(Position(0 - referencia0_), muerto));
    referencia0_++;
  }
  return;
}

/** std::ostream &operator<<(std::ostream &os, const VectorVariable<T> vector)
  * @brief Sobrecarga del operador de salida
  * @param os
  * @param vector
  * @return os
  */
std::ostream &operator<<(std::ostream &os, const VectorVariable vector) {
  for (int i = 0; i < vector.vector_.size() - 1 ; i++) {
    os << vector.vector_.at(i) << " ";
  }
  os << vector.vector_.at(vector.vector_.size() - 1);
  return os;
}
