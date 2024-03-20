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
  int table_size = 0; // tamaño de la tabla
  int funcion_dispersion = 0; // tipo de función de dispersión 1 = módulo, 2 = pseudoaleatoria, 3 = suma
  int hash_type = 0; // tipo de hash 1 = cerrado, 2 = abierto
  int funcion_exploracion = 0; // tipo de función de exploración 1 = lineal, 2 = cuadrática, 3 = doble dispersión, 4 = redispersión
  int block_size = 0; // tamaño del bloque
};
Dato leer_datos(int argc, char *argv[]);
int numero_aleatorio(const int limite_inferior = 0, const int limite_superior = 10000000, const int sumador = 0);
char letra_mayus_aleatoria(const int sumador = 0);


#endif