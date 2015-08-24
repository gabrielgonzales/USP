#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
int tam, i;
clock_t init, end;
int *vet;

   // aloca vetor com tamanhos comecando em 500 e incrementando de 200 em 200
   for (tam = 1000; NULL != (vet = malloc(tam * sizeof(int) )) ; tam *= 1.1 )
   {
      // preenche  vetor com numeros aleatorios
      printf("Tamanho do vetor: %d \n", tam );
      for (i = 0; i < tam; i++)
      {
         vet[i] = rand();
      }

      // conta o tempo decorrido em micro segundos
      init = clock();
      selecao_direta(vet, tam);
      end = clock();
      end = (end - init) / (CLOCKS_PER_SEC / 1000);

      // mostra o tempo decorrido
      printf("\tTempo decorrido (1/1000 s): %ld\n", end);
/*      for (i = 0; i < tam; i++)
      {
         printf("%d ", vet[i]);
      }
      printf("\n");
*/
    // libera o vetor
      free(vet);
   }

}

void selecao_direta(int numeros[], int N)
 {
 int prox, iMenor, i;
    for (prox=0; prox < N - 1; prox++) // percorre vetor principal
    {
      // o primeiro elemento do vetor é o menor elemento inicialmente
      iMenor = prox;

      // percorre subvetor procurando o menor elemento
      for (i = prox + 1; i < N; i++)
      {
          if (numeros[i] < numeros[iMenor])
              iMenor = i;
      }

      // executa a troca da próxima posição com o menor elemento encontrado no subvetor
      int temp = numeros[prox];
      numeros[prox] = numeros[iMenor];
      numeros[iMenor] = temp;
    }
  }
