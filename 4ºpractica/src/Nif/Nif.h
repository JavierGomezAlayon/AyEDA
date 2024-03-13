// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo Nif.h: Declaración de la clase Nif
//        En este fichero se declara la clase Nif
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_Nif_H
#define C_Nif_H
#include <iostream>
#include <string>

class Key {
  public:
  virtual long int getValue() = 0;

  };
class Nif : public Key{
 public:
  Nif();
  Nif(std::string nif);
  long int getValue();
  std::string getOriginal();
 private:
  std::string nif_;
  long int IDnif_;
  static int contador; //se utiliza para generar números aleatorios distintos para nada más.
};



#endif