# <h2>Projeto-Nota-3-Daniel-Ribeiro-Erick-Ferreira</h2>
Trabalho/projeto referente à terceira nota na cadeira Estrutura de Dados Básico

Autores:
1 - Daniel Vitor Ribeiro Moreira;
2 - Erick Ferreira de Sousa;

Componentes exigidos:
1 - Sistema Operacional Windows;
2 - IDE para C(CodeBlocks e afins);

Descrição geral
O trabalho consiste de três principais estruturas: A estrutura Produto(Árvore Binária), a estrutura Clientes(Árvore AVL) e a estrutura Venda(Lista Encadeada para representar o fluxo de entrada e saída de estoque) que se encarregarão de controlar o fluxo de cadastro de produtos
e clientes, assim como moldá-los(alterar, excluir, pesquisar), além do fluxo de entrada e saída dos produtos. 

Distribuição do Código
- Todas as funções relacionadas ao Produto estão em Produto.c;
- Todas as funções relacionadas ao Cliente estão em Cliente.c;
- Todas as funções relacionadas à E/S do Produto estão em Venda.c;
- Estruturas e declaração de funções estão inseridas no arquivo main.h, com linhas comentadas para a distribuição de cada seção de funções, 
assim como as próprias estruturas;
- À fim de deixar o código enxuto e reservar a main apenas para a chamada de funções, descartando leitura de variáveis e derivados, foram
utilizados sucessivos encapsulamentos das funções, de forma à facilitar a leitura da main.
