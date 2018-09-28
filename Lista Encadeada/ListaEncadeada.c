//IGOR LUCIO ROCHA ALVES --- 3902
#include <stdio.h>
#include <stdlib.h>

typedef struct sData{
    int num;
}Dados;

typedef struct sCell{
    Dados info;
    struct sCell* next;
}CELULA;

CELULA* criarCelula(){
    CELULA* nova = (CELULA *) malloc(sizeof(CELULA));
    return nova;
}

void inicializarLista(CELULA** lista){
    (*lista) = NULL;
}

int listaVazia(CELULA** lista){
    if(*lista == NULL){
        return 1;
    }else{
        return 0;
    }
}

int inserirFim(CELULA** lista,Dados elemento){
    CELULA* novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria cheia!!\n");
        return 0;
    }
    novaCelula->info = elemento; //se alocou, colocamos o a informacao (elemento) dentro da celula nova
    novaCelula->next = NULL; //como é inserir no final, a prox. posicao é NULL
    //se lista estiver vazia
    if(listaVazia(lista)){
        (*lista) = novaCelula;
        return 1;
    }
    //auxiliar inicia a busca pelo ultimo elemento
    CELULA* auxiliar = (*lista);
    //percorrer p/ procurar a ultima celula da lista
    while(auxiliar->next != NULL){
        auxiliar = auxiliar->next;
    }
    auxiliar->next = novaCelula; //quando achar a ultima, inserir a nova no fim.
    return 1;
}

int inserirInicio(CELULA** lista,Dados elemento){
    CELULA* novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria Cheia.");
        return 0;
    }
    novaCelula->info = elemento;
    if(listaVazia(lista)){
        return inserirFim(lista,elemento);
    }
    novaCelula->next = (*lista);
    (*lista) = novaCelula;
    return 1;
}

void imprimirElemento(Dados elemento){
    printf("%d ",elemento.num);
}

void imprimirLista(CELULA** lista){
    CELULA* auxiliar;
    auxiliar = (*lista);
    if(listaVazia(lista)){
        printf("Lista Vazia!\n");
    }else{
        while (auxiliar != NULL){
            imprimirElemento(auxiliar->info);
            auxiliar = auxiliar->next;
        }
        printf("\n");
    }
    free(auxiliar);
    auxiliar = NULL;
}

void concatenar(CELULA** lista1,CELULA** lista2){
    CELULA* l3;
    inicializarLista(&l3);
    CELULA* aux1 = (*lista1);
    CELULA* aux2 = (*lista2);
    while(!listaVazia(&aux1)){
        inserirFim(&l3,aux1->info);
        aux1 = aux1->next;
        if(listaVazia(&aux1)) break;
    }
    while(!listaVazia(&aux2)){
        inserirFim(&l3,aux2->info);
        aux2 = aux2->next;
        if(listaVazia(&aux2)) break;
    }
    imprimirLista(&l3);
    free(aux1);
    free(aux2);
    aux1 = NULL;
    aux2 = NULL;
}

int tamanhoLista(CELULA** lista){
    int cont=0;
    CELULA* auxiliar = (*lista);
    while (auxiliar != NULL){
        cont++;
        auxiliar = auxiliar->next;
    }
    free(auxiliar);
    auxiliar = NULL;
    return cont;
}

Dados removerInicio(CELULA** lista){
    CELULA* removida;
    Dados removido;
    removido.num = -1;
    if(listaVazia(lista)){
        printf("\nLista Vazia!");
        return removido;
    }
    removida = (*lista);
    removido = removida->info;
    (*lista) = (*lista)->next;
    free(removida);
    removida = NULL;
    return removido;
}

Dados removerFim(CELULA** lista){
    CELULA* removida;
    CELULA* anterior;
    Dados removido;
    removido.num = -1;
    if(listaVazia(lista)){
        printf("\nLista Vazia!");
        return removido;
    }
    if((*lista)->next == NULL){
        return removerInicio(lista);
    }
    removida = (*lista);
    while(removida->next != NULL){
        anterior = removida;
        removida = removida->next;
    }
    removido = removida->info;
    anterior->next = NULL;
    free(removida);
    removida = NULL;
    return removido;
}

void liberarCelulas(CELULA** lista){
    CELULA* auxiliar = (*lista);
    while(auxiliar != NULL){
        if(listaVazia(lista)){
            printf("\nLista Vazia!");
            return;
        }
        removerInicio(lista);
        auxiliar = auxiliar->next;
    }
    free(auxiliar);
    auxiliar = NULL;
}

int somaLista(CELULA** lista){
    CELULA* auxiliar = (*lista);
    int soma=0;
    if(listaVazia(lista)){
        printf("\nLista Vazia!");
        return 0;
    }
    while(auxiliar != NULL){
        soma += auxiliar->info.num;
        auxiliar = auxiliar->next;
    }
    free(auxiliar);
    auxiliar = NULL;
    return soma;
}

void inverter(CELULA** lista){
    CELULA* pa,*auxiliar,*pd;
    pa = NULL;
    auxiliar = (*lista);
    pd = auxiliar->next;
    if(!listaVazia(lista)){
        while(auxiliar != NULL){
            auxiliar->next = pa;
            pa = auxiliar;
            auxiliar = pd;
            if(pd != NULL) pd = pd->next;
        }
        (*lista) = pa;
    }else{
        printf("\nLista Vazia!\nImpossivel inverter");
    }
}

void intersecao(CELULA** lista1,CELULA** lista2){
    CELULA* l3;
    inicializarLista(&l3);
    CELULA* aux1 = (*lista1);
    CELULA* aux2 = (*lista2);
    while(!listaVazia(&aux1)){
        if(aux1->info.num == (*lista2)->info.num){
            inserirInicio(&l3,aux1->info);
            if(listaVazia(&aux1)) break;
        }
        aux1 = aux1->next;
    }
    while(!listaVazia(&aux2)){
        if(aux2->info.num == (*lista1)->info.num) {
            inserirInicio(&l3, aux2->info);
            if (listaVazia(&aux2)) break;
        }
        aux2 = aux2->next;
    }
    imprimirLista(&l3);
}

int inserirPositivo(CELULA** lista,Dados elemento){
    CELULA* novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria Cheia.");
        return 0;
    }
    novaCelula->info = elemento;
    if(listaVazia(lista)){
        if(novaCelula->info.num >= 0){
            return inserirFim(lista,elemento);
        }else{
            printf("\nNumero deve ser positivo.");
        }
    }
    if(novaCelula->info.num >= 0){
        novaCelula->next = (*lista);
        (*lista) = novaCelula;
        return 1;
    }else{
        printf("\nNumero deve ser positivo.");
        return 0;
    }
}



CELULA* pesquisarImpar(CELULA** lista){
    CELULA* auxiliar;
    if(listaVazia(lista)){
      printf("\nErro: Lista Vazia.");
      return NULL;
    }
    auxiliar = (*lista);
    while (auxiliar != NULL) {
      if(auxiliar->info.num%2==1){
        return auxiliar;
      }
      auxiliar = auxiliar->next;
    }
    return NULL;
    free(auxiliar);
    auxiliar = NULL;
}

Dados removerImpar(CELULA** lista){
    CELULA* removida;
    CELULA* aux = (*lista);
    CELULA* anterior;
    Dados removido;
    removido.num = -1;
    if(listaVazia(lista)){
        return removido;
    }
    while (aux != NULL) {
      removida = pesquisarImpar(lista);
      if(removida == NULL){
        return removido;
      }
      if(removida == (*lista)){
          return removerInicio(lista);
      }

      removido = removida->info;
      anterior = (*lista);

      while (anterior->next != removida) {
        anterior = anterior->next;
      }
      anterior->next = removida->next;
    }
    free(removida);
    return removido;
    removida = NULL;
}

int main() {
    Dados d;
    CELULA* lista1;
    CELULA* lista2;
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    int opcao=0,lista_option=0;
    do{
        printf("\n\t:: Menu de Opcoes ::\n\n");
        printf("\t1 - Inserir Elemento\n");
        printf("\t2 - Tamanho da Lista\n");
        printf("\t3 - Remover impares\n");
        printf("\t4 - Concatenar Listas\n");
        printf("\t5 - Imprimir Lista\n");
        printf("\t6 - Liberar Celulas\n");
        printf("\t7 - Inverter Lista\n");
        printf("\t8 - Intersecao\n");
        printf("\t9 - Soma de Elementos\n");
        printf("\t10 - Sair\n\n");
        printf("Escolha uma opcao ->  ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("\nEscolha a Lista (1 ou 2) -> ");
                scanf("%d",&lista_option);
                fflush(stdin);
                if(lista_option == 1){
                  printf("\nDigite o elemento a ser inserido -> ");
                  scanf("%d",&d.num);
                  if(inserirInicio(&lista1,d)==1)
                    printf("\n\tInserido com sucesso!\n\n");
                    else printf("\n\tErro na insercao!\n\n");
                }else if(lista_option == 2){
                  printf("\nDigite o elemento a ser inserido -> ");
                  scanf("%d",&d.num);
                  if(inserirInicio(&lista2,d)==1)
                    printf("\n\tInserido com sucesso!\n\n");
                    else printf("\n\tErro na insercao!\n\n");
                } else printf("\nOpcao invalida!\n\n");
                break;
            case 2:
            printf("\nEscolha a Lista (1 ou 2) -> ");
            scanf("%d",&lista_option);
            fflush(stdin);
            if(lista_option == 1){
                printf("\n\tTamanho: %d\n\n",tamanhoLista(&lista1));
            }else if(lista_option == 2){
                printf("\n\tTamanho: %d\n\n",tamanhoLista(&lista2));
            } else printf("\nOpcao invalida!\n\n");
            break;
            case 3:
                printf("\nEscolha lista 1 ou 2: ");
                scanf("%d",&lista_option);
                if(lista_option == 1) removerImpar(&lista1);
                else if(lista_option == 2) removerImpar(&lista2);
                else printf("\nOpcao invalida.");
                break;
            case 4:
                concatenar(&lista1,&lista2);
                break;
            case 5:
                printf("\nEscolha lista 1 ou 2: ");
                scanf("%d",&lista_option);
                if(lista_option == 1) imprimirLista(&lista1);
                else if(lista_option == 2) imprimirLista(&lista2);
                else printf("\nOpcao invalida.");
                break;
            case 6:
                printf("\nEscolha lista 1 ou 2: ");
                scanf("%d",&lista_option);
                if(lista_option == 1) liberarCelulas(&lista1);
                else if(lista_option == 2) liberarCelulas(&lista2);
                else printf("\nOpcao invalida.");
                break;
            case 7:
                printf("\nEscolha lista 1 ou 2: ");
                scanf("%d",&lista_option);
                if(lista_option == 1) inverter(&lista1);
                else if(lista_option == 2) inverter(&lista2);
                else printf("\nOpcao invalida.");
                break;
            case 8:
                intersecao(&lista1,&lista2);
                break;
            case 9:
                printf("\nEscolha lista 1 ou 2: ");
                scanf("%d",&lista_option);
                if(lista_option == 1) printf("\nSoma: %d\n\n",somaLista(&lista1));
                else if(lista_option == 2) printf("\nSoma: %d\n\n",somaLista(&lista2));
                else printf("\nOpcao invalida.");
                break;
            case 10:
                printf("\nVoce Saiu!");
                break;
        }

    }while(opcao != 10);

    free(lista1);
    free(lista2);
    lista1 = NULL;
    lista2 = NULL;
    return 0;
}
