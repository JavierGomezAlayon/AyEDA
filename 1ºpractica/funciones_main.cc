// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 01 : Autómata celular elemental
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/24
// Archivo funciones_main.cc: Implementación de funciones_main
//        En este fichero se implementa las funciones de la clase funciones_main
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/11/24 - Creación (primera versión) del código
#ifndef C_funciones_main_CC
#define C_funciones_main_CC

#include"funciones_main.h"


/** void RecogerParametro(int argc, char *argv[]);
  * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
  * @param argc, argv
  * @return retorna un struct Dato.
  */
Dato RecogerParametro(int argc, char *argv[]) {
  // Instancio las constantes
  const std::string KSize = "-size";
  const std::string KBorder = "-border";
  const std::string Kfichero = "-init";
  // Instancio la struct de datos
  Dato datos;
  // Compruebo que el número de argumento sea correcto.
  if (argc > 3 && argc < 8) {
    // Recorro el array comprobando lo que contiene
    for (int i = 0; i < argc; i++) {
      if (argv[i] == KSize) {
        datos.tamano = *argv[i + 1];
        i++;
      } else if (argv[i] == KBorder) { // compruebo que tipo de borde es y le asigno un objeto frontera al struct datos.
        if (argv[i + 1] == "b=open") { // si es open se comprueba si es fria o caliente y se pone dicho tipo.
          if (*argv[i + 2] == 0) { datos.border_type = fria; }
          else if ( *argv[i + 2] == 1) { datos.border_type = caliente; }
          else {
            std::cerr << "Error (1): Has puesto un argumento invalido." << std::endl;
            exit(EXIT_FAILURE);
          }
          i++;
        } else if (argv[i + 1] == "b=periodic") {
          datos.border_type = periodica;
        } else if (argv[i + 1] == "b=reflectora" ) {
          datos.border_type = reflectora;
        } else { // Error
          std::cerr << "Error (1): Has puesto un argumento invalido." << std::endl;
          exit(EXIT_FAILURE);
        }
        i++;
      } else if (argv[i] == Kfichero) {
        datos.fichero = argv[i + 1];
        i++;
      } else { // Error
        std::cerr << "Error (1): Has puesto un argumento invalido." << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    return datos;
  }
  // Error
  std::cerr << "Error (0): Has puesto un número de argumentos invalido." << std::endl ;
  exit(EXIT_FAILURE);
}

#endif