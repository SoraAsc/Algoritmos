#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkListADT.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	void* coeficiente;
	unsigned int expoente;
} POLINOMIO;

int linesNum = 0;

LIST** buildList(void);
int cmpExpoente(void* pPoly1, void* pPoly2);

int main(int argc, char *argv[]) {
	
	LIST** poly1;
	int addResult, i;
	poly1 = buildList();
		
	for(i = 0; i < linesNum; i++)
	{
		destroyList(poly1[i]);
	}
	
	free(poly1);
	return 0;
}

LIST** buildList(void)
{
	FILE *file;
	LIST** list;
	POLINOMIO* pPoly;
	void * coeficiente;
	unsigned int expoente;
	int addResult, i;
	char line[150], cLine;
	
	file = fopen("poli.txt", "r");
	if(!file)
	{
		printf("Erro ao abrir o arquivo");
		exit(100);
	}
	
	while((cLine = fgetc(file)) != EOF) if(cLine == '\n') linesNum++;
	
	
	list = (LIST**) malloc(linesNum * sizeof(LIST*));
	for(i = 0; i < linesNum; i++)
	{
		list[i] = createList(cmpExpoente);
	}	

	i = 0;
	fseek(file,0, SEEK_SET);
	while(fgets(line, sizeof(line), file) != NULL)
	{
		char* c;
		char *rest = line;
		while((c = strtok_r(rest, " ", &rest)))
		{
			pPoly = (POLINOMIO*) malloc(sizeof(POLINOMIO));
			if(!pPoly)
			{
				printf("\nMemoria insuficiente\n");
				exit(130);
			}
			sscanf(c, "%d^%ld", &coeficiente, &expoente);
			pPoly->coeficiente = (int *) coeficiente;
			pPoly->expoente = expoente;
			addResult = addNode(list[i], pPoly);
			if (addResult != 0)
	        {
	        	if (addResult == -1)
	            	printf("Memoria insuficiente\a\n"),exit (140);
	        	else
	            	printf("Polinomio Duplicado nao adicionado.\n\a");		
			}
			//printf("Coeficiente: %d, Expoente: %ld\n", coeficiente, expoente);
		}
		i++;
	}
	fclose(file);
	return list;
}

int cmpExpoente(void* pPoly1, void* pPoly2)
{
	int result;
	unsigned int expoente1,expoente2;
	
	expoente1 = ((POLINOMIO*)pPoly1)->expoente;
	expoente2 = ((POLINOMIO*)pPoly2)->expoente;
	
	if(expoente1 > expoente2)
		result = +1;
	else if(expoente1 < expoente2)
		result = -1;
	else result = 0;
	
	return result;
}
