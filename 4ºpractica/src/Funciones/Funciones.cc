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
  const std::string Kts = "-ts";
  const std::string Kfd = "-fd";
  const std::string Khash = "-hash";
  const std::string Kbs = "-bs";
  const std::string Kfe = "-fe";
  // Constantes de hash
  const std::string Kopen = "open";
  const std::string Kclosed = "close";


Dato leer_datos(int argc, char *argv[]) {
  // Instancio la struct de datos
  Dato datos;
  // Compruebo que el número de argumento sea correcto.
  if (argc == 11 || argc == 7) {
    // Recorro el array comprobando lo que contiene
    for (int i = 1; i < argc; i++) {
      if (argv[i] == Kts) {
        datos.table_size = std::atoi(argv[i + 1]);
        if (datos.table_size < 1) {
          throw std::string( "Error (0): Has puesto un tamaño de tabla invalido." );
        }
        i ++;
      } else if (argv[i] == Kfd) { // compruebo que tipo de borde es y le asigno un objeto frontera al struct datos.
        datos.funcion_dispersion = std::atoi(argv[i + 1]);
        if (datos.funcion_dispersion < 1 || datos.funcion_dispersion > 3) {
          throw std::string( "Error (1): Has puesto un argumento fd invalido." );
        }
        i++;
      } else if (argv[i] == Khash) {
        if (argv[i + 1] == Kopen) {
          datos.hash_type = 2;
        } else if (argv[i + 1] == Kclosed) {
          datos.hash_type = 1;
        } else {
          throw std::string( "Error (2): Has puesto un tipo de hash invalido." );
        }
        i++;
      } else if (argv[i] == Kbs) {
        datos.block_size = std::atoi(argv[i + 1]);
        if (datos.block_size < 1) {
          throw std::string( "Error (3): Has puesto un tamaño de bloque invalido." );
        }
        i++;
      } else if (argv[i] == Kfe) {
        datos.funcion_exploracion = std::atoi(argv[i + 1]);
        if (datos.funcion_exploracion < 1 || datos.funcion_exploracion > 4) {
          throw std::string( "Error (4): Has puesto un argumento fe invalido." );
        }
        i++;
      } else if (argv[i] == "-h") {
        std::cout << "Uso: " << argv[0] << " -ts [tamaño_tabla] -fd [tipo_funcion_dispersion] -hash [tipo_hash] -bs [tamaño_bloque] -fe [tipo_funcion_exploracion]" << std::endl;
        std::cout << "  -ts tamaño_tabla: Tamaño de la tabla hash." << std::endl;
        std::cout << "  -fd tipo_funcion_dispersion: Tipo de función de dispersión. 1 = módulo, 2 = pseudoaleatoria, 3 = suma." << std::endl;
        std::cout << "  -hash tipo_hash: Tipo de hash. 1 = cerrado, 2 = abierto." << std::endl;
        std::cout << "  -bs tamaño_bloque: Tamaño del bloque." << std::endl;
        std::cout << "  -fe tipo_funcion_exploracion: Tipo de función de exploración. 1 = lineal, 2 = cuadrática, 3 = doble dispersión, 4 = redispersión." << std::endl;
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

