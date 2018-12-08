#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
/* int tipo;
        0 - Não Crítico
        1 - Crítico */
typedef struct sElemento{
    int id;
    int tipo;
}SO;

typedef struct sDeque{
    SO info[SIZE];
    int ultimo,cabecalho;
}DEQUE;

void inicializar(DEQUE* d){
    d->ultimo = 0;
    d->cabecalho = d->ultimo;
}

int dequeCheio(DEQUE* d){
    if( ((d->ultimo+1)%SIZE) == d->cabecalho){
        return 1;
    }
    return 0;
}

int dequeVazia(DEQUE* d){
    if (d->ultimo == d->cabecalho){
        return 1;
    }
    return 0;
}

int inserirInicio(DEQUE* d,SO elemento){
    int anterior;
    if(dequeCheio(d)){
        printf("\nDeque Cheio!!");
        return 0;
    }
    d->info[d->cabecalho] = elemento;
    anterior = (SIZE + (d->cabecalho-1))%SIZE;
    d->cabecalho = anterior;
    return 1;
}

int inserirFim(DEQUE* d,SO elemento){
    if(dequeCheio(d)){
        printf("\nDeque Cheio!!");
        return 0;
    }
    int proxi = (d->ultimo+1)%SIZE;
    d->info[proxi] = elemento;
    d->ultimo = proxi;
    return 1;
}

SO removerInicio(DEQUE* d){
    SO removido;
    removido.id = -1;
    if(dequeVazia(d)){
        printf("\nDeque Vazio!");
        return removido;
    }
    d->cabecalho = (d->cabecalho+1)%SIZE;
    removido = d->info[d->cabecalho];
    return removido;
}

SO removerFim(DEQUE* d){
    SO removido;
    int anterior;
    if(dequeVazia(d)){
        printf("\nDeque Vazio!");
        return removido;
    }
    removido = d->info[d->ultimo];
    anterior = (SIZE+(d->ultimo-1))%SIZE;
    d->ultimo = anterior;
    return removido;
}

void imprimirElemento(SO info){
    printf("\nID: %d\nTipo: %d\n",info.id,info.tipo);
}

void imprimir(DEQUE* d){
    SO aux;
    DEQUE daux;
    inicializar(&daux);
    if(dequeVazia(d)){
        printf("\nDeque Vazio!!");
    }else{
        while(!dequeVazia(d)){
            aux = removerInicio(d);
            imprimirElemento(aux);
            inserirFim(&daux,aux);
        }
        while(!dequeVazia(&daux)){
            inserirFim(d,removerInicio(&daux));
        }
    }
}

void liberarInicio(DEQUE* d){
    if(dequeVazia(d)){
        printf("\nDeque Vazio!");
        return;
    }
    imprimir(d);
    while(!dequeVazia(d)){
        removerInicio(d);
    }
}

void liberarFim(DEQUE* d){
    if(dequeVazia(d)){
        printf("\nDeque Vazio!");
        return;
    }
    imprimir(d);
    while(!dequeVazia(d)){
        removerFim(d);
    }
}

SO imprimeInit(DEQUE* d){
    if(dequeVazia(d)){
        printf("\nDeque Vazio!!");
        return;
    }
    int proxi = (d->cabecalho+1)%SIZE;
    imprimirElemento(d->info[proxi]);
}

SO imprimeFim(DEQUE* d){
    if(dequeVazia(d)){
        printf("\nDeque Vazio!");
        return;
    }
    int anterior = (SIZE+(d->ultimo-1))%SIZE;
    imprimirElemento(d->info[anterior]);
}

int inserirPrioridade(DEQUE* d,SO elemento){
    if(dequeCheio(d)){
        printf("\nDeque Cheio!!");
        return 0;
    }
    if(elemento.tipo == 1){
        inserirInicio(d,elemento);
    }else if(elemento.tipo == 0){
        inserirFim(d,elemento);
    }
    return 1;
}

int tamanhoDeque(DEQUE* d){
    if(dequeVazia(d)){
        printf("\nDeque Vazio!!");
        return 0;
    }
    DEQUE aux;
	inicializar(&aux);
	int cont=0;
	while(!dequeVazia(d)){
		cont++;
        inserirInicio(&aux,removerInicio(d));
	}
	while(!dequeVazia(&aux)){
        inserirInicio(d,removerInicio(&aux));
	}
	return cont;
}

int main(){
    DEQUE d;
	SO info;
	int opcao;
    inicializar(&d);
	do{
		system("cls");
		printf("\t\t\t**** DEQUE ESTATICO || MENU **** \n\n");
		printf("\t\t\t#### SEJA BEM VINDO(A) #### \n");
		printf(":: Menu de Opcoes ::\n\n");
		printf("1 - Vazio\n");
		printf("2 - Cheio\n");
        printf("3 - Inserir por Prioridade\n");
		printf("4 - Imprimir o deque e remover todos os elementos a partir do inicio.\n");
		printf("5 - Imprimir o deque e remover todos os elementos a partir do fim.\n");
		printf("6 - Imprimir o elemento do inicio sem remove-lo\n");
        printf("7 - Imprimir o elemento do fim sem remove-lo\n");
        printf("8 - Tamanho\n");
		printf("0 - Sair\n\n");
		printf("Escolha uma opcao:  ");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao){
			case 1:
                if(dequeVazia(&d)==1)
                    printf("\nDeque Vazio!");
                else printf("\nDeque nao esta vazio!");
				printf("\n\n");
				system("pause");
				break;
			case 2:
                if(dequeCheio(&d)==1)
                    printf("\nDeque Cheio!");
                else printf("\nDeque nao esta cheio!");
                printf("\n\n");
				system("pause");
				break;
			case 3:
                fflush(stdin);
                printf("\nID: ");
                scanf("%d",&info.id);
                fflush(stdin);
                printf("\nTipo: ");
                scanf("%d",&info.tipo);
                fflush(stdin);
                if(inserirPrioridade(&d,info)==1)
                    printf("\nInserido com sucesso!!");
				printf("\n\n");
				system("pause");
				break;
			case 4:
                liberarInicio(&d);
                printf("\n\n");
				system("pause");
				break;
            case 5:
                liberarFim(&d);
                printf("\n\n");
				system("pause");
				break;
            case 6:
                imprimeInit(&d);
                printf("\n\n");
				system("pause");
				break;
            case 7:
                imprimeFim(&d);
                printf("\n\n");
				system("pause");
				break;
            case 8:
                printf("\nTamanho: %d\n",tamanhoDeque(&d));
                printf("\n\n");
				system("pause");
				break;
            case 0:
                printf("\nVoce saiu!!");
                printf("\n\n");
				system("pause");
				break;
			default:
				printf("\nDigite uma opcao valida.\n");
		}

	}while(opcao != 0);

    return 0;
}
