#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


//typedef Lista encadeada SIMPLES
typedef struct Lista{
	int 	valor;
	int 	ehPrimeiro;
	Lista 	*prox;
	Lista 	*ant;
}Lista;

class ListaDuplaEncadeada{
	//Campos da classe
	public: int tamanho ;
	private: Lista *cabeca;


	public:
		//Construtor
		ListaDuplaEncadeada(){
			this->tamanho = 0;
			this->cabeca  = NULL;
		}

		~ListaDuplaEncadeada(){

		}

		//Funcao que mostra lista toda
		void mostraLista(){
			Lista *aux = this->cabeca;
			do{
				printf("\t%d\n",aux->valor)? aux = aux->prox: aux = aux->prox;
			}while(!aux->ehPrimeiro);
			return;
		}

		void algoritmoFlaviousJosephus(int pulos){
			Lista *aux = this->cabeca;
			int  i = 0 ;
			while(this->tamanho > 1){
				i += pulos-1;
				i = i%(this->tamanho+1);
				this->eliminaDaLista(i);
			}
		}

		//funcao que elimina da lista dupla encadeada
		// Primeiro andamos na lista
		// caso que seja cabeca da lista
		// caso que nao seja
		void eliminaDaLista(int indice){
			Lista *aux = this->cabeca;
			while( indice-- >0)
				aux = aux->prox;
			if(aux == this->cabeca){
				this->cabeca= aux->prox;
				this->cabeca->ehPrimeiro = TRUE;
				free(aux);
			}else{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				free(aux);
			}
			this->tamanho--;
			return ;
		}	

		//Funcao que faz a lista ser inserida no final um elemento
		void insereLista(int i){
			Lista *aux = NULL;
			if(this->cabeca == NULL){
				this->cabeca = (Lista *)malloc(sizeof(Lista));
				this->cabeca->valor = i; 
				this->cabeca->ehPrimeiro = TRUE;
				this->cabeca->prox = this->cabeca; 
				this->cabeca->ant = this->cabeca;
			}else{
				aux = this->cabeca;
				while(aux->prox != this->cabeca)
					aux = aux->prox;
				aux->prox = (Lista *)malloc(sizeof(Lista));
				aux->prox->valor = i;
				aux->prox->ehPrimeiro = FALSE;
				aux->prox->prox = this->cabeca;	
				aux->prox->ant = aux;
				this->cabeca->ant = aux->prox;
			}
			this->tamanho++;
			return;
		}

		// GETS e SETS
		Lista* getCabeca(){
			return this->cabeca;
		}


};

int main(){
	int   entrada, pulos, i = 0,numTestes,j = 0;
	scanf("%d",&numTestes);
	for (j = 0; j < numTestes; ++j){
		ListaDuplaEncadeada lista;
		//Leitura argumentos 
		scanf("%d %d",&entrada,&pulos);
		//Loop de alimentacao da lista
		while(entrada > i++){
			lista.insereLista(i);
		}
		lista.algoritmoFlaviousJosephus(pulos);
		printf("Case %d: %d\n",j+1, lista.getCabeca()->valor);
	}
	return 0 ;
}