#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
	int info;
	struct sNo* esquerda;
	struct sNo* direita;
}NO;

NO* criarCelula(){
	NO* nova = (NO *) malloc(sizeof(NO));
	if(nova == NULL) return NULL;
	nova->direita = NULL;
	nova->esquerda = NULL;
	return nova;
}

void inicializar(NO** raiz){
	(*raiz) = NULL;
}

int vazia(NO** raiz){
	if( (*raiz) == NULL) return 1;
	return 0;
}

int inserirRecursivo(NO** raiz, int elemento){
	if(vazia(raiz)){
		NO* nova = criarCelula();
		nova->info = elemento;
		*raiz = nova;
		return 1;
	}
	if((*raiz)->info > elemento){
		return inserirRecursivo(&(*raiz)->esquerda,elemento);
	}else{
		return inserirRecursivo(&(*raiz)->direita,elemento);
	}
}

int inserirIterativo(NO** raiz, int elemento){
	NO* aux = *raiz;
	NO* nova = criarCelula();
	nova->info = elemento;
	if(vazia(raiz)){
		*raiz = nova;
		return 1;
	}
	while (aux != NULL){
		if(aux->info > elemento){
			if(aux->esquerda == NULL){
				aux->esquerda = nova;
				return 1;
			}
			aux = aux->esquerda;
		}else{
			if(aux->direita == NULL){
				aux->direita = nova;
				return 1;
			}
			aux = aux->direita;
		}
	}
	return 0;
}

void emOrdem(NO** raiz){
	if((*raiz)!= NULL){
		emOrdem(&(*raiz)->esquerda);
		printf("\n%d",(*raiz)->info);
		emOrdem(&(*raiz)->direita);
	}
}

void preOrdem(NO** raiz){
    if((*raiz) != NULL){
        printf("\n%d", (*raiz)->info);
        preOrdem(&(*raiz)->direita);
        preOrdem(&(*raiz)->esquerda);
    }
}

void posOrdem(NO** raiz){
    if((*raiz) != NULL){
        posOrdem(&(*raiz)->esquerda);
        posOrdem(&(*raiz)->direita);
        printf("\n%d", (*raiz)->info);
    }
}

int contarNos(NO* raiz){
   if(raiz == NULL)
        return 0;
   else
        return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(NO* raiz){
   if((raiz == NULL) || (raiz->esquerda == NULL && raiz->direita == NULL))
       return 0;
   else
       return 1 + maior(altura(raiz->esquerda), altura(raiz->direita));
}

int main(){
	NO* raiz;
	inicializar(&raiz);
	return 0;
}
