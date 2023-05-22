#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TAD_Cilindro.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Portuguese");
	Cilindro * c1, * c2;
	Ponto * p1, * p2;
	p1 = Ponto_cria(2, 4, 1);
	p2 = Ponto_cria(4, 6, 1);
	c1 = Cilindro_cria(p1, 2, 4);
	c2 = Cilindro_cria(p2, 8, 4);
	
	printf("\n------------------- Cilindro 1 -------------------");
	printf("\n햞ea: %.3f\nVolume: %.3f", Cilindro_area(c1), Cilindro_volume(c1));
	
	printf("\n------------------- Cilindro 2 -------------------");
	printf("\n햞ea: %.3f\nVolume: %.3f", Cilindro_area(c2), Cilindro_volume(c2));
	
	Ponto_atribui(p1, 19, 20, 6);
	Ponto_atribui(p2, 5, 144, 10);
	Cilindro_altera(c1, p1, 4, 10);
	Cilindro_altera(c2, p2, 1, 18);
	
	printf("\n------------------- Cilindro 1 -------------------");
	printf("\n햞ea: %.3f\nVolume: %.3f", Cilindro_area(c1), Cilindro_volume(c1));
	
	printf("\n------------------- Cilindro 2 -------------------");
	printf("\n햞ea: %.3f\nVolume: %.3f", Cilindro_area(c2), Cilindro_volume(c2));
	
	Cilindro_libera(c1);
	Cilindro_libera(c2);
	Ponto_libera(p1);
	Ponto_libera(p2);
	return 0;
}
