//
//  main.c
//  dectohex
//
//  Created by Anderson Bucchianico on 21/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#include "decToHex.h"

//Converte numeros decimais para código hexadecimal em maiúsculas

/* Observações
 *  Na declaração da função é necessário colocar um ponteiro * para
 *  que se retorne uma string ao invés de aprenas um caractere.
 *  É necessario declarar a variavel de retorno como static, para
 *  que o conteúdo dela seja acessado mesmo após o término da função
*/

unsigned char* decToHex(unsigned int numero){
    
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
            case 0: hex[c] = '0';
                break;
            case 1: hex[c] = '1';
                break;
            case 2: hex[c] = '2';
                break;
            case 3: hex[c] = '3';
                break;
            case 4: hex[c] = '4';
                break;
            case 5: hex[c] = '5';
                break;
            case 6: hex[c] = '6';
                break;
            case 7: hex[c] = '7';
                break;
            case 8: hex[c] = '8';
                break;
            case 9: hex[c] = '9';
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
