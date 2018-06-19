
tree * removeValue(tree * arvore, int valor) {
  tree *aux = arvore;
  tree *ant;

  // primeiro procuramos o valor
  while(aux->value != valor && aux != NULL){
    ant = aux;
    if(valor > aux->value)
      aux = aux->right;
    else
      aux = aux->left;
  }
  // caso nao tiver encontrado o valor
  if (aux == NULL) {
    printf("valor %d nao foi encontrado!\n", valor);
    pausar();
    return arvore;
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
  //****************
  return arvore;
}
