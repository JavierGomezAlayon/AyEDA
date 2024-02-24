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
#ifndef C_MatrizVariable_H
#define C_MatrizVariable_H

#include<vector>
#include"VectorVariable.h"
#include"Cell.h"

class MatrizVariable {
 public:
  MatrizVariable(std::pair<int,int>);
  ~MatrizVariable();
  Cell& getCell(const std::pair<int,int>);
  void setCell(const std::pair<int,int>, const Cell&);
  std::pair<int, int> getTamano() const;
  std::pair<int, int> posBegin() const;
  std::pair<int, int> posEnd() const;
  void AumentarTamano(const int, const int);
  friend std::ostream& operator<<(std::ostream& os, const MatrizVariable matriz);
 private:
 std::vector<VectorVariable> matriz_;
 int referencia0_filas_; // Referencia donde está la posición 0 de las filas.
};

#endif