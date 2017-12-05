#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    int info;
    struct sCell* next;
}CELULA;

void inicializarLista(CELULA** lista);
CELULA* criarCelula();
int listaVazia(CELULA** lista);
void imprimirLista(CELULA** lista);
int inserirInicio(CELULA** lista,int elemento);
void removerInicio(CELULA** lista);
void removerFim(CELULA** lista);
void liberarLista(CELULA** lista);

int main(){
  CELULA* ptrlista;
  int opcao=0,elemento=0;

  do {
      printf("\n1 - Inicializar Lista\n");
      printf("2 - Lista Vazia\n");
      printf("3 - Inserir Inicio\n");
      printf("4 - Remover Fim\n");
      printf("5 - Imprimir Lista\n");
      printf("6 - Liberar Lista\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            inicializarLista(&ptrlista);
            break;
        case 2:
            if(listaVazia(&ptrlista)==1) printf("Lista Vazia!\n");
            else printf("Lista Nao Vazia\n");
            break;
        case 3:
            printf("\nNumero para inserir: ");
            scanf("%d",&elemento);
            if(inserirInicio(&ptrlista,elemento)==1) printf("Inserido com Sucesso\n");
            else printf("ERRO: Inserir Inicio\n");
            break;
        case 4:
            removerFim(&ptrlista);
            break;
        case 5:
            imprimirLista(&ptrlista);
            break;
        case 6:
            liberarLista(&ptrlista);
            break;
        case 0:
            printf("Voce Saiu!!\n");
            break;
      }
  } while(opcao != 0);

	free(ptrlista);
	ptrlista = NULL;
	return 0;

}

void inicializarLista(CELULA** lista){
    (*lista) = NULL;
}

CELULA* criarCelula(){
  CELULA* nova = (CELULA*) malloc(sizeof(CELULA));
  return nova;
}

int listaVazia(CELULA** lista){
  if((*lista) == NULL) return 1;
  else return 0;
}

void imprimirLista(CELULA** lista){
  if(listaVazia(lista)){
      printf("\nLista Vazia!");
      return;
  }else{
      CELULA* aux;
      aux = (*lista)->next;
      printf("\nLista: ");
      do{
        printf(" %d ",aux->info);
        aux = aux->next;
      }while(aux != (*lista)->next);
  }
}

int inserirInicio(CELULA** lista,int elemento){
  CELULA* nova = criarCelula();
  CELULA* aux;
  if(nova == NULL) return 0;
  nova->info = elemento;
  if(listaVazia(lista)){
      (*lista) = nova;
      nova->next = nova;
      return 1;
  }
    aux = (*lista)->next;
    // procurando o elem. anterior
    while(aux != (*lista)->next){
      aux = aux->next;
    }
    (*lista)->next = nova;
    nova->next = aux;
    return 1;
}

void removerFim(CELULA** lista){
    CELULA* aux;
    CELULA* anterior;
    if(listaVazia(lista)){
      printf("\nLista Vazia!");
      return;
    }
    // achando a celula anterior ao final
    anterior = (*lista)->next;
    while(anterior->next != (*lista)){
      anterior = anterior->next;
    }
    aux = (*lista);
    anterior->next = (*lista)->next;
    (*lista) = anterior;
    free(aux);
    aux = NULL;
}

void liberarLista(CELULA** lista){
    CELULA* aux;
    if(listaVazia(lista)){
      printf("\nLista Vazia!");
      return;
    }
    aux = (*lista);
    while(!listaVazia(lista)){
      if((*lista)->next == (*lista)) { 
      	removerFim(lista);
	    inicializarLista(lista);
      }else{
        aux = (*lista)->next;
        (*lista)->next = aux->next;
        free(aux);
    }
  }
    aux = NULL;
}
