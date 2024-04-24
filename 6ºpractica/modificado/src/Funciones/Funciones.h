// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/13/24
// Archivo Funciones.h: Declaración de la clase Funciones
//        En este fichero se declara la clase Funciones
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/13/24 - Creación (primera versión) del código
#ifndef C_Funciones_H
#define C_Funciones_H

#include <iostream>
#include <string>
#include<time.h>
#include<stdlib.h>

struct Dato {
  int ab = 0; // <abe|abb>,<1|2> para indicar el tipo de árbol con el que se va a trabajar.
  int init = 0; // <manual|random|file>,<1|2|3> para indicar la forma de introducir los datos de la secuencia
  int size = 0; // <s>, s es el número de elementos a generar
  std::string fichero = ""; // <f>, f es nombre del fichero de entrada
};
Dato leer_datos(int argc, char *argv[]);
int numero_aleatorio(const int limite_inferior = 0, const int limite_superior = 10000000, const int sumador = 0);
char letra_mayus_aleatoria(const int sumador = 0);




#endif