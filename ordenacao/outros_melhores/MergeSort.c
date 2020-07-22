#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void junta(int vec[], int tam);
int mergeSort(int vec[], int tam, int qtd);
void mostrar(int vec[], int tamanho);
int qtd = 0;


int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int vetor[] = {4,3,-2,-3,2};

    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    mostrar(vetor, tamanho);
    
    printf("Vetor ordenado com %d trocas.\n\n", mergeSort(vetor, tamanho, qtd));
   
    mostrar(vetor, tamanho);
}

//Aplica o modo mergeSort
int mergeSort(int vec[], int tam, int qtd) {
	int meio;
	if (tam > 1) {
		meio = tam / 2;
		qtd = mergeSort(vec, meio, qtd);
		qtd = mergeSort(vec + meio, tam - meio, qtd);
		junta(vec, tam);
	}
	return (qtd+1);
}

//Junta os pedaços num novo vetor ordenado
void junta(int vec[], int tam) {
	int i, j, k;
	int meio;
	int* tmp;
	tmp = (int*) malloc(tam * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}

	meio = tam / 2;
	i = 0;
	j = meio;
	k = 0;
	while (i < meio && j < tam) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}
		else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == meio) {
		while (j < tam) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}
	else {
		while (i < meio) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < tam; ++i) {
		vec[i] = tmp[i];
	}
	free(tmp);
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




