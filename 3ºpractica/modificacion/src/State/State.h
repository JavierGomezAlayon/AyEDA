// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo State.h: Declaración de la clase State
//        En este fichero se declara la clase State
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#pragma once
#include <iostream>

enum estado {
  muerto,
  vivo
};

class State {
 public:
  State(const estado = muerto);
  int getState() const;
  void setState(const estado);
  friend std::ostream& operator<<(std::ostream& os, const State& estado);
 private:
  estado estado_;
};
