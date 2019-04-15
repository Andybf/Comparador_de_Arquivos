/*
 * Nome:        Comparador > Exibicoes.h
 * Criado por:  Anderson Bucchianico
 * Data:        14 de abril de 2019
 * Descrição:   Responsável por exibir as tabelas de informações para o usuário
 */

#ifndef Exibicoes_h
#define Exibicoes_h

//Definição de bibliotecas do C
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

//Definição de bibliotecas pessoias
#include "Utils.h"

//exibe as permissões de leitura, escrita e execução dos arquivos.
void exibirPermissoes (struct stat*);

//Exibe as datas de criação, modificação e último acesso dos arquivos.
void exibirHistorico (struct stat*);

//exibe o tamanho dos arquivos em bytes e a diferença entre eles.
void exibirTamanho (unsigned int*);

//Mostra a lista de caracteres diferentes presentes nos arquivos para comparação
void exibirListaChar (unsigned int*, unsigned char*, unsigned char*);

//Mostra o resultado da comparação caractere por caractere
void exibirConteudo (unsigned int*,int,float);

void exibirCabecalho(void);

#endif /* Exibicoes_h */
