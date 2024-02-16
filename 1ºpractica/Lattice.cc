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
  * @param tamano,frontera,fichero
  * @return objeto de la clase Lattice
  */
Lattice::Lattice(const int tamano, frontera frontera, std::string fichero) { 
  tamano_ = tamano;
  frontera_ = frontera;
  generacion_ = 0;
  vector_ = new Cell[tamano];
  return;
}

/** void inicializar();
  * @brief inicializa la tabla con todas las celulas a estado 0 menos el del medio
  */
void Lattice::inicializar() {
  for (int i = 0; i < tamano_ ; i++) {
    vector_[i] = Cell(Position(i),State(muerto));
    if (i == tamano_ / 2) {
      vector_[i] = Cell(Position(i),State(vivo));
    }
  }
}

/** const Cell& Lattice::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante
  */
const Cell& Lattice::getCell(const Position& posicion) const {
  return vector_[posicion.getPosition()];
}

/** void Lattice::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void Lattice::nextGeneration() {
  for(int i = 0; i < this->tamano_; i++) {
    Position posicion(i);
    Cell celula = this->getCell(posicion);
    celula.nextState(*this);
  }
  for(int i = 0; i < this->tamano_; i++) {
    Position posicion(i);
    Cell celula = this->getCell(posicion);
    celula.updateState();
  }
  this->generacion_ ++;
}

/** ostream& operator<<(ostream&, const Lattice&);
  * @brief sobrecarga del operador <<
  * @param os,tabla
  * @return objeto de la clase ostream
  */
std::ostream& operator<<(std::ostream& os, const Lattice& tabla) {
  for(int i = 0; i < tabla.tamano_; i++) {
    Position posicion(i);
    os << tabla.getCell(posicion);
  }
  os << " G(" << tabla.generacion_ << ")" << std::endl;
  return os;
}

const frontera Lattice::getFrontera() const{
  return frontera_;
}
#endif

