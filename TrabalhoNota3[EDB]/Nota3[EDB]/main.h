#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <stdbool.h>

typedef struct{
	int codigo;
	char desc[31];
	float preco;
	int quant;
}Produtos;

typedef struct node{
	Produtos produto;
	struct node *pdir;
	struct node *pesq;
}arv_produtos;

typedef struct{
    int id;
    char CPF[30];
    char nome[30];
    char Celular[11];
}Cliente;

typedef struct No{
    struct No *dir;
    struct No *esq;
    Cliente cliente;
    int h;
}Avlcliente;

typedef struct no{
    Produtos p;
    char data[11];
    int opr;
    int qtd;
    struct no *prox;
}Venda;

#endif
//Fun��es
int menu();//menu principal
void limpatela();//limpar a tela...

//Fun��es do Cliente
Avlcliente *criaarvAVL ();//Criar �rvore
int acesso_h(Avlcliente *no);//Acesso � �rvore
int calc_fb(Avlcliente *no);//C�lculo do balanceamento
int estavazia (Avlcliente *a);//Verificar se est� vazia
int maior(int a, int b);//Verificar o maior entre dois elementos
int altura(Avlcliente *a);//Retornar altura da �rvore
int pesquisarCliente(Avlcliente *a,int cod);//Pesquisar Cliente
int editarCliente(Avlcliente *a,int cod);//Alterar Cliente
void preordem(Avlcliente *a);//Exibir cliente Pre-Ordem
void inordem(Avlcliente *a);//Exibir cliente In-Ordem
void posordem(Avlcliente *a);//Exibir cliente P�s-Ordem
Avlcliente* rotacao_esquerda(Avlcliente *raiz);//Rota��o � esquerda
Avlcliente* rotacao_direita(Avlcliente *raiz);//Rota��o � direita
Avlcliente* rotacao_d_esquerda(Avlcliente *no);//Rota��o d_esquerda
Avlcliente* rotacao_d_direita(Avlcliente *no);//Rota��o d_direita
Avlcliente *inserearvb(Avlcliente *a, Cliente v);//Inserir Cliente
Avlcliente *retira(Avlcliente *a, int v);//Excluir Cliente
Avlcliente* liberaAvlCliente (Avlcliente *a);//Liberar Cliente
Avlcliente *retornaCliente(Avlcliente *a,int cod);//Retornar Cliente

//Fun��es Auxiliares de Cliente
Cliente infoC(Cliente v);
int ClienteCod();
int idC(int id);
void ClienteStatus(int x);

//Fun��es do Produto

arv_produtos *criar();
bool estavazio(arv_produtos *pont);
void p_preordem(arv_produtos *a);
void exibirumproduto(Produtos p);
void estoqueproduto(arv_produtos *arv, int cod);
arv_produtos *inserirproduto(arv_produtos *arv,Produtos novoproduto);
int buscarproduto(arv_produtos *arv, int cod);
arv_produtos *excluirproduto(arv_produtos *arv,int cod);
int alterarproduto(arv_produtos *arv,int cod);

//Fun��es Auxiliares de Produto
Produtos infoP(Produtos novoproduto);
int idP(int id);
void ProdutoStatus(int x);

//Fun��es da Venda
void mg();
void exibirhistorico();
void exibirVenda(Venda *v);
arv_produtos *infoES(arv_produtos *arv);
arv_produtos *retornaProduto(arv_produtos *arv, int cod);
