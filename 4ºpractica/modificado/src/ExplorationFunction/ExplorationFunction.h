// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo ExplorationFunction.h: Declaración de la clase ExplorationFunction
//        En este fichero se declara la clase ExplorationFunction
// Referencias:
//        Enlaces de Keyerés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_ExplorationFunction_H
#define C_ExplorationFunction_H
#include "../DispersionFunction/DispersionFunction.h"
// el punto 2 de la practica.

// hay que implementar 4 funciones de exploración distKeyas: 
//■ Exploración lineal, g(k,i) = i
//■ Exploración cuadrática, g(k,i) = i^2
//■ Doble dispersión, g(k,i) = f(k) * i // (f(k) es una función de dispersión.)
//■ Redispersión, g(k,i) = f(i)(k). // f(i)(k) es una función de dispersión que depende de i.)

template <class Key>
class ExplorationFunction {
 public:
  ExplorationFunction(const DispersionFunction<Key>& dispersionFunction) : dispersionFunction_(dispersionFunction) {}
  virtual unsigned operator()(const Key&, unsigned) const = 0;
  virtual ~ExplorationFunction() {};
 protected:
  const DispersionFunction<Key>& dispersionFunction_;
};

template <class Key>
class LinearExploration : public ExplorationFunction<Key> {
 public:
  LinearExploration(const DispersionFunction<Key>& dispersionFunction) : ExplorationFunction<Key>(dispersionFunction) {};
  unsigned operator()(const Key&, unsigned) const override;
 private:
};

template <class Key>
class QuadraticExploration : public ExplorationFunction<Key> {
 public:
  QuadraticExploration(const DispersionFunction<Key>& dispersionFunction) : ExplorationFunction<Key>(dispersionFunction) {};
  unsigned operator()(const Key&, unsigned) const override;
 private:
};

template <class Key>
class DoubleDispersion : public ExplorationFunction<Key> {
 public:
  DoubleDispersion(const DispersionFunction<Key>& dispersionFunction) : ExplorationFunction<Key>(dispersionFunction) {};
  unsigned operator()(const Key&, unsigned) const override;
 private:
};

template <class Key>
class Redispersion : public ExplorationFunction<Key> {
 public:
  Redispersion(const DispersionFunction<Key>& dispersionFunction) : ExplorationFunction<Key>(dispersionFunction) {};
  unsigned operator()(const Key&, unsigned) const override;
 private:
};

// ---------------------------------------------------------------------------------------------------------------------- //

template <class Key>
unsigned LinearExploration<Key>::operator()(const Key&, unsigned i) const {
  return (i + 1) % this->dispersionFunction_.getTableSize();
}

template <class Key>
unsigned QuadraticExploration<Key>::operator()(const Key&, unsigned i) const {
  return (i * i) % this->dispersionFunction_.getTableSize();
}

template <class Key>
unsigned DoubleDispersion<Key>::operator()(const Key& key, unsigned i) const {
  return (i * this->dispersionFunction_(key) % this->dispersionFunction_.getTableSize());
}

template <class Key>
unsigned Redispersion<Key>::operator()(const Key& key, unsigned i) const {
  srand(key.getValue());
  for (int j = 0; j < i; j++) {
    rand();
  }
  return rand() % this->dispersionFunction_.getTableSize();
}


#endif