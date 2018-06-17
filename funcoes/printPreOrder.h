void printPreOrder(tree *arvore)
{
  if(arvore == NULL)
    ;//return 0;
  else
  {
    printf("%d\n",arvore->value);
    printPreOrder(arvore->left);
    printPreOrder(arvore->right);
  }
}
