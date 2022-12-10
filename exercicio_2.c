#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int number;
  struct Node * next;
}Node;

typedef struct Fila{
  Node *inicio;
  Node *fim; 
}Fila;

void inicializa(Fila *f){
  f->inicio = NULL;
  f->fim = NULL;
}

void enqueue(int number, Fila *f){
  Node *ptr = (Node*) malloc(sizeof(Node));
  if(ptr == NULL)
  {
  	printf("Erro de alocação.\n");
  	return;
  }
  else
  {
    ptr->number = number;
    ptr->next = NULL;
    if(f->inicio == NULL)
    {
      f->inicio = ptr;
    }
    else
    {
      f->fim->next = ptr;
  }
  f->fim = ptr;
  return;
  }
}


int dequeue(Fila *f){
 Node *ptr = f->inicio;
 int number;
 if(ptr != NULL)
 {
	f->inicio = ptr->next;
	ptr->next = NULL;
	number = ptr->number;
	free(ptr);
	if(f->inicio == NULL)
	{
		f->fim = NULL;
	}
	return number;
 }
 else
 {
	printf("Fila vazia.\n");
	return 0;
 }
}

void exibir(Fila *f){
  Node *ptr = f->inicio;
  if(ptr != NULL)
  {
    while(ptr != NULL)
    {
      printf("%d\n", ptr->number);
      ptr = ptr->next;
    }
  }
  else
  {
    printf("Fila vazia.\n");
    return;
  }
}

void encontrar(Fila *f, int valor){
	Node *ptr = f->inicio;
  int aux;
	if(ptr == NULL)
	{
		printf("Pilha vazia.\n");
		return;
	}
	else
	{
		while(ptr != NULL)
		{
      if(valor == ptr->number)
      {
        aux = 1;
        break;
      }
      else
      {
        aux = 2;
      }
			ptr = ptr->next;
		}
  }

  if(aux == 1)
  {
    printf("\nO valor informado existe na fila.\n");
  }
  else
  {
    printf("\nO valor informado não existe na fila.\n");
  }
}



int main(void) {
  int opcao, valor, limite, localizar, contador = 0;
  Fila *f1 = (Fila*) malloc(sizeof(Fila));
  printf("Informe um limite para a fila: ");
  scanf("%d", &limite);
  inicializa(f1);
  do
  {

  printf("\n 0 - Sair\n 1 - Inserir\n 2 - remover\n 3 - Exibir quantidade de elementos\n 4 - Exibir todos os valores contidos na fila\n 5 - Encontrar um valor na fila\n\n");
    
  printf("\nDigite a opção desejada: ");
  scanf("%d", &opcao);

  switch(opcao)
  {
    case 1:
    if(f1 == NULL)
    {
      printf("Erro de alocação na fila.\n");
      exit(0);
    }
    else if(contador == limite)
    {
      printf("\nA fila está cheia, remova um valor para continuar ou digite 0 para sair.\n");
      break;
    }
    else
    {
      {     
        printf("\nInforme um valor: ");
        scanf("%d", &valor);
        enqueue(valor, f1); 
        contador++;
      }
    }
    break;

    case 2:
     dequeue(f1);
     contador--;
    break;

    case 3:
      printf("\nQuantidade de elementos contidos na fila: %d\n", contador);
    break;
    
    case 4:
      exibir(f1);
    break;

    case 5:
      printf("\nInforme o valor que deseja encontrar: ");
      scanf("%d", &localizar);
      encontrar(f1, localizar);
    break;

    default:
    if(opcao != 0)
    {
      printf("\nOpção inválida.\n");
    }  
  }
}while(opcao != 0);
  return 0;
}