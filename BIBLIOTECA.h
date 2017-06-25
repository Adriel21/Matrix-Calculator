#include <stdio.h>
#include <stdlib.h>


// FUNÇÔES DOS VETORES
struct Vetor {
	int *ender;
	int elem;
};

//FUNÇÃO PARA A LEITURA DE VETORES

struct Vetor leituraDeVet (int elem){
	int i;
	struct Vetor vetor;
	vetor.elem=elem;
	vetor.ender= (int *) malloc(vetor.elem*sizeof(int));
	printf("\n\n");
    for(i=0; i<vetor.elem; i++){                              // LAÇO PARA PERCORRER OS ESPAÇOS E ARMAZENAR O VALOR DIGITADO NA MEMÓRIA
    	printf("Elemento %d: ", i+1);
    	scanf("%d", &vetor.ender[i]);
	
	}
	
	printf("\n\n");
	return vetor;
}			

//FUNÇÃO PARA EXIBIR OS VETORES

void exibicaoDeVet (struct Vetor vetor){
	int i;
	printf("(");
	for(i=0; i<vetor.elem; i++){                                         //LAÇO PARA PERCORRER OS ESPAÇOS NA MEMÓRIA E PRINTAR NA TELA O VALOR QUE ESTÁ EM TAL ESPAÇO
		if(i != vetor.elem-1){                                           // IF E ELSE PARA ORGANIZAR A BELEZA DO VETOR QUANDO O MESMO FOR PRINTADO
			printf("%d,", vetor.ender[i]);
		}
		else{
			printf("%d)", vetor.ender[i]);
		}
	}
}

//FUNÇÃO PARA SOMAR OS VETORES

struct Vetor somaDeVet (struct Vetor vetorA , struct Vetor vetorB){
	int i;
	struct Vetor vetorRes;
	vetorRes.ender= (int *) malloc(vetorA.elem*sizeof(int));
	for(i=0; i< vetorA.elem; i++){                                                          //lAÇO PARA SOMAR CADA VALOR DE MESMA POSIÇÃO ENTRE OS DOIS VETORES CRIADOS PELO USUÁRIO
		vetorRes.ender[i]= vetorA.ender[i] + vetorB.ender[i];
	}
	return vetorRes;
}

//FUNÇÃO PARA MULTIPLICAR UM DOS VETORES POR UM NÚMERO ESCALAR

struct Vetor produtoPorEscalar (struct Vetor vetor, int multiplicador){
	int i;
	struct Vetor vetorRes;
	vetorRes.elem=vetor.elem;
	vetorRes.ender= (int *) malloc(vetor.elem*sizeof(int));
	for(i=0; i< vetor.elem; i++){                                                           //LAÇO PARA MULTIPLICAR CADA POSIÇÃO DO VETOR PELO NÚMERO ESCALAR ESCOLHIDO PELO USUÁRIO
		vetorRes.ender[i]= multiplicador*vetor.ender[i];
	}
	return vetorRes;
}

//FUNÇÃO PARA O PRODUTO ESCALAR ENTRE OS VETORES

int produtoEscalar(struct Vetor vetorA , struct Vetor vetorB){
	int i;
	int Res=0;
	
	for(i=0; i< vetorA.elem; i++){                                                         // LAÇO PARA MULTIPLICAR A MESMA POSIÇÃO DE CADA VETOR E SOMAR AS RESPOSTAS
		
		Res = Res + (vetorA.ender[i]*vetorB.ender[i]);
	}
	return Res;
}

//   FIM DAS FUNÇÔES DOS VETORES








//FUNÇÔES DAS MATRIZES

struct Matriz {
	int Linhas;
	int Colunas;
	int **ender;
};

    int i, lin, col;
	
//FUNÇÃO DE LEITURA DE MATRIZES

struct Matriz leituraDeMat( int linhas, int colunas){
	
	struct Matriz matriz;
	
	matriz.Linhas=linhas;
	matriz.Colunas=colunas;
		
	matriz.ender= (int**) malloc(matriz.Linhas*sizeof (int*));
	
	for(i = 0; i < matriz.Linhas ; i++) {
        matriz.ender[i]= (int*) malloc(matriz.Colunas*sizeof (int*));
	}

	
	for(lin = 0; lin < matriz.Linhas ; lin++){                                          //LAÇO PARA PERCORRER OS ESPAÇOS E ARMAZENAR O VALOR DIGITADO NA MEMÓRIA
		for(col = 0; col < matriz.Colunas ; col++){
			printf("Digite o elemento [%i][%i]: ", lin+1, col+1);
			scanf("%i", &matriz.ender[lin][col]);
		}
		printf("\n");
	}
    
    return matriz;
}

//FUNÇÃO DE EXIBIÇÃO DE MATRIZES

void exibicaoDeMat( struct Matriz matriz){
 

	for(lin = 0; lin < matriz.Linhas; lin++){                               //LAÇO PARA PERCORRER OS ESPAÇOS NA MEMÓRIA E PRINTAR NA TELA O VALOR QUE ESTÁ EM TAL ESPAÇO
		printf("| ");
		for(col = 0; col < matriz.Colunas; col++){
			if(col < matriz.Colunas-1){                                     // IF E ELSE PARA ORGANIZAR A BELEZA DA MATRIZ QUANDO A MESMA FOR PRINTADA
			    printf("%i, ", matriz.ender[lin][col]);			
			}
			else{
				printf("%i |\n", matriz.ender[lin][col]);	
			}
		}

	}
    printf("\n\n");

}

//FUNÇÃO DE SOMA DE MATRIZES

struct Matriz somaDeMat( struct Matriz matrizA, struct Matriz matrizB){
	
	struct Matriz matrizRes;
	
	matrizRes.Linhas= matrizA.Linhas;
	matrizRes.Colunas= matrizA.Colunas;
	
	matrizRes.ender= (int**) malloc(matrizA.Linhas*sizeof (int*));
	
	for(i = 0; i < matrizA.Linhas ; i++) {
        matrizRes.ender[i]= (int*) malloc(matrizA.Colunas*sizeof (int*));
	}
	
	
	for(lin = 0 ; lin < matrizA.Linhas ; lin++){                                                //lAÇO PARA SOMAR CADA VALOR DE MESMA POSIÇÃO ENTRE AS DUAS MATRIZES CRIADAS PELO USUÁRIO
		for( col = 0; col < matrizA.Colunas; col++){
			matrizRes.ender[lin][col] = matrizA.ender[lin][col] + matrizB.ender[lin][col];
		}
	}
	return matrizRes;
}

//FUNÇÃO DE MATRIZES TRANSPOSTAS 

struct Matriz transpostaDeMat( struct Matriz matriz){
	
	struct Matriz matrizTrans;
	
    matrizTrans.Colunas = matriz.Linhas;
    matrizTrans.Linhas = matriz.Colunas;
    
	matrizTrans.ender= (int**) malloc(matriz.Linhas*sizeof (int*));
	
	for(i = 0; i < matriz.Linhas ; i++) {
        matrizTrans.ender[i] = (int*) malloc(matriz.Colunas*sizeof (int*));
	}
	
	for (lin=0; lin< matriz.Linhas ; lin++){                                           //LAÇO PARA "TROCAR" AS POSIÇÕES DOS VALORES DIGITADOS NAS DETERMINADAS MEMÓRIAS PELO USUÁRIO ( TROCA A LINHA PELA COLUNA E VIRSE-VERSA )
		for(col=0; col< matriz.Colunas ; col++){
			matrizTrans.ender[col][lin]= matriz.ender[lin][col];
		}
	}
	
	return matrizTrans;

}

//FUNÇÃO DE MULTIPLICAÇÃO DE MATRIZES

struct Matriz multiplicacaoDeMat ( struct Matriz matrizA , struct Matriz matrizB ){
	
	int linha, coluna;
	
	struct Matriz matrizMulti;
	
	matrizMulti.Linhas= matrizA.Linhas;
	matrizMulti.Colunas= matrizB.Colunas;
	
	matrizMulti.ender= (int**) malloc(matrizA.Linhas*sizeof (int*));
	
	for(i = 0; i < matrizA.Linhas ; i++) {
        matrizMulti.ender[i] = (int*) malloc(matrizMulti.Colunas*sizeof (int*));
	}
	
	for(linha = 0; linha < matrizMulti.Linhas ; linha++){                                    // lAÇO PARA ZERAR TODAS AS POSIÇÕES DE MEMÓRIA DA MATRIZ, POIS PODE OCORRER UM ERRO SE JÁ HOUVER PREVIAMENTE UM VALOR ARMAZENADO EM TAL LOCAL E ACABAR IMPRIMINDO UM NÚMERO EQUIVOCADO
		for( coluna = 0; coluna < matrizMulti.Colunas ; coluna++){  
			matrizMulti.ender[linha][coluna] = 0;                 
		}  
	}
	matrizB = transpostaDeMat( matrizB );
	
	for (lin = 0; lin < matrizMulti.Linhas ; lin++){                                          //LAÇOS PARA PERCORRER OS DEVIDOS LOCAIS E ORGANIZAR AS OPERAÇÕES DEVIDAMENTE 
		for(col = 0; col < matrizMulti.Colunas ; col++){
			for ( i = 0 ; i < matrizA.Colunas ; i++){
				
				matrizMulti.ender[lin][col] += (matrizA.ender[lin][i]*matrizB.ender[col][i]);
				
			}
		}
	}
	
	return matrizMulti;
}

//FUNÇÃO PARA DETERMINAR O DETERMINANTE DE MATRIZES DE ORDENS 1X1, 2X2 OU 3X3

int determinanteDeMat (struct Matriz matriz) {
	
	if( (matriz.Linhas*matriz.Colunas)== 1 ){                                      // IF CASO A MATRIZ SEJA DE ORDEM 1X1
		
		return matriz.ender[0][0];
	}
	if(( matriz.Linhas*matriz.Colunas)== 4 ){                                      // IF CASO A MATRIZ SEJA DE ORDEM 2X2
		
		return ( 
		
		         (matriz.ender[0][0]*matriz.ender[1][1])                            // Multiplicação da diagonal principal
		          
				 -                                                                        // ( menos )
				 
				 (matriz.ender[0][1]*matriz.ender[1][0])                            // Multiplicação da diagonal secundária
				 
			   );
		
	}
	if( (matriz.Linhas*matriz.Colunas)== 9 ){                                      // IF CASO A MATRIZ SEJA DE ORDEM 3X3
		
		return ( 
		  
		           ( (matriz.ender[0][0]*matriz.ender[1][1]*matriz.ender[2][2])+          //Multiplicação da primeira diagonal principal ( mais )
				  (matriz.ender[0][1]*matriz.ender[1][2]*matriz.ender[2][0])+             //Multiplicação da segunda diagonal principal ( mais )
				  (matriz.ender[0][2]*matriz.ender[1][0]*matriz.ender[2][1]) )            //Multiplicação da terceira diagonal principal 
				  
				  -                                                                       // ( Menos )
				  
			   	( (matriz.ender[2][0]*matriz.ender[1][1]*matriz.ender[0][2])+             //Multiplicação da primeira diagonal secundária ( mais )
				  (matriz.ender[2][1]*matriz.ender[1][2]*matriz.ender[0][0])+             //Multiplicação da segunda diagonal secundária ( mais )
				  (matriz.ender[2][2]*matriz.ender[1][0]*matriz.ender[0][1]) )             //Multiplicação da terceira diagonal secundária 
				  
			   );
				
	}	
	
	return 0;
}

//FUNÇÃO DE VERIFICAR SE UMA MATRIZ É OU NÃO SIMETRICA

void matrizSimetrica (struct Matriz matriz, struct Matriz matrizTrans){
     
    int posicaoCoincidente;
    
     matrizTrans= transpostaDeMat(matriz);
	
	for (lin=0; lin< matriz.Linhas ; lin++){                               // LAÇO PARA VERIFICAR SE HÁ IGUALDADE NAS MESMAS POSIÇÕES DE UMA MATRIZ E SUA TRANSPOSTA
		for(col=0; col< matriz.Colunas ; col++){
			if(matriz.ender[lin][col] == matrizTrans.ender[lin][col]){               // IF PARA CASO AS POSIÇÕES SEJAM IGUAIS,  AUMENTAR O CONTADOR CRIADO COM +1
				posicaoCoincidente++;
			}
		}
	}
	
	
	    if (posicaoCoincidente == (matriz.Linhas * matriz.Colunas)){                 // IF PARA VERIFICAR SE O VALOR FINAL DO CONTADOR COINCIDE COM A MULTIPLICAÇÃO DO TAMANHO DA LINHA E DA COLUNA DA MATRIZ
			printf("\n\n E simetrica. \n\n");
		}
		
		else{
		printf("\n\n Nao e simetrica. \n\n");
		}
	
}

// FIM DAS FUNÇÕES 
