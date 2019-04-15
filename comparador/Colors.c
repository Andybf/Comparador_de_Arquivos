/*
 * Nome:        Comparador > Colors.c
 * Criado por:  Anderson Bucchianico
 * Data:        24 de março de 2019
 * Descrição:   Biblioteca de cores e efeitos gráficos para o terminal
 */

#include "Colors.h"

void black(){
    printf("\033[1;30m");
}

void red(){
    printf("\033[1;31m");
}

void yellow(){
    printf("\033[1;33m");
}

void green(){
    printf("\033[1;32m");
}

void blue(){
    printf("\033[1;34m");
}

void white(){
    printf("\033[0m");
}


