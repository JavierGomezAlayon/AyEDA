// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo Nif.h: Declaración de Nif
//        En este fichero se declara las funciones de la clase Nif
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código
#ifndef C_Nif_H
#define C_Nif_H
#include <iostream>
#include <string>

class Nif {
 public:
  Nif();
  Nif(std::string nif);
  long int getValue() const;
  std::string getOriginal() const;
  friend std::ostream& operator<<(std::ostream& os, const Nif& nif);
  bool operator==(const Nif& nif) const;
 private:
  std::string nif_;
  long int IDnif_;
  static int contador; //se utiliza para generar números aleatorios distintos para nada más.
};


#endif