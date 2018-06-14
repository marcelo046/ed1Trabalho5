void limpaTela() {
  system("clear");
}
void tiraTerminador(char *texto)
{

	if(texto[strlen(texto)-1] == '\n')
	{
		texto[strlen(texto)-1] = '\0';
	}
}
void  limpaBuffer() {
  char lixo;
  do
  {
    scanf("%c",&lixo);
  }while (lixo != '\n');
}
int mostraMenu(){
    int opcao;
    //limpaTela();
    printf(" ========================================\n");
    printf("|         >>>>>>>>> Menu <<<<<<<<<       |\n");
    printf("| 1 - Carregar arvore de arquivo         |\n");
    printf("| 2 - Imprimir arvore                    |\n");
    printf("| 3 - Arvore cheia                       |\n");
    printf("| 4 - Procurar valor                     |\n");
    printf("| 5 - Pegar altura                       |\n");
    printf("| 6 - Remover valor                      |\n");
    printf("| 7 - Imprimir in order                  |\n");
    printf("| 8 - Imprimir pre order                 |\n");
    printf("| 9 - Imprimir post order                |\n");
    printf("| 10 - Balancear arvore                  |\n");
    printf("| 0 - Sair                               |\n");
    printf(" ========================================\n");
    printf("Sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
}

void leCaminhoArquivo(char *caminho){
  int pause;
  char nome[9];
  printf("Nome do arquivo: ");
  limpaBuffer();
  fgets(nome,5,stdin);
  tiraTerminador(nome);
  strcat(nome, ".txt");
  strcpy(caminho, "./BSTs/");
  strcat(caminho, nome);

}

tree* insereArvore(tree *arvore,int valor){
  tree *novo = (tree*)malloc(sizeof(tree));
  tree *aux = arvore;
  tree *ant;
  novo->value = valor;
  novo->left = NULL;
  novo->right = NULL;
  if(arvore == NULL){
    arvore = novo;
  }
  else{
    while(aux != NULL){
      if(valor > aux->value){
        ant = aux;
        aux = aux->right;
      }
      else{
        ant = aux;
        aux = aux->left;
      }
    }
    if(valor > ant->value){
      ant->right = aux;
    }
    else{
      ant->left = aux;
    }
  }
}

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
