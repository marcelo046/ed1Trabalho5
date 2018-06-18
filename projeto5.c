//Alunos: Fabiana Luiza Vasconcelos Pfeilsticker Ribas  16/0005736
//        Joao Pedro Mota Jardim                        16/0031982
//        Marcelo Araujo dos Santos                     16/0035481

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct TREE {
  int value;
  struct TREE *left;
  struct TREE *right;
}tree;

#include "funcoes/todas.h"

int main() {
  char caminho[16];
  tree *arvore = NULL;
  tree *aux;
  int opcao,valor,h,lixo;
  do
  {
    opcao = mostraMenu();
    limparTela();
    switch(opcao)
    {
      case 1:
        arvore = freeArvore(arvore);
        leCaminhoArquivo(caminho);
        arvore = loadTreeFromFile(arvore,caminho);
        break;
      case 2:
        h = getHeight(arvore);
        showTree(arvore,h);
        scanf("%c", &lixo);
        pausar();
        break;
      case 3:
        isFull(arvore);
        scanf("%c", &lixo);
        pausar();
        break;
      case 4:
        leValor(&valor);
        limparTela();
        aux = searchValue(arvore,valor);
        if(aux == NULL){
          printf("Valor nao esta presente na arvore\n");
        }
        else if(aux->value == valor){
          printf("No solicitado: %d\n",aux->value);
          printf("Altura do no: %d\n",pegaAlturaNo(arvore,valor));
          printf("O valor pedido e o inicio da arvore e nao possui pai ou irmaos\n");
        }
        else{
          printf("No solicitado:");
          if(aux->left != NULL){
            if(aux->left->value == valor){
              printf("%d\n",aux->left->value);
              printf("Altura do no: %d\n",pegaAlturaNo(arvore,valor));
              printf("O valor do seu pai e %d e ",aux->value);
              if(aux->right != NULL)
                printf("o valor do seu irmao e %d\n",aux->right->value);
              else
                printf("o no nao possui irmao\n");
            }
          }
          if(aux->right != NULL){ // e o no da direita
            if(aux->right->value == valor){
              printf("%d\n",aux->right->value);
              printf("Altura do no: %d\n",pegaAlturaNo(arvore,valor));
              printf("O valor do seu pai e %d e ",aux->value);
              if(aux->left != NULL)
                printf("o valor do seu irmao e %d\n",aux->left->value);
              else
                printf("o no nao possui irmao\n");
           }
         }
        }
        scanf("%c", &lixo);
        pausar();
        break;
      case 5:
        h = getHeight(arvore);
        printf("A altura da arvore e %d",h);
        break;
      case 6:
        //leValor(&valor);
        //removeValue(arvore,valor);
        break;
      case 7:
        printInOrder(arvore);
        scanf("%c", &lixo);
        pausar();
        break;
      case 8:
        printPreOrder(arvore);
        scanf("%c", &lixo);
        pausar();
        break;
      case 9:
        printf("essa eh a arvore\n\n");
        printPostOrder(arvore);
        scanf("%c", &lixo);
        pausar();
        break;
      case 10:
        //if(!verificaBalanceada(arvore)) // Retorna um int, 0 = nao balanceada, 1 = balanceada
          //balanceTree(arvore);
        break;
      case 0:
        arvore = freeArvore(arvore);
    }
  }while(opcao != 0);
  return 0;
}
