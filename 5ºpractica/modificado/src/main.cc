// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo main.cc: programa cliente.
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código


// comparaciones e intercambios poner la media de comparaciones e intercambios de 10 vectores de 1000 unidades.

#include <iostream>
#include <string>
#include <fstream>
#include "Funciones/Funciones.h"
#include "Sequence/Sequence.h"
#include "Nif/Nif.h"
#include "Metodos/Metodos.h"
#include "SortMethod/SortMethod.h"

void setInit(Dato& datos, staticSequence<Nif>* secuencia);

int main(int argc, char *argv[]) {
// modificación
  std::vector <std::pair<int,int>> resultados1;
  std::vector <std::pair<int,int>> resultados2;
  std::vector <std::pair<int,int>> resultados3;
  std::vector <std::pair<int,int>> resultados4;
  std::vector <std::pair<int,int>> resultados5;
  staticSequence<Nif>* secuencia;
  std::pair<int,int> resultado;
  for (int i = 0; i < 10; i++) {
    secuencia = new staticSequence<Nif>(1000);
    for (int i = 0; i < 1000; i++) {
      secuencia->insert(Nif());
    }
    SortMethod<Nif>* metodo;
    for (int j = 1; j <= 5; j++) {
      switch (j) {
        case 1:
          metodo = new Seleccion<Nif>(secuencia);
          resultado = metodo->sort();
          resultados1.push_back(resultado);
          break;
        case 2:
          metodo = new QuickSort<Nif>(secuencia);
          resultado = metodo->sort();
          resultados2.push_back(resultado);
          break;
        case 3:
          metodo = new HeapSort<Nif>(secuencia);
          resultado = metodo->sort();
          resultados3.push_back(resultado);
          break;
        case 4:
          metodo = new ShellSort<Nif>(secuencia);
          resultado = metodo->sort();
          resultados4.push_back(resultado);
          break;
        case 5:
          metodo = new RadixSort<Nif>(secuencia);
          resultado = metodo->sort();
          resultados5.push_back(resultado);
          break;
      }
    }
  }
  std::pair<int,int> media1;
  std::pair<int,int> media2;
  std::pair<int,int> media3;
  std::pair<int,int> media4;
  std::pair<int,int> media5;
  // Hago la media de cada vector de resultados
  for (int i = 0; i < 10; i++) {
    media1 = std::make_pair(media1.first + resultados1[i].first, media1.second + resultados1[i].second);
    media2 = std::make_pair(media2.first + resultados2[i].first, media2.second + resultados2[i].second);
    media3 = std::make_pair(media3.first + resultados3[i].first, media3.second + resultados3[i].second);
    media4 = std::make_pair(media4.first + resultados4[i].first, media4.second + resultados4[i].second);
    media5 = std::make_pair(media5.first + resultados5[i].first, media5.second + resultados5[i].second);
  }
  media1 = std::make_pair(media1.first / 10, media1.second / 10);
  media2 = std::make_pair(media2.first / 10, media2.second / 10);
  media3 = std::make_pair(media3.first / 10, media3.second / 10);
  media4 = std::make_pair(media4.first / 10, media4.second / 10);
  media5 = std::make_pair(media5.first / 10, media5.second / 10);
  // Muestro los resultados
  std::cout << "Media de comparaciones e intercambios de 10 vectores de 1000 unidades" << std::endl;
  std::cout << "Seleccion: " << media1.first << " comparaciones y " << media1.second << " intercambios" << std::endl;
  std::cout << "QuickSort: " << media2.first << " comparaciones y " << media2.second << " intercambios" << std::endl;
  std::cout << "HeapSort: " << media3.first << " comparaciones y " << media3.second << " intercambios" << std::endl;
  std::cout << "ShellSort: " << media4.first << " comparaciones y " << media4.second << " intercambios" << std::endl;
  std::cout << "RadixSort: " << media5.first << " comparaciones y " << media5.second << " intercambios" << std::endl;



  return 0;
}