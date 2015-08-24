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
      insercao_direta(vet, tam);
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

void insercao_direta(int numeros[], int N)
 {
 int ivet, numeroAInserir, isubv;
    for (ivet=1; ivet<N; ivet++)
    {
      numeroAInserir = numeros[ivet];
      isubv = ivet;
      while ((isubv>0) && (numeros[isubv-1]>numeroAInserir))
      {
        numeros[isubv] = numeros[isubv-1];
        insubv--;
      }
      numeros[isubv] = numeroAInserir;
    }
 }
