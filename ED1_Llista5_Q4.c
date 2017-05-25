#define <stdio.h>
#define <stdlib.h>

typedef struct tipoCliente
{	char nome[30];
	int cpf;
}	Cliente;

typedef struct celulaEncadeada
{	Cliente cliente;
	struct celulaEncadeada* prox;
}	Celula, FEnc;

Celula* criar(Celula *cel)
{	Celula *fe = (Celula*) malloc ((sizeof(Celula));
	if (!fe)
	{	printf ("Falta de memoria para a criacao da fila encadeada");
		return NULL;
	}
	fe->prox = NULL;
	return fe;
}

void enqueue (FEnc *f, Cliente c);
{	Celula *p = f;
	Celula *aux = (Celula*) malloc ((sizeof(Celula));
	aux.cliente.nome = c.nome;
	aux.cliente.cpf = c.cpf;
	int i=0;
	while (p->prox != NULL)
	{	p = p->prox;
		i++;
	}
	p->prox = aux;
	aux->prox = NULL;
	printf("\n\nO Cliente %s, CPF: %d foi inserido com sucesso no final da fila!", c.nome, c.cpf);
	printf("\nTamanho: %d clientes estão atualmente aguardando na fila", i+1);
}

	
Celula* dequeue (FEnc *f, Cliente c)
{	Celula *excluida = NULL, *p = f;
	int i = 0 ;
	Celula *aux = p->prox;
	Cliente cli = aux->cliente;
	if ( (strcmp (cli.nome, c.nome) == 0 ) && (cli.cpf == c.cpf) )
	{	printf("\n\nO Cliente %s, CPF: %d foi removido com sucesso do inicio da fila!", c.nome, c.cpf);
		excluida = aux;
		p->prox = aux->prox
		aux->prox = NULL;
		while (p->prox != NULL)
		{	p = p->prox;
			i++;
		}
		printf("\nTamanho: %d clientes estão atualmente aguardando na fila", i+1);
		free (aux);
	}
	else	printf ("O Cliente %s, CPF: %d, nao pode ser removido da fila porque nao esta na primeira posicao!", c.nome, c.cpf);
	return (excluida);
}	

void imprimir(FEnc *f)
{	Celula *p = l;
	int i=0;
	printf("\n\n<<< Listagem Geral dos Clientes na Fila Encadeada >>>");
	for (p=l; p->prox != NULL; p=p->prox)
	{	printf("\n\nPosição: %d", i);
		printf("\nCliente: %s", p->cliente[i].nome);
		printf("\nCPF: %d", p->cliente[i].cpf);
		i++;
	}
	printf("\nTamanho: %d clientes estão atualmente aguardando na fila", i+1);
}

void deletar(FEnc *f)
{	Celula *p = f, aux = NULL;
	while (p->prox != NULL)
	{	aux = p;
		free(p);
		p = aux->prox;
	}
	p = f
	free(p);
}
