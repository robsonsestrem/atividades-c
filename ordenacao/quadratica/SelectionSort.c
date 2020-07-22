#include <stdio.h>
#include <stdlib.h>


void troca(int* a, int* b);
void mostrar(int vec[], int tamanho);
int selectionSort(int vec[], int tam);

int main(){
    int vetor[] = {4, 3, -2, -3, 2};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    mostrar(vetor, tamanho);
    printf("Vetor ordenado com %d trocas.\n\n", selectionSort(vetor, tamanho));
    mostrar (vetor, tamanho);
}

//Aplica o modo selectionSort
int selectionSort(int vec[], int tam){
	int i, j, min, qtd=0;
	for (i = 0; i < (tam-1); i++){
		min = i;
		for (j = (i+1); j < tam; j++) {
			if(vec[j] < vec[min]) {
				min = j;
			}
			qtd++;
			mostrar(vec, tam);
			//na apostila o qtd++ está errado
			//e foi colocado neste ponto
		}
		if (i != min) {
			troca(&vec[i], &vec[min]);
			//Testado qtd++ aqui;
			
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


