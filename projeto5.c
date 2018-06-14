//Alunos: Fabiana Luiza Vasconcelos Pfeilsticker Ribas  16/0005736
//        Joao Pedro Mota Jardim                        16/0031982
//        Marcelo Araujo dos Santos                     16/0035481

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TREE {
  int value;
  struct TREE *left;
  struct TREE *right;
}tree;

#include "funcoes/todas.h"

int main() {
  char caminho[16];
  tree *arvore = NULL;
  int opcao,valor,h;
  do
  {
    opcao = mostraMenu();
    limparTela();
    switch(opcao)
    {
      case 1:
        //freeArvore(l); // verificar se ela ja n esta vazia antes plz
        leCaminhoArquivo(caminho);
        arvore = loadTreeFromFile(arvore,caminho);
        break;
      case 2:
        //showTree(arvore);
        break;
      case 3:
        //isFull(arvore);
        break;
      case 4:
        //leValor(&valor);
        //searchValue(arvore,valor);
        break;
      case 5:
        ;
        h = getHeight(arvore) - 1; // lembrar q ta sempre passando em 1 da altura
        printf("A altura da arvore e %d",h);
        break;
      case 6:
        //leValor(&valor);
        //removeValue(arvore,valor);
        break;
      case 7:
        printInOrder(arvore);
        break;
      case 8:
        printPreOrder(arvore);
        break;
      case 9:
        printf("essa eh a arvore\n\n");
        printPostOrder(arvore);
        pausar();
        break;
      case 10:
        //if(!verificaBalanceada(arvore)) // Retorna um int, 0 = nao balanceada, 1 = balanceada
          //balanceTree(arvore);
        break;
      case 0:
        //freeArvore(l);
        ;
    }
  }while(opcao != 0);
  return 0;
}
