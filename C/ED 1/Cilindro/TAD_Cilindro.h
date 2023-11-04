#include "TAD_Ponto.h"

typedef struct cilindro Cilindro;
//Cria um novo Cilindro
Cilindro* Cilindro_cria(Ponto* p, float raio, float altura);
//Altera os valores do Cilindro
int Cilindro_altera(Cilindro *c, Ponto* p, float raio, float altura);
//Calcula a �rea do Cilindro
double Cilindro_area(Cilindro *c);
//Calcula o volume do Cilindro
double Cilindro_volume(Cilindro * c);
//Libera o Cilindro da mem�ria.
void Cilindro_libera(Cilindro* c);
