#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRevista{
	char nome[30];
	int n_pags;
	char categoria[30];
}REVISTA;

typedef struct sCell{
	REVISTA elem;
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

int push(CELULA** ptrTopo,REVISTA info){
	CELULA* nova = criarCelula();	
	if(nova == NULL) return 0;
	nova->elem = info;
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

REVISTA pop(CELULA** ptrTopo){
	CELULA* removida;
    REVISTA removido;
    strcpy(removido.categoria," ");
    strcpy(removido.nome," ");
    removido.n_pags = -1;
    if(pilhaVazia(ptrTopo)){
        printf("\nPilha Vazia!");
        return removido;
    }
    removida = (*ptrTopo);
    removido = removida->elem;
    (*ptrTopo) = (*ptrTopo)->next;
    free(removida);
    removida = NULL;
    return removido;
}

void imprimirElemento(REVISTA info){
	printf("\nNome: %s",info.nome);
	printf("\nCategoria: %s",info.categoria);
	printf("\nN.pags: %d\n",info.n_pags);
}

REVISTA topoEl(CELULA** ptrTopo){
	REVISTA topo;
	strcpy(topo.categoria," ");
	strcpy(topo.nome," ");
	topo.n_pags = -1;
	if(pilhaVazia(ptrTopo)){
		printf("\nPilha Vazia!\n");
		return topo;
	}
	topo = (*ptrTopo)->elem;
	return topo;
}

void imprimirPop(CELULA** ptrTopo){
	REVISTA aux;
	if(pilhaVazia(ptrTopo)){
		printf("\nPilha Vazia!");
		return;
	}
	// removendo da pilha original até ficar vazia
	while(!pilhaVazia(ptrTopo)){
		aux = pop(ptrTopo);
		imprimirElemento(aux);
	}
}

void imprimirAux(CELULA** ptrTopo){
	CELULA* pilhaAux;
	REVISTA aux;
	inicializarPilha(&pilhaAux);
	if(pilhaVazia(ptrTopo)){
		printf("\nPilha Vazia!");
		return;
	}
	// tirando da pilha original e colocando na auxiliar
	while(!pilhaVazia(ptrTopo)){
		aux = pop(ptrTopo);
		push(&pilhaAux,aux);
		imprimirElemento(aux);
	}
	// voltando pra pilha original
	while(!pilhaVazia(&pilhaAux)){
		aux = pop(&pilhaAux);
		push(ptrTopo,aux);
	}
	free(pilhaAux);
	pilhaAux = NULL;
}

int main(){
	CELULA* ptrTopo;
	REVISTA info;
	int opcao=0;
  do {
      printf("\n1 - Inicializar Pilha\n");
      printf("2 - Pilha Vazia\n");
      printf("3 - Push\n");
      printf("4 - Pop\n");
      printf("5 - Elemento Topo\n");
      printf("6 - Imprimir e desempilhar\n");
      printf("7 - Imprimir usando Auxiliar\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            inicializarPilha(&ptrTopo);
            break;
        case 2:
            if(pilhaVazia(&ptrTopo)==1) printf("Pilha Vazia!\n");
            else printf("Pilha Nao Vazia\n");
            break;
        case 3:
        	printf("\nNome > ");
        	scanf("%s",info.nome);
        	printf("\nN. Pags.: > ");
        	scanf("%d",&info.n_pags);
        	printf("\nCategoria > ");
        	scanf("%s",info.categoria);
			if(push(&ptrTopo,info)==1) printf("Inserido com sucesso!\n");
			else printf("Erro!\n");
            break;
        case 4:
			pop(&ptrTopo);
			printf("Removido!\n");
            break;
        case 5:
        	printf("\nElemento do Topo > \n");
            imprimirElemento(topoEl(&ptrTopo));
            printf("\nRemovido!");
            break;
        case 6:
			imprimirPop(&ptrTopo);
            break;
        case 7:
            imprimirAux(&ptrTopo);
        	break;
        case 0:
            printf("\nVoce Saiu!!\n");
            break;
      }
  } while(opcao != 0);
	
	free(ptrTopo);
	ptrTopo = NULL;
	return 0;	
}
