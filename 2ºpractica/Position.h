// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Position.h: Declaración de la clase Position
//        En este fichero se declara la clase Position
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_Position_H
#define C_Position_H

#include <iostream>

class Position {
 public:
  Position(const int = 0, const int = 0);
  std::pair<int, int> getPosition() const;
  void setPosition(const int, const int);
 private:
 std::pair<int, int> position_;
};



#endif