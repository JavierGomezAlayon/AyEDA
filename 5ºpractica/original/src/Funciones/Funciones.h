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
  int size = 0; //  tamaño de la secuencia
  int ordenacion = 0; // es el código que identifica un método de ordenación.
  int init = 0; // indica la forma de introducir los datos de la secuencia 1 = manual, 2 = random, 3 = file
  std::string fichero = ""; // nombre del fichero en caso de que se haya elegido la opción file
  bool trace = false; // indica si se debe mostrar la traza de la ordenación
};
Dato leer_datos(int argc, char *argv[]);
int numero_aleatorio(const int limite_inferior = 0, const int limite_superior = 10000000, const int sumador = 0);
char letra_mayus_aleatoria(const int sumador = 0);




#endif