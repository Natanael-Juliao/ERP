#include <stdio.h>
#include <string.h>

int main()
{
    char nome[3][5]={"Nata", "Toto",};
    int menu[5] = {1,2,3,4,},i = 0;

    /*do
     {
         printf("Digite um nome: ");
         scanf("%s", nome[i]);
         i++;
     } while (i < 3);*/

    do
    {
        printf("O nome e: %s\n", nome[i]);
        printf("O numero e: %d\n", menu[i])
        i++;
    } while (i<strlen(nome[i]));

    return 0;
}