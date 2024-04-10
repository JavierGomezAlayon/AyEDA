// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo SortMethod.h: Declaración de la clase SortMethod
//        En este fichero se declara la clase SortMethod
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código
#ifndef C_SortMethod_H
#define C_SortMethod_H
#include "../Sequence/Sequence.h"
#include "../Nif/Nif.h"
#include "../Metodos/Metodos.h"

template <class Key>
class SortMethod {
 public:
  SortMethod(staticSequence<Key>* sequence, bool traza = false);
  virtual std::pair<int,int> sort() = 0;
 protected:
  staticSequence<Key>* sequence_;
  bool traza_;
};

template <class Key>
class Seleccion : public SortMethod<Key> {
 public:
  Seleccion(staticSequence<Key>* sequence, bool traza = false);
  std::pair<int,int> sort() override;
};

template <class Key>
class QuickSort : public SortMethod<Key> {
 public:
  QuickSort(staticSequence<Key>* sequence, bool traza = false);
  std::pair<int,int> sort() override;
};

template <class Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(staticSequence<Key>* sequence, bool traza = false);
  std::pair<int,int> sort() override;
};

template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(staticSequence<Key>* sequence, bool traza = false);
  std::pair<int,int> sort() override;
};

template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(staticSequence<Key>* sequence, bool traza = false);
  std::pair<int,int> sort() override;
};

// -------------------------------------------------------------------------- //


/** 
  * @brief Constructor de la clase SortMethod
  * @return un objeto de la clase SortMethod
  */
template <class Key>
SortMethod<Key>::SortMethod(staticSequence<Key>* sequence, bool traza): sequence_(sequence), traza_(traza) {}

/** 
  * @brief Constructor de la clase Seleccion
  * @return un objeto de la clase Seleccion
  */
template <class Key>
Seleccion<Key>::Seleccion(staticSequence<Key>* sequence, bool traza): SortMethod<Key>(sequence, traza) {}

/** 
  * @brief Método que ordena la secuencia
  */
template <class Key>
std::pair<int,int> Seleccion<Key>::sort() {
  int size = this->sequence_->getSize();
  std::pair<int,int> pair = seleccion(*this->sequence_, size, this->traza_);
  return pair;
}

/** 
  * @brief Constructor de la clase QuickSort
  * @return un objeto de la clase QuickSort
  */
template <class Key>
QuickSort<Key>::QuickSort(staticSequence<Key>* sequence, bool traza): SortMethod<Key>(sequence, traza) {}

/** 
  * @brief Método que ordena la secuencia
  */
template <class Key>
std::pair<int,int> QuickSort<Key>::sort() {
  int size = this->sequence_->getSize();
  std::pair<int,int> pair = quickSort(*this->sequence_, 0, size - 1, this->traza_);
  return pair;
}

/** 
  * @brief Constructor de la clase HeapSort
  * @return un objeto de la clase HeapSort
  */
template <class Key>
HeapSort<Key>::HeapSort(staticSequence<Key>* sequence, bool traza): SortMethod<Key>(sequence, traza) {}

/** 
  * @brief Método que ordena la secuencia
  */
template <class Key>
std::pair<int,int> HeapSort<Key>::sort() {
  int size = this->sequence_->getSize();
  std::pair<int,int> pair = heapSort(*this->sequence_, size, this->traza_);
  return pair;
}

/** 
  * @brief Constructor de la clase ShellSort
  * @return un objeto de la clase ShellSort
  */
template <class Key>
ShellSort<Key>::ShellSort(staticSequence<Key>* sequence, bool traza): SortMethod<Key>(sequence, traza) {}

/** 
  * @brief Método que ordena la secuencia
  */
template <class Key>
std::pair<int,int> ShellSort<Key>::sort() {
  int size = this->sequence_->getSize();
  std::pair<int,int> pair = shellSort(*this->sequence_, size, this->traza_);
  return pair;
}

/** 
  * @brief Constructor de la clase RadixSort
  * @return un objeto de la clase RadixSort
  */
template <class Key>
RadixSort<Key>::RadixSort(staticSequence<Key>* sequence, bool traza): SortMethod<Key>(sequence, traza) {}

/** 
  * @brief Método que ordena la secuencia
  */
template <class Key>
std::pair<int,int> RadixSort<Key>::sort() {
  int size = this->sequence_->getSize();
  std::pair<int,int> pair = radixSort(*this->sequence_, size, this->traza_);
  return pair;
}

#endif