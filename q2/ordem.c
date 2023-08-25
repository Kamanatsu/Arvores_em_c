#include "ordem.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

void troca(int A,int B){
    int t = A;
    A = B; 
    B = t;
}

void bolha(int n, int *v){
    int i, j, temp;
    for(i=n-1; i>0; i--)
        for(j=0; j<i; j++)
            if(v[j]> v[j+1]){
                temp = v[j]; // Troca
                v[j] = v[j+1];
                v[j+1] = temp;
    }
}

void rapida(int n, int *v){
    if(n>1){
        int x = v[0];
        int a =1; int b = n-1;
        while(1){
            while(a<n && v[a] <=x) a++;
            while(v[b]>x) b--;
            if(a<b){
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;b--;
            }else
                break;
        }
        v[0] = v[b];
        v[b] = x;
        rapida(b,v);
        rapida(n-a,&v[a]);
    }
}

void insertionSort(int n, int *v){ 
    int i, element, j; 
    for (i = 1; i < n; i++) { element = v[i]; j = i - 1; while (j >= 0 && v[j] > element) { 
            v[j + 1] = v[j]; 
            j = j - 1; 
        } 
        v[j + 1] = element; 
    } 
}

void heapsort(int n, int *v){
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}

void mergesort(int *v,int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);
        mergesort(v,inicio,meio);
        mergesort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}

void merge(int *v,int inicio,int meio,int fim){
    int *temp,p1,p2,tamanho,i,j,k;
    int fim1 = 0,fim2 = 0;
    tamanho = fim+inicio+1;
    p1 = inicio;
    p2 = meio +1;
    temp = (int*)malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0;i<tamanho;i++){
            if(!fim && !fim2){
                if(v[p1]<v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                if(p1>meio) fim1=1;
                if(p2>fim) fim2 =1;
            }else{
                if(!fim)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        for(j=0,k=inicio;j<tamanho;j++,k++){
            v[k] = temp[j];
        }
    }
    
}

static void constroiHeap(int m, int *v){
   for (int k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}

static void peneira (int m, int *v){
   int f = 2;
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      // f é o filho mais valioso de f/2
      if (v[f/2] >= v[f]) break;
      troca (v[f/2], v[f]);
      f *= 2;
   }
}

void crescente(int m,int *v){
    int i;
    v[0] = 0;
    int a = 0;
    for(i = 0; i<= m-1;i++){
        a = a + 2;
        v[i] = a;
    }
}

void decrescente(int m,int *v){
    int i;
    v[0] = 0;
    int a = m*3;
    for(i = m-1; i = 0;i--){
        a = a - 2;
        v[i] = a;
    }
}

void aleatorio(int m,int *v){
    for(int i = 0; i<= m-1;i++){
        v[i] = rand() % m*1.3;
    }
}

void contagemC_bolha(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    crescente(m,v);
    t = clock();
    bolha(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemD_bolha(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    decrescente(m,v);
    t = clock();
    bolha(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemR_bolha(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    aleatorio(m,v);
    t = clock();
    bolha(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemC_insert(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    crescente(m,v);
    t = clock();
    insertionSort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemD_insert(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    decrescente(m,v);
    t = clock();
    insertionSort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemR_insert(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    aleatorio(m,v);
    t = clock();
    insertionSort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemC_quick(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    crescente(m,v);
    t = clock();
    rapida(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemD_quick(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    decrescente(m,v);
    t = clock();
    rapida(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemR_quick(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    aleatorio(m,v);
    t = clock();
    rapida(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemC_heap(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    crescente(m,v);
    constroiHeap(m,v);
    t = clock();
    heapsort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemD_heap(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    decrescente(m,v);
    constroiHeap(m,v);
    t = clock();
    heapsort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemR_heap(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    aleatorio(m,v);
    constroiHeap(m,v);
    t = clock();
    heapsort(m,v);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemC_merge(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    crescente(m,v);
    
    t = clock();
    mergesort(v,0,m-1);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemD_merge(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    decrescente(m,v);
    
    t = clock();
    mergesort(v,0,m-1);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void contagemR_merge(int m){
    
    clock_t t;
    int *v = malloc(m*sizeof(int));
    aleatorio(m,v);
    
    t = clock();
    mergesort(v,0,m-1);
    t = clock() - t; 
    
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
}


