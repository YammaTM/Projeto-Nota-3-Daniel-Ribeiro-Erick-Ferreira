#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"

Venda* inserevenda(Venda *v, Produtos p, char *data, int opr, int qtd){
    Venda *n = (Venda*)malloc(sizeof(Venda));
    n->p = p;
    strcpy(n->data,data);
    n->opr = opr;
    n->qtd = qtd;
    n->prox = v;
    return n;
}



void Dividir(Venda *molho, Venda **frente, Venda **tras ){
    Venda *rapido;
    Venda *devagar;
    devagar = molho;
    rapido = molho->prox;

    while (rapido != NULL){
        rapido = rapido->prox;
        if(rapido != NULL){
            devagar = devagar->prox;
            rapido = rapido->prox;
        }
    }

    *frente = molho;
    *tras = devagar->prox;
    devagar->prox = NULL;
}

Venda* SortedMerge(Venda *v1, Venda *v2){
    Venda *valor = NULL;

    if(v1 == NULL)
        return (v2);
    else if(v2 == NULL)
        return (v1);

    if(v1->p.codigo <= v2->p.codigo){
        valor = v1;
        valor->prox = SortedMerge(v1->prox,v2);
    }
    else{
        valor = v2;
        valor->prox = SortedMerge(v1,v2->prox);
    }
    return(valor);
}

void MergeSort(Venda **raiz){
    Venda *primeiro = *raiz;
    Venda *v1;
    Venda *v2;

    if((primeiro == NULL) || (primeiro->prox == NULL)){
        return;
    }

    Dividir(primeiro, &v1, &v2);

    MergeSort(&v1);
    MergeSort(&v2);

    *raiz = SortedMerge(v1,v2);
}

arv_produtos *retornaProduto(arv_produtos *arv, int cod) {
    if(estavazio(arv)){
        return arv;
    }else if(arv->produto.codigo==cod){
        return arv;
    }else if(arv->produto.codigo>cod){
        retornaProduto(arv->pesq,cod);
    }else{
        retornaProduto(arv->pdir,cod);
    }
}

Venda *vend= NULL;
arv_produtos *infoES(arv_produtos *arv)
{

    int c=0,auxA,quant,auxB,op;
    auxA = idP(c);
    auxB = buscarproduto(arv,auxA);
    if(auxB)
    {
        arv_produtos *aux5 = retornaProduto(arv,auxA);
ini:
        printf("Digite qual operacao deseja para esse produto: \n\n");
        printf("(1) - Entrada\n");
        printf("(0) - Saida\n\n");
        printf("-> ");
        scanf("%d",&op);
        if(op)
        {
            printf("\nDigite quantas unidades deseja adicionar ao produto: ");
            scanf("%d",&quant);
            aux5->produto.quant += quant;
            vend=inserevenda(vend,aux5->produto,__DATE__,op,quant);
        }
        else
        {
            printf("\nDigite quantas unidades deseja retirar do produto: ");
            scanf("%d",&quant);
            if(quant == aux5->produto.quant)
            {
                aux5->produto.quant -= quant;
                vend=inserevenda(vend,aux5->produto,__DATE__,op,quant);
                arv = excluirproduto(arv,c);
            }
            else if(quant > aux5->produto.quant)
            {
                printf("\nQuantidade maior que a existente, tente outra vez\n");
                limpatela();
                goto ini;
            }
            else
            {
                aux5->produto.quant -= quant;
                vend=inserevenda(vend,aux5->produto,__DATE__,op,quant);
            }
        }
    }
    return arv;

}
void exibirhistorico(){
    if(vend!=NULL){
        exibirVenda(vend);
    }else{
        printf("Sem historico\n");
    }

}
void mg(){
    MergeSort(&vend);
}

void exibirVenda(Venda *v)
{
    Venda *aux;
    //aux=vend;
    //MergeSort(&aux);
    printf("\t\t\t MATEUS E-COMMERCE RELATORIO DE ESTOQUE \t\t\t\n");
    for(aux = v; aux != NULL; aux = aux->prox)
    {
        if(aux->opr == 1)
        {
            printf("Cod: %d\nDesc: %s\nPreco: %.2f\nQuantidade Atual: %d\nQuantidade Alterada: %d\n Op: Entrada\n Data: %s\n",
                   aux->p.codigo,aux->p.desc,aux->p.preco,aux->p.quant,aux->qtd,aux->data);
                        printf("\t\t\t\n##################################\t\t\t\n\n");

        }
        else
        {
            printf("Cod: %d\nDesc: %s\nPreco: %.2f\nQuantidade Atual: %d\nQuantidade Alterada: %d\n Op: Saida\n Data: %s\n",
                   aux->p.codigo,aux->p.desc,aux->p.preco,aux->p.quant,aux->qtd,aux->data);
                        printf("\t\t\t\n##################################\t\t\t\n\n");
        }
    }
}
