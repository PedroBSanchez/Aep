//ARVORE PARA USUARIO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoElemento
{
	int id;
	char senha[20];
	char email[40];
	char nome[20];
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
		strcpy(raiz->elemento.email, elemento->email);
		strcpy(raiz->elemento.nome, elemento->nome);
		strcpy(raiz->elemento.senha, elemento->senha);
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
	scanf("%d", &elemento->id);
	printf("\n Informe novo nome para elemento: ");
	fflush(stdin);
	gets(elemento->nome);
	printf("\n Informe novo email para elemento: ");
	fflush(stdin);
	gets(elemento->email);
	printf("\n Informe novo senha para elemento: ");
	fflush(stdin);
	gets(elemento->senha);
}

void preOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		printf("\n Id: %d", raiz->elemento.id);
		printf("\n Nome: %s", raiz->elemento.nome);
		printf("\n Email: %s", raiz->elemento.email);
		printf("\n Senha: %s", raiz->elemento.senha);
		printf("\n------------------------");
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
		printf("\n Nome: %s", raiz->elemento.nome);
		printf("\n Email: %s", raiz->elemento.email);
		printf("\n Senha: %s", raiz->elemento.senha);
		printf("\n------------------------");
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
		printf("\n Nome: %s", raiz->elemento.nome);
		printf("\n Email: %s", raiz->elemento.email);
		printf("\n Senha: %s", raiz->elemento.senha);
		printf("\n------------------------");
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
				//se o elemento n�o tiver sub-�rvore direita
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
						else //n� possui 2 sub-�rvores
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
	raiz = NULL; //inicializa��o da raiz da �rvore
	
	TElemento elemento;
	
	int opcao;
	
	do
	{
		printf("\n 1 - Inserir Id para arvore");
		printf("\n 2 - Apresentar pre-ordem");
		printf("\n 3 - Apresentar em-ordem");
		printf("\n 4 - Apresentar pos-ordem");
		printf("\n 5 - Consultar Id");
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


