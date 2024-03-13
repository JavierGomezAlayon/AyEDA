// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 04 : Búsqueda por dispersión
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/12/24
// Archivo DispersionFunction.h: Declaración de la clase DispersionFunction
//        En este fichero se declara la clase DispersionFunction
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        03/12/24 - Creación (primera versión) del código
#ifndef C_DispersionFunction_H
#define C_DispersionFunction_H

template <typename Key>
class DispersionFunction {
 public:
  DispersionFunction();
  virtual unsigned operator()(const Key&) const = 0;
 private:
 
};



#endif