void printInOrder(tree *arvore)
{
  if(arvore == NULL)
  return 0;

  if(*arvore != NULL)
  {
    printInOrder(&((*arvore)->left));
    printf("%i\n", (*arvore)->value);
    printInOrder(&((*arvore)->right));
  }
}
