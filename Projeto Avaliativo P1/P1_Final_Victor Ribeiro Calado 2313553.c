//Victor Ribeiro Calado
//RA 2313553

//		P1 Entrega FINAL - Estrutura de Dados 2
//               Prof Fabio Fernandes Da Rocha Vicente

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

//Inclusão da Função InsertionSort

void insertionSort(int arr[], int n, int* trocas, int* comparacoes) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
        	
        	//Incrementação das trocas e as comparacoes
        	(*trocas)++;
        	(*comparacoes)++;
        	
            printf("Trocou: %d com %d\n", arr[j], key);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}//OK

//Inclusão da Função SelectionSort

void selectionSort(int arr[], int n, int* trocas, int* comparacoes) {
	
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        
        for (j = i+1; j < n; j++) {
        	
        	//Incrementação das comparações
            (*comparacoes)++;
            
            if (arr[j] < arr[min_idx])
            	
                min_idx = j;
        }
        if (min_idx != i) {
        	
        	//Incrementação das trocas
        	(*trocas)++;
        	
            printf("Trocou: %d com %d\n", arr[i], arr[min_idx]);
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}//OK


int main() {
    int tamconju;
    int vectA[MAX_N] = {0}; 
	int vectB[MAX_N] = {0};
    
    printf("Informe o tamanho dos conjuntos:");
    scanf("%d", &tamconju);// Armazena no endereço de N
    
//Se o valor for 0 algoritmo vai parar
	if (tamconju ==0){
		printf("Valor primario e zero, encerrando o software.\n");
		return 0;
	}//OK

    int posA = 0, posB = 0;
    int i;
    
    for ( i = 0; i < tamconju * 2; i++) {
        int num;
        char set;
        
	printf("Informe um numero seguido do conjunto A ou B:");
	scanf("%d %c", &num, &set);
        
        //Reconhecimento de A ou B
        if (set == 'A') { 
            if (posA < tamconju) {//Reconhecimento se A esta cheio
                vectA[posA++] = num;//Inclusão de indice 
            } else {
                printf("Tamanho do conjunto A cheio.\n");
                return 1;//Encerramento do software com erro
		}
        } else if (set == 'B') {
            if (posB < tamconju) {//Reconhecimento se B esta cheio
                vectB[posB++] = num;//Inclusão de indice
            } else {
                printf("Tamanho do conjunto B cheio.\n");
                return 1;//Encerramento do software com erro
		}
        } else {
            printf("Conjunto invalido.\n");
            return 1;//Encerramento do software com erro
        }
}//OK
   
//Print do Conjunto A    
    printf("Conjunto A:");
    for (i = 0; i < posA; i++) {
    printf("%d ", vectA[i]);
}//OK
    
    printf("\n");
	
//Print do Conjunto B    
    printf("Conjunto B:");
    for ( i = 0; i < posB; i++) {
    printf("%d ", vectB[i]);
}//OK
	
	    
printf("\n");
    
//Print do InsertionSort/ trocas e comparacoes

int trocas = 0, comparacoes = 0;
printf("\nInsertionSort\n");
insertionSort(vectA, posA, &trocas, &comparacoes);
printf("InsetionSort:trocas:%d  Comparacoes:%d\n", trocas, comparacoes);
//OK
    
//Print do SelectionSort/ trocas e comparacoes
	
trocas = 0, comparacoes = 0;
printf("\nSelectionSort\n");
selectionSort(vectB, posB, &trocas, &comparacoes);
printf("SelectionSort: trocas:%d  Comparacoes:%d\n", trocas, comparacoes);
//OK
    
    return 0;
}
