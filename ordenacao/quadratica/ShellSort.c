#include <stdio.h>
#include <stdlib.h>

void mostrar(int vec[], int tamanho);
int shellSort(int vec[], int tam);
void troca(int* a, int* b);

int main(){
    int vetor[] = {4, 3, -2, -3, 2};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    mostrar(vetor, tamanho);
    printf("Vetor ordenado com %d trocas.\n\n", shellSort(vetor, tamanho));
    mostrar (vetor, tamanho);
}

//Aplica o shellSort
int shellSort(int vec[], int tam) {
  int i , j , valor, qtd=0;
  int gap = 1;
  do {
    gap = 3*gap+1;
  } while(gap < tam);
  do {
    gap /= 3;
    for(i = gap; i < tam; i++) {
      valor = vec[i];
      j = i - gap;
      while (j >= 0 && valor < vec[j]) {
        vec[j + gap] = vec[j];
        j -= gap;
        qtd++;
        //mostrando as trocas
        mostrar(vec, tam);
      }
      vec[j + gap] = valor;
    }
  } while ( gap > 1);
  return (qtd);
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
  printf("[ ");
  for (i = 0; i < tamanho; i++ ){
    printf("%d  ",vec[i]);
  }
  printf("]\n\n");
}

