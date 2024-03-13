// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo Sequence.h: Declaración de la clase Sequence
//        En este fichero se declara la clase Sequence
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_Sequence_H
#define C_Sequence_H
#include "../DispersionFunction/DispersionFunction.h"
#include "../ExplorationFunction/ExplorationFunction.h"
#include "../HashTable/HashTable.h"

template <typename Key>
class Container {
 public:
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
 private:
 
};

template<class Key> 
class dynamicSequence: public Container<Key> {
 public:
  dynamicSequence();
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
 private:
};

template<class Key> 
class staticSequence: public Container<Key> {
 public:
  staticSequence();
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  virtual bool isFull() const;
 private:
  int tableSize_;
  //Container table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  int blockSize_;
};


#endif