#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCell{
	int info;
	struct sCell* next;
}CELULA;


CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	nova->next = NULL;
	return nova;
}

void inicializarPilha(CELULA** ptrTopo){
	(*ptrTopo) = NULL;
}

int pilhaVazia(CELULA** ptrTopo){
	if((*ptrTopo) == NULL) return 1;
	return 0;
}

int push(CELULA** ptrTopo,int elemento){
	CELULA* nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	// se pilha estiver vazia
	if(pilhaVazia(ptrTopo)){
		(*ptrTopo) = nova;
		return 1;
	}
	// se pilha nao estiver vazia
	nova->next = (*ptrTopo);
	(*ptrTopo) = nova;
	return 1;
}

int pop(CELULA** ptrTopo){
	CELULA* removida;
    if(pilhaVazia(ptrTopo)){
        printf("\nPilha Vazia!");
        return 0;
    }
    removida = (*ptrTopo);
    (*ptrTopo) = (*ptrTopo)->next;
    free(removida);
    removida = NULL;
    return 1;
}

void imprimirElemento(int info){
	printf(" %d ",info);
}

int topoEl(CELULA** ptrTopo){
	int topo=0;
	if(pilhaVazia(ptrTopo)){
		printf("\nPilha Vazia!\n");
		return 0;
	}
	topo = (*ptrTopo)->info;
	return topo;
}

int compararPilhas(CELULA** pilha1,CELULA** pilha2){
	CELULA* aux1;
	CELULA* aux2;
	aux1 = (*pilha1);
	aux2 = (*pilha2);
	//se uma das pilhas estiver vazia, nao tem como comparar
	if(pilhaVazia(pilha1) || pilhaVazia(pilha2)){
		printf("\nUma das pilhas esta vazia!\n");
		return 0;
	}
	// enquanto pilha1 nao estiver vazia e pilha2 tambem nao estiver vazia
	while(aux1 != NULL || aux2 != NULL){
		//se elementos sao diferentes, entao nao é igual
		if(aux1->info != aux2->info){
			return 0;
		}
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	if(aux1 != NULL || aux2 != NULL){
		return 0;
	}
	return 1;
}


int main(){
	CELULA* pilha1;
	CELULA* pilha2;

	inicializarPilha(&pilha1);
	inicializarPilha(&pilha2);

	push(&pilha1,50);
	push(&pilha2,50);

    if(compararPilhas(&pilha1,&pilha2)==1) printf("Iguais\n");
	else printf("Diferentes\n");

	free(pilha1);
	free(pilha2);
	pilha1 = NULL;
	pilha2 = NULL;
	return 0;
}
