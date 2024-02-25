// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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
#pragma once

#include"Position.h"
#include<iostream>
#include"State.h"

class Lattice;

class Cell {
 public:
  Cell(const Position&, const State&);
  State getState() const;
  Position getPosition() const;
  void setState(State);
  void nextState(const Lattice&);
  void updateState();
  friend std::ostream& operator<<(std::ostream& os, const Cell& celula);
 private:
  Position posicion_;
  State estado_;
  State siguiente_estado_;
};

