#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include"main.h"

arv_produtos *criar(){
	return NULL;
}
bool estavazio(arv_produtos *pont){
		return (pont==NULL);

}
arv_produtos *inserirproduto(arv_produtos *arv,Produtos novoproduto){
	if(estavazio(arv)){
		arv_produtos *novo=(arv_produtos*)malloc(sizeof(arv_produtos));
		novo->produto.codigo=novoproduto.codigo;
		strcpy(novo->produto.desc,novoproduto.desc);
		novo->produto.preco=novoproduto.preco;
		novo->produto.quant=novoproduto.quant;
		novo->pesq=NULL;
		novo->pdir=NULL;
		return novo;
	}else{
		if(novoproduto.codigo<arv->produto.codigo){
			arv->pesq=inserirproduto(arv->pesq,novoproduto);
		}else{
			arv->pdir=inserirproduto(arv->pdir,novoproduto);
		}
		return arv;
	}
}

int buscarproduto(arv_produtos *arv, int cod) {
    if(estavazio(arv)){
        return 0;
    }else if(arv->produto.codigo==cod){
        printf("Produto existente\n");
        printf("Desc: %s\nCodigo: %d\nPreco: %.2f\nQuantidade: %d\n",arv->produto.desc,arv->produto.codigo,arv->produto.preco,arv->produto.quant);
        return 1;
    }else if(arv->produto.codigo>cod){
        buscarproduto(arv->pesq,cod);
    }else{
        buscarproduto(arv->pdir,cod);
    }
}
void estoqueproduto(arv_produtos *arv, int cod) {
    if(estavazio(arv)){
        printf("\nSem estoque\n");
    }else if(arv->produto.codigo==cod){
        printf("Produto existente\n");
        printf("Descricao: %s\nQuantidade em estoque: %d\n",arv->produto.desc,arv->produto.quant);
    }else if(arv->produto.codigo>cod){
        buscarproduto(arv->pesq,cod);
    }else{
        buscarproduto(arv->pdir,cod);
    }

}


arv_produtos *excluirproduto(arv_produtos *arv,int cod){
	if (estavazio(arv)) {
        return 0;
    } else if (cod < arv->produto.codigo) {
        arv->pesq = excluirproduto(arv->pesq,cod);
    } else if (cod > arv->produto.codigo) {
        arv->pdir = excluirproduto(arv->pdir,cod);
    } else {
        if ( arv->pesq == NULL && arv->pdir == NULL) {
            free(arv);
            arv=NULL;
        }  else if ( arv->pesq == NULL ) {
            arv_produtos *aux = arv->pdir;
            free(arv);
            arv = aux;
        }  else if ( arv->pdir == NULL ) {
            arv_produtos *aux = arv->pesq;
            free(arv);
            arv = aux;
        } else {
            arv_produtos *aux = arv->pesq;
            while(aux->pdir!=NULL) {
                aux = aux->pdir;
            }
            arv->produto.codigo=aux->produto.codigo;
            aux->produto.codigo=cod;
            arv->pesq = excluirproduto(arv->pesq,cod);
        }
    }
    return arv;
}

void p_preordem(arv_produtos *a) {
    if (!estavazio(a)){
        printf("cod: %d descricao: %s  preco:%.2f  quantidade: %d\n", a->produto.codigo,a->produto.desc,a->produto.preco,a->produto.quant);
        p_preordem(a->pesq);
        p_preordem(a->pdir);
    }
}
void exibirumproduto(Produtos p){
	printf("cod: %d descricao: %s  preco:%.2f  quantidade: %d\n", p.codigo,p.desc,p.preco,p.quant);
}

int alterarproduto(arv_produtos *arv,int cod){
    if(estavazio(arv)){
        return 0;
    }else if(arv->produto.codigo==cod){
        char nomeProd[50];
        int idProd=0;
        float auxProd=0;
        int op;
        printf("Produto existente\n");
        printf("Desc: %s\nCodigo: %d\nPreco: %.2f\nQuantidade: %d\n",arv->produto.desc,arv->produto.codigo,arv->produto.preco,arv->produto.quant);

        printf("Alterar desc do produto?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar a desc do produto\n");
            scanf(" %[^\n]s",nomeProd);
            strcpy(arv->produto.desc,nomeProd);
        }
        fflush(stdin);

        printf("Alterar codigo do produto?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o codigo do produto\n");
            scanf("%d",&idProd);
            arv->produto.codigo = idProd;
        }
        fflush(stdin);

        printf("Alterar preco do produto?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o preco do cliente\n");
            scanf("%f",&auxProd);
            arv->produto.preco = auxProd;
        }
        fflush(stdin);

        printf("Alterar quantidade do produto?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar a quantidade do produto\n");
            scanf("%d",&idProd);
            arv->produto.quant = idProd;
        }
        fflush(stdin);

        return 1;
    }else if(arv->produto.codigo>cod){
        alterarproduto(arv->pesq,cod);
    }else{
        alterarproduto(arv->pdir,cod);
    }
    return 0;

}

Produtos infoP(Produtos novoproduto){

                printf("inserir Produto\ncodigo: ");
				fflush(stdin);
				scanf("%d",&novoproduto.codigo);

				printf("\nnome/decricao: ");
				fflush(stdin);
				gets(novoproduto.desc);

				printf("\npreco: ");
				fflush(stdin);
				scanf("%f",&novoproduto.preco);

				printf("\nquantidade: ");
				fflush(stdin);
				scanf("%d",&novoproduto.quant);
				limpatela();

                return novoproduto;
}

int idP(int id){
    system("cls");
    printf("Insira o Codigo do Produto:\n");
    scanf("%d",&id);

    limpatela();
    return id;
}

void ProdutoStatus(int x)
{
    if(x==0)
    {
        printf("\n\nProduto nao encontrado");
    }
    limpatela();
}
