#include <stdio.h>
#include <string.h>

float markup(float a, float b)
{
    float resultado = ((a / b) - 1) * 100;
    return (resultado);
}

int main()
{
    int menu_principal_opcao, quantidade_produto[10] = {0}, cont_vetor = 0, recebe_cod_prod[10] = {0}, recebe_quant_venda[10] = {0}, recebe_menu_venda, contador = 0, cont = 0, recebimento, contador_custo[10] = {0};
    char nome_produto[10][10];
    float preco_produto[10] = {0}, custo_produto[10] = {0}, total = 0, mkp_produto[10];

    quantidade_produto[cont_vetor];
    recebe_cod_prod[cont_vetor];
    recebe_quant_venda[cont_vetor];
    recebimento;
    nome_produto[cont_vetor][20];
    preco_produto[cont_vetor];
    custo_produto[cont_vetor];
    mkp_produto[cont_vetor];

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
                int i = cont_vetor;
                int divisao; // cont_vetor está contando os vetores.
                system("cls");
                printf("\n");
                printf("    -CADASTRO-\n\n");
                printf("\nDigite o nome do produto: ");
                scanf("%s", nome_produto[i]);
                printf("Digite o MarkUp Desejado: ");
                scanf("%f", &mkp_produto[i]);
                cont_vetor++;
                do // Loop do submenu de cadastro (operação de cadastrar mais itens).
                {
                    printf("\nProduto Cadastrado Com Sucesso!\n\nDeseja cadastrar outro produto?\n1 - Sim\n2 - Nao\nDigite a opcao desejada: ");
                    scanf("%d", &menu_principal_opcao);
                    if (menu_principal_opcao == 1) // Menu Cadastro do Produto.
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
                // int a = 0;
                printf("\nCodigo: 000%d", i + 1);
                printf("\nDescricao: %s", nome_produto[i]);
                printf("\nQuantidade em Estoque: %d", quantidade_produto[i]);
                printf("\nPreco de Venda: R$ %.2f", preco_produto[i]);
                if (markup(preco_produto[i], custo_produto[i]) > 0 && markup(preco_produto[i], custo_produto[i]) <= 100)
                {
                    printf("\nMarkUp: %.2f\n", markup(preco_produto[i], custo_produto[i]));
                }
                else
                {
                    printf("\nMarkUp: 0\n");
                }
            }
            system("pause");
            system("cls");
        }

        else if (menu_principal_opcao == 3) // Menu de Venda.
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
                quantidade_produto[i] -= recebe_quant_venda[i];
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
                printf("\n%d unidades", recebe_quant_venda[i]);
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

        else if (menu_principal_opcao == 4) // Menu de Entrada de Produto.
        {
            char pesquisa_menu[5];
            int quantidade_entrada;
            float recebe_custo;
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
                do
                {
                    printf("Digite o Codigo do Produto: ");
                    scanf("%d", &recebimento);
                    printf("\nDigite a Quantidade Para Entrada em Estoque: ");
                    scanf("%d", &quantidade_entrada);
                    recebimento -= 1;
                    quantidade_produto[recebimento] += quantidade_entrada;
                    printf("Digite o Custo do Produto: R$ ");
                    scanf("%f", &recebe_custo);
                    if (contador_custo[recebimento] == 0)
                    {
                        custo_produto[recebimento] += recebe_custo;
                        contador_custo[recebimento] = 1;
                    }
                    else
                    {
                        custo_produto[recebimento] = ((custo_produto[recebimento] * (quantidade_produto[recebimento] - quantidade_entrada)) + (recebe_custo * quantidade_entrada)) / quantidade_produto[recebimento];
                    }

                    preco_produto[recebimento] = (custo_produto[recebimento] * (mkp_produto[recebimento] / 100)) + custo_produto[recebimento];
                    printf("\n\nConfirma a operacao?\n1 - Sim\n2- Nao\nDigite a opcao desejada: ");
                    scanf("%d", &recebe_menu_venda);
                    if (recebe_menu_venda == 1)
                    {
                        break;
                    }
                    else if (recebe_menu_venda == 2)
                    {
                        printf("\nPor favor, refaca a operacao!");
                        system("cls");
                        break;
                    }
                } while (recebe_menu_venda != 1);
            }
            else
            {
                do
                {
                    printf("Digite o Codigo do Produto: ");
                    scanf("%d", &recebimento);
                    printf("\nDigite a Quantidade Para Entrada em Estoque: ");
                    scanf("%d", &quantidade_entrada);
                    recebimento -= 1;
                    quantidade_produto[recebimento] += quantidade_entrada;
                    printf("Digite o Custo do Produto: R$ ");
                    scanf("%f", &recebe_custo);
                    if (contador_custo[recebimento] == 0)
                    {
                        custo_produto[recebimento] += recebe_custo;
                        contador_custo[recebimento] = 1;
                    }
                    else
                    {
                        custo_produto[recebimento] = ((custo_produto[recebimento] * (quantidade_produto[recebimento] - quantidade_entrada)) + (recebe_custo * quantidade_entrada)) / quantidade_produto[recebimento];
                    }

                    preco_produto[recebimento] = (custo_produto[recebimento] * (mkp_produto[recebimento] / 100)) + custo_produto[recebimento];
                    printf("\n\nConfirma a operacao?\n1 - Sim\n2- Nao\nDigite a opcao desejada: ");
                    scanf("%d", &recebe_menu_venda);
                    if (recebe_menu_venda == 1)
                    {
                        break;
                    }
                    else if (recebe_menu_venda == 2)
                    {
                        printf("\nPor favor, refaca a operacao!");
                        system("cls");
                        break;
                    }
                } while (recebe_menu_venda != 1);
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