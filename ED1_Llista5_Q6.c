#define <stdio.h>
#define <stdlib.h>

typedef struct tipoCliente
{	char nome[30];
	int cpf;
}	Cliente;

typedef struct celulaDupEncadeadaCircular
{	Cliente cliente;
	struct celulaDupEncadeada* prox;
	struct celulaDupEncadeada* ant;
}	Celula, LDEnc;

Celula* criar()
{	Celula *lde = (Celula*) malloc ((sizeof(Celula));
	if (!de)
	{	printf ("Falta de memoria para a criacao da Lista Duplamente Encadeada encadeada");
		return NULL;
	}
	lde->prox = NULL;
	lde->ant = NULL;
	return (lde);
}

void inserir (LDEnc *lde, Cliente c, int pos);
{	Celula *p = lde, aux = NULL;
	Celula *inc = (Celula*) malloc ((sizeof(Celula));
	inc.cliente.nome = c.nome;
	inc.cliente.cpf = c.cpf;
	int i=0;
	if (p->prox != lde)
	{	for (i=0; i<pos; i++)
		{	p = p->prox;
			if (p->prox == lde)
			{	printf ("\n\nA lista duplamente encadeada é menor que a posição desejada. A inserção será feita no fim da lista!");
				break;
			}
		} /* p aponta para o elem. da posição imediatamente anterior à posição*/
		if (p->prox != lde)
			aux = p->prox->prox; /*aux guarda pont pra o próximo elem. após a posição*/
		else		aux = lde;
		p->prox = inc;
		inc->ant = p;
		inc->prox = aux;
		aux->ant = inc;
	}
	else
	{	p-prox = inc;
		inc->prox = p;
		inc->ant = p;
		p->ant = inc;
		printf("\n\nA Lista Duplamente Encadeada estava vazia!");
	}
	printf("\nO Cliente %s, CPF: %d foi inserido com sucesso na Lista Duplamente Encadeada!", c.nome, c.cpf);
}

	
Celula* remover (LDEnc *lde, int pos)
{	Celula *excluida = NULL, *p = lde;
	int i = 0 ;
	if (p->prox != lde)
	{	for (i=0; i<pos; i++)
		{	p = p->prox;
			if (p->prox == lde)
			{	printf ("\n\nA lista duplamente encadeada é menor que a posição desejada. Sera removido o ultimo cliente!");
				break;
			}
		}
		excluida = p->prox;
		aux = excluida->prox;
		p->prox = aux;
		aux->ant = p;
		printf("\n\nO Cliente %s, CPF: %d foi removido com sucesso do inicio da Lista Duplamente Encadeada!", excluida->cliente.nome, excluida->cliente.cpf);
		aux = excluida;
		free(aux);
		return (excluida);
	}
	printf ("\n\nA lista duplamente encadeada esta vazia! Impossivel remover!");
	return (NULL);
}

void imprimir(LDEnc *lde)
{	Celula *p = lde;
	int i=0;
	printf("\n\n<<< Listagem Geral dos Clientes na Lista Duplamente Encadeada Encadeada >>>");
	for (p=lde; p->prox != NULL; p=p->prox)
	{	printf("\n\nPosição: %d", i);
		printf("\nCliente: %s", p->cliente[i].nome);
		printf("\nCPF: %d", p->cliente[i].cpf);
		i++;
	}
	printf("\nTamanho: %d clientes estão atualmente aguardando na Lista Duplamente Encadeada", i+1);
}

int buscar(LDEnc *lde, Cliente c);
{	Celula *p = lde;
	int i=0;
	int pos = -1;
	while (p->prox != lde)
	{	if  ( ( strcmp ( c.nome, p->cliente.nome ) == 0 ) && ( p->cliente.cpf == c.cpf) )
		{	pos = i;
			break;
		}
		i++;
		p=p->prox;
	}
	return pos;
}	


void deletar(LDEnc (lde)
{	Celula *p = lde, aux = lde;
	while (p->prox != lde)
	{	aux = p;
		free(p);
		p = aux->prox;
	}
	p = lde
	free(p);
}
