#include <stdio.h>
#include <stdlib.h>

//typedef Lista encadeada SIMPLES
typedef struct Lista{
	int 	valor;
	Lista 	*prox;
	Lista 	*ant;
}Lista;

//Funcao que mostra lista toda
void mostraLista(Lista **lista){
	Lista *aux = *lista;
	while(aux != NULL)
			printf("\t%d\n",aux->valor)? aux = aux->prox: aux = aux->prox;
	return;
}


//funcao que elimina da lista dupla encadeada
// Primeiro andamos na lista
// caso que seja cabeca da lista
// caso que nao seja
void eliminaDaLista(Lista **lista, int indice){
	Lista *aux = *lista;
	while( indice-- >0)
		aux = aux->prox;
	if(aux == *lista){
		*lista = aux->prox;
		free(aux);
	}else{
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		free(aux);
	}
	return ;
}

int main(){
	Lista *lista = NULL, *aux = NULL;
	int   entrada, pulos, i = 0;
	scanf("%d %d",&entrada,&pulos);
	//Loop de alimentacao da lista
	while(entrada > i++){
		if(lista == NULL){
			lista = (Lista *)malloc(sizeof(Lista));
			lista->valor = i; 
			lista->prox = NULL; 
			lista->ant = NULL;
		}else{
			aux = lista;
			while(aux->prox != NULL)
				aux = aux->prox;
			aux->prox = (Lista *)malloc(sizeof(Lista));
			aux->prox->valor = i;
			aux->prox->prox = NULL;	
			aux->prox->ant = aux;
		}	
	}
	//Mostra a lista inteira
	mostraLista(&lista);
	eliminaDaLista(&lista,pulos);
	mostraLista(&lista);
	return 0 ;
}