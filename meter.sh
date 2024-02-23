#!/bin/bash

# VARIABLES
DIRECTORIO=./2ºpractica/
PROGRAMA=
numero_de_practica="02"
nombre_de_practica="Autómata celular elemental"
# PROGRAMAS
#mkdir "$DIRECTORIO"
while [ "$1" != "" ]; do
  PROGRAMA=$1
  shift
  touch "$DIRECTORIO""$PROGRAMA".cc
  cat formatocc.txt | sed \
    -e "s/¬/$PROGRAMA.cc/g" \
    -e "s|\*date*|$(date +%D)|g" \
    -e "s|\*programa_sin_cc|$PROGRAMA|g" \
    -e "s|\*numero|$numero_de_practica|g" \
    -e "s|\*nombre_practica|$nombre_de_practica|g" > "$DIRECTORIO""$PROGRAMA".cc 
  
  touch "$DIRECTORIO""$PROGRAMA".h
  cat formatoh.txt | sed -e "s/¬/$PROGRAMA.h/g" -e "s|\*date*|$(date +%D)|g" -e "s|\*programa_sin_cc|$PROGRAMA|g" -e "s|\*numero|$numero_de_practica|g" -e "s|\*nombre_practica|$nombre_de_practica|g" > "$DIRECTORIO""$PROGRAMA".h
  #touch "$DIRECTORIO""$PROGRAMA"/Makefile
  #cat Makefile | sed -e "s/¬/$PROGRAMA.cc/g" -e "s|\*programa_sin_cc|$PROGRAMA|g" > "$DIRECTORIO""$PROGRAMA"/Makefile 
done
#touch "$DIRECTORIO"makefile
#cat makefile > "$DIRECTORIO"makefile