#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int number;
  struct Node * next;

}Node;

typedef struct Pilha{
  Node * topo;
}Pilha;

typedef struct Fila{
  Node * inicio;
  Node * fim;
}Fila;

void inicializa_pilha(Pilha *p){
  p->topo = NULL;
}

void push(int number, Pilha *p){
  Node *ptr = (Node*) malloc(sizeof(Node));
  if(ptr == NULL)
  {
    printf("Não foi possível alocar o novo valor na memória.");
  }
  else
  {
    if (number <= 0) {
      return;
    }
    else {
    ptr->number = number;
    ptr->next = p->topo;
    p->topo = ptr;
    }
  }
}

int pop(Pilha *p){
  Node* ptr = p->topo;
  int number;
  if(ptr == NULL)
  {
  	printf("Pilha vazia.\n");
  }
  else
  {
  	p->topo = ptr->next;
  	ptr->next = NULL;
  	number = ptr->number;
  	free(ptr);
  	return number;
  }
}

void imprimir_pilha(Pilha *p){
	Node *ptr = p->topo;
	if(ptr == NULL)
	{
		printf("Pilha vazia.\n");
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			printf("%d\n", ptr->number);
			ptr = ptr->next;
		}
		printf("\n");
  }
}
void imprimir_fila(Fila *f){
	Node *ptr = f->inicio;
	if(ptr == NULL)
	{
		printf("Fila vazia.\n");
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			printf("%d ", ptr->number);
			ptr = ptr->next;
		}
		printf("\n");
  }
}

void inicializa_fila(Fila *f){
  f->inicio = NULL;
  f->fim = NULL;
}

void enqueue(int number, Fila *f){
  Node *ptr = (Node*) malloc(sizeof(Node));
  if(ptr == NULL)
  {
    printf("Não foi possível alocar o novo valor na memória.");
  }
  else
  {
    ptr->number = number;
    ptr->next = NULL;
    if (f->inicio == NULL)
    {
      f->inicio = ptr;
    }
    else 
    {
      f->fim->next = ptr;
    }
    f->fim = ptr;
  }
}

int dequeue(Fila *f){
  Node *ptr = f->inicio;
  int number;
  if(ptr == NULL)
  {
  	printf("Fila vazia.\n");
  }
  else
  {
  	f->inicio = ptr->next;
  	ptr->next = NULL;
  	number = ptr->number;
  	free(ptr);
    if (f->inicio == NULL) 
    {
      f->fim = NULL;
    }
    return number;
  }
}

int main(void) {
  int valor;
  Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
  Fila *fila_impar = (Fila*) malloc (sizeof(Fila));
  Fila *fila_par = (Fila*) malloc (sizeof(Fila));

  inicializa_pilha(p1);
  inicializa_fila(fila_impar);
  inicializa_fila(fila_par);

  if(p1 == NULL)
  {
     printf("Erro de alocação da pilha.\n");
     exit(0);
  }
  else {
    printf("\nInforme valores para a pilha: \n");
    
    do {
      scanf("%d", &valor);
      push(valor, p1);
       if (valor % 2 == 1) {
         enqueue(valor, fila_impar);
       }
       else if (valor % 2 == 0) {
         enqueue(valor, fila_par);
       }   
      if (valor <= 0) {
        break;
       }
    }while(valor > 0);
    }

  printf("\nPilha: \n");
  imprimir_pilha(p1);
  printf("\n");
  printf("Fila par: ");
  imprimir_fila(fila_par);
  printf("\n");
  printf("Fila impar: ");
  imprimir_fila(fila_impar);
  
  
return 0;
}