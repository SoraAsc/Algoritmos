#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TAD_Pilha_Generica1iii.h"

char* getSymbolName(char c)
{
	switch(c)
	{
		case '(':
		case ')':
			return "Parênteses";
		case '[':
		case ']':
			return "Colchetes";
		case '{':
		case '}':
			return "Chaves";	
		default: return "Não Identificado";
	}
}

int main (void)
{
	setlocale(LC_ALL,"Portuguese");
//	Local Definitions
	Stack* stack;
	char   token;
	char*  dataPtr;
	char   fileID[25];
	FILE*  fpIn;
	int    lineCount = 1;

//	Statements
	// Cria a Pilha
	stack = CreateStack();
	//printf ("Enter file ID for file to be parsed: ");
	//scanf  ("%s", fileID);
	
	//fpIn = fopen ("close-miss.txt", "r");
	fpIn = fopen ("teste.txt", "r");

	//fpIn = fopen ("no-errors.txt", "r");
	//fpIn = fopen ("open-miss.txt", "r");

	if (!fpIn) printf("Error opening %s\n", fileID), exit(100);

	// Lê os characteres do arquivo fonte e os analisa, enquanto não encontrar o fim do arquivo.
	while ((token = fgetc (fpIn)) != EOF )
	{
	    if (token == '\n') lineCount++;
	    if (token == '(' || token == '{' || token == '[')
	    {
	    	//Adiciona os símbolos correspondentes na pilha.
	    	dataPtr = (char*) malloc (sizeof (char));
	        *dataPtr = token;
	        //printf("%c - %d\n",*dataPtr, lineCount);
	        PushStack(stack, dataPtr);
	    } // if
	    else
	    {
	    	if(token == ')' || token == '}' || token == ']')
	    	{
	    		char openToken;
	    		if(PeekStack(stack) != NULL) openToken = *((char *) PeekStack(stack));
	    		if (EmptyStack(stack))
	            {
	            	printf("Erro na linha %d: não foi encontrado um %s de abertura", lineCount, getSymbolName(token));
	                return 1;
	            }
	    		else if (PeekStack(stack) != NULL && 
					( (token == ')' && openToken == '(') || (token == '}' && openToken == '{') || (token == ']' && openToken == '[') ))
	    		{
	    			PopStack(stack);
				}
	            else
	            {
	            	printf("Erro na linha %d: o (%s) não pode fechar com o (%s)", lineCount, getSymbolName(openToken), getSymbolName(token));
	                return 1;
				}
			}	
	    } // else
	} // while

	if (!EmptyStack(stack))
	{
		printf("Erro na linha %d: não foi encontrado nenhum simbolo de fechamento correspondente", lineCount);
	    return 1;
	} // if

	// Destroi a Pilha
	DestroyStack(stack);
	//Se chegou até aqui deu tudo certo.
	printf ("Verificação concluida com sucesso: Houve um total de %d linhas verificadas.\n", lineCount-1);
	return 0;
}	// main

