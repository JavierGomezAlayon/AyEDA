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
 protected:
  Key dato_;
  NodoB<Key> *izq_;
  NodoB<Key> *der_;

 
};



#endif