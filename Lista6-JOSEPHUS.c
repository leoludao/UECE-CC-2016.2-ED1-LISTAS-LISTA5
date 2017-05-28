#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoCandidato
{	char nome[30];
	int numero;
	char partido[10];
}	Candidato;

typedef struct celulaDuplamenteEncadeada
{	Candidato candidato;
	struct celulaDuplamenteEncadeada* hrr; /*próx Célula no sentido horário*/
	struct celulaDuplamenteEncadeada* ant; /*próx Célula no sentido anti-horário*/
}	CelulaDE;

typedef struct listaCircular
{	CelulaDE *celApontada;
	int tamanho;
	int sentido; /* (-1) se for pra o apontamento rodar em sentido anti-horario, e (+1) em sentido horário*/
}	listaCirc;


listaCirc* criar_listaCirc()
{	CelulaDE *cel = (CelulaDE*) malloc (sizeof(CelulaDE));
	listaCirc *lcirc = (listaCirc*) malloc (sizeof(listaCirc));
	if (!lcirc)
	{	printf ("Falta de memoria para a criacao da Lista Circular");
		return NULL;
	}
	lcirc->celApontada = cel;
	cel->hrr = lcirc->celApontada;
	cel->ant = lcirc->celApontada;
	lcirc->tamanho = 0; /*tamanho guardara a posição de inserção do próximo elemento*/
	lcirc->sentido = 0;
	return (lcirc);
}


void insecao_horaria (listaCirc *lcirc, Candidato cand, int pos)
{	CelulaDE *p = lcirc->celApontada, *aux = NULL, *celRef = p;
	int i;
	if ( pos <= 0 )		pos = 1; /* o valor mínimo para pos é 1, que é a posição atualmente apontada */

	/* Caso base: lista vazia */
	if ( lcirc->tamanho == 0 )
	{	strcpy (p->candidato.nome, cand.nome);
		p->candidato.numero = cand.numero;
		strcpy (p->candidato.partido, cand.partido);
		printf("\n\nA Lista Circular estava vazia!");
		lcirc->celApontada = p;
	}
	else
	{	CelulaDE *inc = (CelulaDE*) malloc (sizeof(CelulaDE));
		strcpy (inc->candidato.nome, cand.nome);
		inc->candidato.numero = cand.numero;
		strcpy (inc->candidato.partido, cand.partido);
		if ( pos > lcirc->tamanho )	/* Caso pos inserção maior que tamanho da Lista Circular */
		{	printf ("\n\nA Lista Circular e menor que a posicao desejada. A insercao horaria sera feita na posicao imediatamente anterior a da celula atualmente apontada!");
			p = p->ant;	/* p aponta para a posição do último elemento antes da célula apontada */
			p->hrr = inc;
			/* p->ant não precisa mudar pois aponta para o penúltimo elemento*/
			inc->ant = p;
			inc->hrr = celRef;
			celRef->ant = inc;
			/* celRef->hrr não precisa mudar pois aponta para o primeiro elem após a ref */
		}
		else		/* Caso pos inserção menor que ou igual ao tamanho da Lista Circular */	
		{	for ( i=1 ; i < pos - 1 ; i++ )
			{	p = p->hrr;
			}	/* p aponta para a posição do elemento imediatmente anteriror à posição onde se quer inserir */
			aux = p->hrr;
			p->hrr = inc;
			inc->hrr = aux;
			inc->ant = p;
			aux->ant = inc;
		}
		lcirc->celApontada = inc;
	}
	printf("\nO candidato %s, numero: %d, partido: %s foi inserido com sucesso na Eleicao Circular!", cand.nome, cand.numero, cand.partido);
	lcirc->tamanho++;
	printf("\nTamanho atual da Lista Circular: %d candidatos !", lcirc->tamanho);
	return;
}

void insecao_anti_horaria (listaCirc *lcirc, Candidato cand, int pos)
{	CelulaDE *p = lcirc->celApontada, *celRef = p, *aux = NULL;
	int i=0;
	if ( pos <= 0 )		pos = 1; /* o valor mínimo para pos é 1, que é a posição atualmente apontada */

	/* Caso base: lista vazia */
	if ( lcirc->tamanho == 0 )
	{	strcpy (p->candidato.nome, cand.nome);
		p->candidato.numero = cand.numero;
		strcpy (p->candidato.partido, cand.partido);
		printf("\n\nA Lista Duplamente Encadeada estava vazia!");
		lcirc->celApontada = p;
	}
	else
	{	CelulaDE *inc = (CelulaDE*) malloc (sizeof(CelulaDE));
		strcpy (inc->candidato.nome, cand.nome);
		inc->candidato.numero = cand.numero;
		strcpy (inc->candidato.partido, cand.partido);
		
		if ( pos > lcirc->tamanho )	/* Caso pos inserção maior que tamanho da Lista Circular */
		{	printf ("\n\nA Lista Circular e menor que a posicao desejada. A insercao horaria sera feita na posicao imediatamente posterior a da celula atualmente apontada!");
			p = p->hrr;	/* p aponta para a posição do último elemento antes da célula apontada, considerando-se o sentido anti-horário*/
			p->ant = inc;
			/* p->hrr não precisa mudar pois aponta para o penúltimo elemento*/
			inc->hrr = p;
			inc->ant = celRef;
			celRef->hrr = inc;
			/* celRef->ant não precisa mudar pois aponta para o primeiro elem após a ref, considerando-se o sentido anti-horário*/
		}
		else		/* Caso pos inserção menor que ou igual ao tamanho da Lista Circular */	
		{	for (i=1 ; i < pos - 1 ; i++ )
			{	p = p->ant;
			}	/* p aponta para a posição do elemento imediatmente anteriror à posição onde se quer inserir, considerando-se o sentido anti-horário */
			aux = p->ant;
			p->ant = inc;
			inc->ant = aux;
			inc->hrr = p;
			aux->hrr = inc;
		}
		lcirc->celApontada = inc;
	}
	printf("\nO candidato %s, numero: %d, partido: %s foi inserido com sucesso na Eleicao Circular!", cand.nome, cand.numero, cand.partido);
	lcirc->tamanho++;
	printf("\nTamanho atual da Lista Circular: %d candidatos !", lcirc->tamanho);
	return;
}

void aponte_prox_horaria (listaCirc *lcirc)
{	CelulaDE *p = lcirc->celApontada;
	p=p->hrr;
	lcirc->celApontada = p;
	printf("\n\nO candidato %s, numero: %d, partido: %s, eh agora o candidato apontado!", p->candidato.nome, p->candidato.numero, p->candidato.partido);
	return;
}
	
void aponte_prox_anti_horaria (listaCirc *lcirc)
{	CelulaDE* p = lcirc->celApontada;
	p=p->ant;
	lcirc->celApontada = p;
	printf("\n\nO candidato %s, numero: %d, partido: %s, eh agora o candidato apontado!", p->candidato.nome, p->candidato.numero, p->candidato.partido);
	return;
}

void remover (listaCirc *lcirc, int pos, int sentido)
{	CelulaDE *phrr, *pant, *p = lcirc->celApontada;
	if (lcirc->tamanho > 0)
	{	int i;
		for (i=1; i < pos; i++)
		{	p = p->hrr;
		}
		phrr = p->hrr;
		pant = p->ant;
		phrr->ant = pant;
		pant->hrr = phrr;
		printf("\n\nO candidato %s, numero: %d, partido: %s, foi removido com sucesso da Eleicao Circular!", p->candidato.nome, p->candidato.numero, p->candidato.partido);
		lcirc->tamanho--;
		if (sentido ==  1) aponte_prox_horaria (lcirc);
		if (sentido == -1) aponte_prox_anti_horaria (lcirc);
			printf("\nTamanho atual da Lista Circular: %d candidatos !", lcirc->tamanho);
			free(p);
	}
	else
		printf ("\n\nA Lista Circular esta vazia! Impossivel remover!");
	return;
}

void imprimir(listaCirc *lcirc)
{	CelulaDE *p = lcirc->celApontada;
	float dist, graus;
	int i;
	int tam = lcirc->tamanho;
	dist = 360 / tam;
	printf("\n\n<<< Listagem Geral dos Candidatos na Eleicao Circular >>>");
	for (i=0; i < tam ; i++)
	{	graus = 360 - (i * dist);
		if (graus==360) graus = 0;
		printf("\n\nPosicao relativa ao Candidato atualmente apontado: %3.1f graus\nObs.: cresce no sentido anti-horario.", graus);
		printf("\nCandidato: %s", p->candidato.nome);
		printf("\nnumero: %d", p->candidato.numero);
		printf("\npartido: %s", p->candidato.partido);
		p = p->hrr;
	}
	printf("\nTamanho: %d candidatos estao atualmente na Eleicao Circular\n\n", i);
}

void josephus_total (listaCirc *lcirc, int m, int sentido)
{	CelulaDE *p = NULL;
	int n = lcirc->tamanho;
	int i;
	for(i=1 ; i < n ; i++)
	{	remover (lcirc, m, sentido);
		if (sentido == 1) aponte_prox_horaria (lcirc);
	}
	p = lcirc->celApontada;
	printf("\n\nO candidato %s, numero: %d, partido: %s, foi o VENCEDOR da eleicao JOSEPHUS!\n\n", p->candidato.nome, p->candidato.numero, p->candidato.partido);
}

void josephus_um_por_um (listaCirc *lcirc, int m, int sentido)
{	CelulaDE *p = NULL;
	remover (lcirc, m, sentido);
	p = lcirc->celApontada;
	if (sentido == 1) aponte_prox_horaria (lcirc);
	/*if (sentido == -1) aponte_prox_anti_horaria (lcirc)*/
	if ( lcirc->tamanho == 1 )
		printf("\n\nO candidato %s, numero: %d, partido: %s, foi o VENCEDOR da eleicao JOSEPHUS!\n\n", p->candidato.nome, p->candidato.numero, p->candidato.partido);
	else	printf("\n\nAinda há candidatos para excluir!!!");
}


int main()
{	listaCirc *eleicao;
	eleicao = criar_listaCirc();

	Candidato leo = {"leonardo Neves", 3377, "PFIL"};
	Candidato xan = {"Alexandre Samael", 1771, "PMUSC"};
	Candidato ste = {"Stephanie Figueiredo", 2112, "PMOR"};
	Candidato lil = {"Valquiria Lilith", 9999, "PMAMB"};
	Candidato rau = {"Raul Seixas Cao", 1269, "PCAO"};
	Candidato ecl = {"Eclipse Gato", 5555, "PGATO"};
	
	insecao_horaria (eleicao, leo, 1);
	insecao_horaria (eleicao, xan, 3);
	insecao_horaria (eleicao, ste, 4);
	insecao_horaria (eleicao, lil, 5);
	insecao_horaria (eleicao, rau, 6);
	insecao_horaria (eleicao, ecl, 10);

	imprimir(eleicao);
	josephus_total (eleicao, 4, -1);

	return(777);
}
