void printPostOrder(tree *arvore)
{
  if(arvore == NULL)
  return 0;

  if(*arvore != NULL)
  {
    printPostOrder(&((*arvore)->left));
    printPostOrder(&((*arvore)->right));
    printf("%i\n", (*arvore)->value);
  }
}
