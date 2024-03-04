
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

// función copiada de internet para hacer las cosas más bonitas y pasar de generación en generación de una forma más cómoda.
#include <termios.h>
#include <unistd.h>
int getch() {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

int main(int argc, char* argv[]) {
  Dato datos = RecogerParametro(argc, argv);
  // Si el cliente puso un fichero se construye el lattice con el fichero.
  if (datos.fichero != "") {
    Lattice lattice(datos.fichero, datos.border_type);
    char ch;
    bool contador_vida = false;
    do {
      system("clear");
      switch (ch) {
        case 'n':
          lattice.nextGeneration();
          if (contador_vida) {
            std::cout << "Población: " << lattice.Population() << std::endl;
          } else {
            std::cout << lattice << std::endl;
          }
          break;
        case 'l':
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
          contador_vida = !contador_vida;
          break;
        case 'x':
          exit(0);
          break;
        case 's':
          lattice.save("save.txt");
          break;
        case 'h':
          std::cout << "introduce n para siguiente generación, l para ver las siguientes 5 generaciones, c para ver la población, s para guardar y x para salir.\n";
          break;
      }
    }while (std::cin >> ch); 
  } else {
    Lattice lattice(datos.tamano, datos.border_type);
    lattice.inicializar();
    do {
      system("clear");
      std::cout << lattice << std::endl;
      std::cout << "Población: " << lattice.Population() << std::endl;
      lattice.nextGeneration();
    }while (getch()); 
  }
  return 0;
}
