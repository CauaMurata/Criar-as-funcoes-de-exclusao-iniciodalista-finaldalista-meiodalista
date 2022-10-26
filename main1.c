
//FUNÇOES DE EXCLUSAO LINHA 68-109

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserir_inicio(No **lista, int num){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  }
}

void inserir_fim(No **lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    if(*lista==NULL)
      *lista=novo;
    else{
      aux = *lista;
      while(aux->proximo)
        aux=aux->proximo;
      aux->proximo=novo;
    }
  }
}

void inserir_meio(No **lista, int num, int ant){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor=num;

    if(*lista==NULL){
      novo->proximo=NULL;
      *lista=novo;
    }else{
      aux=*lista;
      while(aux->valor != ant && aux->proximo)
        aux=aux->proximo;
      novo->proximo=aux->proximo;
      aux->proximo=novo;
    }
  }
}

void imprimir(No *no){
  printf("\nLista: ");
  while(no){
    printf("%d ",no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

void remover_inicio(No **lista){
  No *remover = NULL;

  if(*lista){
    remover = *lista;
    *lista = remover->proximo;
  }else
    printf("---Lista Vazia---\n");
}

void remover_fim(No **lista){
  No *remover, *aux = NULL;

  if(*lista){
    remover = *lista;
    aux = *lista;
    while(aux->proximo){
      remover=aux;
      aux=aux->proximo;
    }
    remover->proximo=NULL; 
  }else
    printf("---Lista Vazia---\n");
}

void remover_meio(No **lista, int num){
  No *remover, *aux = NULL;
  //bool validar=false;
  
  if(*lista){
    remover = *lista;
    aux = *lista;
    while(remover->valor != num && remover->proximo){
      aux=remover;
      remover=remover->proximo;
    }
    if(num==remover->valor){
      aux->proximo=remover->proximo;
    }
  }else
    printf("---Lista Vazia---\n");
}

int main(void) {
  int opcao, valor, anterior;
  No *lista = NULL;

  do{
    printf("[1] Inserir no inicio\n[2] Inserir no fim\n[3] Inserir no meio\n[4] Remover inicio\n[5] Remover fim\n[6] Remover meio\n[7] Imprimir\n[0] Sair\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        inserir_inicio(&lista,valor);
        system("clear");
        break;
      case 2:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        inserir_fim(&lista,valor);
        system("clear");
        break;
      case 3:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        printf("\n Anterior: ");
        scanf("%d",&anterior);
        inserir_meio(&lista,valor,anterior);
        system("clear");
        break;
      case 4:
        system("clear");
        remover_inicio(&lista);
        break;
      case 5:
        system("clear");
        remover_fim(&lista);
        break;
      case 6:
        system("clear");
        printf("Insira o valor que deseja remover: ");
        scanf("%d",&valor);
        remover_meio(&lista,valor);
        break;
      case 7:
        imprimir(lista);
        break;
      default:
        if(opcao!=0)
          printf("Opção inválida\n");
    }
  }while(opcao!=0);
}
