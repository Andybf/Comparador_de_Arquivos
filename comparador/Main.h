/*
 * Nome:        Comparador > Main.h
 * Criado por:  Anderson Bucchianico
 * Data:        19 de março de 2019
 * Descrição:   Inicio do programa onde fica o fluxo principal,
                responsável por receber os arquivos, opções do usuário,
                processar informações e depois exibi-las.
 */


#ifndef Main_h
#define Main_h

//Definição de bibliotecas do C
#include <stdio.h>      // Biblioteca para E/S
#include <string.h>     // Manipulação de Strings
#include <time.h>       // Usado para contar o tempo de execução

//Definição de bibliotecas pessoias
#include "Utils.h"
#include "Colors.h"
#include "Exibicoes.h"

//Variaveis macro
#define MAXBYTES 4294967295

#define PERMISSOES       "-p"
#define HISTORICO        "-h"
#define TAMANHO          "-t"
#define LISTA            "-l"
#define CONTEUDO         "-c"

#endif /* comparador_h */
