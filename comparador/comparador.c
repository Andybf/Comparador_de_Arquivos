//  Created by Anderson Bucchianico on 19/03/19.

#include "comparador.h"

//começo do programa
int main(int argc, char** argv){
    
    clock_t t;
    t = clock();
    
    separador(0,1);
    printf("Comparador de Arquivos");
    separador(1,1);
    
    //verifica quantos parametros foram enviados para o programa
    switch(argc){
        case 3:
            break;
        default:
            ajuda();
    }
    
    unsigned int c;
    
    //tenta abrir e informa os arquivos que foram abertos
    FILE *arq[2]; //cria as variaveis de arquivo
    for (c=1; c<=2; c++) {
        if ((arq[c-1] = fopen(argv[c],"r"))){
            printf("%dº arquivo: %s \n",c,argv[c]);
        } else {
            red();
            printf("ERRO:");
            white();
            printf("Não foi possível localizar o %dº arquivo! Você digitou certo?\n",c);
            exit(0);
        }
    }
    
    separador(0,1);
    
    
    //pega o tamanho dos arquivos
    unsigned int tamArq[2];
    for(c=0; c<=1; c++){ // faz duas vezes
        while ((getc(arq[c])) != EOF){
            tamArq[c]++;
        }
        rewind(arq[c]); //rebobinar o ponteiro para o começo do arquivo
    }
    int difbytes = (tamArq[0] - tamArq[1]);
    
    if (tamArq[0] > MAXBYTES || tamArq[1] > MAXBYTES){
        red();
        printf("AVISO: ");
        white();
        printf("O programa só consegue endereçar até 2^32 bytes, ou seja, até %li bytes (4096 Megabytes)",MAXBYTES);
        separador(1, 1);
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
    printf("Tamanho dos arquivos:\n");
    printf("┌--------------┬-------------------------┐\n");
    if (maiorArquivo == 2) {
        printf("|  2º Arquivo  | ");
        formatador(tamArq[0]);
        printf("|  1º Arquivo  | ");
        formatador(tamArq[1]);
    } else {
        printf("|  1º Arquivo  | ");
        formatador(tamArq[0]);
        printf("|  2º Arquivo  | ");
        formatador(tamArq[1]);
    }
    printf("|  Diferença   | ");
    formatador(negToPos(difbytes));
    printf("├--------------┴-------------------------┤\n");
    if (tamArq[0] == tamArq[1]) {
        printf("|  Os arquivos possuem o mesmo tamanho!  |\n");
    } else {
        printf("|  Os arquivos têm tamanhos diferentes!  |\n");
    }
    printf("└----------------------------------------┘");
    
    separador(1,1);
    
    //cria vetores dinamicamente para cada arquivo
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
    
    //imprime o cabeçalho da tabela
    printf("Conteúdo dos Arquivos: (Em hexadecimal)\n");
    printf("┌--------------┬------------┬------------┐\n");
    printf("|   Endereço   | 1º Arquivo | 2º Arquivo |\n");
    printf("├--------------┼------------┼------------┤\n");
    
    //verificando se são iguais
    int charDif = 0;
    for (c=0; c<tamArq[0]; c++) {
        if (ch1[c] != ch2[c]) {
            charDif++;
            printf("|  0x%s  ",decToHex(c));
            printf("|     %s     ",&decToHex(ch1[c])[6]); //retorna o caractere formatado a partir da 4ª posição
            printf("|     %s     |\n",&decToHex(ch2[c])[6]);
        }
    }
    //Imprime o rodapé
    printf("├--------------┴------------┴------------┤\n");
    if (charDif > 99999) {
        printf("|     Caracteres diferentes: %i      |\n",charDif);
    } else if (charDif > 9999) {
        printf("|     Caracteres diferentes: %i       |\n",charDif);
    } else if (charDif > 999){
        printf("|      Caracteres diferentes: %i       |\n",charDif);
    } else if (charDif > 99) {
        printf("|  Total de caracteres diferentes: %i   |\n",charDif);
    } else if (charDif > 9) {
        printf("|   Total de caracteres diferentes: %i   |\n",charDif);
    } else if (charDif < 10) {
        printf("|   Total de caracteres diferentes: %i    |\n",charDif);
    }
    printf("└----------------------------------------┘\n");
    
    printf("Status: ");
    green();
    printf("Finalizado!\n");
    white();
    t = clock() - t;
    double ttaken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Tempo de execução: %.2f segundos\n",ttaken);
    
    separador(0, 1);
    
    return 0;
}
