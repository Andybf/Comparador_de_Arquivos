# Comparador_de_Arquivos
Compara dois arquivos referenciados pelo usuário e mostra em tabelas quantos e quais bytes quais são diferentes entre eles.

Interface:
* Linha de Comando (CLI)

Linguagem Usada:
* C
  
Sistema Operacionais testados:
* macOS Mojave 10.14.4
* iOS 11.4.1
* Linux Ubuntu 18.10

* Pode ser portado para Windows também, embora isso ainda não foi testado.
  
IDE:
* Xcode 10.1

## Compilação ## 

Abra o terminal (Bash) do seu computador, navegue para dentro da pasta onde se localiza o arquivo `makefile` e execute o seguinte comando:

`$ make`

## Execução do programa ## 

Para executar o programa corretamente, referencie o caminho dos dois arquivos a serem comparados separando-os por espaços.
Exemplo:

`$ ./comparador /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext`

Você também pode salvar os resultados para dentro de um arquivo executando o programa da seguinte forma:

`$ ./comparador /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext > log.txt`

## Observações ## 

Tamanho máximo recomendado por arquivo:
* 4.294.967.295 bytes (4096 Megabytes)
