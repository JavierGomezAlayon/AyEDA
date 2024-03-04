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
Lattice::Lattice(const int tamano, frontera frontera, std::string fichero = "") { 
  frontera_ = frontera;
  generacion_ = 0;
  if (frontera == fria || frontera == caliente) { // si tiene una frontera fria o caliente se le añade 2 celulas constantes
    tamano_ = tamano + 2;
    vector_.resize(tamano_);
    if (frontera == fria) {
      vector_[0] = new Cell(Position(0), estado(muerto));
      vector_[tamano_ - 1] = new Cell(Position(tamano_ - 1), estado(muerto));
    } else if (frontera == caliente) {
      vector_[0] = new Cell(Position(0), estado(vivo));
      vector_[tamano_ - 1] = new Cell(Position(tamano_ - 1), estado(vivo));
    }
    if (fichero != "") {
      std::ifstream input(fichero);
      estado estado;
      for (int i = 1; i < tamano + 1; i++) {
        int estado_input = -1;
        input >> estado_input;
        if (estado_input == 0) {
          estado = muerto;
        } else if (estado_input == 1) {
          estado = vivo;
        } else { // error
          std::cerr << "Error (2): En el fichero " << fichero << " se ha introducido un valor no computable o no se ha introducido los suficientes valores." << std::endl;
          exit(EXIT_FAILURE);
        }
        vector_[i] = new Cell(Position(i), estado);
      }
    }
  } else if (frontera == periodica || frontera == reflectora) { // si tiene una frontera periodica o reflectora
    tamano_ = tamano;
    vector_.resize(tamano);
    if (fichero != "") { // si hay un fichero se lee el fichero
      std::ifstream input(fichero);
      estado estado;
      for (int i = 0; i < tamano; i++) {
        int estado_input = -1;
        input >> estado_input;
        if (estado_input == 0) {
          estado = muerto;
        } else if (estado_input == 1) {
          estado = vivo;
        } else { // error
          std::cerr << "Error (2): En el fichero " << fichero << " se ha introducido un valor no computable o no se ha introducido los suficientes valores." << std::endl;
          exit(EXIT_FAILURE);
        }
        vector_[i] = new Cell(Position(i), estado);
      }
    }
  } 
  return;
}

/** ~Lattice()
  * @brief el destructor de la clase Lattice
  */
Lattice::~Lattice() {
  if (this->frontera_ == fria || this->frontera_ == caliente) {
    for (int i = 0; i < this->tamano_; i++) {
      delete vector_[i];
    }
  } else {
    for (int i = 0; i < this->tamano_; i++) {
      delete vector_[i];
    }
  }
}

/** void inicializar();
  * @brief inicializa la tabla con todas las celulas a estado 0 menos el del medio
  */
void Lattice::inicializar() {
  if (this->frontera_ == fria || this->frontera_ == caliente) {
    for (int i = 1; i < tamano_ - 1 ; i++) {
      if (i == tamano_ / 2) {
        vector_[i] = new Cell(Position(i),State(vivo));
      } else {
        vector_[i] = new Cell(Position(i),State(muerto));
      }
    }
  } else {
    for (int i = 0; i < tamano_ ; i++) {
      if (i == tamano_ / 2) {
        vector_[i] = new Cell(Position(i),State(vivo)); 
      } else {
        vector_[i] = new Cell(Position(i),State(muerto));
      }
    }
  }
}

/** const Cell& Lattice::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante
  */
Cell& Lattice::getCell(const Position& posicion) const {
  return *vector_[posicion.getPosition()];
}

/** const int Lattice::getTamano() const
  * @brief devuelve el tamaño del lattice
  * @return el tamaño del vector de celulas
  */
const int Lattice::getTamano() const {
  return this->tamano_;
}

/** const frontera Lattice::getFrontera() const
  * @brief devuelve el tipo de frontera del lattice
  * @return el tipo de frontera del lattice
  */
const frontera Lattice::getFrontera() const{
  return frontera_;
}
/** void Lattice::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void Lattice::nextGeneration() {
  if (this->frontera_ == fria || this->frontera_ == caliente) {
    for(int i = 1; i < this->tamano_ - 1; i++) { // cada celula obtiene el nextState
      Position posicion(i);
      this->getCell(posicion).nextState(*this);
    }
    for(int i = 1; i < this->tamano_ - 1; i++) { // cada celula se actualiza el estado
      Position posicion(i);
      this->getCell(posicion).updateState();
    }
  } else {
    for(int i = 0; i < this->tamano_; i++) { // cada celula obtiene el nextState
      Position posicion(i);
      this->getCell(posicion).nextState(*this);
    }
    for(int i = 0; i < this->tamano_; i++) { // cada celula se actualiza el estado
      Position posicion(i);
      this->getCell(posicion).updateState();
    }
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
  os << " G(" << tabla.generacion_ << ")";
  return os;
}

#endif


