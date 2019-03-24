//  Created by Anderson Bucchianico on 19/03/19.

#ifndef comparador_h
#define comparador_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXBYTES 4294967295

void ajuda(void);
int formatador(int);
int separador(int,int);
int count(int);
int negToPos(int);

char* decToHex(int);

#endif /* comparador_h */
