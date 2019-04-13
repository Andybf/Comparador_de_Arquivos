//
//  Utils.c
//  comparador
//
//  Created by Anderson Bucchianico on 24/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#include "Utils.h"

void ajuda(){
    printf("Escrito totalmente em C por:\n    Anderson Bucchianico\n\n");
    
    printf("Versão:\n    1.1 - 13 de abril de 2019\n\n");
    
    yellow();
    printf("Uso incorreto do programa detectado!\n");
    white();
    printf("    Exemplo: \n");
    printf("    ./comparador /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext [ -x ]\n\n");
    
    printf(" - Tamanho máximo permitido por arquivo: %ld bytes (4 Gigabytes).\n",MAXBYTES);
    printf(" - Você pode arrastar e soltar os arquivos para dentro do terminal para adicioná-los.\n");
    printf(" - Caso não queira ver a lista de caracteres diferentes use a opção -x no final do comando.\n");
    separador(0,1);
    exit(0);
}

//conta o número de digitos em um int
int count(int num){
    int contagem = 0;
    while(num != 0){
        contagem++;
        num /= 10;
    }
    return contagem;
}

//Transforma o numero negativo para positivo
int negToPos(int num){
    if (num < 0){
        return num -= num + num;
    } else {
        return num;
    }
}

//aplica espaços nas tabelas para manter a formatação
void espacamento(int numero, int espacos){
    int contagem = count(numero);
    if (contagem == 0){ contagem = 1; };
    for (int a=0; a<espacos-contagem; a++) {
        printf(" ");
    }
}

//aplica um separador no console
void separador (int start, int end) {
    //coletando informações sobre a quantidade de colunas no bash
    struct winsize width;
    ioctl(0, TIOCGWINSZ, &width);
    int col = width.ws_col /2;
    //restrições
    if (col == 0) { col = 40; }
    if (col > 60) { col = 60; }
    //aplica uma quebra de linha no começo
    if (start == 1) { printf("\n"); }
    int c;
    for (c=1; c<=col; c++) { //aplica o separador
        printf("- ");;
    }
    if (end == 1) { printf("\n"); }
}

//Transforma um numero decimal para hexadecimal, suporta numeros de até 2^32
unsigned char* decToHex(unsigned int numero) {
    
    static unsigned char hex[9];
    unsigned int resto[8];
    unsigned int result;
    result = numero;
    
    for (int p=7; p>=0; p--) {
        resto[p] = (int) result % 16; //resto da divisão por 16
        result   = (int) result / 16; //dividido por 16
    }
    
    for (int c=7; c>=0; c--) {// este for tem que se repetir quatro vezes apenas.
        switch (resto[c]) {
            case 0:  hex[c] = '0'; break;
            case 1:  hex[c] = '1'; break;
            case 2:  hex[c] = '2'; break;
            case 3:  hex[c] = '3'; break;
            case 4:  hex[c] = '4'; break;
            case 5:  hex[c] = '5'; break;
            case 6:  hex[c] = '6'; break;
            case 7:  hex[c] = '7'; break;
            case 8:  hex[c] = '8'; break;
            case 9:  hex[c] = '9'; break;
            case 10: hex[c] = 'A'; break;
            case 11: hex[c] = 'B'; break;
            case 12: hex[c] = 'C'; break;
            case 13: hex[c] = 'D'; break;
            case 14: hex[c] = 'E'; break;
            case 15: hex[c] = 'F'; break;
        }
    }
    return hex;
}


