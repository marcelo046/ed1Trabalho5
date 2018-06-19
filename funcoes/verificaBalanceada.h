int verificaBalanceada(tree *arvore){
  if(arvore == NULL){
    return 1;
  }
  else
  {
    if(abs(getHeight(arvore->left) - getHeight(arvore->right)) > 1){
      return 0;
    }
    verificaBalanceada(arvore->left);
    verificaBalanceada(arvore->right);
  }
}
