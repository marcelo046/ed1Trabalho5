tree* insereArvore(tree *arvore,int valor){
  tree *novo = (tree*)malloc(sizeof(tree));
  tree *aux = arvore;
  tree *ant;
  novo->value = valor;
  novo->left = NULL;
  novo->right = NULL;
  if(arvore == NULL){
    arvore = novo;
    return novo;
  }
  else{
    while(aux != NULL){
      if(valor > aux->value){
        ant = aux;
        aux = aux->right;
      }
      else{
        ant = aux;
        aux = aux->left;
      }
    }
    if(valor > ant->value){
      ant->right = novo;
    }
    else{
      ant->left = novo;
    }
  }
  return arvore;
}
