void showTree(tree *arvore,int altura) {
    tree *aux = arvore;
    int elementos = (pow(2,altura));
    elementos--;
    int ordem[elementos],i = 0,atual = 0;
    if (aux == NULL){
      printf("Nao ha arvore carregada\n");
      return;
    }
    printf("Numero de elementos no maximo da arvore de altura %d = %d \n",altura, elementos);
    ordem[i] = aux->value;
    printf("ordem[%d] = %d \n",i, ordem[i]);
    i++;
    while(i < elementos){
        if(ordem[atual] == 0)
        {
          ordem[i] = 0;
          printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
          ordem[i] = 0;
          printf("ordem[%d] = %d \n",i, ordem[i]);
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
          printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
          if (aux->right != NULL)
            ordem[i]= aux->right->value;
          else
            ordem[i] = 0;
          printf("ordem[%d] = %d \n",i, ordem[i]);
          i++;
        }
        atual++;
    }
}
