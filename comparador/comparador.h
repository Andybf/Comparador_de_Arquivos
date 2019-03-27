//  Created by Anderson Bucchianico on 19/03/19.

#ifndef comparador_h
#define comparador_h

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAXBYTES 4294967295

void ajuda(void);
int formatador(int);
int separador(int,int);

//utils
int count(int);
int negToPos(int);

//decimal para hexadecimal
char* decToHex(int);

//cores
void red(void);
void yellow(void);
void green(void);
void blue(void);
void white(void);

#endif /* comparador_h */
