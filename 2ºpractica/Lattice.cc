// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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

#include"Lattice.h"

Lattice::Lattice(const std::string fichero, const frontera frontera) {
  this->generacion_ = 0;
  this->frontera_ = frontera;
  std::ifstream input(fichero);
  input >> this->tamano_.first;
  input >> this->tamano_.second;
  matriz_= MatrizVariable(this->tamano_);
  estado estado;
  std::string linea;
  std::getline(input, linea); // para quitar un bug de que coge solo un retorno de carro
  for (int i = 0; i < this->matriz_.getTamano().first ; i++) {
    std::getline(input, linea);
    for (int j = 0; j < this->matriz_.getTamano().second ; j++) {
      int estado_input = linea.at(j);
      // Según el estado qu haya como input lo ponemos.
      if (estado_input == ' ') {
        estado = muerto;
      } else if (estado_input == 'x') {
        estado = vivo;
      } else { // error
        std::cerr << "Error (2): En el fichero " << fichero << " se ha introducido un valor no computable o no se ha introducido los suficientes valores." << std::endl;
        exit(EXIT_FAILURE);
      }
      this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), estado));
    }
  }
}

/** Lattice::Lattice()
  * @brief Crea el objeto de la clase Lattice.
  * @param tamano,frontera,fichero
  * @return objeto de la clase Lattice
  */
Lattice::Lattice(const std::pair<int,int>& tamano, frontera frontera) { 
  this->frontera_ = frontera;
  this->generacion_ = 0;
  this->tamano_ = tamano;
  this->matriz_ = MatrizVariable(tamano);
  return;
}

/** void inicializar();
  * @brief Le pregunta al usuario cuales quiere que estén vivos
  */
void Lattice::inicializar() {
  std::cout << "Este es el inicializador de la matriz, por favor introduzca el estado de las celulas (1 -> viva o 0 -> muerta) fila por fila dejando un hueco entre cada celula." << std::endl;
  std::cout << "La matriz es de "<< this->tamano_.first << " filas y " << this->tamano_.second << " columnas. " << std::endl;
  for (int i = 0 ; i < this->tamano_.first ; i++) {
    for (int j = 0 ; j < this->tamano_.second ; j++) {
      int estado;
      std::cin >> estado;
      if (estado == 1) {
        this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), vivo));
      } else if (estado == 0) {
        this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), muerto));
      } else {
        std::cerr << "Error (1): Se ha introducido un valor no computable." << std::endl;
        exit(EXIT_FAILURE);
      }
    }
  }
}

/** const Cell& Lattice::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante. Si es sin frontera devuelve una celula muerta.
  */
Cell& Lattice::getCell(Position posicion) {
  if (this->frontera_ == reflectora) {
  posicion.fix(this->tamano_.first - 1, this->tamano_.second - 1);
  }else if (this->frontera_ == sin_frontera && this->matriz_.fueraDeRango(posicion.getPosition())) {
    // devuelve una celula muerta
    Cell* pointer = new Cell(Position(-1,-1), muerto);
    return *pointer;
  }
  return this->matriz_.getCell(posicion.getPosition());
}

/** const int Lattice::getTamano() const
  * @brief devuelve el tamaño del lattice
  * @return el tamaño del vector de celulas
  */
const std::pair<int,int> Lattice::getTamano() const {
  return this->tamano_;
}

/** const frontera Lattice::getFrontera() const
  * @brief devuelve el tipo de frontera del lattice
  * @return el tipo de frontera del lattice
  */
const frontera Lattice::getFrontera() const{
  return this->frontera_;
}

/** void Lattice::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void Lattice::nextGeneration() {
  for(int i = 0; i < this->tamano_.first; i++) { // cada celula obtiene el nextState
    for(int j = 0; j < this->tamano_.second; j++) { 
      Position posicion(i, j);
      this->getCell(posicion).nextState(*this);
    }
  }
  if (this->frontera_ == sin_frontera) {
    // Comprobar si hay una celula viva en los bordes y si es así aumentar el tamaño de la matriz.
    // Función comprobar frontera
    for (int i = 0; i < this->tamano_.first; i++) {
      if (this->getCell(Position(i,0)).getState().getState() == 1) {
        this->matriz_.AumentarTamano(0,-1);
        this->tamano_.second++;
      }
      if (this->getCell(Position(i,this->tamano_.second - 1)).getState().getState() == 1) {
        this->matriz_.AumentarTamano(0,1);
        this->tamano_.second++;
      }
    }
    for (int i = 0; i < this->tamano_.second; i++) {
      if (this->getCell(Position(0,i)).getState().getState() == 1) {
        this->matriz_.AumentarTamano(-1,0);
        this->tamano_.first++;
      }
      if (this->getCell(Position(this->tamano_.first - 1,i)).getState().getState() == 1) {
        this->matriz_.AumentarTamano(1,0);
        this->tamano_.first++;
      }
    }
  }
  for(int i = 0; i < this->tamano_.first; i++) { // cada celula obtiene el nextState
    for(int j = 0; j < this->tamano_.second; j++) { // cada celula se actualiza el estado
      Position posicion(i, j);
      this->getCell(posicion).updateState();
    }
  }
    std::cout << "tamaño: " << this->tamano_.first << " " << this->tamano_.second << "\n";
    std::cout << "posición begin: " << this->matriz_.posBegin().first << " " << this->matriz_.posBegin().second << "\n";
    std::cout << "posición end: " << this->matriz_.posEnd().first << " " << this->matriz_.posEnd().second << "\n";
  this->generacion_ ++;
}

int Lattice::Population() {
  int suma = 0;
  for(int i = 0; i < this->tamano_.first; i++) {
    for(int j = 0; j < this->tamano_.second; j++) {
      Position posicion(i, j);
      suma += this->getCell(posicion).getState().getState();
    }
  }
  return suma;
}


/** ostream& operator<<(ostream&, const Lattice&);
  * @brief sobrecarga del operador <<
  * @param os,tabla
  * @return objeto de la clase ostream
  */
std::ostream& operator<<(std::ostream& os, const Lattice& tabla) {
  os << " G(" << tabla.generacion_ << ")\n";
  os << tabla.matriz_;
  return os;
}


