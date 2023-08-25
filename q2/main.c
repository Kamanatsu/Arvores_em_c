#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordem.h"



int main(){
    printf("\nbolhas crescente:");
    contagemC_bolha(100);
    contagemC_bolha(1000);
    contagemC_bolha(10000);
    contagemC_bolha(100000);
    contagemC_bolha(1000000);
    
    printf("\n\nbolhas decrescente:");
    contagemD_bolha(100);
    contagemD_bolha(1000);
    contagemD_bolha(10000);
    contagemD_bolha(100000);
    contagemD_bolha(1000000);
    
    printf("\n\nbolhas aleatorio:");
    contagemR_bolha(100);
    contagemR_bolha(1000);
    contagemR_bolha(10000);
    contagemR_bolha(100000);
    contagemR_bolha(1000000);
  
  
    printf("\ninsert crescente:");
    contagemC_insert(100);
    contagemC_insert(1000);
    contagemC_insert(10000);
    contagemC_insert(100000);
    contagemC_insert(1000000);
    
    printf("\n\ninsert decrescente:");
    contagemD_insert(100);
    contagemD_insert(1000);
    contagemD_insert(10000);
    contagemD_insert(100000);
    contagemD_insert(1000000);
    
    printf("\n\ninsert aleatorio:");
    contagemR_insert(100);
    contagemR_insert(1000);
    contagemR_insert(10000);
    contagemR_insert(100000);
    contagemR_insert(1000000);
    
    printf("\nquick crescente:");
    contagemC_quick(100);
    contagemC_quick(1000);
    contagemC_quick(10000);
    contagemC_quick(100000);
    contagemC_quick(1000000);
    
    printf("\n\nquick decrescente:");
    contagemD_quick(100);
    contagemD_quick(1000);
    contagemD_quick(10000);
    contagemD_quick(100000);
    contagemD_quick(1000000);
    
    printf("\n\nquick aleatorio:");
    contagemR_quick(100);
    contagemR_quick(1000);
    contagemR_quick(10000);
    contagemR_quick(100000);
    contagemR_quick(1000000);
    
    printf("\nmerge crescente:");
    contagemC_merge(100);
    contagemC_merge(1000);
    contagemC_merge(10000);
    contagemC_merge(100000);
    contagemC_merge(1000000);
    
    printf("\n\nmerge decrescente:");
    contagemD_merge(100);
    contagemD_merge(1000);
    contagemD_merge(10000);
    contagemD_merge(100000);
    contagemD_merge(1000000);
    
    printf("\n\nmerge aleatorio:");
    contagemR_merge(100);
    contagemR_merge(1000);
    contagemR_merge(10000);
    contagemR_merge(100000);
    contagemR_merge(1000000);
    
     printf("\nheap crescente:");
    contagemC_heap(100);
    contagemC_heap(1000);
    contagemC_heap(10000);
    contagemC_heap(100000);
    contagemC_heap(1000000);
    
    printf("\n\nmerge decrescente:");
    contagemD_heap(100);
    contagemD_heap(1000);
    contagemD_heap(10000);
    contagemD_heap(100000);
    contagemD_heap(1000000);
    
    printf("\n\nmerge aleatorio:");
    contagemR_heap(100);
    contagemR_heap(1000);
    contagemR_heap(10000);
    contagemR_heap(100000);
    contagemR_heap(1000000);
    
    return 0;
}
