// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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
#pragma once

#include<iostream>
#include<string>
#include"Lattice.h"

// Definimos un struct para poder pasar al main los datos correspondientes.
struct Dato {
  frontera border_type = sin_frontera;
  std::pair<int,int> tamano = std::pair<int,int>(1,1);
  std::string fichero;
};

Dato RecogerParametro(int argc, char *argv[]);
void Recoger_borde(char *argv[], int &i, Dato &datos);
