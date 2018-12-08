#include <stdio.h>
#include <stdlib.h>

typedef struct sProcess{
	int idProcesso;
	int tempoProcesso;
}PROCESSO;

typedef struct sCell{
	PROCESSO info;
	struct sCell* next;
}CELULA;

typedef struct sFila{
	CELULA* inicio;
	CELULA* fim;
}FILA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(FILA* fila){
	fila->inicio = NULL;
	fila->fim = NULL;
}

int filaVazia(FILA* fila){
	if(fila->inicio == NULL && fila->fim == NULL) return 1;
	else return 0;
}

int enfileirar(FILA* fila,PROCESSO elemento){
	CELULA* nova;
	nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = NULL;
	if(filaVazia(fila)){
		fila->inicio = nova;
		fila->fim = nova;
		return 1;
	}
	fila->fim->next = nova;
	fila->fim = nova;
	return 1;
}

PROCESSO desenfileirar(FILA* fila){
	CELULA* removida;
	PROCESSO removido;
	removido.idProcesso = -1;
	removido.tempoProcesso = -1;
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return removido;
	}else{
		removida = fila->inicio;
		//caso 1: se tiver só um elemento, a fila ficará vazia!
		if(removida->next == NULL){
			fila->fim = NULL;
			fila->inicio = NULL;
			removido = removida->info;
			free(removida);
			return removido;
		}
		//caso 2: Se tiver mais de um elemento, a fila nao ficara vazia!
		removido = removida->info;
		fila->inicio = removida->next;
		free(removida);
		return removido;
	}
}

void imprimirProcesso(PROCESSO elemento){
	printf("\nID Processo > %d\n",elemento.idProcesso);
	printf("Tempo Processo > %d\n\n",elemento.tempoProcesso);
}

PROCESSO desenfileirarMaior(FILA* fila){
	CELULA* aux;
	CELULA* anterior;
	CELULA* removida;
	PROCESSO removido;
	removido.idProcesso = -1;
	removido.tempoProcesso = -1;
	if(filaVazia(fila)){
		printf("Fila Vazia!");
		return removido;
	}
	removida = fila->inicio;
	aux = fila->inicio;
	// achando o maior processo com maior tempo de espera e guardando na variavel "removida"
	while(aux != NULL){
		if(aux->info.tempoProcesso > removida->info.tempoProcesso){
			removida = aux;
		}
		aux = aux->next;
	}
	removido = removida->info;
	// se o elemento a ser removido for o primeiro da fila logo a mesma ficará vazia!
	if(removida == fila->inicio){
		fila->fim = NULL;
		fila->inicio = NULL;
		free(removida);
		return removido;
	}
	// se o elemento a ser removido não for o primeiro da fila, logo teremos que achar o elemento anterior.
		anterior = fila->inicio;
		while(anterior->next != removida){
			anterior = anterior->next;
		}
		anterior->next = removida->next;
		free(removida);
		return removido;		
}

int tamanho(FILA* fila){
	CELULA* aux;
	int cont=0;
	aux = fila->inicio;
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return 0;
	}
	while(aux != NULL){
		cont++;
		aux = aux->next;
	}
	return cont;
}

void imprimir(FILA* fila){
	FILA aux;
	inicializar(&aux);
	PROCESSO infoaux;
	if(filaVazia(fila)){
		printf("\nFila Vazia!");
		return;
	}
	while(!filaVazia(fila)){
		infoaux = desenfileirar(fila);
		imprimirProcesso(infoaux);
		enfileirar(&aux,infoaux);
	}
	while(!filaVazia(&aux)){
		enfileirar(fila,desenfileirar(&aux));
	}
}

void imprimirMaior(FILA* fila){
	CELULA* aux;
	CELULA* maior;
	if(filaVazia(fila)){
		printf("Fila Vazia!");
		return;
	}
	aux = fila->inicio;
	maior = fila->inicio;
	while(aux != NULL){
		if(aux->info.tempoProcesso > maior->info.tempoProcesso){
			maior = aux;
		}
		aux = aux->next;
	}
	printf("\nO processo com maior tempo de espera eh");
	imprimirProcesso(maior->info);	
}

int main(){
	FILA fila;
	PROCESSO elemento;
	inicializar(&fila);
	int opcao=0;
	
	do {
      printf("\n1 - Fila Vazia\n");
      printf("2 - Enfileirar Processo\n");
      printf("3 - Desenfileirar processo c/ maior tempo de espera\n");
      printf("4 - Imprimir o processo c/ maior tempo de espera (sem remover)\n");
      printf("5 - Imprimir Fila\n");
      printf("6 - Tamanho da Fila\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            if(filaVazia(&fila)==1) printf("Fila Vazia!\n");
            else printf("Fila Nao Vazia!\n");
            break;
        case 2:
        	printf("\nID Processo > ");
        	scanf("%d",&elemento.idProcesso);
        	printf("\nTempo Processo > ");
        	scanf("%d",&elemento.tempoProcesso);
        	if(enfileirar(&fila,elemento)==1) printf("Processo Enfileirado!\n");
        	else printf("ERRO!\n");
        	break;
        case 3:
			desenfileirarMaior(&fila);
        	break;
        case 4:
        	imprimirMaior(&fila);
        	break;
        case 5:
        	imprimir(&fila);
        	break;
        case 6:
        	printf("Tamanho Fila > %d\n",tamanho(&fila));
        	break;
        case 0:
            printf("\nVoce Saiu!!\n");
            break;
      }
  } while(opcao != 0);

	return 0;
}
