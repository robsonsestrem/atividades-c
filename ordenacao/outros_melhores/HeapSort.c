#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int heapSort(int vec[], int tam);
int heapifica(int vec[], int tam, int i);
int constroiHeap(int vec[], int tam);
void troca(int* a, int* b);
void mostrar(int vec[], int tamanho);


int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int vetor[] = {4,3,-2,-3,2};

    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    mostrar(vetor, tamanho);
    
    printf("Vetor ordenado com %d trocas.\n\n", heapSort(vetor, tamanho));
   
    mostrar(vetor, tamanho);
}

//Ordena com base na estrutura heap
int heapSort(int vec[], int tam) {
	int n, i, qtd;
	qtd = 0;
	qtd += constroiHeap(vec, tam);
	n = tam;
	for(i=tam-1;i>0;i--) {
		troca(&vec[0], &vec[i]);
		n--;
		qtd += heapifica(vec, n, 0);
	}
	return qtd;
}

//Garante as propriedades de heap a um nó
int heapifica(int vec[], int tam, int i) {
	int e, d, maior, qtd;
	qtd = 1;
	e = 2*i+1;
	d = 2*i+2;
	if(e<tam && vec[e] > vec[i]) {
	 maior = e;
	}
	else {
	 maior = i;
	}
	if(d<tam && vec[d] > vec[maior]) {
	 maior = d;
	}
	if(maior != i) {
	 troca(&vec[i], &vec[maior]);
	 qtd += heapifica(vec, tam, maior);
	}
	return qtd;
}

//Transforma o vetor em uma heap
int constroiHeap(int vec[], int tam) {
	int i, qtd;
	qtd = 0;
	for(i=tam/2;i>=0;i--){
		qtd += heapifica(vec, tam, i);
	}
	return qtd;
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





