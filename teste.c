#include <stdio.h>

int main()
{
    char nome[10], opt;
    int menu;

    do
    {
        printf("\n1 - Cadastrar Produto");
        printf("\n2 - Consultar Estoque");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &menu);
        if (menu == 1)
        {
            /*do
            {*/            
            printf("\nDigite o nome do Produto: ");
            scanf("%s", nome);
            /*if(menu2=='s' || menu2=='S')
            {
                menu2=1;
            }
            else if(menu2=='n' || menu2=='N')
            {
                menu2=0;
            }
            else
            {
                printf("Opcao Invalida!");
            }
            } while (menu2!=0);*/
        }
        if (menu == 2)
        {
            printf("%s", nome);
        }
    } while (menu != 3);

    return 0;
}