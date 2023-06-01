#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "TAD_Fila3iii.h"

//	Prototype Statements
int getIndexOfLetter(char word);
char getLetterOfIndex(int number);

// Foi considerado apenas as letras do alfabeto brasileiro, pois h� muitos outros, devido a isso inclui a �ltima posi��o com
// caracteres especiais, pontua��o e letras que n�o pertencem ao alfabeto americano.
int main (int argc, char *argv[])
{
//	Local Definitions
	FILE *file;
	Queue** lettersCategory;
	char c, antC = ' ';
	char*  dataPtr;
	bool isNewWord = true;
	int numLetters = 27, i;
	
	
	lettersCategory = (Queue**) malloc(numLetters * sizeof(Queue*));
	
	for(i = 0; i < numLetters; i++)
	{
		lettersCategory[i] = Create_Queue();
	}	
		
	file = fopen("teste.txt","r");
	if(file == NULL)
	{
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}
	
	while((c = fgetc(file)) != EOF)
	{
		// Se a ultima palavra da linha n�o conter '-', significa que a palavra ainda n�o terminou e continua na pr�xima linha.
		// Fora isso o comportamento padr�o �, se encontrou espa�o ou fim da linha � uma nova palavra.
		if( !(c=='\n' && antC == '-') && (c == ' ' || c == '\n'))
			isNewWord = true;
		else if(isNewWord)
		{
			isNewWord = false;
			dataPtr = (char*) malloc (sizeof (char));
			*dataPtr = c;
			Enqueue(lettersCategory[getIndexOfLetter(c)], dataPtr);
		}
		antC = c;
	}
	
	
	fclose(file);

	printf("\n================================ TABELA QUANTIDADE LETRAS ================================\n");
	for(i = 0; i < numLetters; i++)
	{
		if(i%3 == 0) printf("\n");
		printf("(%c - %d) |", getLetterOfIndex(i), Size_Queue(lettersCategory[i]));
	}
	
	for(i = 0; i < numLetters; i++)
	{
		Destroy_Queue(lettersCategory[i]);
	}

	return 0;
}	// main

int getIndexOfLetter(char letter)
{
	int index = towlower(letter) - 'a';
	return index > -1 && index < 26 ? index : 26;
}

char getLetterOfIndex(int number)
{
	char letter = 'a' + number;
	return number > -1 && number < 26 ? letter : '+';
}


