#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"

Avlcliente *criaarvAVL () {
    return NULL;
}

int acesso_h(Avlcliente *no){
    return  (no==NULL)?-1:no->h;
}

int calc_fb(Avlcliente *no){
    return abs(altura(no->esq) - altura(no->dir));
}

int estavazia (Avlcliente *a) {
    return (a==NULL);
}

int maior(int a, int b){
        return (a > b)?a:b;
}

int altura(Avlcliente *a){
   if((a == NULL))
       return 0;
   else
       return 1 + maior(altura(a->esq), altura(a->dir));
}

Avlcliente* rotacao_esquerda(Avlcliente *raiz){
    Avlcliente *auxi=raiz->esq;
    raiz->esq=auxi->dir;
    auxi->dir=raiz;

    raiz->h=altura(raiz);
    auxi->h=altura(auxi);

    raiz=auxi;
    return auxi;
}

Avlcliente* rotacao_direita(Avlcliente *raiz){
    Avlcliente *auxi=raiz->dir;
    raiz->dir=auxi->esq;
    auxi->esq=raiz;

    raiz->h=altura(raiz);
    auxi->h=altura(auxi);

    raiz=auxi;
    return auxi;
}

Avlcliente* rotacao_d_esquerda(Avlcliente *no){

    no->esq=rotacao_direita(no->esq);

    no=rotacao_esquerda(no);
    return no;
}

Avlcliente* rotacao_d_direita(Avlcliente *no){

    no->dir=rotacao_esquerda(no->dir);

    no=rotacao_direita(no);
    return no;
}

Avlcliente *inserearvb(Avlcliente *a, Cliente v) {
    if (estavazia(a)) {
        Avlcliente *nova = (Avlcliente*) malloc(sizeof(Avlcliente));
        nova->cliente= v;
        nova->h=0;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    } else {
        if (v.id < a->cliente.id) { //lado esquerdo: <
            a->esq = inserearvb(a->esq,v);
            if(calc_fb(a)>1){
                if(a->dir==NULL && v.id < a->esq->cliente.id){
                    return rotacao_esquerda(a);
                }else{
                    return rotacao_d_esquerda(a);
                }
            }
        } else { //lado  direito: >=
            a->dir = inserearvb(a->dir,v);
            if(calc_fb(a)>1){
                if( a->esq==NULL &&  v.id > a->dir->cliente.id){
                    return rotacao_direita(a);
                }else{
                    return rotacao_d_direita(a);
                }
            }
        }
        return a;
    }
}

Avlcliente *retira(Avlcliente *a, int v) {
    if (estavazia(a)) {
        return NULL;
    } else if (v < a->cliente.id) {
        a->esq = retira(a->esq,v);
        if(calc_fb(a)>1){
           if( altura(a->dir->esq)<=altura(a->dir->dir)){
            return rotacao_direita(a);
           }else{
                return rotacao_d_direita(a);
            }
        }
    } else if (v > a->cliente.id) {
        a->dir = retira(a->dir,v);
        if(calc_fb(a)>1){
            if(altura(a->esq->dir)<=altura(a->esq->esq)){
            return rotacao_esquerda(a);
           }else{
                return rotacao_d_esquerda(a);
            }
        }
    } else {
        if ( a->esq == NULL && a->dir == NULL) {
            free(a);
            a=NULL;
        }  else if ( a->esq == NULL ) {
            Avlcliente *aux = a->dir;
            free(a);
            a = aux;
        }  else if ( a->dir == NULL ) {
            Avlcliente *aux = a->esq;
            free(a);
            a = aux;
        } else {
            Avlcliente *aux = a->esq;
            while(aux->dir!=NULL) {
                aux = aux->dir;
            }
            a->cliente.id=aux->cliente.id;
            aux->cliente.id=v;
            a->esq = retira(a->esq,v);
        }
    }
    return a;
}

void preordem(Avlcliente *a) {
    if (!estavazia(a)) {
        printf("Id :%d, Nome: %s\n", a->cliente.id ,a->cliente.nome);
        preordem(a->esq);
        preordem(a->dir);
    }
}

void inordem(Avlcliente *a) {
    if (!estavazia(a)) {
        inordem(a->esq);
        printf("Nome: %s\nID: %d\nCPF: %s\nCelular: %s\n\n",a->cliente.nome,a->cliente.id,a->cliente.CPF,a->cliente.Celular);
        inordem(a->dir);
    }
}

void posordem(Avlcliente *a) {
    if (!estavazia(a)) {
        posordem(a->esq);
        posordem(a->dir);
        printf("Id :%d, Nome: %s\n", a->cliente.id ,a->cliente.nome);
    }
}

int pesquisarCliente(Avlcliente *a,int cod){
    if(estavazia(a)){
        return 0;
    }else if(a->cliente.id==cod){
        printf("Cliente existente\n");
        printf("Nome: %s\nID: %d\nCPF: %s\nCelular: %s\n\n",a->cliente.nome,a->cliente.id,a->cliente.CPF,a->cliente.Celular);
        return 1;
    }else if(a->cliente.id>cod){
        pesquisarCliente(a->esq,cod);
    }else{
        pesquisarCliente(a->dir,cod);
    }
    return 0;
}

int editarCliente(Avlcliente *a,int cod){
    if(estavazia(a)){
        return 0;
    }else if(a->cliente.id==cod){
        char nomeProd[50];
        int idProd=0;
        int op;
        printf("Cliente existente\n");
        printf("Nome: %s\nID: %d\nCPF: %s\nCelular: %s\n\n",a->cliente.nome,a->cliente.id,a->cliente.CPF,a->cliente.Celular);

        printf("Alterar nome do cliente?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o nome do cliente\n");
            scanf(" %[^\n]s",nomeProd);
            strcpy(a->cliente.nome,nomeProd);
        }
        fflush(stdin);

        printf("Alterar id do cliente?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o id do cliente\n");
            scanf("%d",&idProd);
            a->cliente.id = idProd;
        }
        fflush(stdin);

        printf("Alterar CPF do cliente?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o CPF do cliente\n");
            scanf(" %[^\n]s",nomeProd);
            strcpy(a->cliente.CPF,nomeProd);
        }
        fflush(stdin);

        printf("Alterar Celular do cliente?\n1-Sim\n2-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Informar o Celular do cliente\n");
            scanf(" %[^\n]s",nomeProd);
            strcpy(a->cliente.Celular,nomeProd);
        }
        fflush(stdin);


        printf("Informacoes atualizadas:\nNome: %s\nID: %d\nCPF: %s\nCelular: %s\n\n",a->cliente.nome,a->cliente.id,a->cliente.CPF,a->cliente.Celular);
        return 1;
    }else if(a->cliente.id>cod){
        editarCliente(a->esq,cod);
    }else{
        editarCliente(a->dir,cod);
    }
    return 0;
}

Avlcliente* liberaAvlCliente (Avlcliente *a) {
    if (!estavazia(a)) {
        liberaAvlCliente(a->esq);
        liberaAvlCliente(a->dir);
        free(a);
    }
    return NULL;
}

Avlcliente *retornaCliente(Avlcliente *a,int cod){
    if(estavazia(a)){
        return NULL;
    }else if(a->cliente.id==cod){
        return a;
    }else if(a->cliente.id>cod){
        retornaCliente(a->esq,cod);
    }else{
        retornaCliente(a->dir,cod);
    }
    return NULL;
}

void limpatela(){
    printf("\n");
    system("pause");
    system("cls");
}

int ClienteCod(int id){
    system("cls");

    printf("1 - Insira o ID do Cliente:\n");
    scanf("%d",&id);

    limpatela();
    return id;
}

void ClienteStatus(int x)
{
    if(x==0)
    {
        printf("\n\nCliente nao encontrado");
    }
    limpatela();
}

int idC(int id){
    system("cls");
    printf("Insira o ID do Cliente:\n");
    scanf("%d",&id);

    limpatela();
    return id;
}

Cliente infoC(Cliente v){
    system("cls");
    printf("1 - Insira o ID do Cliente:\n");
    scanf("%d",&v.id);

    printf("2 - Insira o CPF do Cliente: \n");
    fflush(stdin);
    gets(v.CPF);

    printf("3 - Insira o nome do Cliente \n");
    fflush(stdin);
    gets(v.nome);

    printf("4 - Insira o Celular do Cliente: \n");
    fflush(stdin);
    gets(v.Celular);

    limpatela();
return v;
}
