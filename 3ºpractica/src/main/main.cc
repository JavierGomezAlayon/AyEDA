
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

int main(int argc, char* argv[]) {
  Dato datos;
  try {
  datos = RecogerParametro(argc, argv);
  } catch (const std::string& error) {
    std::cerr << error << std::endl;
    return 1;
  }
  // Si el cliente puso un fichero se construye el lattice con el fichero.
  if (datos.fichero != "") {
    Lattice lattice(datos.fichero, datos.border_type);
    char ch;
    bool contador_vida = false;
    std::cout << lattice << std::endl;
    do {
      Menu(ch, lattice, contador_vida);
    }while (std::cin >> ch); 
  } else {
    Lattice lattice(datos.tamano, datos.border_type);
    lattice.inicializar();
    char ch;
    bool contador_vida = false;
    std::cout << lattice << std::endl;
    do {
      Menu(ch, lattice, contador_vida);
    }while (std::cin >> ch); 
  }
  return 0;
}


