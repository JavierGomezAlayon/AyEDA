// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Lattice.h: Declaración de la clase Lattice
//        En este fichero se declara la clase Lattice
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#pragma once

#include<vector>
#include<fstream>
#include"../Position/Position.h"
#include"../Cell/Cell.h"
#include"../MatrizVariable/MatrizVariable.h"
#include<sstream>

class VectorVariable;
class Cell;

enum frontera {
  fria,
  caliente,
  periodica,
  reflectora,
  sin_frontera
};

class Lattice {
 public:
  Lattice(const std::pair<int,int>&, const frontera);
  Lattice(const std::string, const frontera);
  Cell& getCell(Position);
  const frontera getFrontera() const;
  const std::pair<int,int> getTamano() const;
  void inicializar();
  void nextGeneration();
  int Population();
  friend std::ostream &operator<<(std::ostream &os, const Lattice &tabla);
  void save(const std::string);
private:
  void corregirTamano();
  MatrizVariable matriz_;
  frontera frontera_;
  std::pair<int, int> tamano_;
  int generacion_;
};
