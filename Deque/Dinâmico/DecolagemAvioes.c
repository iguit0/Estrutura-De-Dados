#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sAviao{
	int num;
	int ano;
	char nome[20];
}AVIAO;

typedef struct sCell{
	AVIAO info;
	struct sCell* next;
}CELULA;

typedef struct sFila{
	CELULA* inicio;
	CELULA* fim;
	int tamanho;
}FILA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA*) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(FILA* f){
	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = 0;
}

int filaVazia(FILA* f){
	if(f->inicio == NULL && f->fim == NULL) return 1;
	return 0;
}

int enfileirar(FILA* f,AVIAO elemento){
	CELULA* nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = NULL;
	if(filaVazia(f)){
		f->inicio = nova;
		f->fim = nova;
		f->tamanho++;
		return 1;
	}	
	f->fim->next = nova;
	f->fim = nova;
	f->tamanho++;
	return 1;
}

AVIAO desenfileirar(FILA* f){
	CELULA* removida;
	AVIAO removido;
	removido.ano = -1;
	removido.num = -1;
	strcpy(removido.nome," ");
	if(filaVazia(f)){
		printf("Fila Vazia!\n");
		return removido;
	}
	removida = f->inicio;
	removido = removida->info;
	if(removida->next == NULL){
		inicializar(f);
		free(removida);
		return removido;
	}
	f->inicio = f->inicio->next;
	free(removida);
	return removido;
}

int listarAvioes(FILA* f){
	return f->tamanho;
}

void limparFila(FILA* f){
	printf("\nLiberando Fila...\n");
	while(!filaVazia(f))
		desenfileirar(f);
}

void imprimirElemento(AVIAO elemento){
	printf("\nNum.: %d\nAno: %d\nNome: %s\n\n",elemento.num,elemento.ano,elemento.nome);
}

void imprimeInit(FILA* f){
	if(filaVazia(f)){
		printf("Fila Vazia\n");
		return;
	}
	imprimirElemento(f->inicio->info);
}

void imprimirFila(FILA* f){
	FILA f2;
	inicializar(&f2);
	AVIAO removido;
	if(filaVazia(f)){
		printf("Fila Vazia!\n");
		return;
	}
	while(!filaVazia(f)){
		removido = desenfileirar(f);
		imprimirElemento(removido);
		enfileirar(&f2,removido);
	}
	while(!filaVazia(&f2)){
		enfileirar(f,desenfileirar(&f2));
	}
}

int main(){
	FILA f;
	AVIAO elemento;
	inicializar(&f);
	elemento.num = 1;
	elemento.ano = 2002;
	strcpy(elemento.nome,"Boeing 747");
	enfileirar(&f,elemento);
	elemento.num = 2;
	elemento.ano = 2013;
	strcpy(elemento.nome,"Boeing 723");
	enfileirar(&f,elemento);
	imprimirFila(&f);
	printf("\nAvioes aguardando: %d\n",listarAvioes(&f));
	
	return 0;
}
