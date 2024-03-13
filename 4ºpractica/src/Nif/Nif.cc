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

/** Nif::Nif()
  * @brief Constructor por defecto del objeto de la clase Nif.
  * @return objeto de la clase Nif
  */
Nif::Nif() {
  nif_ = "00000000A";
  IDnif_ = 0;
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
long int Nif::getValue() {
  return IDnif_;
}

/** Nif::getOriginal()
  * @brief Devuelve el nif original.
  * @return nif original.
  */
std::string Nif::getOriginal() {
  return nif_;
}

