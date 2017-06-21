#include <stdio.h>
#include <stdlib.h>

struct Vetor {
	int *ender;
	int elem;
};

struct Vetor leituraDeVet (int elem){
	int i;
	struct Vetor vetor;
	vetor.elem=elem;
	vetor.ender= (int *) malloc(vetor.elem*sizeof(int));
	printf("\n\n");
    for(i=0; i<vetor.elem; i++){
    	printf("Elemento %d: ", i+1);
    	scanf("%d", &vetor.ender[i]);
    	
	printf("\n\n");
	
	return vetor;
	}
}			
