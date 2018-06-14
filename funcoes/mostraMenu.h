int mostraMenu(){
    int opcao;
    limpaTela();
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
