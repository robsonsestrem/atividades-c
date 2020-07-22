#include <stdio.h>
#include <stdlib.h>


void troca(int* a, int* b);
int bubbleSort(int vec[]);
void mostrar(int vec[], int tamanho);


int main(){
    int vetor[] = {4, 3, -2, -3, 2};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    mostrar(vetor, tamanho);
    printf("Vetor ordenado com %d trocas.\n\n", bubbleSort(vetor));
    mostrar (vetor, tamanho);
}

//Aplicando o booblesort
int bubbleSort(int vec[]){
	int qtd=0, i, j, tmp;
	for (i = 0; i < 5 -1; i++) {
		for (j = i+1; j < 5; j++){
			if (vec[i] > vec[j]){
				troca(&vec[i], &vec[j]);	
				//qtd++;
	    		mostrar(vec, 5);
			}
			qtd++;
			//na apostila o qtd++ está errado
			//e foi colocado neste ponto
		}
	}
	return(qtd);
}


//Função genérica de troca de valores
void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//Função mostrar vetor ordenado
void mostrar(int vec[], int tamanho){
  int i;
  printf("[  ");
  for (i = 0; i < tamanho; i++ ){
    printf("%d  ",vec[i]);
  }
  printf("]\n\n");
}

