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
#ifndef C_VectorVariable_H
#define C_VectorVariable_H

#include<iostream>
#include<vector>
#include"Cell.h"

class VectorVariable {
 public:
  VectorVariable();
  friend std::ostream& operator<<(std::ostream& os, const VectorVariable vector);
 private:
  std::vector<Cell*> vector_;
 
};



#endif