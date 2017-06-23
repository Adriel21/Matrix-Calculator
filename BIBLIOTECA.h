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
	
	}
	
	printf("\n\n");
	return vetor;
}			

void exibicaoDeVet (struct Vetor vetor){
	int i;
	printf("(");
	for(i=0; i<vetor.elem; i++){
		if(i != vetor.elem-1){
			printf("%d,", vetor.ender[i]);
		}
		else{
			printf("%d)", vetor.ender[i]);
		}
	}
}

struct Vetor somaDeVet (struct Vetor vetorA , struct Vetor vetorB){
	int i;
	struct Vetor vetorRes;
	vetorRes.ender= (int *) malloc(vetorA.elem*sizeof(int));
	for(i=0; i< vetorA.elem; i++){
		vetorRes.ender[i]= vetorA.ender[i] + vetorB.ender[i];
	}
	return vetorRes;
}

struct Vetor produtoPorEscalar (struct Vetor vetor, int multiplicador){
	int i;
	struct Vetor vetorRes;
	vetorRes.elem=vetor.elem;
	vetorRes.ender= (int *) malloc(vetor.elem*sizeof(int));
	for(i=0; i< vetor.elem; i++){
		vetorRes.ender[i]= multiplicador*vetor.ender[i];
	}
	return vetorRes;
}

int produtoEscalar(struct Vetor vetorA , struct Vetor vetorB){
	int i;
	int Res;
	struct Vetor vetorRes;
	vetorRes.elem=vetorA.elem;
	vetorRes.ender= (int *) malloc(vetorA.elem*sizeof(int));
	for(i=0; i< vetorA.elem; i++){
		vetorRes.ender[i] = vetorA.ender[i]*vetorB.ender[i];
		Res+= vetorRes.ender[i];
	}
	return Res;
}
