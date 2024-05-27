#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int qtde_est[5], menu1_option, opt1, a = 0, contador = 0, recebe = 0;
    char nome_prod[10][10];
    float preco_v[5], custo[5];

    printf("  --SISTEMA DE GESTAO--\n\n");

    nome_prod[contador][10];
    qtde_est[contador];
    preco_v[contador];
    custo[contador];

    do
    {
        printf("\n");
        printf("        -MENU-\n\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Consultar Estoque\n");
        printf("3 - Efetuar Venda\n");
        printf("4 - Logoff\n\n");
        printf("Digite a Opcao Desejada: ");
        scanf("%d", &menu1_option);

        if (menu1_option == 1)
        {
            int i = a;
            do
            {
                system("cls");
                printf("\n");
                printf("    -CADASTRO-\n\n");
                printf("\nDigite o nome do produto: ");
                fflush(stdin);
                scanf("%s", nome_prod[i]);
                printf("Digite a quantidade: ");
                scanf("%d", &qtde_est[i]);
                printf("Digite o custo do produto: R$ ");
                scanf("%f", &custo[i]);
                printf("Digite o preco de venda do produto: R$ ");
                scanf("%f", &preco_v[i]);
                printf("\nDeseja cadastrar outro produto?");
                printf("\n1 - Sim");
                printf("\n2 - Nao\n");
                printf("Digite a opcao desejada: ");
                scanf("%d", &opt1);
                a++;
                contador++;
                if (opt1 == 1)
                {
                }
                else if (opt1 == 2)
                {
                    system("cls");
                    break;
                }
                else if (opt1 != 1 || opt1 != 2)
                {
                    printf("\nOpcao invalida!");
                }
                i++;
            } while (opt1 == 1);
        }

        if (menu1_option == 2)
        {
            system("cls");
            for (int i = 0; i < contador; i++)
            {
                printf("   -ESTOQUE-\n\n");
                printf("\nCodigo: 000%d", i + 1);
                printf("\nProduto: %s", nome_prod[i]);
                printf("\nQuantidade: %d", qtde_est[i]);
                printf("\nPreco de Venda: R$ %.2f", preco_v[i]);
                printf("\nMarkUp: %.2f\n\n", ((preco_v[i] / custo[i]) - 1) * 100);
            }
            system("pause");
            system("cls");
        }

        if (menu1_option == 3)
        {
            system("cls");
            int i = 0;
            int a = 0;
            int b = 0;
            int recebe1[i];
            int cont = 1;
            do
            {
                printf("     -VENDA-\n");
                printf("\nDigite o codigo do produto: ");
                scanf("%d", &recebe);
                printf("\nProduto: %s", nome_prod[recebe - 1]);
                printf("\nQuantidade Disponivel: %d", qtde_est[recebe - 1]);
                printf("\nPreco: R$ %.2f", preco_v[recebe - 1]);
                printf("\n\nQuantidade Venda: ");
                scanf("%d", &a);
                if (a > qtde_est[recebe - 1])
                {
                    printf("\nQuantidade Indisponivel!\n\nRefaca o Processo...\n\n");
                    system("pause");
                    system("cls");
                }
            } while (a > qtde_est[recebe - 1]);

            printf("\nAdicionar outro produto: \n1 - Sim\n2 - Nao\nDigite a Opcao Desejada: ");
            scanf("%d", &b);
            if (b == 1)
            {
                do
                {
                    int i = 0;
                    printf("\nDigite o codigo do produto: ");
                    scanf("%d", &recebe1[i]);
                    printf("\nProduto: %s", nome_prod[recebe1[i]]);
                    printf("\nQuantidade Disponivel: %d", qtde_est[recebe1[i]]);
                    printf("\nPreco: R$ %.2f", preco_v[recebe1[i]]);
                    printf("\n\nQuantidade Venda: ");
                    scanf("%d", &a);
                    if (a > qtde_est[recebe1[i]])
                    {
                        printf("\nQuantidade Indisponivel!\n\nRefaca o Processo...\n\n");
                        break;
                    }
                    printf("\nAdicionar outro produto: \n1 - Sim\n2 - Nao\nDigite a Opcao Desejada: ");
                    cont++;
                    scanf("%d", &b);
                } while (b == 1);
            }
            system("cls");
            printf("\n\n");
            printf("     -CHECKOUT-");
            printf("\n\nOs produtos foram: \n");
            printf("%d - %s", 1, nome_prod[recebe - 1]);
            if (b == 1)
            {
                int i = 0;
                do
                {
                    printf("%d - %s\n", i + 2, nome_prod[recebe1[i]]);
                    i++;
                } while (i < contador);
            }
            printf("\nTotal da Venda: R$ %.2f\n\n", qtde_est[recebe - 1] * preco_v[recebe - 1]);
            system("pause");
            system("cls");
        }

    } while (menu1_option != 4);

    return 0;
}