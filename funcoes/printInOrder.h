void printInOrder(tree *arvore)
{
  if(arvore == NULL)
    ;//return 0;
  else
  {
    printInOrder(arvore->left);
    printf("%d\n", arvore->value);
    printInOrder(arvore->right);
  }
}
