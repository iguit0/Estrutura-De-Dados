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

typedef struct sPilha{
	int tamanho;
	CELULA* topo;
}PILHA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializarPilha(PILHA* p){
	p->topo = NULL;
	p->tamanho = 0;
}

int pilhaVazia(PILHA* p){
	if(p->topo == NULL) return 1;
	return 0;
}

int push(PILHA* p,int elemento){
	CELULA* nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = NULL;
	if(pilhaVazia(p)){
		p->topo = nova;
		p->tamanho++;
		return 1;
	}
	nova->next = p->topo;
	p->topo = nova;
	p->tamanho++;
	return 1;
}

int pop(PILHA* p){
	CELULA* removida;
	int removido = -1;
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!!");
		return removido;
	}
	removida = p->topo;
	removido = removida->info;
	p->topo = p->topo->next;
	p->tamanho--;
	free(removida);
	return removido;
}

void imprimirPilha(PILHA* ptrTopo){
	PILHA pilhaAux;
	int aux;
	inicializarPilha(&pilhaAux);
	if(pilhaVazia(ptrTopo)){
		printf("\nPilha Vazia!");
		return;
	}

	while(!pilhaVazia(ptrTopo)){
		aux = pop(ptrTopo);
		push(&pilhaAux,aux);
		printf(" %d ",aux);
	}
	while(!pilhaVazia(&pilhaAux)){
		aux = pop(&pilhaAux);
		push(ptrTopo,aux);
	}
}

void invertePilha(PILHA* p){
	PILHA pAux;
	inicializarPilha(&pAux);
	int aux=0;
	if(pilhaVazia(p)){
		printf("Pilha Vazia!\n");
		return;
	}
	printf("\nPilha Invertida > ");
	while(!pilhaVazia(p)){
		push(&pAux,pop(p));
	}
	while(!pilhaVazia(&pAux)){
		aux = pop(&pAux);
		printf(" %d ",aux);
		push(p,aux);
	}
}

void inicializarFila(FILA* f){
	f->inicio = NULL;
	f->fim = NULL;
}

int filaVazia(FILA* f){
	if(f->inicio == NULL && f->fim == NULL) return 1;
	return 0;
}

int enfileirar(FILA* f,int elemento){
	CELULA* nova;
	nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = NULL;
	if(filaVazia(f)){
		f->inicio = nova;
		f->fim = nova;
		return 1;
	}
	f->fim->next = nova;
	f->fim = nova;
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

		if(removida->next == NULL){
			inicializarFila(fila);
			free(removida);
			return removido;
		}

		fila->inicio = removida->next;
		free(removida);
		return removido;
}

void imprimirFila(FILA* f){
	FILA aux;
	inicializarFila(&aux);
	int info = 0;
	printf("Elementos > ");
	if(filaVazia(f)){
		printf("Fila Vazia!\n");
		return;
	}
	while(!filaVazia(f)){
		info = desenfileirar(f);
		enfileirar(&aux,info);
		printf(" %d ",info);
	}
	while(!filaVazia(&aux))
		enfileirar(f,desenfileirar(&aux));
}

void inverteFila(FILA* f){
		PILHA p;
		inicializarPilha(&p);
		while(!filaVazia(f)){
			push(&p,desenfileirar(f));
		}
		while(!pilhaVazia(&p)){
			enfileirar(f,pop(&p));
		}
}

int main(){
	FILA f;
    PILHA p;
	inicializarPilha(&p);
	inicializarFila(&f);
	push(&p,1);
	push(&p,2);
	invertePilha(&p);
	return 0;
}
