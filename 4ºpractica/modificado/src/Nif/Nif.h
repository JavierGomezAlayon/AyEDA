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

class coche {
 public:
  coche();
  coche(std::string matricula);
  coche(std::string matricula, std::string marca, std::string modelo, int numero_clase, int numero_valvulas, int CC, int potencia);
  std::string getMatricula() const;
  long int getValue() const;
  friend std::ostream& operator<<(std::ostream& os, const coche& coche);
  bool operator==(const coche& coche) const;
 private:
  std::string matricula_;
  int potencia_;
  std::string marca_;
  std::string modelo_;
  int numero_clase_;
  int numero_valvulas;
  int CC_;
  static int contador; //se utiliza para generar números aleatorios distintos para nada más.
};


#endif