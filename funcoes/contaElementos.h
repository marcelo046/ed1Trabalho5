void contaElementos(tree *arvore,int *elementos)
{
  if(arvore == NULL)
    ;//return 0;
  else
  {
    *elementos = *elementos + 1;
    contaElementos(arvore->left,elementos);
    contaElementos(arvore->right,elementos);
  }
}
