//
//  formatBytes.c
//  comparador
//
//  Created by Anderson Bucchianico on 23/03/19.
//  Copyright © 2019 Anderson Bucchianico. All rights reserved.
//

#include "formatBytes.h"

int formatador(int op){
    switch (count(op)) {
        case 1:
            printf("                %d bytes |\n",op);
            break;
        case 2:
            printf("               %d bytes |\n",op);
            break;
        case 3:
            printf("              %d bytes |\n",op);
            break;
        case 4:
            printf("             %d bytes |\n",op);
            break;
        case 5:
            printf("            %d bytes |\n",op);
            break;
        case 6:
            printf("           %d bytes |\n",op);
            break;
        case 7:
            printf("          %d bytes |\n",op);
            break;
        case 8:
            printf("         %d bytes |\n",op);
            break;
        case 9:
            printf("        %d bytes |\n",op);
            break;
        default:
            for (int c=0; c<=15; c++) {
                printf(" ");
            }
            printf("0 bytes |\n");
    }
    return 0;
}
