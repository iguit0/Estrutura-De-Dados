#include <stdio.h>
#include <stdlib.h>

typedef struct sDados{
	int elemento;
	int cont;
}DADOS;

typedef struct sCell{
	DADOS info;
	struct sCell* next;
}CELULA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(CELULA** lista){
	(*lista) = NULL;
}

int vazia(CELULA** lista){
	if( (*lista) == NULL) return 1;
	else return 0;
}

int pesqMoverpFrente(CELULA** lista,DADOS info){
	CELULA* auxiliar;
	CELULA* anterior;
	
	auxiliar = (*lista);
	while(auxiliar != NULL){
		if(auxiliar->info.elemento == info.elemento){
			break;
		}
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	
	if(auxiliar ==NULL){
		return 0;
	}
	if(auxiliar == (*lista)){
		return 1;
	}
	
	anterior->next=auxiliar->next;
	auxiliar->next = (*lista);
	(*lista) = auxiliar;
	return 1;
}

int pesqTransposicao (CELULA** lista,DADOS info){
	CELULA* auxiliar;
	CELULA* anterior;
	CELULA* pesquisada;
	
	auxiliar = (*lista);
	
	if(auxiliar->info.elemento == info.elemento){
		return 1;
	}
	
	while(auxiliar != NULL){
		if(auxiliar->next->info.elemento == info.elemento){
			break;
		}
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	
	if(auxiliar == NULL){
		return 0;
	}
	
	pesquisada = auxiliar->next;
	anterior->next = pesquisada;
	auxiliar->next = pesquisada->next;
	pesquisada->next = auxiliar;
	
	return 1;
}

int pesqContagem (CELULA** lista,DADOS info){
	CELULA* auxiliar;
	CELULA* anterior;
	CELULA* pesquisada;
	
	auxiliar = (*lista);
	while(auxiliar != NULL){
		if(auxiliar->info.elemento == info.elemento)
			break;
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	
	if(auxiliar==NULL){
		return 0;
	}
	if(auxiliar==(*lista)){
		auxiliar->info.cont++;
		return 1;
	}
	
	anterior = auxiliar->next;
	pesquisada = auxiliar;
	
	auxiliar = (*lista);
	
	while(auxiliar!=NULL){
		if(pesquisada->info.cont > auxiliar->info.cont)
			break;
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	pesquisada->next = auxiliar;
	
	if(auxiliar == (*lista)){
		(*lista) = pesquisada;
		return 1;
	}else{
		anterior->next = pesquisada;
		return 1;
	}
}

int inserirInicio(CELULA** lista,DADOS elemento){
	CELULA* nova = criarCelula();
	if(nova==NULL) return 0;
	nova->info = elemento;
	nova->next = NULL;
	if(vazia(lista)){
		(*lista) = nova;
		return 1;
	}
	nova->next = (*lista);
	(*lista) = nova;
	return 1;
}

int imprimir(CELULA** lista){
	CELULA* aux;
	if(vazia(lista)){
		return;
	}else{
		aux = (*lista);
		printf("\nElementos > ");
		while(aux!=NULL){
			printf(" %d ",aux->info.elemento);
			aux = aux->next;
		}
	}
}

int main(){
	CELULA* lista;
	DADOS elemento;
	inicializar(&lista);
	elemento.elemento = 3;
	inserirInicio(&lista,elemento);
	elemento.elemento = 2;
	inserirInicio(&lista,elemento);
	elemento.elemento = 1;
	inserirInicio(&lista,elemento);
	
	elemento.elemento = 3;
	//pesqMoverpFrente(&lista,elemento);
	//pesqContagem(&lista,elemento);
	pesqTransposicao(&lista,elemento);
	
	imprimir(&lista);
	free(lista);
	lista = NULL;
	return 0;
}
