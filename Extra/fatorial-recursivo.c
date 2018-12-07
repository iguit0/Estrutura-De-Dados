#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){       // função recursiva.
    int resultado;
    
    if(x == 0){
    	resultado = 1;   //caso base
	}else{
		resultado = x * fatorial(x - 1);    //parâmetro da chamada recursiva.
	}
	return resultado;
}
int main() {
    int fatorial(int x);
    int numero,resultado;
    
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&numero);
    
    resultado = fatorial(numero);
    
    printf("\nO fatorial e: %d\n\n",resultado);
    
	return 0;
}
