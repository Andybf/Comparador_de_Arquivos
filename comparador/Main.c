/*
 * Nome:        Comparador > Main.c
 * Criado por:  Anderson Bucchianico
 * Data:        19 de março de 2019
 * Descrição:   Inicio do programa onde fica o fluxo principal,
                responsável por receber os arquivos, opções do usuário,
                processar informações e depois exibi-las.
*/

#include "Main.h"

//Inicio do Programa.
int main (int argc, char** argv) {
    
    int opcoesAtivadas[5];
    //variavel usada como contador para os laços de repetição
    unsigned int c;
    //cria as variaveis de arquivo
    FILE *arq[2];
    //cria o vetor tamanho do Arquivo de 2 posições, guarda o tamanho de cada arquivo
    unsigned int tamArq[2];
    //Guarda informações sobre o arquivo
    struct stat infoArq[2];
    //aloca espaço na memoria criando vetores dinamicamente para cada arquivo
    unsigned char* ch1 = NULL;
    unsigned char* ch2 = NULL;
    int charDif = 0;
    float taxaOrig = 0.0;
    int maiorArq = 0;
    
    clock_t tempoDeExecucao = clock();

    separador(0,1);
    printf("Comparador de Arquivos\n");
    
    //verifica quantos parametros foram enviados para o programa
    if (argc == 1) {
        sobre();
    }
    if (argc < 4) {
        red();
        printf("\nERRO:");
        white();
        printf(" O número de parâmetros passados é insuficiente, insira pelo menos 4 parâmetros!\n\n");
        ajuda();
    }
    for (c=1; c<argc-2; c++) {
        if         (strcmp(argv[c],PERMISSOES)  == 0) {
            opcoesAtivadas[0] = 1;
        }
        else if    (strcmp(argv[c],HISTORICO)   == 0) {
            opcoesAtivadas[1] = 1;
        }
        else if     (strcmp(argv[c],TAMANHO)    == 0) {
            opcoesAtivadas[2] = 1;
        }
        else if    (strcmp(argv[c],LISTA)    == 0) {
            opcoesAtivadas[3] = 1;
        }
        else if      (strcmp(argv[c],CONTEUDO)     == 0) {
            opcoesAtivadas[4] = 1;
        }
        else {
            red();
            printf("\nERRO:");
            white();
            printf(" Os parâmetros passados estão incorretos!\n\n");
            ajuda();
        }
    }
    
    //tenta abrir e informa os arquivos que foram abertos
    for (c=0; c<2; c++) {
        if ((arq[c] = fopen(argv[argc-2+c],"r"))) {
            printf("%dº arquivo: %s \n",c+1,argv[argc-2+c]);
        } else {
            red();
            printf("\nERRO:");
            white();
            printf(" Não foi possível localizar o %dº arquivo! Você digitou certo?\n\n",c+1);
            ajuda();
        }
    }
    
    // pega o tamanho do arquivo
    for(c=0; c<2; c++){
        if (stat(argv[argc-2+c],&infoArq[c]) == 0) {
            tamArq[c] = (int) infoArq[c].st_size;
        } else {
            red();
            printf("\nERRO:");
            white();
            printf(" Não foi possível obter informações do %dº arquivo!\n\n",c+1);
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
    if ((strcmp(argv[argc+1],argv[argc+2])) == 0) {
        yellow();
        printf("\nAVISO: ");
        white();
        printf("Você está pedido para comparar arquivos iguais que possuem o mesmo nome e caminho, logicamente o resultado será zero.\n");
    }
    
    if (opcoesAtivadas[3] == 1 || opcoesAtivadas[4] == 1) {
        ch1 = (unsigned char*) malloc(tamArq[0] * sizeof(char));
        ch2 = (unsigned char*) malloc(tamArq[1] * sizeof(char));
        
        //preenche o 1º array criado anteriormente
        for(c=0; c<tamArq[0]; c++){
            ch1[c] = fgetc(arq[0]);
        }
        //preenche o 2º array
        for(c=0; c<tamArq[1]; c++){
            ch2[c] = fgetc(arq[1]);
        }
        
        if (tamArq[1] > tamArq[0]) {
            maiorArq = 1;
        }
        
        //Faz a contagem de quantos caracteres são diferentes
        for (c=0; c<tamArq[maiorArq]; c++) {
            if (ch1[c] != ch2[c]) {
                charDif++;
            }
        }
        
        taxaOrig = 100-((float)(charDif*100)/tamArq[0]);
    }
    
    //fechando os arquivos pois não será mais usado
    fclose(arq[0]);
    fclose(arq[1]);
    
    if (opcoesAtivadas[0] == 1) {
        exibirPermissoes(infoArq);
    }
    if (opcoesAtivadas[1] == 1) {
        exibirHistorico(infoArq);
    }
    if (opcoesAtivadas[2] == 1) {
        exibirTamanho(tamArq);
    }
    if (opcoesAtivadas[3] == 1) {
        exibirListaChar(tamArq,ch1,ch2);
    }
    if (opcoesAtivadas[4] == 1) {
        exibirConteudo(tamArq,charDif,taxaOrig);
    }
    
    printf("Status: ");
    green();
    printf("Finalizado!\n");
    white();
    
    tempoDeExecucao = clock() - tempoDeExecucao;
    printf("Tempo de execução: %.2f segundos\n",( (double) tempoDeExecucao ) / CLOCKS_PER_SEC );
    
    separador(0, 1);
    
    return 0;
}
