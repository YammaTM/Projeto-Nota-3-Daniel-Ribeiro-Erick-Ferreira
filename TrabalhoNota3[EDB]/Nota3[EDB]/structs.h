#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

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
    char CPF[30];
    char Nome[30];
    char Celular[11];
}Cliente;

typedef struct No{
    struct No *dir;
    struct No *esq;
    Cliente cliente;
    int h;
}Avlcliente;

#endif
