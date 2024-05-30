#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float markup(float a, float b)
{
    float res_mkp;
    res_mkp = (((a / b) - 1) * 100);
    return (res_mkp);
}

int estoque(int a, int b, int c)
{
    int res_est;
    res_est = (a - b - c);
    return (res_est);
}

int main()
{
    int qtde_est[5], menu1_option, opt1, a = 0, contador = 0, recebe = 0, qtde_numerador[5] = {0}, qtdven_numerador[5] = {0}, baixa[5]={0};
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
                baixa[i] = qtde_est[i];
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
            printf("   -ESTOQUE-\n\n");
            for (int i = 0; i < contador; i++)
            {
                printf("\nCodigo: 000%d", i + 1);
                printf("\nProduto: %s", nome_prod[i]);
                printf("\nQuantidade: %d", estoque(qtde_est[i], baixa[recebe - 1], qtdven_numerador[i]));
                printf("\nPreco de Venda: R$ %.2f", preco_v[i]);
                printf("\nMarkUp: %.2f\n", markup(preco_v[i], custo[i]));
                if (markup(preco_v[i], custo[i]) < 20)
                {
                    printf("\n##Produto com markup baixo, revise o preco de venda!!##\n\n");
                }
                else
                {
                    printf("\n\n");
                }
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
            int d = 0;
            int f = 1;
            int recebe1[i];
            int cont = 0;
            int numerador[f];
            int qtde_numerador[f];
            int preco_numerador[f];
            int qtdven_numerador[f];
            int pular = 0;
            float subtot = 0;
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
                qtde_est[recebe - 1] = a;
                if (a > qtde_est[recebe - 1])
                {
                    printf("\nQuantidade Indisponivel!\n\nRefaca o Processo...\n\n");
                    system("pause");
                    system("cls");
                }
            } while (a > qtde_est[recebe - 1]);

            printf("\nAdicionar outro produto: \n1 - Sim\n2 - Nao\nDigite a Opcao Desejada: ");
            scanf("%d", &d);

            if (d == 1)
            {
                int i = 0;
                do
                {
                    int pega = 0;
                    do
                    {
                        printf("\nDigite o codigo do produto: ");
                        scanf("%d", &pega);
                        printf("\nProduto: %s", nome_prod[pega - 1]);
                        numerador[i] = nome_prod[pega - 1];
                        printf("\nQuantidade Disponivel: %d", qtde_est[pega - 1]);
                        qtde_numerador[i] = qtde_est[pega - 1];
                        printf("\nPreco: R$ %.2f", preco_v[pega - 1]);
                        preco_numerador[i] = preco_v[pega - 1];
                        printf("\n\nQuantidade Venda: ");
                        scanf("%d", &a);
                        qtdven_numerador[i] = a;
                        if (qtdven_numerador[i] == 0)
                        {
                            pular = 1;
                        }
                        else if (a > qtde_est[pega - 1])
                        {
                            printf("\nQuantidade Indisponivel!\n\nRefaca o Processo...\n\n");
                            system("pause");
                            system("cls");
                        }
                    } while (a > qtde_est[pega - 1]);
                    printf("\nAdicionar outro produto: \n1 - Sim\n2 - Nao\nDigite a Opcao Desejada: ");
                    i++;
                    cont++;
                    f++;
                    scanf("%d", &b);
                } while (b == 1);
            }

            system("cls");
            printf("\n\n");
            printf("     -CHECKOUT-");

            if (d == 2)
            {
                float tot_final = subtot + ((float)qtde_est[recebe - 1] * preco_v[recebe - 1]);
                printf("\n\nOs produtos foram: \n\n");
                printf("Item %d: %s \nQuantidade: %d\n\n", 1, nome_prod[recebe - 1], qtde_est[recebe - 1]);
                printf("\nTotal da Venda: R$ %.2f\n\n", tot_final);
                system("pause");
                system("cls");
            }
            else if (d == 1 && (b == 1 || b == 2))
            {
                int i = 0;
                printf("\n\nOs produtos foram: \n\n");
                printf("Item %d: %s \nQuantidade: %d\n\n", i + 1, nome_prod[recebe - 1], qtde_est[recebe - 1]);
                do
                {
                    printf("Item %d: %s \nQuantidade: %d\n\n", i + 2, numerador[i], qtdven_numerador[i]);
                    subtot += (float)qtdven_numerador[i] * preco_numerador[i];
                    i++;
                } while (i < cont);
                float tot_final = subtot + ((float)qtde_est[recebe - 1] * preco_v[recebe - 1]);
                printf("\nTotal da Venda: R$ %.2f\n\n", tot_final);
                system("pause");
                system("cls");
            }
        }
    } while (menu1_option != 4);

    return 0;
}