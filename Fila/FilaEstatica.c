#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct sFila{
	int elemento[TAM];
	int inicio;
	int fim;
}FILA;

void inicializar(FILA* fila){
	fila->fim = 0;
	fila->inicio = fila->fim;
}

int filaVazia(FILA* fila){
	if(fila->fim == fila->inicio) return 1;
	return 0;
}

int filaCheia(FILA* fila){
	int prox = (fila->fim+1)%TAM;
	if(prox == fila->inicio) return 1;
	return 0;
}

int enfileirar(FILA* fila,int elemento){
	int prox;
	if(filaCheia(fila)){
		printf("Fila Cheia!\n");
		return 0;
	}
	prox = (fila->fim+1)%TAM;
	fila->elemento[prox] = elemento;
	fila->fim = prox;
	return 1;
}

int desenfileirar(FILA* fila){
	int removido = -1;
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return 0;
	}
	fila->inicio = (fila->inicio+1)%TAM;
	removido = fila->elemento[fila->inicio];
	return removido;
}

void imprimir(FILA* fila){
	int infoaux = -1;
	FILA aux;
	inicializar(&aux);
	if(filaVazia(fila)){
		printf("Fila Vazia!\n");
		return;
	}else{
		printf("Elementos > ");
		while(!filaVazia(fila)){
			infoaux = desenfileirar(fila);
			printf(" %d ",infoaux);
			enfileirar(&aux,infoaux);
		}
		while(!filaVazia(&aux)){
			infoaux = desenfileirar(&aux);
			enfileirar(fila,infoaux);
		}
	}	
}

void imprimirAux(FILA* fila){
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return;
	}else{
		imprimir(fila);
		while(!filaVazia(fila)){
			desenfileirar(fila);
		}
	}
}

int main(){
	FILA fila;
	int opcao=0,elemento=0;
	inicializar(&fila);

	do {
      printf("\n1 - Fila Vazia\n");
      printf("2 - Fila Cheia\n");
      printf("3 - Enfileirar\n");
      printf("4 - Desenfileirar\n");
      printf("5 - Imprimir\n");
      printf("6 - Imprimir e desenfileirar\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            if(filaVazia(&fila)==1) printf("Fila Vazia!\n");
            else printf("Fila Nao Vazia!\n");
            break;
        case 2:
        	if(filaCheia(&fila)==1) printf("Fila Cheia!\n");
        	else printf("Fila Nao Cheia!\n");
            break;
        case 3:
        	printf("\nElemento > ");
        	scanf("%d",&elemento);
        	if(enfileirar(&fila,elemento)==1) printf("Enfileirado!\n");
        	else printf("ERRO!\n");
        	break;
        case 4:
			desenfileirar(&fila);
        	break;
        case 5:
        	imprimir(&fila);
        	break;
        case 6:
        	imprimirAux(&fila);
        	break;
        case 0:
            printf("\nVoce Saiu!!\n");
            break;
      }
  } while(opcao != 0);
	
	return 0;
}
