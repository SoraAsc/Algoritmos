#ifndef TAD_PONTO_H_INCLUDED
#define TAD_PONTO_H_INCLUDED

typedef struct ponto Ponto;
// Cria um novo ponto
Ponto* Ponto_cria(float x, float y, float z);
// Libera um ponto
void Ponto_libera (Ponto* p);
//Acessa os valores de "x" e "y" de um ponto
int Ponto_acessa(Ponto* p, float* x, float* y, float * z);
//Atribui os valores "x" e "y" a um ponto
int Ponto_atribui(Ponto* p, float x, float y, float z);
// Calcula a distÂncia entre dois pontos
float Ponto_distancia(Ponto* p1, Ponto* p2);

#endif // TAD_PONTO_H_INCLUDED
