//ARVORE PARA TRABALHO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoElemento
{
	int id;
	char descricao[30];
	char exercicio[30];
	int nivelDeRisco;
	char ambienteTrabalho[30];
	char epiTrabalho[30];
}TElemento;

typedef struct tipoNo
{
	TElemento elemento;
	struct tipoNo *esq, *dir;
}TNo;




TNo* inserir (TNo *raiz, TElemento *elemento)
{
	if (raiz == NULL)
	{
		raiz = new TNo;
		raiz->elemento.id = elemento->id;
		strcpy(raiz->elemento.descricao, elemento->descricao);
		strcpy(raiz->elemento.exercicio,elemento->exercicio);
		raiz->elemento.nivelDeRisco = elemento->nivelDeRisco;
		strcpy(raiz->elemento.ambienteTrabalho,elemento->ambienteTrabalho);
		strcpy(raiz->elemento.epiTrabalho, elemento->epiTrabalho);
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	else
	{
		if (elemento->id < raiz->elemento.id)
		{
			 raiz->esq = inserir (raiz->esq, elemento);
		}
		else
		{
			raiz->dir = inserir (raiz->dir, elemento);
		}
	}
	return raiz;
}

void lerDados (TElemento *elemento)
{
	printf("\n Informe novo id para elemento: ");
	fflush(stdin);
	scanf("%d", &elemento->id);
	printf("\n Informe novo descricao para elemento: ");
	fflush(stdin);
	gets(elemento->descricao);
	printf("\n Informe novo exercicio para elemento: ");
	fflush(stdin);
	gets(elemento->exercicio);
	printf("\n Informe novo nivel De Risco para elemento: ");
	fflush(stdin);
	scanf("%d", &elemento->nivelDeRisco);
	printf("\n Informe novo ambiente de Trabalho para elemento: ");
	fflush(stdin);
	gets(elemento->ambienteTrabalho);
	printf("\n Informe novo epi de Trabalho para elemento: ");
	fflush(stdin);
	gets(elemento->epiTrabalho);
}

void preOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		printf("\n Id: %d", raiz->elemento.id);
		printf("\n Descricao: %s", raiz->elemento.descricao);
		printf("\n Exercicio: %s", raiz->elemento.exercicio);
		printf("\n Nivel De Risco: %d", raiz->elemento.nivelDeRisco);
		printf("\n Ambiente de Trabalho: %s", raiz->elemento.ambienteTrabalho);
		printf("\n Epi de Trabalho: %s", raiz->elemento.epiTrabalho);
		printf("\n--------------------------");
		preOrdem (raiz->esq);
		preOrdem (raiz->dir);
	}
}

void emOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		emOrdem (raiz->esq);
		printf("\n Id: %d", raiz->elemento.id);
		printf("\n Descricao: %s", raiz->elemento.descricao);
		printf("\n Exercicio: %s", raiz->elemento.exercicio);
		printf("\n Nivel De Risco: %d", raiz->elemento.nivelDeRisco);
		printf("\n Ambiente de Trabalho: %s", raiz->elemento.ambienteTrabalho);
		printf("\n Epi de Trabalho: %s", raiz->elemento.epiTrabalho);
		printf("\n--------------------------");
		emOrdem (raiz->dir);
		
	}
}

void posOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		posOrdem (raiz->esq);
		posOrdem (raiz->dir);
		printf("\n Id: %d", raiz->elemento.id);
		printf("\n Descricao: %s", raiz->elemento.descricao);
		printf("\n Exercicio: %s", raiz->elemento.exercicio);
		printf("\n Nivel De Risco: %d", raiz->elemento.nivelDeRisco);
		printf("\n Ambiente de Trabalho: %s", raiz->elemento.ambienteTrabalho);
		printf("\n Epi de Trabalho: %s", raiz->elemento.epiTrabalho);
		printf("\n--------------------------");
	}
}


int consultarRecursivo (TNo *auxRaiz, int auxValor)
{
	if (auxRaiz == NULL)
	{
		return 0;
	}
	else
	{
		if (auxRaiz->elemento.id == auxValor)
		{
			return 1;
		}
		else
		{
			if (auxValor < auxRaiz->elemento.id)
			{
				return consultarRecursivo (auxRaiz->esq, auxValor); // 2a. / 4a.
			}
			else
			{
				return consultarRecursivo (auxRaiz->dir, auxValor); // 3a. / 
			}
		}
	}
}

int sobeMaiorDireita (TNo *aux)
{
	while (aux->dir != NULL)
	{
		aux = aux->dir;
	}
	return (aux->elemento.id);
}


TNo* remover (TNo *raiz, int auxValor)
{
	if (raiz == NULL)
	{
		printf("\n Elemento nao encontrado!");
	}
	else
	{
		if (auxValor < raiz->elemento.id)
		{
			raiz->esq = remover (raiz->esq, auxValor);
		}
		else
		{
			if (auxValor > raiz->elemento.id)
			{
				raiz->dir = remover (raiz->dir, auxValor);
			}
			else //encontrei o valor
			{
				//se o elemento não tiver sub-árvore direita
				{
					if (raiz->dir == NULL)
					{
						TNo *aux;
						aux = raiz;
						raiz = raiz->esq;
						free(aux);
					}
					else
					{
						if (raiz->esq == NULL)
						{
							TNo *aux;
							aux = raiz;
							raiz = raiz->dir;
							free(aux);
						}
						else //nó possui 2 sub-árvores
						{
							raiz->elemento.id = sobeMaiorDireita (raiz->esq);
							raiz->esq = remover (raiz->esq, raiz->elemento.id);
						}
					}
				}
			}
		}
	}
	return raiz;
}


int main()
{
	TNo *raiz;
	raiz = NULL; //inicialização da raiz da árvore
	
	TElemento elemento;
	
	int opcao;
	
	do
	{
		printf("\n 1 - Inserir Id para arvore");

		printf("\n 2 - Apresentar pre-ordem");
		printf("\n 3 - Apresentar em-ordem");
		printf("\n 4 - Apresentar pos-ordem");

		printf("\n 5 - Consultar Id - recursivo");
		printf("\n 6 - Excluir Id da arvore");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
			case 1:
				{
					lerDados(&elemento);
					raiz = inserir (raiz, &elemento); break;
				}
			case 2: preOrdem (raiz); break;
			case 3: emOrdem (raiz); break;
			case 4: posOrdem (raiz); break;
			case 5:
				{
					int auxValor, encontrou;
					printf("\n Informe Id a ser consultado: ");
					scanf("%d", &auxValor);
					encontrou = consultarRecursivo(raiz, auxValor);
					if (encontrou == 1)
					{
						printf("\n Id Encontrado!");
					}
					else
					{
						printf("\n Id nao encontrado!");
					}
					getch();
					break;
				}
			case 6:
				{
					int auxValor;
					printf("\n Informe Id para ser excluido");
					scanf("%d", &auxValor);
					raiz = remover (raiz, auxValor);
				}
		}
		
	}while (opcao != 0);
}


