// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo ExplorationFunction.h: Declaración de la clase ExplorationFunction
//        En este fichero se declara la clase ExplorationFunction
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_ExplorationFunction_H
#define C_ExplorationFunction_H

template <typename key>
class ExplorationFunction {
 public:
  ExplorationFunction();
  virtual unsigned ExplorationFunction<Key>::operator()(const Key&, unsigned) const=0;
 private:
 
};



#endif