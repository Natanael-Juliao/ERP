#include <stdio.h>
#include <string.h>

float markup(float a, float b)
{
    float resultado = ((a / b) - 1) * 100;
    return (resultado);
}

int main()
{
    int menu_principal_opcao, quantidade_produto[10], cont_vetor = 0, recebe_cod_prod[10] = {0}, recebe_quant_venda[10] = {0}, recebe_menu_venda, contador = 0, cont = 0, recebimento;
    char nome_produto[10][10];
    float preco_produto[10], custo_produto[10], total = 0;

    quantidade_produto[cont_vetor];
    recebe_cod_prod[cont_vetor];
    recebe_quant_venda[cont_vetor];
    recebimento;
    nome_produto[cont_vetor][20];
    preco_produto[cont_vetor];
    custo_produto[cont_vetor];

    printf("  --SISTEMA DE GESTAO--\n\n");
    do // Loop menu principal.
    {
        printf("        -MENU-\n\n"); // Menu principal.
        printf("1 - Cadastro de Produtos\n");
        printf("2 - Consultar Estoque\n");
        printf("3 - Venda de Produtos\n");
        printf("4 - Entrada de Produtos\n");
        printf("5 - Logoff\n\n");
        printf("Digite a Opcao Desejada: ");
        scanf("%d", &menu_principal_opcao);
        if (menu_principal_opcao == 1) // Menu cadastro de produtos.
        {
            do // Loop do menu de cadastro de produtos.
            {
                int i = cont_vetor; // cont_vetor está contando os vetores.
                system("cls");
                printf("\n");
                printf("    -CADASTRO-\n\n");
                printf("\nDigite o nome do produto: ");
                scanf("%s", nome_produto[i]);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade_produto[i]);
                printf("Digite o custo do produto: R$ ");
                scanf("%f", &custo_produto[i]);
                printf("Digite o preco de venda do produto: R$ ");
                scanf("%f", &preco_produto[i]);
                cont_vetor++;
                do // Loop do submenu de cadastro (operação de acrescentar mais itens).
                {
                    printf("\nDeseja cadastrar outro produto?\n1 - Sim\n2 - Nao\nDigite a opcao desejada: ");
                    scanf("%d", &menu_principal_opcao);
                    if (menu_principal_opcao == 1)
                    {
                        i++;
                        break;
                    }
                    else if (menu_principal_opcao == 2)
                    {
                        system("cls");
                        break;
                    }
                    else if (menu_principal_opcao != 1 || menu_principal_opcao != 2)
                    {
                        printf("\nOpcao Invalida, tente novamente");
                    }
                } while (menu_principal_opcao != 1 || menu_principal_opcao != 2);

            } while (menu_principal_opcao == 1);
            menu_principal_opcao = 0;
        }

        else if (menu_principal_opcao == 2) // Menu do Estoque.
        {
            system("cls");
            printf("   -ESTOQUE-\n\n");
            for (int i = 0; i < cont_vetor; i++) // Loop para apresentar todo o estoque.
            {
                int a = 0;
                printf("\nCodigo: 000%d", i + 1);
                printf("\nProduto: %s", nome_produto[i]);
                if (cont > 0 && nome_produto[i] != nome_produto[recebe_cod_prod[a] - 1])
                {
                    a++;
                    if (nome_produto[i] != nome_produto[recebe_cod_prod[a] - 1])
                    {
                        while (nome_produto[i] != nome_produto[recebe_cod_prod[a] - 1])
                        {
                            a++;
                        }
                        printf("\nQuantidade: %d", quantidade_produto[i]);
                    }
                    else if (nome_produto[i] == nome_produto[recebe_cod_prod[a] - 1] && nome_produto[recebe_cod_prod[a]] == 0)
                    {
                        printf("\nQuantidade: %d", quantidade_produto[i]);
                    }
                    else if (nome_produto[i] == nome_produto[recebe_cod_prod[a] - 1])
                    {
                        printf("\nQuantidade: %d", quantidade_produto[i] - recebe_quant_venda[a]);
                        quantidade_produto[i] -= recebe_quant_venda[a];
                        // a++;
                    }
                }

                else if (cont > 0 && nome_produto[i] == nome_produto[recebe_cod_prod[a] - 1] && nome_produto[recebe_cod_prod[a]] == 0)
                {
                    printf("\nQuantidade: %d", quantidade_produto[i]);
                }

                else if (nome_produto[i] == nome_produto[recebe_cod_prod[a] - 1])
                {
                    printf("\nQuantidade: %d", quantidade_produto[i] - recebe_quant_venda[a]);
                    quantidade_produto[i] -= recebe_quant_venda[a];
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

        else if (menu_principal_opcao == 3)
        {
            int i = 0;
            contador = 0;
            cont++;
            do
            {
                system("cls");
                printf("     -VENDA-\n");
                printf("\nDigite o codigo do produto: ");
                scanf("%d", &recebe_cod_prod[i]);
                printf("\nProduto: %s", nome_produto[recebe_cod_prod[i] - 1]);
                printf("\nQuantidade Disponivel: %d", quantidade_produto[recebe_cod_prod[i] - 1]);
                printf("\nPreco: R$ %.2f", preco_produto[recebe_cod_prod[i] - 1]);
                do
                {
                    printf("\n\nQuantidade da Venda: ");
                    scanf("%d", &recebe_quant_venda[i]);
                    if (recebe_quant_venda[i] > quantidade_produto[recebe_cod_prod[i] - 1])
                    {
                        printf("\n\nQuantidade Indisponivel!\n\nDigite uma quantidade valida...");
                    }
                } while (recebe_quant_venda[i] > quantidade_produto[recebe_cod_prod[i] - 1]);
                printf("\nDeseja Adicionar mais produtos?\n1 - Sim\n2 - Nao\nDigite a opcao desejada: ");
                scanf("%d", &recebe_menu_venda);
                if (recebe_menu_venda == 1)
                {
                    i++;
                }
            } while (recebe_menu_venda != 2);
            system("cls");
            printf("     -VENDA-\n");
            printf("\n   -CHECKOUT\n");
            printf("Os produtos foram: ");
            do
            {
                printf("\n%s", nome_produto[recebe_cod_prod[i] - 1]);
                if (recebe_quant_venda > 1)
                {
                    printf("\n%d unidades", recebe_quant_venda[i]);
                }
                else
                {
                    printf("\n%d unidade", recebe_quant_venda[i]);
                }

                printf("\nSubtotal: R$ %.2f", recebe_quant_venda[i] * preco_produto[recebe_cod_prod[i] - 1]);
                printf("\n");
                total += ((float)recebe_quant_venda[i] * preco_produto[recebe_cod_prod[i] - 1]);
                i--;
            } while (i >= contador);
            printf("\nTOTAL = R$ %.2f", total);
            printf("\n\n");
            system("pause");
            system("cls");
        }

        else if (menu_principal_opcao == 4)
        {
            char pesquisa_menu[5];
            int quantidade_entrada;
            system("cls");
            printf("    -Entrada de Produtos-\n\n");
            printf("Deseja Pesquisar o Produto? ('Sim'/'Nao'): ");
            scanf("%s", pesquisa_menu);
            if (strcmp(pesquisa_menu, "Sim") == 0)
            {
                system("cls");
                printf("    -Entrada de Produtos-\n\n");
                for (int i = 0; i < cont_vetor; i++)
                {
                    printf(" Codigo: 000%d - Nome: %s - Quantidade: %d\n\n", i + 1, nome_produto[i], quantidade_produto[i]);
                }
                printf("Digite o Codigo do Produto: ");
                scanf("%d", &recebimento);
                printf("\nDigite a Quantidade Para Entrada em Estoque: ");
                scanf("%d", &quantidade_entrada);
                recebimento -= 1;
                quantidade_produto[recebimento] += quantidade_entrada;
                printf("\nNova Quantidade em Estoque: %d", quantidade_produto[recebimento]);
                printf("\n\n");
            }
            else
            {
                system("cls");
                printf("    -Entrada de Produtos-\n\n");
                printf("Digite o Codigo do Produto: ");
                scanf("%d", &recebimento);
                printf("\n Codigo: 000%d - Nome: %s - Quantidade: %d\n\n", recebimento, nome_produto[recebimento - 1], quantidade_produto[recebimento - 1]);
                printf("\n\nDigite a Quantidade Para Entrada em Estoque: ");
                scanf("%d", &quantidade_entrada);
                recebimento -= 1;
                quantidade_produto[recebimento] += quantidade_entrada;
                printf("\nNova Quantidade em Estoque: %d", quantidade_produto[recebimento]);
                printf("\n\n");
            }
            system("pause");
            system("cls");
        }

        else if (menu_principal_opcao == 5) // Condicional para logoff.
        {
            system("cls");
            printf("    -LOGOFF-\n\n");
        }

        else
        {
            system("cls\n");
            printf("  Opcao Indisponivel\n\n  Tente Novamente!\n\n");
            system("pause\n\n");
            system("cls\n");
        }

    } while (menu_principal_opcao != 5);

    return 0;
}