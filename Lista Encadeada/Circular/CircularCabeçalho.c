#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    int info;
    struct sCell* next;
}CELULA;

CELULA* criarCelula();
void inicializarLista(CELULA** lista);
int listaVazia(CELULA** lista);
void imprimirLista(CELULA** lista);
int inserirInicio(CELULA** lista,int elemento);
int inserirFim(CELULA** lista,int elemento);
void removerInicio(CELULA** lista);
void removerFim(CELULA** lista);
int liberarLista(CELULA** lista);

int main(){
  CELULA* ptrlista;
  inicializarLista(&ptrlista);  
  inserirInicio(&ptrlista,1);
  inserirInicio(&ptrlista,0);
  imprimirLista(&ptrlista);
  free(ptrlista);
  ptrlista = NULL;
  return 0;
}


CELULA* criarCelula(){
  CELULA* nova = (CELULA*) malloc(sizeof(CELULA));
  return nova;
}

void inicializarLista(CELULA** lista){
    CELULA* cabecalho = criarCelula();
    cabecalho->next = NULL;
    (*lista) = cabecalho;
}

int listaVazia(CELULA** lista){
  if((*lista)->next == NULL) return 1;
  else return 0;
}
int inserirInicio(CELULA** lista,int elemento){
	CELULA* nova = criarCelula();
	CELULA* aux;
	if(nova == NULL) return 0;
	nova->info = elemento;
	if(listaVazia(lista)){
		nova->next = nova;
		(*lista)->next = nova;
		(*lista) = nova;
		return 1;
	}
	//achando ultimo elemento
    aux = (*lista);
    do{
    	aux = aux->next;
	}while(aux->next != (*lista));
	aux->next = nova;
	nova->next = (*lista);
	(*lista) = nova;
    return 1;
}

int inserirFim(CELULA** lista,int elemento){
	CELULA* nova = criarCelula();
	CELULA* aux;
	if(nova == NULL) return 0;
	nova->info = elemento;
	if(listaVazia(lista)){
		return inserirInicio(lista,elemento);
	}
	//achando ultimo elemento
    aux = (*lista);
    do{
    	aux = aux->next;
	}while(aux->next != (*lista));	
	aux->next = nova;
	nova->next = (*lista);		
	return 1;
}

void imprimirLista(CELULA** lista){
  if(listaVazia(lista)){
      printf("\nLista Vazia!");
      return;
  }else{
      CELULA* aux;
      aux = (*lista);
      printf("\nLista: ");
      do{
      	printf(" %d ",aux->info);
      	aux = aux->next;
	  }while(aux != (*lista));
  }
}

void removerInicio(CELULA** lista){
	
	}


void removerFim(CELULA** lista){
	
}
