#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct sRevista{
	char nome[30];
	int n_pags;
	char categoria[30];
}REVISTA;

typedef struct sPilha{
	REVISTA elem[SIZE];
	int topo;
}PILHA;

void inicializarPilha(PILHA* p);
int pilhaVazia(PILHA* p);
int pilhaCheia(PILHA* p);
int push(PILHA* p,REVISTA elemento);
REVISTA pop(PILHA* p);
REVISTA topoEl(PILHA* p);
void imprimirElemento(REVISTA elem);
int imprimirPop(PILHA* p);
int imprimirAux(PILHA* p);

int main(){
	PILHA p;	
	REVISTA info;
	int opcao=0;

  do {
      printf("\n1 - Inicializar Pilha\n");
      printf("2 - Pilha Vazia\n");
      printf("3 - Pilha Cheia\n");
      printf("4 - Push\n");
      printf("5 - Pop\n");
      printf("6 - Elemento Topo\n");
      printf("7 - Imprimir e desempilhar\n");
      printf("8 - Imprimir usando Auxiliar\n");
      printf("0 - Sair\n\n");
      printf("Digite sua opcao > ");
      scanf("%d",&opcao);
      switch (opcao) {
        case 1:
            inicializarPilha(&p);
            break;
        case 2:
            if(pilhaVazia(&p)==1) printf("Pilha Vazia!\n");
            else printf("Pilha Nao Vazia\n");
            break;
        case 3:
        	if(pilhaCheia(&p)==1) printf("Pilha Cheia!\n");
            else printf("Pilha Nao Cheia\n");
            break;
        case 4:
        	printf("\nNome > ");
        	scanf("%s",info.nome);
        	printf("\nN. Pags.: > ");
        	scanf("%d",&info.n_pags);
        	printf("\nCategoria > ");
        	scanf("%s",info.categoria);
            if(push(&p,info)==1) printf("Inserido com Sucesso\n");
            else printf("ERRO: Inserir\n");
            break;
        case 5:
            pop(&p);
            printf("\nRemovido!");
            break;
        case 6:
        	printf("\nElemento do Topo > \n");
            imprimirElemento(topoEl(&p));
            break;
        case 7:
            imprimirPop(&p);
        	break;
        case 8:
            imprimirAux(&p);
        	break;
        case 0:
            printf("Voce Saiu!!\n");
            break;
      }
  } while(opcao != 0);


	return 0;	
}

void inicializarPilha(PILHA* p){
	p->topo = -1;
}

int pilhaVazia(PILHA* p){
	if(p->topo == -1) return 1;
	else return 0;
}

int pilhaCheia(PILHA* p){
	if(p->topo == (SIZE-1)) return 1;
	return 0;
}

int push(PILHA* p,REVISTA elemento){
	if(pilhaCheia(p)) return 0;
	p->elem[p->topo+1] = elemento;
	p->topo++;
	return 1;
}

REVISTA pop(PILHA* p){
	REVISTA removido;
	strcpy(removido.nome," ");
	strcpy(removido.categoria," ");
	removido.n_pags = -1;
	if(pilhaVazia(p)) return removido;
	removido = p->elem[p->topo];
	p->topo--;
	return removido;
}

REVISTA topoEl(PILHA* p){
	REVISTA topo;
	strcpy(topo.nome," ");
	strcpy(topo.categoria," ");
	topo.n_pags = -1;
	if(pilhaVazia(p)){
		return topo;
	}
	topo = p->elem[p->topo];
	return topo;
}

void imprimirElemento(REVISTA elem){
	printf("\nNome: %s",elem.nome);
	printf("\nN.pags: %d",elem.n_pags);
	printf("\nCategoria: %s\n",elem.categoria);
}

// imprimir e desempilhar todos elementos
int imprimirPop(PILHA* p){
	PILHA aux;
	inicializarPilha(&aux);
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!");
		return 0;
	}
	//retirando da pilha original e colocando na pilha auxiliar
	while(!pilhaVazia(p)){
		push(&aux,pop(p));
	}
	//imprimindo e desempilhando ao mesmo tempo.
	while(!pilhaVazia(&aux)){
		imprimirElemento(pop(&aux));
	}
	return 1;
}

// Imprimir usando uma pilha auxiliar
int imprimirAux(PILHA* p){
	PILHA aux;
	inicializarPilha(&aux);
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!");
		return 0;	
	}
	//enquanto a pilha original nao esta vazia, retira elemento da original e põe na auxiliar (depois imprime)
	while(!pilhaVazia(p)){
		push(&aux,pop(p));
		imprimirElemento(topoEl(&aux));
	}
	// depois de usar a auxiliar pra impressão, voltando os elementos para pilha original
	while(!pilhaVazia(&aux)){
		push(p,pop(&aux));	
	}
	return 1;
}
