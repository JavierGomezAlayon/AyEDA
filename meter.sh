#!/bin/bash

# VARIABLES
DIRECTORIO=./4ºpractica/src/
PROGRAMA=
numero_de_practica="04"
nombre_de_practica="Búsqueda por dispersión"
# PROGRAMAS
#mkdir "$DIRECTORIO"
while [ "$1" != "" ]; do
  PROGRAMA=$1
  shift
  mkdir "$DIRECTORIO""$PROGRAMA"
  touch "$DIRECTORIO"/"$PROGRAMA"/"$PROGRAMA".cc
  cat formatocc.txt | sed \
    -e "s/¬/$PROGRAMA.cc/g" \
    -e "s|\*date*|$(date +%D)|g" \
    -e "s|\*programa_sin_cc|$PROGRAMA|g" \
    -e "s|\*numero|$numero_de_practica|g" \
    -e "s|\*nombre_practica|$nombre_de_practica|g" > "$DIRECTORIO"/"$PROGRAMA"/"$PROGRAMA".cc 
  
  touch "$DIRECTORIO"/"$PROGRAMA"/"$PROGRAMA".h
  cat formatoh.txt | sed -e "s/¬/$PROGRAMA.h/g" -e "s|\*date*|$(date +%D)|g" -e "s|\*programa_sin_cc|$PROGRAMA|g" -e "s|\*numero|$numero_de_practica|g" -e "s|\*nombre_practica|$nombre_de_practica|g" > "$DIRECTORIO"/"$PROGRAMA"/"$PROGRAMA".h
done
#touch "$DIRECTORIO"main.cc
#cat formatocc.txt | sed \
#    -e "s/¬/main.cc/g" \
#    -e "s|\*date*|$(date +%D)|g" \
#    -e "s|\*programa_sin_cc|main|g" \
#    -e "s|\*numero|$numero_de_practica|g" \
#    -e "s|\*nombre_practica|$nombre_de_practica|g" > "$DIRECTORIO"main.cc 
#touch "$DIRECTORIO"../makefile
#cat makefile > "$DIRECTORIO"../makefile