//  Created by Anderson Bucchianico on 19/03/19.

#ifndef Main_h
#define Main_h

//Definição de bibliotecas do C
#include <stdio.h>      // Biblioteca para E/S
#include <string.h>     // Manipulação de Strings
#include <time.h>       // Usado para contar o tempo de execução
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <locale.h>

//Variaveis macro
#define MAXBYTES 4294967295

//Definição de funções da biblioteca Utils
void            ajuda        (void);
int             count        (int);
int             negToPosi    (int);
float           negToPosf    (float);
void            separador    (int,int);
void            espacamento  (int,int);
unsigned char*  decToHex     (unsigned int);

//Definição de cores
void red(void);
void yellow(void);
void green(void);
void blue(void);
void white(void);

#endif /* comparador_h */
