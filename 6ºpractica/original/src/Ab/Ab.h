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
#include <queue>
#include <iostream>


template <class Key>
class AB {
 public:
  AB();
  AB(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
  void inorden() const;
  friend std::ostream& operator<<(std::ostream &os, const AB<Key> &ab);
  void recorridoPorNiveles() const;
 protected:
  NodoB<Key> *raiz_ = nullptr;
};
 // no se admite inserción de claves repetidas
template <class Key>
class ABE : public AB<Key> { // Árbol binario equilibrado
 public:
  ABE();
  ABE(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
  void recorridoPorNiveles() const;
 private:
 
};

template <class Key>
class ABB : public AB<Key> { // Árbol binario de búsqueda
 public:
  ABB();
  ABB(const Key &k);
  bool insertar(const Key &k);
  bool buscar(const Key &k);
  void recorridoPorNiveles() const;
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

/** std::ostream operator<<(std::ostream &os, const AB<Key> &ab)
  * @brief Sobrecarga del operador <<
  * @param os Flujo de salida
  * @param ab Árbol que se va a mostrar
  * @return Retorna el flujo de salida
  */
template <typename Key>
std::ostream& operator<<(std::ostream &os, const AB<Key> &ab) {
  ab.recorridoPorNiveles();
  return os;
}

/** AB<Key>::recorridoPorNiveles()
  * @brief Muestra el árbol por niveles
  */
template <class Key>
void AB<Key>::recorridoPorNiveles() const {
  std::queue<NodoB<Key>*> cola;
  NodoB<Key> *actual = this->raiz_;
  cola.push(actual);
  int nivel = 0; // Variable para almacenar el nivel actual del árbol
  while (!cola.empty()) {
    int nivel_actual = cola.size(); // Obtener el número de nodos en el nivel actual
    std::cout << "Nivel " << nivel << ": ";
    for (int i = 0; i < nivel_actual; i++) {
      actual = cola.front();
      cola.pop();
      if (actual != nullptr) {
        std::cout << " [" << actual->get_dato() << "]"; // Mostrar el nivel actual junto con el dato
        cola.push(actual->get_izq());
        cola.push(actual->get_der());
      } else {
        std::cout << " [.]" ; // Mostrar un nodo vacío
      }
    }
    std::cout << std::endl;
    nivel++; // Incrementar el nivel después de procesar todos los nodos en el nivel actual
  }
}

/** ABE<Key>::ABE()
  * @brief Constructor por defecto de la clase ABE
  * @return Retorna un objeto de la clase ABE
  */
template <class Key>
ABE<Key>::ABE() {
  this->raiz_ = nullptr;
}

/** ABE<Key>::ABE(const Key &k)
  * @brief Constructor de la clase ABE
  * @param k Clave que se le pasa al constructor
  * @return Retorna un objeto de la clase ABE
  */
template <class Key>
ABE<Key>::ABE(const Key &k) {
  this->raiz_ = new NodoB<Key>(k);
}

/** ABE<Key>::insertar(const Key &k)
  * @brief Inserta una clave en el árbol
  * @param k Clave que se va a insertar
  * @return Retorna true si se ha insertado correctamente
  */
template <class Key>
bool ABE<Key>::insertar(const Key &k) {
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

/** ABE<Key>::buscar(const Key &k)
  * @brief Busca una clave en el árbol
  * @param k Clave que se va a buscar
  * @return Retorna true si la clave se encuentra en el árbol
  */
template <class Key>
bool ABE<Key>::buscar(const Key &k) {
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

/** ABB<Key>::ABB()
  * @brief Constructor por defecto de la clase ABB
  * @return Retorna un objeto de la clase ABB
  */
template <class Key>
ABB<Key>::ABB() {
  this->raiz_ = nullptr;
}

/** ABB<Key>::ABB(const Key &k)
  * @brief Constructor de la clase ABB
  * @param k Clave que se le pasa al constructor
  * @return Retorna un objeto de la clase ABB
  */
template <class Key>
ABB<Key>::ABB(const Key &k) {
  this->raiz_ = new NodoB<Key>(k);
}

/** ABB<Key>::insertar(const Key &k)
  * @brief Inserta una clave en el árbol
  * @param k Clave que se va a insertar
  * @return Retorna true si se ha insertado correctamente
  */
template <class Key>
bool ABB<Key>::insertar(const Key &k) {
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

/** ABB<Key>::buscar(const Key &k)
  * @brief Busca una clave en el árbol
  * @param k Clave que se va a buscar
  * @return Retorna true si la clave se encuentra en el árbol
  */
template <class Key>
bool ABB<Key>::buscar(const Key &k) {
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



#endif