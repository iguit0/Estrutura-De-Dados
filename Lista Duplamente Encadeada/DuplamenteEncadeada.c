#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sContact{
    char nome[30];
    long int telefone;
    char email[30];
}CONTATO;

typedef struct sCell{
    CONTATO info;
    struct sCell* prev;
    struct sCell* next;
}CELULA;

CELULA* criarCelula();
void inicializarLista(CELULA** lista);
int listaVazia(CELULA** lista);
int inserirInicio(CELULA** lista,CONTATO info);
int inserirFim(CELULA** lista,CONTATO info);
int inserirPosicao(CELULA** lista,CONTATO info,int posicao);
void imprimirElemento(CONTATO elemento);
void imprimirInicio(CELULA** lista);
void imprimirFim(CELULA** lista);
CONTATO removerInicio(CELULA** lista);
CONTATO removerFim(CELULA** lista);
CONTATO removerPosicao(CELULA** lista);
int liberarLista(CELULA** lista);
CELULA* pesquisaNome(CELULA** lista,char nome[30]);

int main(){
    CELULA* ptrlista;
    CELULA* temp;
    CONTATO elemento;
    int opcao=0;
    char nome[30];
    inicializarLista(&ptrlista);
	
  do {
  	  printf("\t\n\n DUPLAMENTE ENCADEADA \t\n");
      printf("\n1 - Inserir Inicio\n");
      printf("2 - Inserir Fim\n");
      printf("3 - Remover Fim\n");
      printf("4 - Remover Inicio\n");
      printf("5 - Imprimir Inicio\n");
      printf("6 - Imprimir Fim\n");
      printf("7 - Liberar Lista\n");
      printf("8 - Pesquisar Nome\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            printf("\nNome > ");
            scanf("%s",elemento.nome);
            printf("\nTelefone > ");
            scanf("%d",&elemento.telefone);
            printf("\nE-mail > ");
            scanf("%s",elemento.email);
            if(inserirInicio(&ptrlista,elemento)==1) printf("Inserido com Sucesso\n");
            else printf("ERRO: Inserir Inicio\n");
            break;
        case 2:
            printf("\nNome > ");
            scanf("%s",elemento.nome);
            printf("\nTelefone > ");
            scanf("%d",&elemento.telefone);
            printf("\nE-mail > ");
            scanf("%s",elemento.email);
            if(inserirFim(&ptrlista,elemento)==1) printf("Inserido com Sucesso\n");
            else printf("ERRO: Inserir Inicio\n");
            break;
        case 3:
           	removerFim(&ptrlista);
            break;
        case 4:
            removerInicio(&ptrlista);
            break;
        case 5:
            imprimirInicio(&ptrlista);
            break;
        case 6:
            imprimirFim(&ptrlista);
            break;
        case 7:
        	liberarLista(&ptrlista);
        	break;
        case 8:
        	printf("\nNome a ser pesquisado > ");
        	scanf("%s",nome);
        	temp = pesquisaNome(&ptrlista,nome);
        	if(temp == NULL) printf("\nNao Encontrado!");
        	else{
        		printf("\n\tNome Encontrado!\n");
				imprimirElemento(temp->info);
			} 
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

CELULA* criarCelula(){
	CELULA* nova = (CELULA*) malloc(sizeof(CELULA));
    return nova;
}

void inicializarLista(CELULA** lista){
    (*lista) = NULL;
}

int listaVazia(CELULA** lista){
    if((*lista) == NULL) return 1;
    else return 0;
}

int inserirInicio(CELULA** lista,CONTATO elemento){
    CELULA* nova = criarCelula();
    if(nova == NULL) return 0;
    nova->info = elemento;
    nova->prev = NULL;
    nova->next = NULL;
    if(listaVazia(lista)){
        (*lista) = nova;
        return 1;
    }
    nova->next = (*lista);
    (*lista)->prev = nova;
    (*lista) = nova;
    return 1;
}

int inserirFim(CELULA** lista,CONTATO elemento){
    CELULA* nova = criarCelula();
    CELULA* aux;
    if(nova == NULL) return 0;
    nova->info = elemento;
    nova->next = NULL;
    nova->prev = NULL;
    if(listaVazia(lista)){
        return inserirInicio(lista,elemento);
    }
    aux = (*lista);
    while(aux->next != NULL) {
        aux = aux->next;
    }
    nova->prev = aux;
    aux->next = nova;
    return 1;
}

int inserirPosicao(CELULA** lista,CONTATO elemento,int posicao){

}

void imprimirElemento(CONTATO elemento){
    printf("\nNome: %s",elemento.nome);
    printf("\nTelefone: %d",elemento.telefone);
    printf("\nE-mail: %s",elemento.email);
}

void imprimirInicio(CELULA** lista){
    CELULA* aux;
    if(listaVazia(lista)){
      printf("\nLista Vazia!!");
      return;
    }
    aux = (*lista);
    while(aux != NULL){
        imprimirElemento(aux->info);
        aux = aux->next;
    }
}

void imprimirFim(CELULA** lista){
    CELULA* aux;
    if(listaVazia(lista)){
      printf("\nLista Vazia!!");
      return;
    }
    aux = (*lista);
    while(aux->next != NULL){        
        aux = aux->next;
    }
    while(aux){
    	imprimirElemento(aux->info);
    	aux = aux->prev;
	}
}

CONTATO removerInicio(CELULA** lista){
	CELULA *removida;
	CONTATO removido;
	removido.telefone = -1;
	strcpy(removido.nome," ");
	
	if (listaVazia(lista)) {
		printf("\nERRO! Lista Vazia");
		return removido;
	}
	
	removida = (*lista);
	removido = removida->info;
	(*lista) = (*lista)->next;
	
	if ((*lista) != NULL) {
		(*lista)->prev = NULL;
	}
	
	free(removida);
	return removido;
}

CONTATO removerFim(CELULA** lista){
	CELULA *removida;
	CONTATO removido;
	removido.telefone = -1;
	strcpy(removido.nome," ");
	
	if (listaVazia(lista)) {
		printf("\nLista vazia.");
		return removido;
	}
	
	removida = (*lista);
	while(removida->next != NULL) {
		removida = removida->next;
	}
	
	// so possui um elemento
	if (removida == (*lista)) {
		return removerInicio(lista);
	}
	
	removido = removida->info;
	(removida->prev)->next = NULL;
	free(removida);
	return removido;
}

CONTATO removerPosicao(CELULA** lista){
	
}

int liberarLista(CELULA** lista){
	CELULA* auxiliar = (*lista);
	while(auxiliar != NULL){
		if(listaVazia(lista)){
			printf("\nERRO: Lista Vazia!!");
			return 0;
		}
		removerInicio(lista);
		auxiliar = auxiliar->next;
	}	
	return 1;
}

CELULA* pesquisaNome(CELULA** lista,char nome[30]){
	CELULA* auxiliar;
	if(listaVazia(lista)){
		printf("\nERRO: Lista Vazia");
		return NULL;
	}
	auxiliar = (*lista);
	while(auxiliar != NULL){
		if(strcmp(auxiliar->info.nome,nome)==0){
			return auxiliar;
		}
		auxiliar = auxiliar->next;
	}
	return NULL;	
}
