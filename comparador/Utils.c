/*
 * Nome:        Comparador > Utils.c
 * Criado por:  Anderson Bucchianico
 * Data:        24 de março de 2019
 * Descrição:   Biblioteca de funções pessoal, usada no programa principal.
 */

#include "Utils.h"

void ajuda(){
    printf("    Ajuda: \n");
    printf("    ./comparador [ -p -h -t -c -l ] arquivo.ext arquivo2.ext\n\n");
    
    printf("    -p    Exibe tabela de permissões\n");
    printf("    -h    Exibe tabela de histórico\n");
    printf("    -t    Exibe tabela de tamanhos\n");
    printf("    -l    Exibe a lista de caracteres diferentes\n");
    printf("    -c    Exibe tabela de caracteres diferentes\n\n");
    
    printf("Tamanho máximo permitido por arquivo: %ld bytes (4 Gigabytes).\n",MAXBYTES);
    printf("Você pode arrastar e soltar os arquivos para dentro do terminal para adicioná-los.\n");
    separador(0,1);
    exit(0);
}

void sobre () {
    printf("\nDesenvolvido por:\n    Anderson Bucchianico\n\n");
    
    printf("E-mail:\n    anderson584bf@gmail.com\n\n");
    
    printf("Versão:\n    1.2 - 15 de abril de 2019\n");
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
int negToPosi(int num){
    if (num < 0){
        return num -= num + num;
    } else {
        return num;
    }
}
float negToPosf(float num) {
    if (num < 0){
        return num -= num + num;
    } else {
        return num;
    }
    return num;
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
    int c;
    int colunas;
    //coletando informações sobre a quantidade de colunas no bash
    struct winsize width;
    
    ioctl(0, TIOCGWINSZ, &width);
    colunas = width.ws_col /2;
    
    if (colunas == 0) {
        colunas = 40;
    }
    if (colunas > 60) {
        colunas = 60;
    }
    if (start == 1) {
        printf("\n");
    }
    for (c=1; c<=colunas; c++) {
        printf("- ");;
    }
    if (end == 1) {
        printf("\n");
    }
}

//Transforma um numero decimal para hexadecimal, suporta numeros de até 2^32
unsigned char* decToHex(unsigned int numero) {
    
    static unsigned char hex[9];
    unsigned int resto[8];
    unsigned int result;
    int c;
    
    result = numero;
    
    for (c=7; c>=0; c--) {
        resto[c] = (int) result % 16;
        result   = (int) result / 16;
    }
    
    for (c=7; c>=0; c--) {
        switch (resto[c]) {
            case 0:  hex[c] = '0';
                break;
            case 1:  hex[c] = '1';
                break;
            case 2:  hex[c] = '2';
                break;
            case 3:  hex[c] = '3';
                break;
            case 4:  hex[c] = '4';
                break;
            case 5:  hex[c] = '5';
                break;
            case 6:  hex[c] = '6';
                break;
            case 7:  hex[c] = '7';
                break;
            case 8:  hex[c] = '8';
                break;
            case 9:  hex[c] = '9';
                break;
            case 10: hex[c] = 'A';
                break;
            case 11: hex[c] = 'B';
                break;
            case 12: hex[c] = 'C';
                break;
            case 13: hex[c] = 'D';
                break;
            case 14: hex[c] = 'E';
                break;
            case 15: hex[c] = 'F';
                break;
        }
    }
    return hex;
}
