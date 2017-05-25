#define <stdio.h>
#define <stdlib.h>

typedef struct tipoCliente
{	char nome[30];
	int cpf;
}	Cliente;

typedef struct celulaEncadeada
{	Cliente cliente;
	struct celulaEncadeada* prox;
}	Celula;

typedef struct pilhaEncadeada
{	Celula *topo;
	Celula *fundo;
	int tamanho;
}	PEnc;


PEnc* criar()
{	PEnc *pi = (PEnc*) malloc ((sizeof(PEnc));
	if (!pi)
	{	printf ("Falta de memoria para a criacao da pilha encadeada");
		return NULL;
	}
	pi->topo = (Celula*) malloc (sizeof(Celula));
	pi->fundo = pi->topo;
	pi->topo->prox = NULL;
	pi->tamanho = 0;
	return pi;
}

void push (PEnc *pi, Cliente c);
{	Celula *p = (Celula*) malloc (sizeof(Celula));
	p->cliente = c; /*criou*/
	p->prox = pi->topo; /*apontou*/
	pi->topo = p; /*atualizou o criado*/
	pi->tamanho++;
	return;
}

Cliente pop(PEnc *pi, Cliente c);
{	Celula *p = pi->topo;
	Celula aux = NULL;
	if ( ( (strcmp (p->cliente.nome,c.nome)) == 0) && (p->cliente.cpf == c.cpf) )
	{	pi->topo = p->prox;
		p->prox = NULL;
		aux = p->cliente;
		free(p);
		pi->tamanho--;
		printf("O Cliente %s, CPF: %d, foi removido da pilha!", aux.nome, aux.cpf);
	}
	if (aux == NULL)	printf("O Cliente nao pode ser removido porque nao esta no topo da pilha");
	return (aux);
}

void deletar(PEnc *pi)
{	Celula *p = pi->topo, aux = NULL;
	while (p->prox != pi->fundo)
	{	aux = p;
		free(p);
		p = aux->prox;
	}
	free(pi);
}
