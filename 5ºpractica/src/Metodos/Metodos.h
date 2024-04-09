// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructura de Datos Avanzadas
// Curso: 2º
// Práctica 05 : Algoritmos de ordenación
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/08/24
// Archivo Metodos.h: Declaración de la clase Metodos
//        En este fichero se declara la clase Metodos
// Referencias:
//        Enlaces de interés
//
// Historial de revisiones
//        04/08/24 - Creación (primera versión) del código
# pragma once
#include "../Sequence/Sequence.h"
#include <iostream>
#include "../Nif/Nif.h"

template <typename Key>
void seleccion(staticSequence<Key>& sec, int n, bool imprimirTraza = false) {
  for (int i = 0; i < n - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (sec[j].getValue() < sec[min].getValue()) {
        min = j;
      }
    }
    std::swap(sec[i], sec[min]);
    if (imprimirTraza) {
      std::cout << "Traza en Selección nº " << i + 1 << ": ";
      std::cout << sec << std::endl;
    }
  }
}

template <typename Key>
void quickSort(staticSequence<Key>& sec, int ini, int fin, bool imprimirTraza = false) {
  int i = ini; int f = fin;
  int p = sec[(i + f) / 2].getValue();
  while (i <= f) {
    while (sec[i].getValue() < p) {i++;}
    while (sec[f].getValue() > p) {f--;}
    if (i <= f) {
      std::swap(sec[i], sec[f]);
      i++;
      f--;
    }
  }
  if (ini < f) {
    quickSort(sec, ini, f, imprimirTraza);
    if (imprimirTraza) {
      std::cout << "Traza en quickSort (izquierda): ";
      for (int k = ini; k <= f; ++k) {
        std::cout << sec[k].getValue() << " ";
      }
      std::cout << std::endl;
    }
  }
  if (i < fin) {
    quickSort(sec, i, fin, imprimirTraza);
    if (imprimirTraza) {
      std::cout << "Traza en quickSort (derecha): ";
      std::cout << sec << std::endl;
    }
  }
}

template <typename Key>
void heapSort(staticSequence<Key>& sec, int n, bool imprimirTraza = false) {
  n--;
  for (int i = n / 2; i >= 0; i--) {
    baja(sec, n, i);
  }
  for (int i = n; i > 1; i--) {
    std::swap(sec[1], sec[i]);
    baja(sec, i - 1, 1);
    if (imprimirTraza) {
      std::cout << "Traza en heapSort: ";
      for (int k = 0; k < n + 1; ++k) {
        std::cout << sec[k].getValue() << " ";
      }
      std::cout << std::endl;
    }
  }
}

template <typename Key>
void baja(staticSequence<Key>& sec, int n, int i) {
  while (2 * i + 1<= n) {
    int h1 = 2 * i + 1;
    int h2 = h1 + 1;
    int h;
    if (h1 == n || sec[h1].getValue() > sec[h2].getValue()){
      h = h1;
    } else {
      h = h2;
    }
    if (sec[h].getValue() <= sec[i].getValue()) {
      break;
    } else {
      std::swap(sec[i], sec[h]);
      i = h;
    }
  }
}

template <typename Key>
void shellSort(staticSequence<Key>& sec, int n, bool imprimirTraza = false) {
  int delta = n;
  while (delta > 1) {
    delta = delta / 2;
    for (int i = delta; i < n; i++) {
      int temp = sec[i].getValue();
      int j = i;
      while (j >= delta && temp < sec[j - delta].getValue()) {
        sec[j] = sec[j - delta];
        j -= delta;
      }
      sec[j] = temp;
    }
    if (imprimirTraza) {
      std::cout << "Traza de sec en shellSort (delta = " << delta << "): ";
      for (int k = 0; k < n; ++k) {
        std::cout << sec[k].getValue() << " ";
      }
      std::cout << std::endl;
    }
  }
}

template <typename Key>
int getMax(staticSequence<Key>& sec, int n) {
  int max = sec[0].getValue();
  for (int i = 1; i < n; ++i) {
    if (sec[i].getValue() > max) {
      max = sec[i].getValue();
    }
  }
  return max;
}

template <typename Key>
void countingSort(staticSequence<Key>& sec, int n, int exp, bool imprimirTraza = false) {
  int output[n];
  int count[10] = {0};
  for (int i = 0; i < n; ++i) {
    ++count[(sec[i].getValue() / exp) % 10];
  }
  for (int i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    output[count[(sec[i].getValue() / exp) % 10] - 1] = sec[i].getValue();
    --count[(sec[i].getValue() / exp) % 10];
  }
  for (int i = 0; i < n; ++i) {
    sec[i] = output[i];
  }
  if (imprimirTraza) {
    std::cout << "Traza en countingSort (exp = " << exp << "): ";
    for (int k = 0; k < n; ++k) {
      std::cout << sec[k].getValue() << " ";
    }
    std::cout << std::endl;
  }
}

template <typename Key>
void radixSort(staticSequence<Key>& sec, int n, bool imprimirTraza = false) {
  int max = getMax(sec, n);
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(sec, n, exp, imprimirTraza);
  }
}
