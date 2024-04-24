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

// Defino las constantes
  const std::string Khelp = "-h";
  const std::string Kab = "-ab";
  const std::string Kinit = "-init";
  // Constantes de init
  const std::string Kmanual = "manual";
  const std::string Krandom = "random";
  const std::string Kfile = "file";

Dato leer_datos(int argc, char *argv[]) {
  // Instancio la struct de datos
  Dato datos;
  // Compruebo que el número de argumento sea correcto.
  if (argc >= 5 && argc <= 7 ) {
    // Recorro el array comprobando lo que contiene
    for (int i = 1; i < argc; i++) {
      if (argv[i] == Kab) {
        datos.ab = std::atoi(argv[i + 1]);
        if (datos.ab < 1 || datos.ab > 2) {
          throw std::string( "Error (1): Has puesto un parámetro -ab incorrecto." );
        }
        i ++;
      } else if (argv[i] == Kinit) {
        if (argv[i + 1] == Kmanual) {
          datos.init = 1;
        } else if (argv[i + 1] == Krandom) {
          datos.init = 2;
          datos.size = std::atoi(argv[i + 2]);
          i ++;
        } else if (argv[i + 1] == Kfile) {
          datos.init = 3;
          datos.size = std::atoi(argv[i + 2]);
          datos.fichero = argv[i + 3];
          i += 2;

        } else {
          throw std::string( "Error (2): Has puesto un tipo de inicialización invalido." );
        }
        i++;
      } else if (argv[i] == Khelp) {
        std::cout << "Uso: " << argv[0] << std::endl;
        std::cout << " -ab para indicar el tipo de árbol con el que se va a trabajar. (1 = abe, 2 = abb)" << std::endl;
        std::cout << " -init indica la forma de introducir los datos de la secuencia:" << std::endl;
        std::cout << " manual" << std::endl;
        std::cout << " random [s], s es el número de elementos a generar" << std::endl;
        std::cout << " file [s] [f], s es el número de elementos a generar, f es nombre del fichero de entrada" << std::endl;
        std::cout << " -h muestra esta ayuda" << std::endl;
        exit(EXIT_SUCCESS);
      } else { // Error
        throw std::string( "Error (3): Has puesto un argumento invalido." );
        exit(EXIT_FAILURE);
      }
    }
    return datos;
  } else if (argc == 2 && argv[1] == Khelp) {
      std::cout << "Uso: " << argv[0] << std::endl;
      std::cout << " -ab para indicar el tipo de árbol con el que se va a trabajar. (1 = abe, 2 = abb)" << std::endl;
      std::cout << " -init indica la forma de introducir los datos de la secuencia:" << std::endl;
      std::cout << " manual" << std::endl;
      std::cout << " random [s], s es el número de elementos a generar" << std::endl;
      std::cout << " file [s] [f], s es el número de elementos a generar, f es nombre del fichero de entrada" << std::endl;
      std::cout << " -h muestra esta ayuda" << std::endl;
      exit(EXIT_SUCCESS);
  }
  // Error
  throw std::string( "Error (4): Has puesto un número de argumentos invalido." ) ;
  exit(EXIT_FAILURE);
}

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

