#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "main.h"

int main(){
system("color 5E");
Venda *ve=(Venda*)malloc(sizeof(Venda));
Avlcliente *c = criaarvAVL();
arv_produtos *estoque= criar();
Cliente v;
Produtos novoproduto;

int op = 0,op2=0;;
int aux,aux2 = 0;

 do
    {
        system("cls");
        op = menu();
        switch(op)
        {
        case 1:
            novoproduto=infoP(novoproduto);
            estoque=inserirproduto(estoque,novoproduto);
            break;

        case 2:
            aux = idP(aux);
            aux2 = buscarproduto(estoque,aux);
            ProdutoStatus(aux2);
            break;

        case 3:
            aux = idP(aux);
            aux2 = alterarproduto(estoque,aux);
            ProdutoStatus(aux2);
            break;

        case 4:
            aux = idP(aux);
            aux2 = buscarproduto(estoque,aux);
            if(aux2)
            {
                printf("\nProduto excluido\n");
                estoque = excluirproduto(estoque,aux);
            }
            else
            {
                printf("O produto nao existe");
            }
            limpatela();
            break;

        case 5:
            p_preordem(estoque);
            limpatela();
            break;

        case 6:
            v=infoC(v);
            c = inserearvb(c,v);
            break;

        case 7:
            aux = ClienteCod(aux);
            aux2 = editarCliente(c,aux);
            ClienteStatus(aux2);
            break;

        case 8:
            aux = idC(aux);
            aux2 = pesquisarCliente(c,aux);
            if(aux2)
            {
                printf("\nCliente excluido\n");
                c = retira(c,aux);
            }
            else
            {
                printf("O cliente nao existe");
            }
            limpatela();
            break;

        case 9:
            inordem(c);
            limpatela();
            break;

        case 10:
            estoque=infoES(estoque);
            limpatela();
            break;

        case 11:
            printf("1-Estoque de um produto\n0-Exibir historico de transacoes\nop-> ");
            scanf("%d",&op2);
            if(op2==1){
                aux = idP(aux);
                estoqueproduto(estoque,aux);
            }else{
                mg();
                exibirhistorico();
            }
            limpatela();
            break;
        }
    }
    while(op!=12);
    return 0;
}
