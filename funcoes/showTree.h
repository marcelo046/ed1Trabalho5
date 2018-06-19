void showTree(tree *arvore,int altura) {
    tree *aux = arvore;
    int elementos = (pow(2,altura));
    elementos--;
    int ordem[elementos],i = 0,atual = 0,numNivel ,cont,j,
    espacosParede = 0,espacosEntre = 3,contAux,aumentaEspaco;
    if (aux == NULL){
      printf("Nao ha arvore carregada\n");
      return;
    }
    //printf("Numero de elementos no maximo da arvore de altura %d = %d \n",altura, elementos);
    ordem[i] = aux->value;
    //printf("ordem[%d] = %d \n",i, ordem[i]);
    i++;
    while(i < elementos){
        if(ordem[atual] == 0)
        {
          ordem[i] = 0;
          //printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
          ordem[i] = 0;
          //printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
        }
        else{
          aux = searchValue(arvore,ordem[atual]);// como estou reaproveitando a funcao searchValue q devolve o pai, devo encontrar o valor novamente
          if(aux->left != NULL){
            if(aux->left->value == ordem[atual])
              aux = aux->left;
          }
          if(aux->right != NULL){
            if(aux->right->value == ordem[atual])
              aux = aux->right;
          }
          if (aux->left != NULL)
            ordem[i]= aux->left->value;
          else
            ordem[i] = 0;
          //printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
          if (aux->right != NULL)
            ordem[i]= aux->right->value;
          else
            ordem[i] = 0;
          //printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
        }
        atual++;
    }
    atual = 1;
    i = 1;
    j = 1;
    numNivel = 2;
    //espacosParede = ((espacosEntre - 1) / 2) + 1;
    aumentaEspaco = ((espacosEntre - 1) / 2) + 1;
    for(cont = 0; cont < (altura-1) ;cont++){
      espacosParede = espacosParede + aumentaEspaco;
      aumentaEspaco = 2*aumentaEspaco;
    }
    for(cont = 0; cont < (altura-1) ;cont++){
      espacosEntre = (2*espacosEntre) + 1;
    }
    //printf("espacos parede: %d\n", espacosParede);
    //printf("espacos entre: %d\n", espacosEntre);
    for(cont = 0;cont < espacosParede;cont++){
      printf(" ");
    }
    printf("%d\n",ordem[0]);
    aumentaEspaco = aumentaEspaco / 2;
    espacosParede = espacosParede - aumentaEspaco;
    aumentaEspaco = aumentaEspaco / 2;
    espacosEntre = espacosEntre - 1;
    espacosEntre = espacosEntre / 2;
    do{
      for(cont = 0;cont < espacosParede;cont++){
        printf(" ");
      }
      for(cont = 0;cont < numNivel;cont++){
        if(j % 2 == 1){
          if(ordem[j] != 0)
            printf("/");
          else
            printf(" ");
        }
        if(j % 2 == 0){
          if(ordem[j] != 0)
            printf("\\");
          else
            printf(" ");
        }
        if(cont < numNivel-1){
          for(contAux = 0; contAux < espacosEntre ;contAux++){
            printf(" ");
          }
        }
        j++;
      }
      printf("\n");
      for(cont = 0;cont < espacosParede;cont++){
        printf(" ");
      }
      for(cont = 0;cont < numNivel;cont++){
        if(i % 2 == 1){
          if(ordem[i] != 0)
            printf("%d",ordem[i]);
          else
            printf(" ");
        }
        if(i % 2 == 0){
          if(ordem[i] != 0)
            printf("%d",ordem[i]);
          else
            printf(" ");
        }
        if(cont < numNivel-1){
          if(ordem[i] >= 10){
            for(contAux = 0; contAux < espacosEntre-1;contAux++){
              printf(" ");
            }
          }
          else{
            for(contAux = 0; contAux < espacosEntre;contAux++){
              printf(" ");
            }
          }
        }
        i++;
      }
      printf("\n");
      numNivel = 2*numNivel;
      //atual++;
      //printf("espacos parede utilizado acima: %d\n", espacosParede);
      //printf("espacos entre utilizado acima: %d\n", espacosEntre);
      espacosParede = espacosParede - aumentaEspaco;
      aumentaEspaco = aumentaEspaco / 2;
      espacosEntre = espacosEntre - 1;
      espacosEntre = espacosEntre / 2;
      //printf("espacos parede: %d\n", espacosParede);
      //printf("espacos entre: %d\n", espacosEntre);
    }while(i < elementos);
}
