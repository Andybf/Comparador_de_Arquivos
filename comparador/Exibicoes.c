/*
 * Nome:        Comparador > Exibicoes.c
 * Criado por:  Anderson Bucchianico
 * Data:        14 de abril de 2019
 * Descrição:   Responsável por exibir as tabelas de informações para o usuário
 */

#include "Exibicoes.h"

//exibe as permissões de leitura, escrita e execução dos arquivos.
void exibirPermissoes (struct stat *infoArq) {
    int c;
    char words[4][5] = {
        {'r','e','a','d','\0'},
        {'w','r','t','e','\0'},
        {'e','x','e','c','\0'},
        {' ','-','-',' ','\0'},
    };
    printf("\nPermissões dos Arquivos: \n");
    exibirCabecalho();
    printf("| Usuario   |");
    for (c=0; c<2; c++) {
        printf( "   %s ", (infoArq[c].st_mode & S_IRUSR) ? words[0] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IWUSR) ? words[1] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IXUSR) ? words[2] : words[3]);
        printf("  |");
    }
    printf("\n| Grupo     |");
    for (c=0; c<2; c++) {
        printf( "   %s ", (infoArq[c].st_mode & S_IRGRP) ? words[0] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IWGRP) ? words[1] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IXGRP) ? words[2] : words[3]);
        printf("  |");
    }
    printf("\n| Outros    |");
    for (c=0; c<2; c++) {
        printf( "   %s ", (infoArq[c].st_mode & S_IROTH) ? words[0] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IWOTH) ? words[1] : words[3]);
        printf( "%s ",    (infoArq[c].st_mode & S_IXOTH) ? words[2] : words[3]);
        printf("  |");
    }
    printf("\n└-----------┴--------------------┴--------------------┘\n");
}

//Exibe as datas de criação, modificação e último acesso dos arquivos.
void exibirHistorico (struct stat *infoArq) {
    int c;
    char data[19];
    char dataFormat[19] = "%d/%m/%y  %H:%M:%S";
    printf("\nHistórico dos Arquivos:\n");
    exibirCabecalho();
    printf("| Criado    |");
    for (c=0; c<2; c++) {
        strftime(data, sizeof(data), dataFormat, localtime(&(infoArq[c].st_birthtime)));
        printf(" %s |",data);
    }
    printf("\n| Acessado  |");
    for (c=0; c<2; c++) {
        strftime(data, sizeof(data), dataFormat, localtime(&(infoArq[c].st_atime)));
        printf(" %s |",data);
    }
    printf("\n| Alterado  |");
    for (c=0; c<2; c++) {
        strftime(data, sizeof(data), dataFormat, localtime(&(infoArq[c].st_mtime)));
        printf(" %s |",data);
    }
    printf("\n└-----------┴--------------------┴--------------------┘\n");
}

//exibe o tamanho dos arquivos em bytes e a diferença entre eles.
void exibirTamanho (unsigned int *tamArq) {
    int c;
    printf("\nTamanho dos Arquivos:\n");
    exibirCabecalho();
    printf("| bytes     |");
    for (c=0; c<2; c++) {
        espacamento(tamArq[c], 19);
        printf("%d |",tamArq[c]);
    }
    printf("\n| Diferença |                    |");
    espacamento(tamArq[0] - tamArq[1], 12);
    printf(" %d bytes |\n",negToPosi(tamArq[0] - tamArq[1]));
    printf("├-----------┼--------------------┴--------------------┤\n| Conclusão ");
    if (tamArq[0] == tamArq[1]) {
        printf("|   Os arquivos possuem o mesmo tamanho   |\n");
    } else {
        printf("|   Os arquivos têm tamanhos diferentes   |\n");
    }
    printf("└-----------┴-----------------------------------------┘\n");
}

//Mostra a tabela com as comparações feitas entre os arquivos
void exibirConteudo (unsigned int *tamArq, int charDif, float taxaOrig) {
    //Imprime o rodapé
    printf("\nConteúdo dos Arquivos:\n");
    printf("┌--------------------------------┬--------------------┐\n");
    
    printf("| Caracteres Idênticos:          | ");
    espacamento(tamArq[0]-charDif, 18);
    printf("%i |\n",tamArq[0]-charDif);
    
    printf("| Caracteres Diferentes:         |");
    espacamento(charDif, 19);
    printf("%i |\n", charDif);
    
    printf("| Taxa de Originalidade:         |");
    espacamento(taxaOrig, 14);
    printf("%.3f%c |\n",negToPosf(taxaOrig),37);
    
    printf("└--------------------------------┴--------------------┘\n");
}

//Mostra a lista de caracteres diferentes presentes nos arquivos para comparação
void exibirListaChar (unsigned int *tamArq, unsigned char* ch1, unsigned char* ch2) {
    int c;
    printf("\nLista de Comparação dos Arquivos:\n");
    printf("┌--------------┬------------┬------------┐\n");
    printf("|   Endereço   | 1º Arquivo | 2º Arquivo |\n");
    printf("├--------------┼------------┼------------┤\n");
    for (c=0; c<tamArq[0]; c++) {
        if (ch1[c] != ch2[c]) {
            printf("|  0x%s  ",decToHex(c));
            //retorna o caractere formatado a partir da 6ª posição.
            printf("|     %s     ",&decToHex(ch1[c]) [6]);
            printf("|     %s     |\n",&decToHex(ch2[c]) [6]);
        }
    }
    printf("└--------------┴------------┴------------┘\n");
}

void exibirCabecalho () {
    printf("┌-----------┬--------------------┬--------------------┐\n");
    printf("|           |     1º Arquivo     |     2º Arquivo     |\n");
    printf("├-----------┼--------------------┼--------------------┤\n");
}
