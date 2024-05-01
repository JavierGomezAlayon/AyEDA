// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 06 : Árbol (TAD)
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/18/24
// Archivo main.cc: Implementación de main
//        En este fichero se implementa las funciones de la clase main
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/18/24 - Creación (primera versión) del código
#include <iostream>
#include <string>
#include "Funciones/Funciones.h"
#include "Ab/Ab.h"
#include "NodoB/NodoB.h"
#include "Nif/Nif.h"
#include <chrono>
#include <ctime>

int main(int argc, char *argv[]) {
  Dato datos;
  try { // leer datos
    datos = leer_datos(argc, argv);
  } catch (std::string &error) {
    std::cerr << error << std::endl;
    return 1;
  }
  //mostrar los datos recogidos
  //std::cout << "Datos recogidos: " << std::endl;
  //std::cout << "ab: " << datos.ab << std::endl;
  //std::cout << "init: " << datos.init << std::endl;
  //std::cout << "size: " << datos.size << std::endl;
  //std::cout << "fichero: " << datos.fichero << std::endl;

  //crear el árbol
  AB<int>* arbol;
  if (datos.ab == 1) {
    arbol = new ABE<int>();
  } else if (datos.ab == 2) {
    arbol = new ABB<int>();
  } else {
    std::cerr << "Tipo de árbol no válido" << std::endl;
    return 1;
  }
  //insertar las claves
  if (datos.init == 2) {
    int numero;
    for (int i = 0; i < datos.size; i++) {
      numero = numero_aleatorio(0,1000000,i);
      arbol->insertar(numero);
    }
  }
    //mostrar el árbol


  //menú
  int opcion;
  std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
  std::chrono::duration<float,std::milli> duration, duration2;
  int clave3; 
  
  while (true) {
    opcion = 0;
    std::cout << "Menú: " << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "1. Insertar clave" << std::endl;
    std::cout << "2. Buscar clave" << std::endl;
    std::cout << "3. Mostrar árbol inorden" << std::endl;
    std::cin >> opcion;
    switch (opcion) {
      case 0:
        return 0;
      case 1:
        std::cout << "Introduce la clave a insertar: ";
        //std::string clave;
        //std::cin >> clave;
        //Nif nif(clave);
        //arbol.insertar(nif.getValue());
        int clave;
        std::cin >> clave;
        if (arbol->insertar(clave)) {
          std::cout << "Clave insertada correctamente" << std::endl;
        } else {
          std::cout << "Error al insertar la clave" << std::endl;
        }
        std::cout << std::endl;
       arbol->recorridoPorNiveles();
        break;
      case 2:
        std::cout << "Introduce la clave a buscar: "; 
        int clave2;
        std::cin >> clave2;
        std::cout << arbol->buscar(clave2) << std::endl;
        break;
      case 3:
        std::cout << std::endl;
        //modificación
        start = std::chrono::system_clock::now();
        arbol->recorridoPorNiveles();
        end = std::chrono::system_clock::now();
        duration = end - start;
        std::cout << "Tiempo de ejecución: " << duration.count() << "ms" << std::endl;
        std::cout << std::endl;

        std::cout << "Introduce la clave a buscar: "; 
        std::cin >> clave3;
        start2 = std::chrono::system_clock::now();
        std::cout << arbol->buscar(clave3) << std::endl;
        end2 = std::chrono::system_clock::now();
        duration2 = end2 - start2;
        std::cout << "Tiempo de ejecución: " << duration2.count() << "ms" << std::endl;
        std::cout << std::endl;
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
  return 0;
}