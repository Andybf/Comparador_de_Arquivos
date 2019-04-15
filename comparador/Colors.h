/*
 * Nome:        Comparador > Colors.h
 * Criado por:  Anderson Bucchianico
 * Data:        24 de março de 2019
 * Descrição:   Biblioteca de cores e efeitos gráficos para o terminal
 */

#ifndef Colors_h
#define Colors_h

#include <stdio.h>

//Cores de texto
#define PRETO    30
#define VERMELHO 31
#define VERDE    32
#define AMARELO  33
#define AZUL     34
#define MAGENTA  35
#define CIANO    36
#define BRANCO   37

//Tipos de exibição
#define NORMAL        1
#define TRANSPARENTE  2
#define ITALICO       3
#define SUBLINHADO    4
#define PISCANTE      5
#define INVERTER      7

void black  (void);
void red    (void);
void yellow (void);
void green  (void);
void blue   (void);
void white  (void);

#endif /* Cores_h */
