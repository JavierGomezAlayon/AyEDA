// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 06 : Árbol (TAD)
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/18/24
// Archivo Nodo.h: Declaración de la clase Nodo
//        En este fichero se declara la clase Nodo
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/18/24 - Creación (primera versión) del código
#ifndef C_Nodo_H
#define C_Nodo_H

//clase con template
template <class Key>
class NodoB {
 public:
  NodoB();
  NodoB(const Key &dato, NodoB<Key> *izq = nullptr, NodoB<Key> *der = nullptr);
  Key get_dato() const { return dato_; }
  NodoB<Key> *get_izq() const { return izq_; }
  NodoB<Key> *get_der() const { return der_; }
  void set_dato(const Key &dato) { dato_ = dato; }
  void set_izq(NodoB<Key> *izq) { izq_ = izq; }
  void set_der(NodoB<Key> *der) { der_ = der; }
  bool es_hoja() const { return izq_ == nullptr && der_ == nullptr; }
  void inorden() const;
 protected:
  Key dato_;
  NodoB<Key> *izq_;
  NodoB<Key> *der_;
};

// -------------------------------------------------------------------------------- //

/** NodoB<Key>::NodoB()
  * @brief Constructor por defecto de la clase NodoB
  * @return Retorna un objeto de la clase NodoB
  */
template <class Key>
NodoB<Key>::NodoB() {
  dato_ = Key();
  izq_ = nullptr;
  der_ = nullptr;
}


/** NodoB<Key>::NodoB(const Key &dato, NodoB<Key> *izq, NodoB<Key> *der)
  * @brief Constructor parametrizado de la clase NodoB
  * @param dato Dato que se va a almacenar en el nodo
  * @param izq Puntero al nodo izquierdo
  * @param der Puntero al nodo derecho
  * @return Retorna un objeto de la clase NodoB
  */
template <class Key>
NodoB<Key>::NodoB(const Key &dato, NodoB<Key> *izq, NodoB<Key> *der) {
  dato_ = dato;
  izq_ = izq;
  der_ = der;
}

/** NodoB<Key>::inorden()
  * @brief Recorre el árbol en inorden
  */
template <class Key>
void NodoB<Key>::inorden() const {
  if (izq_ != nullptr) {
    izq_->inorden();
  }
  std::cout << dato_ << " ";
  if (der_ != nullptr) {
    der_->inorden();
  }
}



#endif