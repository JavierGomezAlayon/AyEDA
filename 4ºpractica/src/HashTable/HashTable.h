// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo HashTable.h: Declaración de la clase HashTable
//        En este fichero se declara la clase HashTable
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_HashTable_H
#define C_HashTable_H

#include <map>
#include "../Sequence/Sequence.h"
// debería de ir: <class Key, class Container=staticSequence<Key> >
template<class Key, class Container>
class HashTable {
 public:
  HashTable(unsigned, DispersionFunction<Key>&, ExplorationFunction<Key>&, unsigned);
  insertar(const Key& k);
  bool search(const Key& k) const;
  friend std::ostream& operator<<(std::ostream& os, const HashTable<Key, Container>& ht);
  ~HashTable();
 private:
  int tableSize_;
  DispersionFunction<Key>& fd_;
  ExplorationFunction<Key>& fe_;
  int blockSize_;
  std::map <Key, Container> table_; // con tamaño tableSize_.
};



// -------------------------------------------------------------------------------------------------------------------------------- //

/**
 * @brief Construct a new Hash Table< Key, Container>:: Hash Table object
 * 
 * @tparam Key 
 * @tparam Container 
 * @param tableSize_ 
 * @param fd_ 
 * @param fe_ 
 * @param blockSize_ 
 */
template<typename Key, typename Container>
HashTable<Key,Container>::HashTable(unsigned sizeTabla, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe , unsigned blockSize) : tableSize_(sizeTabla), fd_(fd), fe_(fe), blockSize_(blockSize) {
  for (int i = 0; i < tableSize_; i++) {
    table_[i].second = new Container(blockSize_);
  }
  
}










#endif