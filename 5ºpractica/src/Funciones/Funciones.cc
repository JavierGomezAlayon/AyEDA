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
  const std::string Ksize = "-size";
  const std::string Kord = "-ord";
  const std::string Kinit = "-init";
  const std::string Ktrace = "-trace";
  // Constantes de init
  const std::string Kmanual = "manual";
  const std::string Krandom = "random";
  const std::string Kfile = "file";
  // Otras constantes
  const std::string Ky = "y";
  const std::string Kn = "n";


Dato leer_datos(int argc, char *argv[]) {
  // Instancio la struct de datos
  Dato datos;
  // Compruebo que el número de argumento sea correcto.
  if (argc == 9 || argc == 10) {
    // Recorro el array comprobando lo que contiene
    for (int i = 1; i < argc; i++) {
      if (argv[i] == Ksize) {
        datos.size = std::atoi(argv[i + 1]);
        if (datos.size < 1) {
          throw std::string( "Error (1): Has puesto un tamaño invalido." );
        }
        i ++;
      } else if (argv[i] == Kord) { // compruebo que tipo de borde es y le asigno un objeto frontera al struct datos.
        datos.ordenacion = std::atoi(argv[i + 1]);
        if (datos.ordenacion < 1 || datos.ordenacion > 3) {
          throw std::string( "Error (2): Has puesto un metodo de ordenación invalido." );
        }
        i++;
      } else if (argv[i] == Kinit) {
        if (argv[i + 1] == Krandom) {
          datos.init = 0;
        } else if (argv[i + 1] == Kmanual) {
          datos.init = 1;
        } else if (argv[i + 1] == Kfile) {
          datos.init = 2;
          datos.fichero = argv[i + 2];
          i++;
        } else {
          throw std::string( "Error (3): Has puesto un tipo de inicialización invalido." );
        }
        i++;
      } else if (argv[i] == Ktrace) {
        if (argv[i + 1] == Ky) {
          datos.trace = true;
        } else if (argv[i + 1] == Kn) {
          datos.trace = false;
        } else {
          throw std::string( "Error (4): Has puesto un argumento trace invalido." );
        }
        i++;
      } else if (argv[i] == Khelp) {
        std::cout << "Uso: " << argv[0] << " -size tamaño de la secuencia" << std::endl;
        std::cout << " -ord es el código que identifica un método de ordenación." << std::endl;
        std::cout << " -init indica la forma de introducir los datos de la secuencia 1 = manual, 2 = random, 3 = file" << std::endl;
        std::cout << " -trace indica si se debe mostrar la traza de la ordenación" << std::endl;
        std::cout << " -h muestra esta ayuda" << std::endl;
        exit(EXIT_SUCCESS);
      } else { // Error
        throw std::string( "Error (5): Has puesto un argumento invalido." );
        exit(EXIT_FAILURE);
      }
    }
    return datos;
  }
  // Error
  throw std::string( "Error (6): Has puesto un número de argumentos invalido." ) ;
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

