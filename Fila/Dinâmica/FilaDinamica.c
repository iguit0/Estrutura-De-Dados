#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell* next;
}CELULA;

typedef struct sFila{
	CELULA* inicio;
	CELULA* fim;
}FILA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(nova));
	return nova;
}

void inicializar(FILA* fila){
	fila->fim = NULL;
	fila->inicio = NULL;
}

int filaVazia(FILA* fila){
	if(fila->inicio == NULL && fila->fim == NULL) return 1;
	else return 0;
}

int enfileirar(FILA* fila,int elemento){
	CELULA* nova = criarCelula();
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

int desenfileirar(FILA* fila){
	CELULA* removida;
	int removido = -1;
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return removido;
	}
		removida = fila->inicio;
		removido = removida->info;
		//caso 1: se tiver só um elemento, a fila ficará vazia!
		if(removida->next == NULL){
			fila->fim = NULL;
			fila->inicio = NULL;
			free(removida);
			return removido;
		}
		//caso 2: Se tiver mais de um elemento, a fila nao ficara vazia!
		fila->inicio = removida->next;
		free(removida);
		return removido;
}

void imprimir(FILA* fila){
	FILA aux;
	inicializar(&aux);
	int infoaux = -1;
	if(filaVazia(fila)){
		printf("\nFila Vazia!");
		return;
	}
	printf("\nElementos > ");
	while(!filaVazia(fila)){
		infoaux = desenfileirar(fila);
		printf(" %d ",infoaux);
		enfileirar(&aux,infoaux);
	}
	while(!filaVazia(&aux)){
		enfileirar(fila,desenfileirar(&aux));
	}
}

void imprimirAux(FILA* fila){
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return;
	}else{
		imprimir(fila);
		while(!filaVazia(fila)){
			desenfileirar(fila);
		}
	}
}

int tamanho(FILA* fila){
	FILA aux;
	inicializar(&aux);
	int cont = 0;
	int removido = 0;
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return 0;
	}
	while(!filaVazia(fila)){
		removido = desenfileirar(fila);
		cont++;
		enfileirar(&aux,removido);
	}
	while(!filaVazia(&aux)){
		removido = desenfileirar(&aux);
		enfileirar(fila,removido);
	}
	return cont;
}

int main(){
	FILA fila;
	int opcao=0,elemento=0;
	inicializar(&fila);
	
	do {
      printf("\n1 - Fila Vazia\n");
      printf("2 - Enfileirar\n");
      printf("3 - Desenfileirar\n");
      printf("4 - Imprimir\n");
      printf("5 - Imprimir e desenfileirar\n");
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
        	printf("\nElemento > ");
        	scanf("%d",&elemento);
        	if(enfileirar(&fila,elemento)==1) printf("Enfileirado!\n");
        	else printf("ERRO!\n");
        	break;
        case 3:
			desenfileirar(&fila);
        	break;
        case 4:
        	imprimir(&fila);
        	break;
        case 5:
        	imprimirAux(&fila);
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
