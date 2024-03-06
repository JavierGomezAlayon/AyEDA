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
  // comprobar que se ha abierto el fichero correctamente
  if (!input.is_open()) {
    throw std::string( "Error (4): No se ha podido abrir el fichero " + fichero );
    exit(EXIT_FAILURE);
  }
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
        throw std::string( "Error (2): En el fichero " + fichero + " se ha introducido un valor no computable o no se ha introducido los suficientes valores.");
        exit(EXIT_FAILURE);
      }
      this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), estado));
    }
  }
  input.close();
}

/** Lattice::Lattice()
  * @brief Crea el objeto de la clase Lattice.
  * @param tamano,frontera,fichero
  * @return objeto de la clase Lattice
  */
Lattice::Lattice(const std::pair<int,int>& tamano, frontera frontera) { 
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
  int estado;
  for (int i = 0 ; i < this->tamano_.first ; i++) {
    for (int j = 0 ; j < this->tamano_.second ; j++) {
      std::cin >> estado;
      if (estado == 1) {
        this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), vivo));
      } else if (estado == 0) {
        this->matriz_.setCell(std::pair<int,int>(i,j), Cell(Position(i,j), muerto));
      } else {
        throw std::string( "Error (1): Se ha introducido un valor no computable." );
        exit(EXIT_FAILURE);
      }
    }
  }
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



int Lattice::Population() {
  int suma = 0;
  for(int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1 ; i++) { // cada celula obtiene el nextState
    for(int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) { 
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


/** void Lattice::save(const std::string)
  * @brief Guarda el estado actual del lattice en un fichero
  * @param fichero
  */
void Lattice::save(const std::string fichero) {
  std::ofstream output(fichero);
  if (!output.is_open()) {
    throw std::string( "Error (4): No se ha podido abrir el fichero " + fichero );
    exit(EXIT_FAILURE);
  }
  output << this->tamano_.first << " " << this->tamano_.second << std::endl;
  for (int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1; i++) {
    for (int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) {
      output << ((this->getCell(Position(i,j)).getState().getState() == 1) ? 'x' : ' ');
    }
    output << std::endl;
  }
  output.close();
  return;
}

//---------------------------------------------------------------------------------------------------//

/** LatticeNoBorder::LatticeNoBorder(const std::pair<int,int>&)
  * @brief Crea el objeto de la clase LatticeNoBorder.
  * @param tamano
  * @return objeto de la clase LatticeNoBorder
  */
LatticeNoBorder::LatticeNoBorder(const std::pair<int,int>& tamano) : Lattice(tamano, sin_frontera) {
  corregirTamano();
  return;
}

/** LatticeNoBorder::LatticeNoBorder(const std::string)
  * @brief Crea el objeto de la clase LatticeNoBorder.
  * @param fichero
  * @return objeto de la clase LatticeNoBorder
  */
LatticeNoBorder::LatticeNoBorder(const std::string fichero) : Lattice(fichero, sin_frontera) {
  corregirTamano();
  return;
}

/** const Cell& LatticeNoBorder::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante. Si es sin frontera devuelve una celula muerta.
  */
Cell& LatticeNoBorder::getCell(Position posicion) {
  if (this->matriz_.fueraDeRango(posicion.getPosition())) {
    // devuelve una celula muerta
    Cell* pointer = new Cell(Position(-1,-1), muerto);
    return *pointer;
  }
  return this->matriz_.getCell(posicion.getPosition());
}

/** void LatticeNoBorder::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void LatticeNoBorder::nextGeneration() {
  for(int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1; i++) { // cada celula obtiene el nextState
    for(int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) { 
      Position posicion(i, j);
      this->getCell(posicion).nextState(*this);
    }
  }
  corregirTamano();
  for(int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1 ; i++) { // cada celula obtiene el updateState
    for(int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) { 
      Position posicion(i, j);
      this->getCell(posicion).updateState();
    }
  }
  corregirTamano();
  this->generacion_ ++;
}

/** void LatticeNoBorder::corregirTamano()
  * @brief Corrige el tamaño de la matriz si hay una celula viva en los bordes
  */
void LatticeNoBorder::corregirTamano() {
  // Comprobar si hay una celula viva en los bordes y si es así aumentar el tamaño de la matriz.
  // Función comprobar frontera
  for (int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1; i++) {
    if (this->getCell(Position(i, this->matriz_.posBegin().second)).getState().getState() == 1) {
      this->matriz_.AumentarTamano(0, -1); // aumento hacia la izquierda
      this->tamano_.second++;
      break;
    }
  }
  for (int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1; i++) {
    if (this->getCell(Position(i, this->matriz_.posEnd().second)).getState().getState() == 1) {
      this->matriz_.AumentarTamano(0, 1); // aumento hacia la derecha
      this->tamano_.second++;
      break;
    }
  }
  for (int i = this->matriz_.posBegin().second; i < this->matriz_.posEnd().second + 1; i++) {
    if (this->getCell(Position(this->matriz_.posBegin().first, i)).getState().getState() == 1) {
      this->matriz_.AumentarTamano(-1, 0); // aumento hacia arriba
      this->tamano_.first++;
      break;
    }
  }
  for (int i = this->matriz_.posBegin().second; i < this->matriz_.posEnd().second + 1; i++) {
    if (this->getCell(Position(this->matriz_.posEnd().first, i)).getState().getState() == 1) {
      this->matriz_.AumentarTamano(1, 0); // aumento hacia abajo
      this->tamano_.first++;
      break;
    }
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------------//


/** LatticeReflectora::LatticeReflectora(const std::pair<int,int>&)
  * @brief Crea el objeto de la clase LatticeReflectora.
  * @param tamano
  * @return objeto de la clase LatticeReflectora
  */
LatticeReflectora::LatticeReflectora(const std::pair<int,int>& tamano) : Lattice(tamano, reflectora) {
  return;
}

/** LatticeReflectora::LatticeReflectora(const std::string)
  * @brief Crea el objeto de la clase LatticeReflectora.
  * @param fichero
  * @return objeto de la clase LatticeReflectora
  */
LatticeReflectora::LatticeReflectora(const std::string fichero) : Lattice(fichero, reflectora) {
  return;
}

/** const Cell& LatticeReflectora::getCell(const Position&) const
  * @brief devuelve la celula que está en la posición descrita por el objeto posicion
  * @param posicion
  * @return retorna una celula constante. Si es sin frontera devuelve una celula muerta.
  */
Cell& LatticeReflectora::getCell(Position posicion) {
  posicion.fix(this->tamano_.first - 1, this->tamano_.second - 1);
  return this->matriz_.getCell(posicion.getPosition());
}

/** void LatticeReflectora::nextGeneration()
  * @brief Se carga la siguiente generación de celulas
  */
void LatticeReflectora::nextGeneration() {
  for(int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1; i++) { // cada celula obtiene el nextState
    for(int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) { 
      Position posicion(i, j);
      this->getCell(posicion).nextState(*this);
    }
  }
  for(int i = this->matriz_.posBegin().first; i < this->matriz_.posEnd().first + 1 ; i++) { // cada celula obtiene el updateState
    for(int j = this->matriz_.posBegin().second; j < this->matriz_.posEnd().second + 1; j++) { 
      Position posicion(i, j);
      this->getCell(posicion).updateState();
    }
  }
  this->generacion_ ++;
}