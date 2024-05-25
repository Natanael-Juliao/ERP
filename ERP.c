#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    int qtde_est[5], menu1_option, contador = 0, opt1;
    char nome_prod[10][3];
    float preco_v[5], custo[5];

    printf("  --SISTEMA DE GESTAO--\n\n");

    do
    {
        printf("\n");
        printf("         MENU\n\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Consultar Estoque\n");
        printf("3 - Efetuar Venda\n");
        printf("4 - Logoff\n\n");
        printf("Digite a Opcao Desejada: ");
        scanf("%d", &menu1_option);

        if (menu1_option == 1)
        {
            int i = 0;
            do
            {
                system("cls");
                printf("\n");
                printf("     CADASTRO\n\n");
                printf("\nDigite o nome do produto: ");
                // fflush(stdin);
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
                if (opt1 == 1)
                {
                }
                else if (opt1 == 2)
                {
                    break;
                }
                else
                {
                    printf("\nOpcao invalida!");
                }
                i++;
                contador++;
            } while (opt1 == 1);
            contador += 1;
            system("cls");
        }

        if (menu1_option == 2)
        {
            int i = 0;
            do
            {
                system("cls");
                printf("    ESTOQUE\n\n");
                printf("\nProduto: %s", nome_prod[i]);
                printf("\nQuantidade: %d", qtde_est[i]);
                printf("\nPreco de Venda: R$ %.2f", preco_v[i]);
                printf("\nMarkUp: %.2f\n\n", ((preco_v[i] / custo[i]) - 1)*100);
                i++;

            } while (i < contador);
            
        }

        //printf("%d", contador);
    } while (menu1_option != 4);

    return 0;
}