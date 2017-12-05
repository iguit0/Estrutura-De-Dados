#include <stdio.h>
#include <string.h>
#define MAX_TAM 10

typedef struct sMusica{
    char nome[30];
    int duracao;
    char banda[30];
    int ranque;
}Musica;

typedef struct sLista{
    Musica musica[MAX_TAM];
    int ultimo;
}Lista;

void inicializarLista(Lista* lista){
    lista->ultimo = -1;
}
int inserirMusica(Lista* lista,Musica musica){
    if(listaCheia(lista)){
        printf("\nLista Cheia!\n");
        return 0;
    }
    lista->musica[lista->ultimo+1] = musica;
    lista->ultimo = (lista->ultimo+1);
    return 1;
}
int listaVazia(Lista* lista){
    if(lista->ultimo == -1) return 1;
    else return 0;
}
int listaCheia(Lista* lista){
    if(lista->ultimo == (MAX_TAM - 1)) return 1;
    else return 0;

}
int removerInicio(Lista* lista){
    int i=0;
    if(listaVazia(lista)){
        printf("\nLista Vazia!\n");
        return 0;
    }
    for (i = 0; i < lista->ultimo; i++) {
        lista->musica[i] = lista->musica[i+1];
    }
    lista->ultimo--;
    return 1;
}

int tamanhoLista(Lista* lista){
    return lista->ultimo+1;
}

int inserirOrdenado(Lista* lista,Musica musica){
    int i=0,posicao=0;
    if(listaCheia(lista)){
        printf("\nLista Cheia!\n");
        return 0;
    }
    if(listaVazia(lista)){
        inserirMusica(lista,musica);
        return 1;
    }else{
        for (i = 0; i <= lista->ultimo; i++) {
            if (musica.ranque > lista->musica[i].ranque) {
                posicao = i;
                break;
            }
        }
        for (i = lista->ultimo; i >= posicao; i--) {
            lista->musica[i+1] = lista->musica[i];
        }
        lista->musica[posicao] = musica;
        lista->ultimo = (lista->ultimo + 1);
        return 1;
	}
}

void imprimirLista(Lista* lista){
    int i=0;
    if(listaVazia(lista)){
        printf("\nLista Vazia!\n");
        return;
    }
    for (i = 0; i <= lista->ultimo; i++) {
        printf("\nMusica n.:[%d]\n",i);
        printf("\nNome: %s\n",lista->musica[i].nome);
        printf("\nDuracao: %d\n",lista->musica[i].duracao);
        printf("\nBanda: %s\n",lista->musica[i].banda);
        printf("\nRanque: %d\n",lista->musica[i].ranque);
    }
}

int main(){
    Lista lista;
    Musica musica;
    int opcao=0;
    inicializarLista(&lista);
    do{
        printf("\t\t\t**** Pratica 1 **** \n\n");
        printf(":: Menu de Opcoes ::\n\n");
        printf("1 - Lista Vazia\n");
        printf("2 - Lista Cheia\n");
        printf("3 - Inserindo Musica\n");
        printf("4 - Remover Inicio\n");
        printf("5 - Inserir Ordenado\n");
        printf("6 - Tamanho da Lista\n");
        printf("7 - Imprimir Lista\n");
        printf("8 - Sair\n\n");
        printf("Escolha uma opcao ->  ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                if(listaVazia(&lista) == 1) printf("\nLista Vazia!\n");
                else printf("\nLista nao vazia!");
                break;
            case 2:
                if(listaCheia(&lista) == 1) printf("\nLista Cheia!\n");
                else printf("\nLista nao esta cheia!\n");
                break;
            case 3:
                printf("\nInserindo musica...\n");
                printf("\nNome: ");
                scanf("%s",musica.nome);
                fflush(stdin);
                printf("\nDuracao: ");
                scanf("%d",&musica.duracao);
                fflush(stdin);
                printf("\nBanda: ");
                scanf("%s",musica.banda);
                fflush(stdin);
                printf("\nRanque: ");
                scanf("%d",&musica.ranque);
                if(inserirMusica(&lista,musica) == 1) printf("\nMusica inserida com sucesso!\n");
                else printf("\nERRO: Musica nao inserida!\n");
                break;
            case 4:
                if(removerInicio(&lista) == 1) printf("\nRemovido com sucesso!\n");
                else printf("\nERRO: Nao Removido\n");
                break;
            case 5:
                printf("\nInserindo ordenado...\n");
                /*printf("\nNome: ");
                scanf("%s",musica.nome);
                fflush(stdin);
                printf("\nDuracao: ");
                scanf("%d",&musica.duracao);
                fflush(stdin);
                printf("\nBanda: ");
                scanf("%s",musica.banda);
                fflush(stdin);
                printf("\nRanque: ");
                scanf("%d",&musica.ranque);
                fflush(stdin);*/
                strcpy(musica.nome,"Musica 1");
                strcpy(musica.banda,"Teste");
                musica.ranque = 1;
                musica.duracao = 30;

                if(inserirOrdenado(&lista,musica) == 1) printf("\nMusica inserida com sucesso!\n");
                else printf("\nERRO: Musica nao inserida!\n");

                strcpy(musica.nome,"Musica 2");
                strcpy(musica.banda,"Teste");
                musica.ranque = 2;
                musica.duracao = 30;

                if(inserirOrdenado(&lista,musica) == 1) printf("\nMusica inserida com sucesso!\n");
                else printf("\nERRO: Musica nao inserida!\n");

                strcpy(musica.nome,"Musica 3");
                strcpy(musica.banda,"Teste");
                musica.ranque = 3;
                musica.duracao = 30;

                if(inserirOrdenado(&lista,musica) == 1) printf("\nMusica inserida com sucesso!\n");
                else printf("\nERRO: Musica nao inserida!\n");

                break;
            case 6:
                printf("\nTamanho: %d\n",tamanhoLista(&lista));
                break;
            case 7:
                printf("\nImprimindo Lista...\n");
                imprimirLista(&lista);
                break;
            case 8:
                printf("Voce saiu!");
                break;
        }

    }while(opcao != 8);


    return 0;
}
