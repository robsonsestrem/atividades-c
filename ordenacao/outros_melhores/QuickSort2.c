// Libs
#include <stdio.h>
#include <stdlib.h>

// Define uma constante
#define MAX 5

// Protótipo da função de ordenação
void quick_sort(int *a, int left, int right);
int qtd = 0;

// Função main
int main(int argc, char** argv)
{
	 int i, vet[MAX];
	
	 // Lê MAX ou 10 valores
	 for(i = 0; i < MAX; i++)
	 {
	  printf("Digite um valor: ");
	  scanf("%d", &vet[i]);
	 }
	
	 // Ordena os valores
	 quick_sort(vet, 0, MAX - 1);
	
	printf("\nTotal de Trocas: %d \n", qtd);
	
	 // Imprime os valores ordenados
	 printf("\nValores ordenados \n");
	 for(i = 0; i < MAX; i++)
	 {
	  printf("%d ", vet[i]);
	 }
	 system("pause");
	 return 0;
}

// Função de Ordenação por Seleção
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
            
        }
        while(a[j] > x && j > left) {
            j--;
            
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            qtd++;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
        
    }
    if(i < right) {
        quick_sort(a, i, right);
        
    }
}

