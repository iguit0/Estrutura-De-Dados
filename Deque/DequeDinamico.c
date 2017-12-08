#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell* next;
	struct sCell* prev;
}CELULA;

typedef struct sDeque{
	CELULA* inicio;
	CELULA* fim;
}DEQUE;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA*) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(DEQUE* d){
	d->inicio = NULL;
	d->fim = NULL;
}

int dequeVazio(DEQUE* d){
    if(d->inicio == NULL && d->fim == NULL)
        return 1;
    return 0;
}

int inserirInicio(DEQUE* d,int elemento){
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
    char removido;
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

int removerFim(DEQUE* d){
    CELULA* removida;
    int removido = -1;
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


void imprimir(DEQUE* d){
    DEQUE daux;
    inicializar(&daux);
    int removido = -1;
    if(dequeVazio(d)){
        printf("\nDeque Vazio!!");
        return;
    }
    printf("Elementos > ");
	while(!dequeVazio(d)){
	    removido = removerInicio(d);
	    printf(" %d ",removido);
	    inserirFim(&daux,removido);
	}
	while(!dequeVazio(&daux)){
	    removido = removerInicio(&daux);
	    inserirFim(d,removido);
	}
}

void liberarInicio(DEQUE* d){
    if(dequeVazio(d)){
        printf("\nDeque Vazio!");
        return;
    }
    imprimir(d);
    while(!dequeVazio(d)){
        removerInicio(d);
    }
}

void liberarFim(DEQUE* d){
    if(dequeVazio(d)){
        printf("\nDeque Vazio!");
        return;
    }
    imprimir(d);
    while(!dequeVazio(d)){
        removerFim(d);
    }
}

void imprimeInit(DEQUE* d){
    if(dequeVazio(d)){
        printf("\nDeque vazio!");
        return;
    }
    printf("\nElemento Inicio: %d",d->inicio->info);
}

void imprimeFim(DEQUE* d){
    if(dequeVazio(d)){
        printf("\nDeque vazio!");
        return;
    }
    printf("\nElemento Fim: %d",d->fim->info);
}

// Imprimir removendo a partir do inicio de forma recursiva
void printRemIni(DEQUE *d){
  if (d->inicio == NULL){ // Caso da parada recursiva
    return;
  }
  printf("\nElemento > ");
  printf(" %d ",d->inicio->info);
  removerInicio(d); // removo item do inicio
  printRemIni(d); // Chamo de novo a função de forma recursiva
}

// Imprimir tirando do final e colocando no inicio do mesmo deque
void printEspecial(DEQUE *d){
  if (d->inicio == NULL){
  	return;
  }
  CELULA* aux = d->fim;
  do{ 
    // Printo
  	printf("\nElemento > ");
    printf(" %d ",d->fim->info);
    
    // Mudo os ponteiros nas pontas
    d->inicio->prev = d->fim;
    d->fim->next = d->inicio;
    
    // Mudo a parte intermediária a partir do fim
    d->fim = d->fim->prev;
    d->fim->next = NULL;
    
    // Mudo a parte inicial a partir do ponteiro inicial
    d->inicio = d->inicio->prev;
    d->inicio->prev = NULL;
    
  }while (d->fim != aux);
}

int main(){
	DEQUE d;
	inicializar(&d);
	inserirInicio(&d,10);
	inserirFim(&d,50);
	imprimir(&d);
	//printRemIni(&d);
	//printEspecial(&d);
	return 0;
}
