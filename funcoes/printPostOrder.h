void printPostOrder(tree *arvore)
{
  if(arvore != NULL)
  {
    printPostOrder(arvore->left);
    printPostOrder(arvore->right);
    printf("%i\n", arvore->value);
  }
}
