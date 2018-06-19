int maior(int x, int y)
{
  if (x > y)
   return x;
  else
   return y;
}

void balanceTree(tree* arvore)
{
  int altura = getHeight(arvore);

//balance pera esquerda
  tree* no;
  no = arvore->left;
  arvore->left = no->right;
  no->right = arvore;
  arvore->altura = maior(altura(arvore->left), altura(arvore->right))+1;
  no->altura = maior(altura(no->left), arvore->altura+1;
  arvore = no;

}
