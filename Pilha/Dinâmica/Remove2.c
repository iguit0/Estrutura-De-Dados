#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCell{
	int info;
	struct sCell* next;
}CELULA;

typedef struct sPilha{
	CELULA* topo;	
	int qntd;
}PILHA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(PILHA* p){
	p->topo = NULL;
	p->qntd = 0;
}

int pilhaVazia(PILHA* p){
	if(p->topo == NULL) return 1;
	else return 0;
}

int push(PILHA* p,int elemento){
	CELULA* nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = p->topo;
	if(pilhaVazia(p)){
		p->topo = nova;
		p->qntd++;
		return 1;
	}
	nova->next = p->topo;
	p->topo = nova;
	p->qntd++;
	return 1;
}

int pop(PILHA* p){
	CELULA* removida;
	int removido;
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!");
		return removido;
	}
	removida = p->topo;
	removido = removida->info;
	p->topo = p->topo->next;
	free(removida);
	return removido;
}

void removeDois(PILHA* p){
	PILHA aux;
	inicializar(&aux);
	int removido=0;
	if(pilhaVazia(p)){
		printf("Pilha Vazia!\n");
		return;
	}
	while(!pilhaVazia(p)){
		removido = pop(p);
		if(removido != 2){
			push(&aux,removido);
		}
	}
	while(!pilhaVazia(&aux)){
		push(p,pop(&aux));
	}
}

void imprimir(PILHA* p){
	PILHA aux;
	inicializar(&aux);
	int removido = 0;
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!");
		return;
	}
	printf("Elementos > ");
	while(!pilhaVazia(p)){
		removido = pop(p);
		printf("%d ",removido);
		push(&aux,removido);
	}
	while(!pilhaVazia(&aux))
		push(p,pop(&aux));
}

int main(){
    PILHA p;
    inicializar(&p);
    push(&p,1);
	push(&p,2);
	push(&p,3);
	push(&p,2);
	push(&p,4);
	push(&p,0);
	removeDois(&p);
	imprimir(&p);
	
    return 0;
}
