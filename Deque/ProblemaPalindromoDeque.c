#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCell{
	char info;
	struct sCell* next;
	struct sCell* prev;
}CELULA;

typedef struct sDeque{
	CELULA* inicio;	
	CELULA* fim;
}DEQUE;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(DEQUE* d){
	d->inicio = NULL;
	d->fim = NULL;
}

int dequeVazio(DEQUE *d){
	if(d->inicio == NULL && d->fim == NULL) return 1;
	else return 0;
}

int inserirInicio(DEQUE* d,char elemento){
    CELULA* nova = criarCelula();
    if(nova == NULL){
        printf("\nERRO: Memoria Cheia!");
        return 0;
    }
    nova->info = elemento;
    nova->prev = NULL;
    nova->next = d->inicio;
    if(dequeVazio(d)){
    	d->inicio = nova;
        d->fim = nova;
        return 1;
    }
    d->inicio->prev = nova;
    d->inicio = nova;
    return 1;
}

int inserirFim(DEQUE* d,char elemento){
    CELULA* nova = criarCelula();
    if(nova == NULL){
        printf("\nERRO: Memoria cheia!!");
        return 0;
    }
    nova->info = elemento;
    nova->next = NULL;
    if(dequeVazio(d)){
        nova->prev = NULL;
        d->fim = nova;
        d->inicio = nova;
        return 1;
    }
    nova->prev = d->fim;
    d->fim->next = nova;
    d->fim = nova;
    return 1;
}

char removerInicio(DEQUE* d){
    CELULA* removida;
    char removido = '\0';
    if(dequeVazio(d)){
    	printf("Deque Vazio!\n");
        return removido;
    }
    removida = d->inicio;
    removido = removida->info;
    if(removida == d->fim){
    	d->inicio = NULL;
    	d->fim = NULL;
        free(removida);
        return removido;
    }
    d->inicio = d->inicio->next;
    d->inicio->prev = NULL;
    free(removida);
    return removido;
}

char removerFim(DEQUE* d){
    CELULA* removida;
    char removido = '\0';
    if(dequeVazio(d)){
        printf("\nDeque Vazio!!");
        return removido;
    }
    removida = d->fim;
    removido = removida->info;
    if(removida == d->inicio){
        d->inicio = NULL;
        d->fim = NULL;
        free(removida);
        return removido;
    }
    removida->prev->next = NULL;
    d->fim = removida->prev;
    free(removida);
    return removido;
}

void imprimirDeque(DEQUE* d){
	DEQUE d2;
	inicializar(&d2);
	char aux;
	if(dequeVazio(d)) return;
	while(!dequeVazio(d)){
		aux = removerInicio(d);
		putchar(aux);
		inserirFim(&d2,aux);
	}
	while(!dequeVazio(&d2)){
		inserirFim(d,removerInicio(&d2));
	}
}

int palindromo(DEQUE* d){
	if(dequeVazio(d)){
		printf("Deque Vazio!\n");
		return 0;
	}
	DEQUE d2;
	inicializar(&d2);
	DEQUE d3;
	inicializar(&d3);
	char aux;
	char aux2;
	while(!dequeVazio(d)){
		aux = removerFim(d);
		if(aux != '.' && aux != ' ')
			inserirFim(&d2,aux);
	}
	while(!dequeVazio(&d2)){
		aux = removerFim(&d2);
		inserirFim(d,aux);
		inserirFim(&d3,aux);
	}
	while(!dequeVazio(&d3)){
		aux = removerFim(&d3);
		inserirFim(&d2,aux);
	}
	while(!dequeVazio(d)){
		aux = removerFim(d);
		aux2 = removerFim(&d2);
		if(aux != aux2) return 0;
	}
	return 1;
}

void imprimirInverso(DEQUE* d){
	DEQUE d2;
	inicializar(&d2);
	char aux;
	if(dequeVazio(d)) return;
	printf("\nImprimir Inverso > ");
	while(!dequeVazio(d)){
		aux = removerFim(d);
		putchar(aux);
		inserirInicio(&d2,aux);
	}
	while(!dequeVazio(&d2))
		inserirFim(d,removerInicio(&d2));
}

int main(){
	DEQUE d;
	inicializar(&d);
	char palavra[100];	
	int i=0;
	printf("\nPalavra: ");
	scanf("%s",palavra);
	
	for(i=0;i<strlen(palavra);i++){
		inserirFim(&d,palavra[i]);
	}
	
	//imprimirDeque(&d);
	imprimirInverso(&d);
	
	putchar('\n');
	if(palindromo(&d)==1) printf("\nEh palindromo");
	else printf("\nNao eh palindromo");
	
	return 0;
}
