// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
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

class Position {
 public:
  Position(const int = 0);
  int getPosition() const;
  void setPosition(const int);
 private:
 int posicion_;
};



#endif