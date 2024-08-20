#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree.h"

int  compareInt (void* num1, void* num2);
void printBST   (void* num1);

int main(int argc, char *argv[]) {
	//	Local Definitions 
	BST_TREE* BSTRoot;
	int*      dataPtr;
	int       dataIn = +1;
	
//	Statements 
	printf("Begin BST Demonstation\n");

	BSTRoot = BST_Create (compareInt);

//	Build Tree 
	printf("Enter a list of positive integers;\n");
	printf("Enter a negative number to stop.\n");

	do 
	   {
	    printf("Enter a number: ");
	    scanf ("%d", &dataIn);
	    if (dataIn > -1)
	       {
	        dataPtr = (int*) malloc (sizeof (int));
	        if (!dataPtr)
	            {
	             printf("Memory Overflow in add\n"), 
	             exit(100);
	            } // if overflow 
	        *dataPtr = dataIn;
	        BST_Insert (BSTRoot, dataPtr);
	       } // valid data 
	   } while (dataIn > -1);

	printf("\nBST contains:\n");
	BST_Traverse (BSTRoot, printBST);
	
	do 
	{
		printf("Informe o numero a ser procurado: ");
		scanf("%d", &dataIn);
		if(dataIn >= -1)
		{
			if(BST_Retrieve(BSTRoot, &dataIn) != NULL) printf("O elemento com esse valor foi encontrado!\n\n");
			else printf("Nao existe nenhum elemento com esse valor!\n\n");
		}
	} while(dataIn >= -1);
	
	
	

	printf("\nEnd BST Demonstration\n");
	BST_Destroy(BSTRoot);
	return 0;
}

int compareInt (void* num1, void* num2)
{
//	Local Definitions 
	int key1;
	int key2;

//	Statements 
	key1 = *(int*)num1;
	key2 = *(int*)num2;
	if (key1 < key2)
	    return -1;
	if (key1 == key2)
	    return 0;
	return +1;
}	// compareInt 


/*	====================== printBST ======================  
	Print one integer from BST.
	    Pre  num1 is a pointer to an intger
	    Post integer printed and line advanced
*/
void printBST (void* num1)
{
//	Statements 
	printf("%4d\n", *(int*)num1);
	return;
}	// printBST 
