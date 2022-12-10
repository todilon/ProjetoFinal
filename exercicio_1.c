#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int number;
  struct Node * next;

}Node;

typedef struct Pilha{
  Node * topo;
}Pilha;

void inicializa(Pilha *p){
  p->topo = NULL;
}

void push(int number, Pilha *p){
  Node *ptr = (Node*) malloc(sizeof(Node));
  if(ptr == NULL)
  {
    printf("Não foi possível alocar o novo valor na memória.");
   // return;
  }
  else
  {
    ptr->number = number;
    ptr->next = p->topo;
    p->topo = ptr;
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

void imprimir(Pilha *p){
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

void encontrar(Pilha *p, int valor){
	Node *ptr = p->topo;
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
    printf("\nO valor informado existe na pilha.\n");
  }
  else
  {
    printf("\nO valor informado não existe na pilha.\n");
  }
}


int main(void) {
  int opcao, valor, limite, localizar, contador = 0;
  Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));

  printf("Informe um limite para a Pilha: ");
  scanf("%d", &limite);
  inicializa(p1);
  do
  {

  printf("\n 0 - Sair\n 1 - Inserir\n 2 - remover\n 3 - Exibir quantidade de elementos\n 4 - Exibir todos os valores contidos na Pilha\n 5 - Encontrar um valor na pilha\n\n");
    
  printf("\nDigite a opção desejada: ");
  scanf("%d", &opcao);

  switch(opcao)
  {
    case 1:
    if(p1 == NULL)
    {
      printf("Erro de alocação da pilha.\n");
      exit(0);
    }
    else if(contador == limite)
    {
      printf("\nA pilha está cheia, remova um valor para continuar ou digite 0 para sair.\n");
      break;
    }
    else
    {
      {     
        printf("\nInforme um valor: ");
        scanf("%d", &valor);
        push(valor, p1); 
        contador++;
      }
    }
    break;

    case 2:
     pop(p1);
     contador--;
    break;

    case 3:
      printf("\nQuantidade de elementos contidos na pilha: %d\n", contador);
    break;
    
    case 4:
      imprimir(p1);
    break;

    case 5:
      printf("\nInforme o valor que deseja encontrar: ");
      scanf("%d", &localizar);
      encontrar(p1, localizar);
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