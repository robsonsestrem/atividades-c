#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b);
int insertionSort(int vec[], int tam);
void mostrar(int vec[], int tamanho);


int main(){
    int vetor[] = {4, 3, -2, -3, 2};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    mostrar(vetor, tamanho);
    printf("Vetor ordenado com %d trocas.\n\n", insertionSort(vetor, tamanho));
    mostrar (vetor, tamanho);
}

//Aplicando o insertionSort
int insertionSort(int vec[], int tam)
{
  int i, j, qtd=0;
  for(i = 1; i < tam; i++){
    j = i;
    while((vec[j] < vec[j - 1]) && (j!=0)){
      troca(&vec[j], &vec[j-1]);
      j--;
      qtd++;
      mostrar(vec, tam);
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
