//  Created by Anderson Bucchianico on 19/03/19.

#ifndef Main_h
#define Main_h

#include <stdio.h> //Biblioteca para E/S
#include <string.h> //Manipulação de Strings
#include <time.h>
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

//utils
void ajuda(void);
int espacamento(int,int);
int separador(int,int);
int count(int);
int negToPos(int);
char* decToHex(int);

//cores
void red(void);
void yellow(void);
void green(void);
void blue(void);
void white(void);

#endif /* comparador_h */
