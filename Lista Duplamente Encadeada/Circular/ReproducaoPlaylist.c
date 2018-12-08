#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sMusica{
	char nome[30];
	char banda[20];
	int duracao;
}MUSICA;

typedef struct sCell{
	MUSICA info;
	struct sCell* prev;
	struct sCell* next;
}CELULA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializarLista(CELULA** lista){
	(*lista) = NULL;
}

int listaVazia(CELULA** lista){
	if((*lista) == NULL) return 1;
	else return 0;
}

int inserirInicio(CELULA** lista,MUSICA elemento){
  CELULA* nova = criarCelula();
  if(nova == NULL) return 0;
  nova->info = elemento;
  if(listaVazia(lista)){
      (*lista) = nova;
      nova->next = nova;
      nova->prev = nova;
      return 1;
  }
  	nova->prev = (*lista);
  	nova->next = (*lista)->next;

	(*lista)->next = nova;
	(*lista)->prev = nova;

    return 1;
}

int inserirFim (CELULA **lista, MUSICA elemento) {
	CELULA *nova;
	nova = criarCelula();
	
	if(nova == NULL) return 0;
	
	nova->info = elemento;
	
	if(listaVazia(lista)) {
		return inserirInicio(lista, elemento);
		
	}
	
	nova->prev = (*lista);
	nova->next = (*lista)->next;
	
	(*lista)->next = nova;
	(*lista) = nova;
	
	return 1;
}

MUSICA removerInicio(CELULA **lista) {
	MUSICA removido;
	CELULA *removida;
	
	if(listaVazia(lista)) return removido;
	
	removida = (*lista)->next;
	(*lista)->next = (*lista)->next->next;
	
	removido = removida->info;
	
	free(removida);
	
	return removido;
}

MUSICA removerFim(CELULA **lista) {
	CELULA *removida;
	MUSICA removido;
	
	if(listaVazia(lista)) return removido;
	
	removida = (*lista);
	
	(*lista)->prev->next = (*lista)->next;
	
	(*lista) = (*lista)->prev;
	
	(*lista)->next->prev = (*lista);
	
	removido = removida->info;
	
	free(removida);
	
	return removido;
}

void liberarLista(CELULA **lista) {
	if(listaVazia(lista)) return;
	CELULA* aux;
	aux = (*lista)->next;
	while(aux != (*lista)){
		if( aux == (*lista)){
			removerFim(lista);
		}
		removerInicio(lista);
		aux = aux->next;
	}
}

void imprimirElemento(MUSICA elemento){
	printf("\nMusica: %s",elemento.nome);
	printf("\nBanda: %s",elemento.banda);
	printf("\nDuracao: %d\n",elemento.duracao);
}

void imprimir(CELULA** lista){
	CELULA* aux;
	if(listaVazia(lista)){
		printf("\nLista Vazia");
		return;
	}else{
		printf("\nElementos > \n");
      aux = (*lista)->next;
      do{
        imprimirElemento(aux->info);
        aux = aux->next;
      }while(aux != (*lista)->next);
	}
	free(aux);
	aux = NULL;
}

void exibir(CELULA** lista){
	CELULA* aux = (*lista)->next;
	int tecla;
	if(listaVazia(lista)){
		printf("\nVazio");
		return;
	}else{
		printf("Esquerda e direita > ");
			do{
			tecla = getch();
			if(tecla == 75){
				aux = aux->prev;
				imprimirElemento(aux->info);
			}else if(tecla == 77){
				aux = aux->next;
				imprimirElemento(aux->info);				
			}
		}while(tecla != 27);						
}
}

int main(){
	CELULA* lista;
	MUSICA elemento;
	inicializarLista(&lista);	
	int opcao=0;
  do {
      printf("\n1 - Lista Vazia\n");
      printf("2 - Inserir Inicio\n");
      printf("3 - Inserir Fim\n");
      printf("4 - Remover Inicio\n");
      printf("5 - Remover Fim\n");
      printf("6 - Liberar Lista\n");
      printf("7 - Imprimir\n");
      printf("8 - Exibir\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            if(listaVazia(&lista)==1) printf("Lista Vazia!\n");
            else printf("Lista Nao Vazia\n");
            break;
        case 2:
        	printf("\nMusica > ");
        	scanf("%s",elemento.nome);
        	printf("\nBanda > ");
        	scanf("%s",elemento.banda);
        	printf("\nDuracao > ");
        	scanf("%d",&elemento.duracao);
			if(inserirInicio(&lista,elemento)==1) printf("Inserido com sucesso!\n");
			else printf("Erro!\n");
            break;
        case 3:
        	printf("\nMusica > ");
        	scanf("%s",elemento.nome);
        	printf("\nBanda > ");
        	scanf("%s",elemento.banda);
        	printf("\nDuracao > ");
        	scanf("%d",&elemento.duracao);
        	if(inserirFim(&lista,elemento)==1) printf("Inserido com sucesso!\n");
			else printf("Erro!\n");
        	break;
        case 4:
			removerInicio(&lista);
        	break;
        case 5:
        	removerFim(&lista);
        	break;
        case 6:
        	liberarLista(&lista);
        	break;
        case 7:
        	imprimir(&lista);
        	break;
        case 8:
        	exibir(&lista);
        	break;
        case 0:
            printf("\nVoce Saiu!!\n");
            break;
      }
  } while(opcao != 0);
	
	free(lista);
	lista = NULL;
	return 0;
}
