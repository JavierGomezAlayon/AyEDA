// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/24
// Archivo funciones_main.h: Declaración de las funciones del main
//        
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/11/24 - Creación (primera versión) del código
#ifndef C_funciones_main_H
#define C_funciones_main_H

#include<iostream>
#include<string>
#include"Lattice.h"

// Definimos un struct para poder pasar al main los datos correspondientes.
struct Dato {
  frontera border_type;
  int tamano;
  std::string fichero;
};

Dato RecogerParametro(int argc, char *argv[]);


#endif