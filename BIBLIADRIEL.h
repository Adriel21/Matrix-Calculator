#include <stdio.h>
void ExibirVetor(int n, int cont1, int cont2, int V, int E);

void ExibirVetor(int n, int cont1, int cont2, int V, int E){
	            printf("\nQuantos vetores voce quer expressar? ");
				scanf("%d", &V);
				printf("\nDigite a quantidade de elementos de cada vetor ");
				scanf("%d", &E);
				
				int MatrizQ[V][E];
				
				for(cont1=0; cont1<V; cont1++){
					printf("Digite os elementos do vetor %d\n", cont1+1);
					    for(cont2=0; cont2<E; cont2++){
					    	scanf("%d", &MatrizQ[cont1][cont2]);
						}
				}
				
				for(cont1=0; cont1<V; cont1++){
					printf("Vetor %d", cont1+1);
					printf("(");
					for(cont2=0; cont2<E; cont2++){
						if(cont2!= E-1){
							printf("%d,", MatrizQ[cont1][cont2]);	
						}
						
						else if(cont2==E-1){
							printf("%d)\n", MatrizQ[cont1][cont2]);
						}
					}
				}
}
