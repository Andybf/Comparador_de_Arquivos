//
//  separador.c
//  comparador
//
//  Created by Anderson Bucchianico on 23/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#include "separador.h"

//aplica um separador no console

int separador (int start, int end) {
    
    //coletando informações sobre a quant de colunas no terminal
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int col = w.ws_col /2;
    
    int c;
    if (col == 0) {
        col = 40;
    }
    if (col > 60) {
        col = 60;
    }
    
    if (start == 1) { //aplica uma quebra de linha no começo
        printf("\n");
    }
    for (c=1; c<=col; c++) { //aplica o separador
        printf("- ");;
    }
    if (end == 1) {
        printf("\n");
    }
    
    return 0;
}
