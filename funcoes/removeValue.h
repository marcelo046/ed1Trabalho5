
tree * removeValue(tree * arvore, int valor) {
  tree *aux = arvore;
  tree *ant;
  tree *folha;

  if (arvore == NULL) {
    printf("arvore esta vazia!\n");
    pausar();
    return arvore;
  }
  // primeiro procuramos o valor
  while(aux->value != valor){
    ant = aux;
    if(valor > aux->value)
      aux = aux->right;
    else
      aux = aux->left;
    if (aux == NULL) {
      printf("valor %d nao foi encontrado!\n\n", valor);
      printf("digite qualquer numero e aperte enter para continuar...\n");
      int pausa;
      scanf("%d", &pausa);
      return arvore;
    }
  }

  // caso o No nao tiver filho
  if ((aux->right == NULL) && (aux->left == NULL)) {
    if(valor > ant->value)
      ant->right = NULL;
    else
      ant->left = NULL;
    free(aux);
  }

  // caso o No tiver filho a esquerda
  if (aux->left != NULL && aux->right == NULL) {
    if (ant->value > valor)
      ant->left = aux->left;
    else
      ant->right = aux->left;
    free(aux);
  }
  // caso o No tiver filho a direita
  if (aux->left == NULL && aux->right != NULL) {
    if (ant->value > valor)
      ant->left = aux->right;
    else
      ant->right = aux->right;
    free(aux);
  }
  //caso o No tiver 2 filhos
  if (aux->left != NULL && aux->right != NULL) {
    //a) Vai para a direita
    folha = aux->right;

    //b) Vai para esquerda
    while (folha->left == NULL || folha->right == NULL) {
      folha = aux->left;
    }

    //i) no_remocao.valor = no.valor
    aux->value = folha->value;

    //ii) remover_folha(no)
    arvore = removeValue(arvore, folha->value);
    printf("removido do meio\n");
    pausar();
  }
  printf("antes de retornar\n");
  pausar();
  return arvore;
}
