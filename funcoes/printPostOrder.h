void printPostOrder(tree *arvore)
{
  if(arvore != NULL)
  {
    printPostOrder(arvore->left);
    printPostOrder(arvore->right);
    printf("%d\n", arvore->value);
  }
}
