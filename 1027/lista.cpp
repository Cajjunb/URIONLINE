#include <stdio.h>
#include <stdlib.h>

//typedef Lista encadeada SIMPLES
typedef struct Lista{
	int valor;
	Lista *prox;
	
}Lista;

//Funcao que mostra lista toda
void mostraLista(Lista **lista){
	Lista *aux = *lista;
	while(aux != NULL)
			printf("\t%d\n",aux->valor)? aux = aux->prox: aux = aux->prox;
	return;
}

int main(){
	Lista *lista, *aux;
	int entrada;
	scanf("%d",&entrada);
	//Loop de alimentacao da lista
	while(entrada != -1){
		if(lista == NULL){
			lista = (Lista *)malloc(sizeof(Lista));
			lista->valor = entrada; 
			lista->prox = NULL;
		}else{
			aux = lista;
			while(aux->prox != NULL)
				aux = aux->prox;
			aux->prox = (Lista *)malloc(sizeof(Lista));
			aux->prox->valor = entrada;
			aux->prox->prox = NULL;	
		}	
		scanf("%d",&entrada);
	}
	//Mostra a lista inteira
	mostraLista(&lista);
	return 0 ;
}