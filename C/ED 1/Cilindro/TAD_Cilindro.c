#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TAD_Cilindro.h"

struct cilindro
{
	float x;
	float y;
	float raio;
	float altura;
	Ponto* ponto;
};

Cilindro* Cilindro_cria(Ponto* p, float raio, float altura)
{
	Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
	if(c != NULL)
	{
		//c->x = x;
		//c->y = y;
		c->ponto = p;
		c->raio = abs(raio);
		c->altura = abs(altura);
	}
	return c;
};

int Cilindro_altera(Cilindro *c, Ponto* p, float raio, float altura)
{
	if(c == NULL) return 0;
	//c->x = x;
	//c->y = y;
	c->ponto = p;
	c->raio = abs(raio);
	c->altura = abs(altura);
	return 1;
}

double Cilindro_area(Cilindro * c)
{
	if(c == NULL) return -1;
	return 2*M_PI*c->raio*c->altura + 2*M_PI*pow(c->raio, 2);
}

double Cilindro_volume(Cilindro * c)
{
	if(c == NULL) return -1;
	return M_PI*pow(c->raio, 2)*c->altura;
}

void Cilindro_libera(Cilindro* c)
{
	free(c);
};
