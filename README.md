# Comparador_de_Arquivos
Compara dois arquivos referenciados pelo usuário e mostra em tabelas quantos e quais bytes quais são diferentes entre eles.

Linguagem Usada:
* C
  
Sistema Operacional:
* Testado apenas no MacOS mojave 10.14.3
  
IDE:
* Xcode 10.1

## Compilação ## 

Abra o terminal (Bash) do seu computador, navegue para dentro da pasta onde se localiza o arquivo `makefile` e execute o seguinte comando:

`$ make`

## Execução do programa ## 

Para executar o programa corretamente, referencie o caminho dos dois arquivos a serem comparados separando-os por espaços.
Exemplo:

`$ ./exe /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext`

Você também pode salvar os resultados para dentro de um arquivo executando o programa da seguinte forma:

`$ ./exe /pasta1/pasta2/arquivo.ext /pasta3/pasta4/arquivo2.ext > log.txt`

## Observações ## 

Tamanho máximo recomendado por arquivo:
* 4.294.967.295 bytes (4096 Megabytes)
