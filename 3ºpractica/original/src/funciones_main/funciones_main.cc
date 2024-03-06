// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
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

#include"funciones_main.h"

  // Defino las constantes
  const std::string KSize = "-size";
  const std::string KBorder = "-border";
  const std::string Kfichero = "-init";
  // Constantes de frontera
  const std::string KOpen = "b=open";
  const std::string KPeriodica = "b=periodic";
  const std::string KReflectora = "b=reflectora";
  const std::string kSinborde = "b=noborder";

/** void RecogerParametro(int argc, char *argv[]);
  * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
  * @param argc, argv
  * @return retorna un struct Dato.
  */
Dato RecogerParametro(int argc, char *argv[]) {
  // Instancio la struct de datos
  Dato datos;
  datos.fichero = "";
  // Compruebo que el número de argumento sea correcto.
  if (argc == 5 || argc == 6) {
    // Recorro el array comprobando lo que contiene
    for (int i = 1; i < argc; i++) {
      if (argv[i] == KSize) {
        datos.tamano.first = std::atoi(argv[i + 1]);
        datos.tamano.second = std::atoi(argv[i + 2]);
        i += 2;
      } else if (argv[i] == KBorder) { // compruebo que tipo de borde es y le asigno un objeto frontera al struct datos.
        Recoger_borde(argv, i, datos);
        i++;
      } else if (argv[i] == Kfichero) {
        datos.fichero = argv[i + 1];
        i++;
      } else { // Error
        throw std::string( "Error (1): Has puesto un argumento invalido." );
        exit(EXIT_FAILURE);
      }
    }
    return datos;
  }
  // Error
  throw std::string( "Error (0): Has puesto un número de argumentos invalido." ) ;
  exit(EXIT_FAILURE);
}

/** void Recoger_borde(char *argv[], int &i, Dato &datos);
  * @brief Recoge el tipo de borde que se ha introducido por linea de comando.
  * @param argv, i, datos
  */
void Recoger_borde(char *argv[], int &i, Dato &datos) {
  if (argv[i + 1] == KOpen) { // si es open se comprueba si es fria o ca) {ite y se pone dicho tipo.
    if (*argv[i + 2] == '0') {
      datos.border_type = fria;
    }
    else if (*argv[i + 2] == '1') {
      datos.border_type = caliente;
    } else {
      throw std::string( "Error (3): Has puesto un tipo de frontera abierta no valido" );
      exit(EXIT_FAILURE);
    }
    i++;
  } else if (argv[i + 1] == KPeriodica) {
    datos.border_type = periodica;
  } else if (argv[i + 1] == KReflectora) {
    datos.border_type = reflectora;
  } else if (argv[i + 1] == kSinborde) {
    datos.border_type = sin_frontera;
  } else { // Error
    throw std::string( "Error (1): Has puesto un argumento invalido." );
    exit(EXIT_FAILURE);
  }
}

/** void InterfazGeneraciones(Lattice &lattice);
  * @brief Interfaz para mostrar las generaciones del juego de la vida.
  * @param lattice
  */
void InterfazGeneraciones(Lattice &lattice) {
  char input;
  // Explicación de la interfaz
  std::cout << "Pulse cualquier tecla para avanzar a la siguiente generación." << std::endl;
  while (std::cin >> input) {
    system("clear");
    std::cout << lattice << std::endl;
    std::cout << "Población: " << lattice.Population() << std::endl;
    lattice.nextGeneration();
  }
}

/** void Menu(Lattice& lattice);
  * @brief Menú para el juego de la vida.
  * @param lattice
  */
void Menu(Lattice& lattice) {
  char ch;
  bool contador_vida = false;
  std::cout << lattice << std::endl;
  do {
    switch (ch) {
      case 'n':
        lattice.nextGeneration();
        if (contador_vida) {
          system("clear");
          std::cout << "Población: " << lattice.Population() << std::endl;
        } else {
          system("clear");
          std::cout << lattice << std::endl;
        }
        break;
      case 'l':
        system("clear");
        for (int i = 0; i < 5; i++) {
          lattice.nextGeneration();
          if (contador_vida) {
            std::cout << "Población: " << lattice.Population() << std::endl;
          } else {
            std::cout << lattice << std::endl;
          }
        }
        break;
      case 'c':
        system("clear");
        contador_vida = !contador_vida;
        std::cout << "Se ha cambiado el modo de visionado de la población.\n";
        break;
      case 'x':
        exit(0);
        break;
      case 's':
        system("clear");
        lattice.save("save.txt");
        std::cout << "Guardado en save.txt\n";
        break;
      case 'h':
        system("clear");
        std::cout << "introduce n para siguiente generación, l para ver las siguientes 5 generaciones, c para ver la población, s para guardar y x para salir.\n";
        break;
    }
  } while (std::cin >> ch);
}