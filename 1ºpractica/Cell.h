// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Cell.h: Declaración de la clase Cell
//        En este fichero se declara la clase Cell
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_Cell_H
#define C_Cell_H
#include"Position.h"
#include"State.h"
#include"Lattice.h"
#include"iostream"

class Cell {
 public:
  Cell(const Position&, const State&);
  State getState() const;
  State setState(State);
  int nextState(const Lattice&);
  void updateState();
  
 private:
 
};



#endif