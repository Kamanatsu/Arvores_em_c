typedef struct arvb ArvB;



/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);
// busca
int arvb_altura(ArvB* a);

/*a) folhas de uma árvore binária de busca que
possuem o campo info com n divisores positivos*/
int folhas_ndivp(ArvB* a, int n);

/*b) - retorne a quantidade de nós de uma árvore binária de busca que possuem
os dois filhos (campos dir e esq diferentes de NULL)*/
int dois_filhos(ArvB* a);

/*c) - retorne a quantidade de nós cujas
subárvores esquerda e direita tenham igual altura*/
int nos_igual_altura(ArvB* a);

/*d) - compare se duas árvores binárias de busca são iguais*/
int arv_iguais(ArvB* a, ArvB* b);

/*e) - imprima os elementos de uma árvore binária de busca por níveis*/
void impressao_arv_niveis(ArvB* a);

