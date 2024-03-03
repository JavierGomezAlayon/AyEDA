// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/23/24
// Archivo MatrizVariable.cc: Implementación de MatrizVariable
//        En este fichero se implementa las funciones de la clase MatrizVariable
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/23/24 - Creación (primera versión) del código

#include "MatrizVariable.h"
#include "VectorVariable.h"
#include "Cell.h"
#include "Lattice.h"

/** MatrizVariable::MatrizVariable()
  * @brief Crea el objeto de la clase MatrizVariable.
  * @param tamano: tamaño de la matriz.
  * @return objeto de la clase MatrizVariable
  */
MatrizVariable::MatrizVariable(std::pair<int,int> tamano) {
  matriz_.resize(tamano.first);
  for (int i = 0; i < tamano.first; i++) {
    matriz_.at(i).resize(tamano.second);
    for(int j = 0; j < tamano.second; j++) {
      matriz_.at(i).at(j) = new Cell(Position(i,j), muerto);
    }
  }
  referencia0_filas_ = 0;
  referencia0_columnas_ = 0;
}

/** MatrizVariable::MatrizVariable()
  * @brief Crea el objeto de la clase MatrizVariable.
  * @return objeto de la clase MatrizVariable
  */
MatrizVariable::MatrizVariable() {
  matriz_.resize(0);
  referencia0_filas_ = 0;
}

/** MatrizVariable::~MatrizVariable()
  * @brief Destructor de la clase MatrizVariable
  */
MatrizVariable::~MatrizVariable() {
  for (int i = 0; i < this->matriz_.size(); i++) {
    for (int j = 0; j < this->matriz_.at(i).size(); j++) {
      //delete this->matriz_.at(i).at(j);
    }
  }
}

/** std::pair<int, int> MatrizVariable::getTamano()
  * @brief Devuelve el tamaño de la matriz.
  * @return tamaño de la matriz.
  */
std::pair<int, int> MatrizVariable::getTamano() const {
  int tamanoX = this->matriz_.size();
  int tamanoY = this->matriz_.at(0).size();
  return std::pair<int, int>(tamanoX, tamanoY);
}

/** std::pair<int, int> MatrizVariable::PosBegin()
  * @brief Devuelve la posición de inicio de la matriz.
  * @return posición de inicio de la matriz.
  */
std::pair<int, int> MatrizVariable::posBegin() const {
  return std::pair<int, int>(-(this->referencia0_filas_), -(this->referencia0_columnas_));
}

/** std::pair<int, int> MatrizVariable::posEnd()
  * @brief Devuelve la posición de fin de la matriz.
  * @return posición de fin de la matriz.
  */
std::pair<int, int> MatrizVariable::posEnd() const {
  return std::pair<int, int>(this->matriz_.size() - this->referencia0_filas_ - 1, this->matriz_.at(0).size() - this->referencia0_columnas_ - 1);
}

/** void MatrizVariable::setCell(const std::pair<int,int> posicion, const Cell& cell)
  * @brief Establece la celda en la posición indicada.
  * @param posicion: posición de la celda.
  * @param celda: celda a establecer.
  */
void MatrizVariable::setCell(const std::pair<int,int> posicion, const Cell& cell) {
  this->matriz_.at(posicion.first + this->referencia0_filas_).at(posicion.second + this->referencia0_columnas_) = new Cell(cell);
}

/** Cell& MatrizVariable::getCell(std::pair<int,int> posicion)
  * @brief Devuelve el objeto cell de la posición indicada.
  * @param posicion: posición de la cell en la matriz.
  * @return Una referencia del objeto Cell de dicha posición.
  */
Cell& MatrizVariable::getCell(std::pair<int,int> posicion) {
  return *matriz_.at(posicion.first + referencia0_filas_).at(posicion.second + referencia0_columnas_);
}

/** void MatrizVariable::AumentarTamano(const bool filas, const bool columnas)
  * @brief Aumenta el tamaño de la matriz.
  * @param filas: si se aumentan o no las filas.
  * @param columnas: si se aumentan o no las columnas.
  * @note Si los int son 1 se aumenta positivamente, si son -1 aumenta negativamente y si son 0 no se aumenta.
  */
void MatrizVariable::AumentarTamano(const int filas, const int columnas) { // (y, x)
  if (filas == 1) {
    this->matriz_.push_back(std::vector<Cell*>(matriz_.at(0).size(), new Cell(Position(0,0), muerto))); // creo las células
    for (int i = 0; i < this->matriz_.at(0).size(); i++) { // les pongo la posición
      this->matriz_.at(this->matriz_.size() - 1).at(i)->setPosition(Position(this->posEnd().first, i));
    }
  } else if (filas == -1) {
    this->matriz_.insert(this->matriz_.begin(), std::vector<Cell*>(matriz_.at(1).size(), new Cell(Position(0,0), muerto))); // creo las células
    for (int i = 0; i < this->matriz_.at(0).size(); i++) { // les pongo la posición
      this->matriz_.at(0).at(i)->setPosition(Position(this->posBegin().first, i));
    }
    referencia0_filas_++;
  }
  if (columnas == 1) {
    for (int i = 0; i < this->matriz_.size(); i++) {
      this->matriz_.at(i).push_back(new Cell(Position( i, this->matriz_.at(i).size()), muerto));
    }
  } else if (columnas == -1) {
    for (int i = 0; i < this->matriz_.size(); i++) {
      this->matriz_.at(i).insert(this->matriz_.at(i).begin(), new Cell(Position(i, this->posBegin().first), muerto));
    }
    referencia0_columnas_++;
  }
  return;
}

bool MatrizVariable::fueraDeRango(const std::pair<int,int> posicion) {
  if (posicion.first < this->posBegin().first || posicion.first > this->posEnd().first || posicion.second < this->posBegin().second || posicion.second > this->posEnd().second) {
    return true;
  }
  return false;
}

/** std::ostream &operator<<(std::ostream &os, const MatrizVariable matriz)
  * @brief Sobrecarga del operador de salida.
  * @param os: flujo de salida.
  * @param matriz: matriz a mostrar.
  * @return os.
  */
std::ostream &operator<<(std::ostream &os, const MatrizVariable matriz) {
  // techo
  os << " ";
  for(int i = 0; i < matriz.matriz_.at(0).size(); i++) {
    os << "- ";
  }
  std::endl(os);
  //Matriz con `|` en los lados.
  for (int i = 0; i < matriz.matriz_.size(); i++) {
    for (int j = 0; j < matriz.matriz_.at(i).size(); j++) {
      if (j == 0) {
        os << "|";
      }
      os << matriz.matriz_.at(i).at(j)->getState() << " ";
      if (j == matriz.matriz_.at(i).size() - 1) {
        os << "|";
      }
    }
    os << std::endl;
  }
  // suelo
  os << " ";
  for(int i = 0; i < matriz.matriz_.at(0).size(); i++) {
    os << "- ";
  }
  return os;
}

