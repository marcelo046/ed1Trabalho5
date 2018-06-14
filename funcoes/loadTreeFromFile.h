tree* loadTreeFromFile(tree *arvore,char *caminho){
  //Declarações
  FILE *p_arq;
  int pause,valor;
  //Instruções

  if ((p_arq=fopen(caminho,"r"))==NULL)
  {
      limpaTela();
      printf("nao foi possivel encontrar a arvore\n\n\n\n");
      return NULL;
  }
  else
  {
    while((fscanf(p_arq,"%d ", &valor)) != EOF)
    {
       //fscanf(p_arq,"%d ", &valor);
       //fscanf(p_arq,"%d ",
       //&temp.value);
       arvore = insereArvore(arvore,valor);
       //printf("%d ",valor);
    }
    //scanf("%d\n",&pause );
    fclose(p_arq);
    return arvore;
  }
}
