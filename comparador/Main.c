//  Created by Anderson Bucchianico on 19/03/19.

#include "Main.h"

int main (int argc, char** argv) {
    
    //usado para medir o tempo de execução do programa
    clock_t tempoExecucao = clock();

    separador(0,1);
    printf("Comparador de Arquivos\n");
    
    int OpcaoSemHex = 0;
    
    //verifica quantos parametros foram enviados para o programa
    switch(argc){
        case 3:
            break;
        case 4:
            if (strcmp(argv[3],"-x") == 0) {
                OpcaoSemHex = 1;
            } else {
                ajuda();
            }
            break;
        default:
            ajuda();
    }
    
    //variavel usada como contador para os laços de repetição
    unsigned int c;
    
    //tenta abrir e informa os arquivos que foram abertos
    FILE *arq[2]; //cria as variaveis de arquivo
    for (c=1; c<=2; c++) {
        if ((arq[c-1] = fopen(argv[c],"r"))) {
            printf("\n%dº arquivo: %s \n",c,argv[c]);
        } else {
            red();
            printf("\nERRO:");
            white();
            printf(" Não foi possível localizar o %dº arquivo! Você digitou certo?\n",c);
            exit(0);
        }
    }
    
    //cria o vetor tamanho do Arquivo de 2 posições, guarda o tamanho de cada arquivo
    unsigned int tamArq[2];
    struct stat infoArq;
    
    for(c=1; c<=2; c++){ // faz duas vezes
        if (stat(argv[c],&infoArq) != -1) {
            tamArq[c-1] = (int) infoArq.st_size;
        }
    }
    
    //Se os arquivos forem maiores do que 4GB
    if (tamArq[0] > MAXBYTES || tamArq[1] > MAXBYTES) {
        yellow();
        printf("\nAVISO: ");
        white();
        printf("O programa só consegue endereçar até 2^32 bytes, ou seja, até %li bytes (4GB Gigabytes)",MAXBYTES);
        separador(1, 1);
    }
    
    //se os arquivos forem iguais ao serem comparados
    if ((strcmp(argv[1],argv[2])) == 0) {
        yellow();
        printf("\nAVISO: ");
        white();
        printf("Você está pedido para comparar arquivos iguais que possuem o mesmo nome e caminho, logicamente o resultado será zero.\n");
    }
    
    //deixa o 1º arquivo como sendo o maior em tamanho
    int maiorArquivo = 1;
    if (tamArq[1] > tamArq[0]) {
        maiorArquivo = 2;
        tamArq[0] += tamArq[1];
        tamArq[1] = tamArq[0] - tamArq[1];
        tamArq[0] -= tamArq[1];
    }
    
    //informa o tamanho dos arquivos
    printf("\nTamanho dos arquivos:\n");
    printf("┌--------------┬-------------------------┐\n");
    if (maiorArquivo == 2) {
        printf("|  2º Arquivo  | ");
        espacamento(tamArq[0], 16);
        printf(" %d bytes |\n",tamArq[0]);
        
        printf("|  1º Arquivo  | ");
        espacamento(tamArq[1], 16);
        printf(" %d bytes |\n",tamArq[1]);
    } else {
        printf("|  1º Arquivo  | ");
        espacamento(tamArq[0], 16);
        printf(" %d bytes |\n",tamArq[0]);
        
        printf("|  2º Arquivo  | ");
        espacamento(tamArq[1], 16);
        printf(" %d bytes |\n",tamArq[1]);
    }
    printf("|  Diferença   | ");
    espacamento(tamArq[0] - tamArq[1], 16);
    printf(" %d bytes |\n",negToPos(tamArq[0] - tamArq[1]));
    
    printf("├--------------┴-------------------------┤\n");
    if (tamArq[0] == tamArq[1]) {
        printf("|  Os arquivos possuem o mesmo tamanho!  |\n");
    } else {
        printf("|  Os arquivos têm tamanhos diferentes!  |\n");
    }
    printf("└----------------------------------------┘\n");
    
    //aloca espaço na memoria criando vetores dinamicamente para cada arquivo
    unsigned char* ch1 = (unsigned char*) malloc(tamArq[0] * sizeof(char));
    unsigned char* ch2 = (unsigned char*) malloc(tamArq[1] * sizeof(char));
    
    //preenche o 1º array criado anteriormente
    for(c=0; c<tamArq[0]; c++){
        ch1[c] = fgetc(arq[0]);
    }
    //preenche o 2º array
    for(c=0; c<tamArq[1]; c++){
        ch2[c] = fgetc(arq[1]);
    }
    
    //fechando os arquivos pois não será mais usado
    fclose(arq[0]);
    fclose(arq[1]);
    
    printf("\nConteúdo dos Arquivos:\n");
    
    //verificando se são iguais
    int charDif = 0;
    if (OpcaoSemHex == 0) {
        //imprime o cabeçalho da tabela
        printf("┌--------------┬------------┬------------┐\n");
        printf("|   Endereço   | 1º Arquivo | 2º Arquivo |\n");
        printf("├--------------┼------------┼------------┤\n");
        for (c=0; c<tamArq[0]; c++) {
            if (ch1[c] != ch2[c]) {
                charDif++;
                printf("|  0x%s  ",decToHex(c));
                printf("|     %s     ",&decToHex(ch1[c]) [6]); //retorna o caractere formatado a partir da 6ª posição
                printf("|     %s     |\n",&decToHex(ch2[c]) [6]);
            }
        }
        printf("├--------------┴------------┴------------┤\n");
    } else {
        for (c=0; c<tamArq[1]; c++) {
            if (ch1[c] != ch2[c]) {
                charDif++;
            }
        }
        printf("┌----------------------------------------┐\n");
    }
    //Imprime o rodapé
    printf("| Caracteres Idênticos: ");
    espacamento(tamArq[0]-charDif, 16);
    printf("%i |\n",tamArq[0]-charDif);
    
    printf("| Caracteres Diferentes: ");
    espacamento(charDif, 15);
    printf("%i | \n", charDif);
    
    printf("| Taxa de Originalidade: ");
    float txOrig = 100-((float)(charDif*100)/tamArq[1]);
    espacamento(txOrig, 10);
    printf("%.3f%c |\n",txOrig,37);
    
    printf("└----------------------------------------┘\n");
    
    printf("Status: ");
    green();
    printf("Finalizado!\n");
    white();
    
    tempoExecucao = clock() - tempoExecucao;
    printf("Tempo de execução: %.2f segundos\n",( (double) tempoExecucao ) / CLOCKS_PER_SEC );
    
    separador(0, 1);
    
    return 0;
}
