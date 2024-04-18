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

int main(int argc, char *argv[]) {
  Dato datos;
  try { // leer datos
    datos = leer_datos(argc, argv);
  } catch (std::string &error) {
    std::cerr << error << std::endl;
    return 1;
  }
  //mostrar los datos recogidos
  std::cout << "Datos recogidos: " << std::endl;
  std::cout << "ab: " << datos.ab << std::endl;
  std::cout << "init: " << datos.init << std::endl;
  std::cout << "size: " << datos.size << std::endl;
  std::cout << "fichero: " << datos.fichero << std::endl;

  //crear el árbol
  AB<int> arbol;
  //insertar las claves
  for (int i = 0; i < datos.size; i++) {
    arbol.insertar(i);
  }
    //mostrar el árbol


  //menú
  int opcion;
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
        arbol.insertar(clave);
        break;
      case 2:
        //buscar_clave();
        break;
      case 3:
        arbol.inorden();
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
  return 0;
}