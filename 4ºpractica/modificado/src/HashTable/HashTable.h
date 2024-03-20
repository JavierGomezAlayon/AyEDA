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
#ifndef C_HashthisTable_H
#define C_HashthisTable_H

#include <map>
#include "../Nif/Nif.h"
#include "../Sequence/Sequence.h"

template<class Key>
class staticSequence;
template<class Key>
class dynamicSequence;

template<typename Key>
class closedHashTable;

template<typename Key>
class openHashTable;

//template<typename Key>
//std::ostream& operator<<(std::ostream& os, const closedHashTable<Key>& cht);
//
//template<typename Key>
//std::ostream& operator<<(std::ostream& os, const openHashTable<Key>& oht);

template<class Key>
class closedHashTable {
 public:
  closedHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe , unsigned blockSize);
  bool insertar(const Key& k) ;
  bool search(const Key& k) const ;
  int getTamano() const;
  staticSequence<Key> getTableinPos(int) const;
  ~closedHashTable() {};
  //std::ostream& operator<<(std::ostream& os, const closedHashTable<Key>& cht);
 private:
  int blockSize_;
  ExplorationFunction<Key>& fe_;
  std::vector<staticSequence<Key>> table_;
  int tableSize_;
  DispersionFunction<Key>& fd_;
};

template<class Key>
class openHashTable {
 public:
  openHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd);
  bool insertar(const Key& k) ;
  bool search(const Key& k) const ;
  int getTamano() const;
  dynamicSequence<Key> getTableinPos(int) const;
  ~openHashTable() {};
  //std::ostream& operator<<(std::ostream& os, const openHashTable<Key>& oht);
 private:
  std::vector<dynamicSequence<Key>> table_;
  int tableSize_;
  DispersionFunction<Key>& fd_;
};


// -------------------------------------------------------------------------------------------------------------------------------- //

/** closedHashTable<Key>::closedHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe , unsigned blockSize)
 * @brief Construct a new closed Hash Table< Key>::closed Hash Table object
 * @tparam Key 
 * @tparam Container 
 * @param sizeTabla 
 * @param fd 
 * @param fe 
 * @param blockSize 
 */
template<class Key>
closedHashTable<Key>::closedHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe , unsigned blockSize) : fd_(fd), tableSize_(sizeTabla), fe_(fe), blockSize_(blockSize) {
  for (int i = 0; i < sizeTabla; i++) {
    this->table_.push_back(staticSequence<Key>(blockSize));
  }
}

/** bool closedHashTable<Key>::insertar(const Key& k)
 * @brief Inserta un elemento en la tabla cerrada
 * @tparam Key 
 * @tparam Container 
 * @param k 
 */
template<class Key>
bool closedHashTable<Key>::insertar(const Key& k) {
  int indice = this->fd_(k);
  int i = 0;
  do{
    if (this->table_[indice].insert(k)) {
      return true;
    }
    indice = fe_(k, indice);
    i++;
  } while (indice != this->fd_(k) && i < 1000);
  return false;
}

/** closedHashTable<Key>::search(const Key& k)
 * @brief Busca un elemento en la tabla cerrada
 * @tparam Key 
 * @tparam Container 
 * @param k 
 * @return true si el elemento se encuentra en la tabla y false en caso contrario.
 */
template<class Key>
bool closedHashTable<Key>::search(const Key& k) const {
  int indice = this->fd_(k);
  int i = 0;
  do{
    if (this->table_[indice].search(k)) {
      return true;
    }
    indice = fe_(k, indice);
  } while (indice != this->fd_(k) && i < 1000);
  return this->table_[indice].search(k);
}

/** openHashTable<Key>::openHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd)
 * @brief Construct a new open Hash Table< Key>::open Hash Table object
 * @tparam Key 
 * @tparam Container 
 * @param sizeTabla 
 * @param fd 
 */
template<class Key>
openHashTable<Key>::openHashTable(unsigned sizeTabla, DispersionFunction<Key>& fd) : fd_(fd), tableSize_(sizeTabla) {
  for (int i = 0; i < sizeTabla; i++) {
    this->table_.push_back(dynamicSequence<Key>());
  }
}

/** openHashTable<Key>::insertar(const Key& k)
 * @brief Inserta un elemento en la tabla abierta
 * @tparam Key 
 * @tparam Container 
 * @param k 
 */
template<class Key>
bool openHashTable<Key>::insertar(const Key& k) {
  int indice = this->fd_(k);
  return (this->table_[indice].insert(k));

}

/** openHashTable<Key>::search(const Key& k)
 * @brief Busca un elemento en la tabla abierta
 * @tparam Key 
 * @tparam Container 
 * @param k 
 * @return true si el elemento se encuentra en la tabla y false en caso contrario.
 */
template<class Key>
bool openHashTable<Key>::search(const Key& k) const {
  int indice = this->fd_(k);
  return this->table_[indice].search(k);
}

template<class Key>
int openHashTable<Key>::getTamano() const {
  return this->tableSize_;
}

template<class Key>
int closedHashTable<Key>::getTamano() const {
  return this->tableSize_;
}

template<class Key>
dynamicSequence<Key> openHashTable<Key>::getTableinPos(int pos) const{
  return this->table_.at(pos);
}

template<class Key>
staticSequence<Key> closedHashTable<Key>::getTableinPos(int pos) const{
  return this->table_.at(pos);
}

/** std::ostream& operator<<(std::ostream& os, const closedHashTable<Key>& cht)
 * @brief Imprime la tabla cerrada
 * @tparam Key 
 * @tparam Container 
 * @param os 
 * @param cht 
 * @return std::ostream& 
 */
template<typename Key>
std::ostream& operator<<(std::ostream& os, const closedHashTable<Key>& cht) {
  for (int i = 0; i < cht.getTamano(); i++) {
    os << i << ": " << cht.getTableinPos(i) << std::endl;
  }
  return os;
}

/** std::ostream& operator<<(std::ostream& os, const openHashTable<Key>& oht)
 * @brief Imprime la tabla abierta
 * @tparam Key 
 * @tparam Container 
 * @param os 
 * @param oht 
 * @return std::ostream& 
 */
template<typename Key>
std::ostream& operator<<(std::ostream& os, const openHashTable<Key>& oht) {
  for (int i = 0; i < oht.getTamano(); i++) {
    os << i << ": " << oht.getTableinPos(i) << std::endl;
  }
  return os;
}










#endif