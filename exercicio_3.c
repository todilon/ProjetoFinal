#include <stdio.h>
#include <stdlib.h>

void ordenaDecrescente(int vetor[], int tamanho)
{
    for (int i = 0; i <= tamanho - 1; i++)
    {
        for (int j = i; j <= tamanho - 1; j++)
        {
            if (vetor[i] < vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

void ordenaCrescente(int vetor[], int tamanho)
{
    for (int i = 0; i <= tamanho - 1; i++)
    {
        for (int j = i; j <= tamanho - 1; j++)
        {
            if (vetor[j] < vetor[i])
            {
                int temp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp;
            }
        }
    }
}


void mostrarVetor(int vetor[], int tamanho)
{
    for (int i = 0; i <= tamanho - 1; i++)
    {
        printf("%d\n", vetor[i]);
    }
}

int main()
{
    int tamanho, valor, i = 0;
    printf("Informe o tamanho da primeira Pilha: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    printf("\nInforme os valores da primeira Pilha\n");
    for(i = 0; i < tamanho; i++)
    {
      scanf("%d", &vetor[i]);
    }
    ordenaCrescente(vetor, tamanho);
  

    int tamanho2, valor2, i2 = 0;
    printf("Informe o tamanho da segunda Pilha: ");
    scanf("%d", &tamanho2);
    int vetor2[tamanho2];
    printf("\nInforme os valores da segunda Pilha\n");
    for(i2 = 0; i2 < tamanho2; i2++)
    {
      scanf("%d", &vetor2[i2]);
    }

    ordenaCrescente(vetor2, tamanho2);
    
    int tamanho3 = tamanho + tamanho2 + 1;
    int vetor3[tamanho3];
    int i3 = 0;

    for(int i3 = 0; i3 < tamanho3; i3++)
    {
      vetor3[i3] = vetor[i3];
      vetor3[i3] = vetor2[i3];    
    }

  /*  for(int i3 = 0; i3 < tamanho3; i3++)
    {
      vetor3[i3] = vetor2[i3];
    }*/

    ordenaDecrescente(vetor3, tamanho3);
  
    printf("Primeira pilha crescente:\n");
    mostrarVetor(vetor, tamanho);
    printf("\n");

    printf("Segunda pilha crescente:\n");
    mostrarVetor(vetor2, tamanho2);
    printf("\n");

    printf("Terceira pilha decrescente:\n");
    mostrarVetor(vetor3, tamanho3);
    printf("\n");
	

  return 0;

}