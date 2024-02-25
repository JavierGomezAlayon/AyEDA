// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/22/24
// Archivo VectorVariable.h: Declaración de la clase VectorVariable
//        En este fichero se declara la clase VectorVariable
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/22/24 - Creación (primera versión) del código
#pragma once

#include<iostream>
#include<vector>
#include"Cell.h"
class Cell;
class MatrizVariable;

class VectorVariable {
 public:
  VectorVariable(const int = 1);
  ~VectorVariable();
  Cell& getCell(const int);
  int getTamano() const;
  int begin() const;
  int end() const;
  void setCell(const int, const Cell&);
  void AumentarTamano(const bool);
  friend std::ostream& operator<<(std::ostream& os, const VectorVariable vector);
 private:
  std::vector<Cell*> vector_;
  int referencia0_; // Referencia donde está la posición 0.
 
};
