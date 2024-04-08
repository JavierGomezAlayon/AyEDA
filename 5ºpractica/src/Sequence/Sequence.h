// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo Sequence.h: Declaración de la clase Sequence
//        En este fichero se declara la clase Sequence
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código
#ifndef C_Sequence_H
#define C_Sequence_H

#include <vector>
#include <iostream>

template <class Key>
class Sequence {
 public:
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  friend std::ostream& operator<<(std::ostream& os, const Sequence<Key>& s) {
    for (const auto& k : s.sequence_) {
      if (k != nullptr) {
        os << *k << " ";
      }
    }
    return os;
  }
 protected:
  std::vector<Key*> sequence_;
};

template<class Key> 
class dynamicSequence: public Sequence<Key> {
 public:
  dynamicSequence();
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
};

template<class Key> 
class staticSequence: public Sequence<Key> {
 public:
  staticSequence(int blockSize);
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  bool isFull() const;
 private:
  int blockSize_; // el vector tiene un tamaño fijo: blockSize_.
  int indice_ = 0;
};

// -------------------------------------------------------------------------------------------------------------------------------- //

/** dynamicSequence<Key>::dynamicSequence();
  * @brief Construct a new dynamic Sequence< Key>:: Sequence object
  * @tparam Key 
  */
template<typename Key>
dynamicSequence<Key>::dynamicSequence() { }

/** dynamicSequence<Key>::insert(const Key& k);
  * @brief Inserta un elemento en la secuencia
  * @tparam Key 
  * @param k 
  * @return true si se ha podido completar la operación con éxito y false en caso contrario.
  */
template<typename Key>
bool dynamicSequence<Key>::insert(const Key& k) {
  this->sequence_.push_back(new Key(k));
  return true;
}

/** dynamicSequence<Key>::search(const Key& k);
  * @brief Busca un elemento en la secuencia
  * @tparam Key 
  * @param k 
  * @return true si se ha encontrado el elemento y false en caso contrario.
  */
template<typename Key>
bool dynamicSequence<Key>::search(const Key& k) const {
  for (long unsigned int i = 0; i < this->sequence_.size(); i++) {
    if (*(this->sequence_[i]) == k) {
      return true;
    }
  }
  return false;
}

/** staticSequence<Key>::staticSequence();
  * @brief Construct a new static Sequence< Key>:: Sequence object
  * @param blockSize
  * @tparam Key 
  */
template<typename Key>
staticSequence<Key>::staticSequence(int blockSize) {
  this->blockSize_ = blockSize;
  this->sequence_.resize(blockSize_);
}

/** staticSequence<Key>::insert(const Key& k);
  * @brief Inserta un elemento en la secuencia
  * @tparam Key 
  * @param k 
  * @return true si se ha podido completar la operación con éxito y false en caso contrario.
  */
template<typename Key>
bool staticSequence<Key>::insert(const Key& k) {
  if (isFull()) {
    return false;
  }
  this->sequence_[indice_] = new Key(k);
  this->indice_++;
  return true;
}

/** staticSequence<Key>::search(const Key& k);
  * @brief Busca un elemento en la secuencia
  * @tparam Key 
  * @param k 
  * @return true si se ha encontrado el elemento y false en caso contrario.
  */
template<typename Key>
bool staticSequence<Key>::search(const Key& k) const {
  for (int i = 0; i < this->indice_; i++) {
    if (*(this->sequence_[i]) == k) {
      return true;
    }
  }
  return false;
}

/** staticSequence<Key>::isFull();
  * @brief Comprueba si la secuencia está llena
  * @return true si la secuencia está llena y false en caso contrario.
  */
template<typename Key>
bool staticSequence<Key>::isFull() const {
  return this->indice_ == this->blockSize_;
}


#endif