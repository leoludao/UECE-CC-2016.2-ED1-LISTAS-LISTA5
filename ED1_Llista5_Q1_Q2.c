#define <stdio.h>
#define <stdlib.h>

typedef struct tipoCliente
{	char nome[30];
	int cpf;
}	Cliente;

typedef struct celulaEncadeada
{	Cliente cliente;
	struct celulaEncadeada* prox;
}	Celula, LEnc;

Celula* criar(Celula *cel)
{	Celula *le = (Celula*) malloc ((sizeof(Celula));
	if (!le)
	{	printf ("Falta de memoria para a criacao da lista encadeada");
		return NULL;
	}
	le->prox = NULL;
	return le;
}

void inserir (LEnc *l, Celula c, int pos);
{	Celula *p = l;
	int i=0;
	if (p->prox != NULL)
	{	for (i=0; i < pos; i++)
		{	p = p->prox;
			if (p->prox == NULL)
			{	printf("A lista e menor que a posicao desejada! O Cliente sera inserido no fim da lista!");
				break;
			}
		} /* ao fim do laço, p aponta para o elemento da posição imediatamente antes a pos*/
	c->prox = p->prox;
	p->prox = c;
	return;
}

	
Celula* remover (LEnc *l, int pos)
{	Celula *excluida=NULL, *p=l;
	int i;
	if (p->prox!=NULL)
	{	for (i=0; i < pos; i++)
		{	p = p->prox;
			if (p->prox == NULL)
			{	printf("A lista e menor que a posicao desejada! Sera removido o último Cliente da lista!");
				break;
			}			
		} /* ao fim do laço, p aponta para o elemento da posição imediatamente antes a pos*/
	}
	excluida = p->prox;
	p->prox = excluida->prox;
	excluida->prox = NULL;
	free (excluida);
	return (excluida);
}	

int Busca (LEnc *l, Cliente c)
{	Celula *p = l;
	Cliente aux;
	int pos=-1, i=0;
	while (p->prox !=NULL)
	{	pos = i;
		aux = p->Cliente[i];
		if ( (strcmp (aux.nome, c.nome) == 0 ) && (aux.cpf == c.cpf) )
			break;
		p = p->prox;
		i++;
	}
	if (pos == -1)
		printf ("O Cliente nao esta na lista!");
	return pos;
}


void imprimir(LEnc *l)
{	Celula *p = l;
	int i=0;
	printf("\n\n<<< Listagem Geral dos Clientes na Lista Encadeada>>>");
	for (p=l; p->prox != NULL; p=p->prox)
	{	printf("\n\nPosição: %d", i);
		printf("\nCliente: %s", p->cliente[i].nome);
		printf("\nCPF: %d", p->cliente[i].cpf);
		i++;
	}
}

void deletar(LEnc *l)
{	Celula *p = l, aux = NULL;
	while (p->prox != NULL)
	{	aux = p;
		free(p);
		p = aux->prox;
	}
	p = l
	free(p);
}
