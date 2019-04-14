//
//  Utils.h
//  comparador
//
//  Created by Anderson Bucchianico on 24/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

//Inclusão de bibliotecas do C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

//Variaveis macro
#define MAXBYTES 4294967295

//Definição de funções do arquivo
void            ajuda        (void);
int             count        (int);
int             negToPosi    (int);
float           negToPosf    (float);
void            separador    (int,int);
void            espacamento  (int,int);
unsigned char*  decToHex     (unsigned int);

//definição de cores
void red(void);
void yellow(void);
void green(void);
void blue(void);
void white(void);

#endif /* Utils_h */
