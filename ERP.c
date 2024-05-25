#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtde_est[100], menu1_option, i = 0, contador;
    char nome_prod[20][100], menu1_1;
    float preco_v[100], custo[100];

    printf("  --SISTEMA DE GESTAO--\n\n");

    for (int a = 0;; a++)
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
            do
            {
                system("cls");
                printf("\n");
                printf("     CADASTRO\n\n");
                printf("\nDigite o nome do produto: ");
                scanf("%s", &nome_prod[i]);
                printf("Digite a quantidade: ");
                scanf("%d", &qtde_est[i]);
                printf("Digite o custo do produto: R$ ");
                scanf("%f", &custo[i]);
                printf("Digite o preco de venda do produto: R$ ");
                scanf("%f", &preco_v[i]);
                printf("Deseja cadastrar outro produto? 'S/N': ");
                scanf("%s", &menu1_1);
                if (menu1_1 == 'S' || menu1_1 == 's')
                {
                    menu1_1 = i + 2;
                }
                else if (menu1_1 == 'N' || menu1_1 == 'n')
                {
                    menu1_1 = 1;
                }
                else
                {
                    printf("\nOpcao invalida!");
                }
                i++;
                contador++;
            } while (i < menu1_1);
        }
        contador = contador;
        if (menu1_option == 2)
        {
            int i=0;
            do
            {
                printf("  \nESTOQUE\n\n");
                printf("Produto: %s\n", nome_prod[i]);
                printf("Quantidade: %d\n", qtde_est[i]);
                printf("Custo R$ %.2f\n", custo[i]);
                printf("Preco Venda R$ %.2f\n", preco_v[i]);
                i++;
            } while (i<= contador);
            //system("cls");
        }
        
    }

    return 0;
}