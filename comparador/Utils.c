//
//  Utils.c
//  comparador
//
//  Created by Anderson Bucchianico on 24/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#include "Utils.h"

void ajuda(){
    printf("Escrito totalmente em C por:\n    Anderson Bucchianico\n");
    printf("    24 de março de 2019 \n\n");
    
    printf("Versão:\n    Final 1.0 (MacOS)\n\n");
    
    printf("Uso incorreto do programa detectado!\n    Exemplo: \n");
    printf("    ./comparador /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext \n\n");
    
    printf(" - Tamanho máximo permitido por arquivo: 4.294.967.295 bytes (4096 Megabytes).\n");
    printf(" - Você pode arrastar e soltar os arquivos para dentro do terminal para adicioná-los.\n");
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
