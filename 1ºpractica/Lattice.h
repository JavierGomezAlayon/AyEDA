// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
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
#ifndef C_Lattice_H
#define C_Lattice_H

#include<vector>
#include<fstream>
#include"Position.h"
#include"Cell.h"

class Cell;

enum frontera {
  fria,
  caliente,
  periodica,
  reflectora
};

class Lattice {
 public:
  Lattice(const int, frontera, std::string);
  Cell& getCell(const Position&) const;
  const frontera getFrontera() const;
  void inicializar();
  void nextGeneration();
  friend std::ostream& operator<<(std::ostream& os, const Lattice& tabla);
 private:
  Cell *vector_;
  frontera frontera_;
  int tamano_;
  int generacion_;
};



#endif