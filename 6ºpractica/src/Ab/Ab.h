// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 06 : Árbol (TAD)
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/18/24
// Archivo Ab.h: Declaración de la clase Ab
//        En este fichero se declara la clase Ab
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/18/24 - Creación (primera versión) del código
#ifndef C_Ab_H
#define C_Ab_H

#include "../NodoB/NodoB.h"

template <class Key>
class AB {
 public:
  AB();
  AB(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
  void inorden() const;
  friend std::ostream operator<<(std::ostream &os, const AB<Key> &ab);
 protected:
  NodoB<Key> *raiz_ = nullptr;
};
 // no se admite inserción de claves repetidas
template <class Key>
class ABE { // Árbol binario equilibrado
 public:
  ABE();
  ABE(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
 private:
 
};

template <class Key>
class ABB { // Árbol binario de búsqueda
 public:
  ABB();
  ABB(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
 private:
 
};


// ----------------------------------------------------------------------------- //

/** AB<Key>::AB()
  * @brief Constructor por defecto de la clase AB
  * @return Retorna un objeto de la clase AB
  */
template <class Key>
AB<Key>::AB() {
  this->raiz_ = nullptr;
}

/** AB<Key>::AB(const Key &k)
  * @brief Constructor de la clase AB
  * @param k Clave que se le pasa al constructor
  * @return Retorna un objeto de la clase AB
  */
template <class Key>
AB<Key>::AB(const Key &k) {
  this->raiz_ = new NodoB<Key>(k);
}

/** AB<Key>::insertar(const Key &k)
  * @brief Inserta una clave en el árbol
  * @param k Clave que se va a insertar
  * @return Retorna true si se ha insertado correctamente
  */
template <class Key>
bool AB<Key>::insertar(const Key &k) {
  if (this->raiz_ == nullptr) {
    this->raiz_ = new NodoB<Key>(k);
    return true;
  }
  NodoB<Key> *actual = this->raiz_;
  while (true) {
    if (k < actual->get_dato()) {
      if (actual->get_izq() == nullptr) {
        actual->set_izq(new NodoB<Key>(k));
        return true;
      } else {
        actual = actual->get_izq();
      }
    } else if (k > actual->get_dato()) {
      if (actual->get_der() == nullptr) {
        actual->set_der(new NodoB<Key>(k));
        return true;
      } else {
        actual = actual->get_der();
      }
    } else {
      return false;
    }
  }
}

/** AB<Key>::buscar(const Key &k)
  * @brief Busca una clave en el árbol
  * @param k Clave que se va a buscar
  * @return Retorna true si la clave se encuentra en el árbol
  */
template <class Key>
bool AB<Key>::buscar(const Key &k) {
  NodoB<Key> *actual = this->raiz_;
  while (actual != nullptr) {
    if (k < actual->get_dato()) {
      actual = actual->get_izq();
    } else if (k > actual->get_dato()) {
      actual = actual->get_der();
    } else {
      return true;
    }
  }
  return false;
}

/** AB<Key>::mostrar_inorden()
  * @brief Muestra el árbol en inorden
  */
template <class Key>
void AB<Key>::inorden() const {
  if (this->raiz_->get_izq() != nullptr) {
    this->raiz_->get_izq()->inorden();
  }
  std::cout << this->raiz_->get_dato() << " ";
  if (this->raiz_->get_der() != nullptr) {
    this->raiz_->get_der()->inorden();
  }
}


#endif