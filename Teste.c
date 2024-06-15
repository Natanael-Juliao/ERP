else if (menu_principal_opcao == 2) // Menu do Estoque.
        {
            system("cls");
            printf("   -ESTOQUE-\n\n");
            for (int i = 0; i < cont_vetor; i++) // Loop para apresentar todo o estoque.
            {
                // printf("%s\n", nome_produto[recebe_cod_prod[i]-1]);
                // printf("%d\n", recebe_quant_venda[i]);
                int a = 0;
                int verdadeiro = 0;
                printf("\nCodigo: 000%d", i + 1);
                printf("\nProduto: %s", nome_produto[i]);
                if (cont > 0 && nome_produto[recebe_cod_prod[a] - 1] != nome_produto[i])
                {
                    while(verdadeiro==0 || a < cont)
                    {
                        // int i = 0;

                        // printf("\n\n%s\n%s", nome_produto[recebe_cod_prod[i] - 1], nome_produto[i]);
                        /*if (nome_produto[recebe_cod_prod[a] - 1] == nome_produto[i])
                        {
                            printf("\n%s\n", nome_produto[recebe_cod_prod[a]-1]);
                            printf("%d\n", recebe_quant_venda[a]);
                            //printf("\nQuantidade: %d", quantidade_produto[i] - recebe_quant_venda[a]);
                            verdadeiro = 1;
                        }*/
                        /*if (nome_produto[recebe_cod_prod[a] - 1] != nome_produto[i])
                        {*/
                            // printf("\nTrue\n");
                            a++;
                            if(nome_produto[recebe_cod_prod[a] - 1] == nome_produto[i])
                            {
                                //printf("\n%s\n", nome_produto[recebe_cod_prod[a]-1]);
                                //printf("%d\n", recebe_quant_venda[a]);
                                printf("\nQuantidade: %d", quantidade_produto[i] - recebe_quant_venda[a]);
                                verdadeiro = 1;
                            }
                            // printf("%s", nome_produto[recebe_cod_prod[i] - 1]);
                        //}

                    } //while (verdadeiro == 0);
                }
                // printf("\na = %d\n", a);
                //  printf("%s", nome_produto[recebe_cod_prod[a] - 1]);
                //  printf("\n%s\n", nome_produto[recebe_cod_prod[i] - 1]);
                else if(cont > 0 && nome_produto[recebe_cod_prod[a] - 1] == nome_produto[i])
                {
                    printf("\nQuantidade: %d", quantidade_produto[i] - recebe_quant_venda[a]);
                }
                else if (cont == 0)
                {
                    printf("\nQuantidade: %d", quantidade_produto[i]);
                }
                printf("\nPreco de Venda: R$ %.2f", preco_produto[i]);
                printf("\nMarkUp: %.2f\n", markup(preco_produto[i], custo_produto[i]));
            }
            system("\npause");
            system("cls");
        }