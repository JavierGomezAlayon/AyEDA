// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo Nif.cc: Implementación de Nif
//        En este fichero se implementa las funciones de la clase Nif
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código

#include"Nif.h"
#include "../Funciones/Funciones.h"
int Nif::contador = 0;
int coche::contador = 0;

/** Nif::Nif()
  * @brief Constructor por defecto del objeto de la clase Nif.
  * @return objeto de la clase Nif
  */
Nif::Nif() {
  IDnif_ = numero_aleatorio(10000000, 99999999, contador);
  nif_ = std::to_string(IDnif_) + letra_mayus_aleatoria(contador);
  contador++;
}

/** Nif::Nif(std::string nif)
  * @brief Constructor del objeto de la clase Nif.
  * @param nif string que contiene el nif.
  * @return objeto de la clase Nif
  */
Nif::Nif(std::string nif) {
  nif_ = nif;
  IDnif_ = std::stol(nif);
}

/** Nif::getValue()
  * @brief Devuelve el valor del nif.
  * @return valor del nif.
  */
long int Nif::getValue() const {
  return IDnif_;
}

/** Nif::getOriginal()
  * @brief Devuelve el nif original.
  * @return nif original.
  */
std::string Nif::getOriginal() const {
  return nif_;
}

/** Nif::operator==(const Nif& nif) const
  * @brief Sobrecarga del operador == para comparar dos nif.
  * @param nif objeto de la clase Nif.
  * @return true si son iguales, false si no lo son.
  */
bool Nif::operator==(const Nif& nif) const {
  return nif_ == nif.nif_;
}

/** Nif::operator<<(std::ostream& os, const Nif& nif)
  * @brief Sobrecarga del operador << para imprimir un nif.
  * @param os flujo de salida.
  * @param nif objeto de la clase Nif.
  * @return flujo de salida.
  */
std::ostream& operator<<(std::ostream& os, const Nif& nif) {
  os << nif.nif_;
  return os;
}


/** coche::coche()
  * @brief Constructor por defecto del objeto de la clase coche.
  * @return objeto de la clase coche
  */
coche::coche() {
  // creo una string con 3 letras aleatorias y 4 números aleatorios.
  std::string letras;
  letras.push_back(letra_mayus_aleatoria(contador));
  letras.push_back(letra_mayus_aleatoria(contador * 3 + 1));
  letras.push_back(letra_mayus_aleatoria(contador * 7 + 5));
  matricula_ =  letras + std::to_string(numero_aleatorio(1000, 9999, contador));
  potencia_ = numero_aleatorio(50, 500, contador);
  marca_ = "no definida";
  modelo_ = "no definido";
  numero_clase_ = numero_aleatorio(1, 10, contador);
  numero_valvulas = numero_aleatorio(1, 10, contador);
  CC_ = numero_aleatorio(1000, 9999, contador);
  contador++;
}

/** coche::coche(std::string matricula)
  * @brief Constructor del objeto de la clase coche.
  * @param matricula string que contiene la matricula.
  * @return objeto de la clase coche
  */
coche::coche(std::string matricula) {
  matricula_ = matricula;
  potencia_ = 0;
  marca_ = "no definida";
  modelo_ = "no definido";
  numero_clase_ = 1;
  numero_valvulas = 4;
  CC_ = 0;
}

/** coche::coche(std::string matricula)
  * @brief Constructor del objeto de la clase coche.
  * @param matricula string que contiene la matricula.
  * @return objeto de la clase coche
  */
coche::coche(std::string matricula, std::string marca = "no definida", std::string modelo = "no definido", int numero_clase = 1, int numero_valvulas = 4, int CC = 0, int potencia = 0 ) { 
  matricula_ =  matricula;
  potencia_ = potencia;
  marca_ = marca;
  modelo_ = modelo;
  numero_clase_ = numero_clase;
  numero_valvulas = numero_valvulas;
  CC_ = CC;
}

/** coche::getMatricula()
  * @brief Devuelve la matricula del coche.
  * @return matricula del coche.
  */
std::string coche::getMatricula() const {
  return matricula_;
}

/** coche::getValue()
  * @brief Devuelve el valor de la matricula.
  * @return valor de la matricula.
  */
long int coche::getValue() const {
  int i = int(matricula_[0]) + int(matricula_[1]) + int(matricula_[2]) + std::stoi(matricula_.substr(3, 7));
  return i;
}

/** coche::operator==(const coche& coche) const
  * @brief Sobrecarga del operador == para comparar dos coches.
  * @param coche objeto de la clase coche.
  * @return true si son iguales, false si no lo son.
  */
bool coche::operator==(const coche& coche) const {
  return matricula_ == coche.matricula_;
}

/** coche::operator<<(std::ostream& os, const coche& coche)
  * @brief Sobrecarga del operador << para imprimir un coche.
  * @param os flujo de salida.
  * @param coche objeto de la clase coche.
  * @return flujo de salida.
  */
std::ostream& operator<<(std::ostream& os, const coche& coche) {
  os << coche.matricula_;
  return os;
}
