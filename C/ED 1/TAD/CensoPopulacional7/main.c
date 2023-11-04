/*	This program maintains and displays a list of
	Academy Awards Motion Pictures.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cType.h>
#include <stdbool.h>
#include "linkListADT.h"

/*	Data Structure for Academy Awards
	   Written by:
	   Date:
*/
//const short STR_MAX = 41;
#define STR_MAX 100

typedef struct{
	short   ano;
	char    nome_cidade[STR_MAX];
	unsigned long populacao;
} CENSO_EUA;

//	Prototype Declarations - Application Functions
	LIST* buildList  (void);
	void  printList  (LIST* list);
	int cmpPopulacao (void* pPopulacao1, void* pPopulacao2);

int main (void)
{
//	Local Definitions
	LIST* list;

//	Statements
	list = buildList();
	
	printList(list);

	destroyList(list);
	printf("Fim da Lista\n");
	return 0;
}	// main


LIST* buildList (void)
{
//	Local Definitions
	FILE* file;
	LIST* list;

	char nomeIn[100];
	unsigned long popIn;
	short  anoIn;
	int    addResult;

	CENSO_EUA* pCenso;
	char c;

//	Statements
	list = createList (cmpPopulacao);
	if (!list)
	{
		printf("\aCannot create list\n");
	    exit (100);
	}
	file = fopen("Censo.txt", "r");
	if (!file)
	{
		printf("\aError opening input file\n");
	    exit (110);
	}
	while(fscanf(file,"\"%[^\"]\"\t%hd\t%lu\n",nomeIn, &anoIn, &popIn) != EOF)
	{
		pCenso = (CENSO_EUA*) malloc(sizeof(CENSO_EUA));
	    if (!(pCenso))
	    {
	    	printf("\aOut of Memory in build list\n");
	        exit (100);
		}
		strcpy(pCenso->nome_cidade, nomeIn);
		pCenso->populacao = popIn;
		pCenso->ano = anoIn;
		
		// Insert into list
	    addResult = addNode (list, pCenso);
	    if (addResult != 0)
	        if (addResult == -1)
	            printf("Memory overflow adding movie\a\n"),
	                    exit (120);
	        else
	            printf("Duplicate population %lu not added\n\a",
	                    pCenso->populacao);		
	}
	fclose(file);

	return list;
}	// buildList

void printList(LIST* list)
{
//	Local Definitions
	CENSO_EUA* pCenso;

//	Statements

	// Get first node
	if (listCount (list) == 0)
	   printf("Sorry, nothing in list\n\a");
	else
	   {
	    printf("\nMostrando Lista\n");
	    traverse (list, 0, (void**)&pCenso);
	    do
	      {
	       printf("(%s) - (%hd) - (%lu)\n",pCenso->nome_cidade, pCenso->ano, pCenso->populacao);
	      } while (traverse (list, 1, (void**)&pCenso));
	   } // else
}	// printList

int cmpPopulacao (void* pPopulacao1, void* pPopulacao2)
{
//	Local Definitions
	int   result;
	unsigned long populacao1,populacao2;
	
	char nome1[100], nome2[100];
	
	short ano1, ano2;

//	Statements
	populacao1 = ((CENSO_EUA*)pPopulacao1)->populacao;
	populacao2 = ((CENSO_EUA*)pPopulacao2)->populacao;
	
	strcpy(nome1, ((CENSO_EUA*)pPopulacao1)->nome_cidade);
	strcpy(nome2, ((CENSO_EUA*)pPopulacao2)->nome_cidade);
	
	ano1 = ((CENSO_EUA*)pPopulacao1)->ano;
	ano2 = ((CENSO_EUA*)pPopulacao2)->ano;

	// Ignora dados duplicados.
//	if (populacao1 < populacao2)
//	    result = +1;
//	else
//	    result = -1;
	    
	// Evita cidades com o mesmo ano duplicadas.
	if(strcasecmp(nome1,nome2) == 0 && ano1 == ano2)
		result = 0;	
	else if (populacao1 < populacao2)
	    result = +1;
	else
	    result = -1;

	    
	// Evita dados duplicados.    
//	if (populacao1 < populacao2)
//	    result = +1;
//	else if (populacao1 > populacao2)
//	    result = -1;
//	else
//	    result = 0;
	return result;
}	// cmpPopulacao



