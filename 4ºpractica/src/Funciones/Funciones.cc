// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/13/24
// Archivo Funciones.cc: Implementación de Funciones
//        En este fichero se implementa las funciones de la clase Funciones
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/13/24 - Creación (primera versión) del código

#include"Funciones.h"
#include <unistd.h>

/** int numero_aleatorio(int limite_inferior, int limite_superior)
  * @brief Devuelve un número aleatorio entre dos límites.
  * @param limite_inferior límite inferior.
  * @param limite_superior límite superior.
  * @return número aleatorio.
  */
int numero_aleatorio(const int limite_inferior, const int limite_superior, const int sumador) {
  srand(time(NULL) * (sumador + 1));
  return limite_inferior + rand() % (limite_superior +1 - limite_inferior);
}
/** char letra_mayus_aleatoria()
  * @brief Devuelve una letra mayúscula aleatoria.
  * @return letra mayúscula aleatoria.
  */
char letra_mayus_aleatoria(const int sumador) {
  srand(time(NULL) * sumador + 1);
  return 'A' + rand() % 26;
}

