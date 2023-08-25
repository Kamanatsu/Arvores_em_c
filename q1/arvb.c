#include "arvb.h"
#include <stdio.h>
#include <stdlib.h>


struct arvb{
    char info;
    ArvB *esq;
    ArvB *dir;
};


/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void){
    return NULL;
}

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a){
    return a==NULL;
}

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c){
    if(arvb_vazia(a))
        return NULL;
    else if(a->info < c)
        return arvb_busca(a->dir,c);
    else if(a->info > c)
        return arvb_busca(a->esq,c);
    else //(a->info == c)
        return a;
}

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a){
    if(!arvb_vazia(a)){
        arvb_imprime(a->esq);
        printf("%d ",a->info);
        arvb_imprime(a->dir);
    }
}

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c){
    if(arvb_vazia(a)){
        a = (ArvB*)malloc(sizeof(ArvB));
        a->info = c;
        a->esq = NULL;
        a->dir = NULL;
    }else if(a->info > c)
        a->esq = arvb_insere(a->esq,c);
    else if(a->info < c)
        a->dir = arvb_insere(a->dir,c);
    else
        printf("\n Elemento Ja Pertence a Arvore");
    return a;
}

/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c){
    if(!arvb_vazia(a)){
        if(a->info > c)
            a->esq = arvb_remove(a->esq,c);
        else if (a->info < c)
            a->dir = arvb_remove(a->dir,c);
        else{
            ArvB* t;
            if (a->esq == NULL){
                t = a; a = a->dir;
                free(t);
            }else if (a->dir == NULL){
                t = a; a = a->esq;
                free(t);
            }else{
                t = a->esq;
                while(t->dir!=NULL)
                    t = t->dir;
                a->info = t->info; t->info = c;
                a->esq = arvb_remove(a->esq,c);
            }
        }
    }
    return a;
}

void arvb_libera(ArvB *a){
    if(!arvb_vazia(a)){
        arvb_libera(a->esq);
        arvb_libera(a->dir);
        free(a);
    }
}

int arvb_altura(ArvB *a){
    if(arvb_vazia(a)){
        return -1;
    }
    else{
        int hSAE = arvb_altura(a->esq);
        int hSAD = arvb_altura(a->dir);
        if(hSAE > hSAD)
            return 1+hSAE;
        else
            return 1+hSAD;
    }
}

/*a) folhas de uma árvore binária de busca que
possuem o campo info com n divisores positivos*/
int folhas_ndivp(ArvB* a, int n){
    int t = 0;
    if(!arvb_vazia(a)){
        int i, cont = 0;
        for(i = 1; i<=a->info;i++){
            if(a->info % i ==0)
                cont++;
        }
        if(cont==n)
            t++;
        t = t+folhas_ndivp(a->esq,n)+folhas_ndivp(a->dir,n);
    }
    return t;
}


/*b) - retorne a quantidade de nós de uma árvore binária de busca que possuem
os dois filhos (campos dir e esq diferentes de NULL)*/
int dois_filhos(ArvB* a){
    int t = 0;
    if(a->dir!=NULL&&a->esq!=NULL){
        t++;
        t=t+dois_filhos(a->dir)+dois_filhos(a->esq);
    }
    return t;
}

/*c) - retorne a quantidade de nós cujas
subárvores esquerda e direita tenham igual altura*/
int nos_igual_altura(ArvB* a){
    int cont;
    cont = 0;
    
    if(!arvb_vazia(a)){
        if(arvb_altura(a->esq)==arvb_altura(a->dir)){
            cont = cont + 1;
        }
        cont += (nos_igual_altura(a->esq) + nos_igual_altura(a->dir));
    }
    return cont;
}

/*d) - compare se duas árvores binárias de busca são iguais*/
int arv_iguais(ArvB* a, ArvB* b){
  if (a == b)  return 1;
  if ((a == NULL) || (b == NULL))  return 0;
  return ((a->info == b->info) && arv_iguais(a->esq,  b->esq ) && arv_iguais(a->dir, b->dir));
}

/*e) - imprima os elementos de uma árvore binária de busca por níveis*/
void impressao_arv_niveis(ArvB* a){
    if(!arvb_vazia(a)){
        printf("%d ",a->info);
        if(!arvb_vazia(a->esq)){
            impressao_arv_niveis(a->esq);
        }
        if(!arvb_vazia(a->esq)){
            impressao_arv_niveis(a->dir);
        }
    }
}







