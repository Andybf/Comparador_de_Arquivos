/*
 * Nome:        Comparador > Utils.h
 * Criado por:  Anderson Bucchianico
 * Data:        24 de março de 2019
 * Descrição:   Biblioteca de funções pessoal, usada no programa principal.
 */

#ifndef Utils_h
#define Utils_h

//Inclusão de bibliotecas do C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

#include "Colors.h"

//Variaveis macro
#define MAXBYTES 4294967295

//Definição de funções do arquivo
void            ajuda        (void);
void            sobre        (void);
int             count        (int);
int             negToPosi    (int);
float           negToPosf    (float);
void            separador    (int,int);
void            espacamento  (int,int);
unsigned char*  decToHex     (unsigned int);

#endif /* Utils_h */
