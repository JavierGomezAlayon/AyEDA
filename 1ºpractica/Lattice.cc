// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo Lattice.cc: Implementación de Lattice
//        En este fichero se implementa las funciones de la clase Lattice
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
#ifndef C_Lattice_CC
#define C_Lattice_CC

#include"Lattice.h"

/** Lattice::Lattice()
  * @brief Crea el objeto de la clase Lattice.
  * @param 
  * @return objeto de la clase Lattice
  */
Lattice::Lattice(const int tamano) {
  vector_.resize(tamano);
  return;
}

/** void inicializar();
  * @brief inicializa la tabla con todas las celulas a estado 0 menos el del medio
  */
void Lattice::inicializar() {
  State estado_cero(0);
  State estado_uno(1);
  for(int pos = 0; pos < this->vector_.size(); pos++) {
    Position posicion(pos);
    Cell celula = this->getCell(posicion);
    if (pos == this->vector_.size() / 2) {
      celula.setState(estado_uno);
    } else {
      celula.setState(estado_cero);
    }
  }
}

/** const Cell& Lattice::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante
  */
const Cell& Lattice::getCell(const Position& posicion) const {
  return vector_.at(posicion.getPosition());
}

/** void Lattice::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void Lattice::nextGeneration() {
  for(int pos = 0; pos < this->vector_.size(); pos++) {
    Position posicion(pos);
    Cell celula = this->getCell(posicion);
    celula.updateState();
  }
}

/** ostream& operator<<(ostream&, const Lattice&);
  * @brief sobrecarga del operador <<
  * @param os,tabla
  * @return objeto de la clase ostream
  */
std::ostream& operator<<(std::ostream& os, const Lattice& tabla) {
  for(int pos = 0; pos < tabla.vector_.size(); pos++) {
    Position posicion(pos);
    os << tabla.getCell(posicion);
  }
}
#endif