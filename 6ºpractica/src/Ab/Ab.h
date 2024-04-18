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

#include "../Nodo/Nodo.h"

template <class Key>
class AB {
 public:
  AB();
  AB(const Key &k);
  bool insertar(const Key &k) = 0;
  bool buscar(const Key &k) = 0;
  void mostrar_inorden() const;
  std::ostream operator<<(std::ostream &os, const AB<Key> &ab);
 protected:
  NodoB<Key> *raiz = nullptr;
};

template <class Key>
class ABE { // Árbol binario equilibrado
 public:
  ABE();
 private:
 
};

template <class Key>
class ABB { // Árbol binario de búsqueda
 public:
  ABB();
 private:
 
};


// ----------------------------------------------------------------------------- //

/** AB<Key>::AB()
  * @brief Constructor por defecto de la clase AB
  * @return Retorna un objeto de la clase AB
  */
template <class Key>
AB<Key>::AB() {
  raiz = nullptr;
}

/** AB<Key>::AB(const Key &k)
  * @brief Constructor de la clase AB
  * @param k Clave que se le pasa al constructor
  * @return Retorna un objeto de la clase AB
  */
template <class Key>
AB<Key>::AB(const Key &k) {
  raiz = new NodoB<Key>(k);
}



#endif