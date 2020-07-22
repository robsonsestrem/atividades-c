#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int quickSort(int vec[], int left, int right, int qtd);
int particiona(int vec[], int left, int right);
void troca(int* a, int* b);
void mostrar(int vec[], int tamanho);


int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int vetor[] = {1,9,3,0,9,1,0,5};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    //inicio e fim
    int left=0, right = tamanho-1, qtd;
    printf("Vetor com RA: \n");
    mostrar(vetor, tamanho);
    printf("Vetor da RA ordenado com %d trocas.\n\n", quickSort(vetor, left, right, qtd));
    mostrar(vetor, tamanho);
}

//Aplica o modo do quickSort
int quickSort(int vec[], int left, int right, int qtd) {
	int r;
	if (right > left) {
		r = particiona(vec, left, right);
		qtd = quickSort(vec, left, r - 1, qtd);
		qtd = quickSort(vec, r + 1, right, qtd);
	}
	
return (qtd +1);
}

//Divide o vetor em pedaços menores
int particiona(int vec[], int left, int right) {
	int i, j;
	i = left;
	for (j = left + 1; j <= right; ++j) {
		if (vec[j] < vec[left]) {
			++i;
			troca(&vec[i], &vec[j]);
		}
	}
	troca(&vec[left], &vec[i]);
return i;
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




