
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 02 : El juego de la vida
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/08/24
// Archivo main.cc: El programa cliente.
//        
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        02/08/24 - Creación (primera versión) del código
//        02/26/24 - Hay un bug con el borde noborder pero no sé como solucionarlo.


#include"../Lattice/Lattice.h"
#include"../Cell/Cell.h"
#include"../funciones_main/funciones_main.h"
#include "main.h"

int main(int argc, char* argv[]) {
  Dato datos = RecogerParametro(argc, argv);
  // Si el cliente puso un fichero se construye el lattice con el fichero.
  if (datos.fichero != "") {
    Lattice lattice(datos.fichero, datos.border_type);
    char ch;
    bool contador_vida = false;
    std::cout << lattice << std::endl;
    do {
      menu(ch, lattice, contador_vida);
    }while (std::cin >> ch); 
  } else {
    Lattice lattice(datos.tamano, datos.border_type);
    lattice.inicializar();
    char ch;
    bool contador_vida = false;
    std::cout << lattice << std::endl;
    do {
      menu(ch, lattice, contador_vida);
    }while (std::cin >> ch); 
  }
  return 0;
}

void Menu(char ch, Lattice& lattice, bool& contador_vida) {
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
}
