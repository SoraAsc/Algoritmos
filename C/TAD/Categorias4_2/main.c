/*	Groups numbers into four groups using four queues.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueuesADT.h"

//	Prototype Statements
int getIndexOfLetter(char word);
char getLetterOfIndex(int number);

// Foi considerado apenas as letras do alfabeto brasileiro, pois há muitos outros, devido a isso inclui a última posição com
// caracteres especiais, pontuação e letras que não pertencem ao alfabeto americano.
int main (int argc, char *argv[])
{
//	Local Definitions
	FILE *file;
	QUEUE** lettersCategory;
	char c, antC = ' ';
	char*  dataPtr;
	bool isNewWord = true;
	int numLetters = 27, i;
	
	
	lettersCategory = (QUEUE**) malloc(numLetters * sizeof(QUEUE*));
	
	for(i = 0; i < numLetters; i++)
	{
		lettersCategory[i] = createQueue();
	}	
		
	file = fopen("teste.txt","r");
	if(file == NULL)
	{
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}
	
	while((c = fgetc(file)) != EOF)
	{
		// Se a ultima palavra da linha não conter '-', significa que a palavra ainda não terminou e continua na próxima linha.
		// Fora isso o comportamento padrão é, se encontrou espaço ou fim da linha é uma nova palavra.
		if( !(c=='\n' && antC == '-') && (c == ' ' || c == '\n'))
			isNewWord = true;
		else if(isNewWord)
		{
			isNewWord = false;
			dataPtr = (char*) malloc (sizeof (char));
			*dataPtr = c;
			enqueue(lettersCategory[getIndexOfLetter(c)], dataPtr);
		}
		antC = c;
	}
	
	
	fclose(file);

	printf("\n================================ TABELA QUANTIDADE LETRAS ================================\n");
	for(i = 0; i < numLetters; i++)
	{
		if(i%3 == 0) printf("\n");
		printf("(%c - %d) |", getLetterOfIndex(i), queueCount(lettersCategory[i]));
	}
	
	for(i = 0; i < numLetters; i++)
	{
		destroyQueue(lettersCategory[i]);
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


