void printPreOrder(TREE *arvore)
{
  if(arvore == NULL)
  return 0;
  if(*arvore == NULL)
  return 0;

  if(*arvore != NULL)
  {
    printf("%d\n",(*arvore)->value);
    printPreOrder(&((*arvore)->left));
    printPreOrder(&((*arvore)->right));
  }
}
