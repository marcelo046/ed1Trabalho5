void printPreOrder(tree *arvore)
{
  if(arvore == NULL)
  return 0;

  if(*arvore != NULL)
  {
    printf("%i\n",(*arvore)->value);
    printPreOrder(&((*arvore)->left));
    printPreOrder(&((*arvore)->right));
  }
}
