// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo Nif.cc: Implementación de Nif
//        En este fichero se implementa las funciones de la clase Nif
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código

#include"Nif.h"
#include "../Funciones/Funciones.h"
int Nif::contador = 0;

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

/** Nif::operator=(const int& rhs)
  * @brief Sobrecarga del operador = para asignar un valor a un nif.
  * @param rhs valor a asignar.
  * @return objeto de la clase Nif.
  */
Nif& Nif::operator=(const int& rhs) {
  IDnif_ = rhs;
  nif_ = std::to_string(rhs);
  return *this;
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

