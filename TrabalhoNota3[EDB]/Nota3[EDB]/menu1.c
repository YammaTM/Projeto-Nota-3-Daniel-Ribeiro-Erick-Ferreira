#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu()
{
   printf("(1)Inserir produto     (7)Alterar cliente\n(2)Buscar produto      (8)Excluir cliente\n(3)Alterar produto     (9)Exibir cliente\n(4)Excluir produto     (10)E/S de produto\n(5)Exibir estoque      (11)Exibir produto especifico\n(6)Cadastrar cliente   (12)Sair\n");

    int k = 0;
    printf("Option: \n");
    scanf("%d",&k);
    return k;
}
