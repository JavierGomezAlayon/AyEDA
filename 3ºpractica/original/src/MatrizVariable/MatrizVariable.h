// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/23/24
// Archivo MatrizVariable.h: Declaración de la clase MatrizVariable
//        En este fichero se declara la clase MatrizVariable
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/23/24 - Creación (primera versión) del código
#pragma once

#include<vector>
#include"../VectorVariable/VectorVariable.h"

class VectorVariable;

class MatrizVariable {
 public:
  MatrizVariable();
  MatrizVariable(std::pair<int,int>);
  ~MatrizVariable();
  Cell& getCell(const std::pair<int,int>);
  void setCell(const std::pair<int,int>, const Cell&);
  std::pair<int, int> getTamano() const;
  std::pair<int, int> posBegin() const;
  std::pair<int, int> posEnd() const;
  void AumentarTamano(const int, const int);
  bool fueraDeRango(const std::pair<int,int>);
  friend std::ostream& operator<<(std::ostream& os, const MatrizVariable matriz);
 private:
  std::vector<std::vector<Cell*>> matriz_;
  int referencia0_filas_; // Referencia donde está la posición 0 de las filas.
  int referencia0_columnas_; // Referencia donde está la posición 0 de las columnas.
};
