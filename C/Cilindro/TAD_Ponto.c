#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_Ponto.h"

struct ponto { // Definição do tipo de dados
   float x;
   float y;
   float z;
};

// Cria um novo ponto
Ponto* Ponto_cria(float x, float y, float z){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p !=NULL){
       p->x = x;
       p->y = x;
       p->z = z;
    }
    return p;
};

// Libera um ponto
void Ponto_libera (Ponto* p){
     free(p);
};
//Acessa os valores de "x" e "y" de um ponto
int Ponto_acessa(Ponto* p, float* x, float* y, float* z){
    if (p == NULL)
       return 0;
    *x = p->x;
    *y = p->y;
    *z = p->z;
    return 1;
};

//Atribui os valores "x" e "y" a um ponto
int Ponto_atribui(Ponto* p, float x, float y, float z){
   if (p == NULL)
      return 0;
   p->x = x;
   p->y = x;
   p->z = z;
   return 1;
};

// Calcula a distÂncia entre dois pontos
float Ponto_distancia(Ponto* p1, Ponto* p2){
    if (p1 == NULL || p2 == NULL)
       return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    float dz = p1->z - p2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
};
