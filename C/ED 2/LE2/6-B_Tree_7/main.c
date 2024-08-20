//#include <stdio.h>
//#include <stdlib.h>
//#include "B_Tree.h"
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(int argc, char *argv[]) {
//	return 0;
//}

/*	This program tests B-Trees Trees as implemented in Gilberg & Forouzan

	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "B_Tree.h"

/*  Prototype Functions  */
void insert       (BTREE *tree);
void delete       (BTREE *tree);
void search       (BTREE *tree);
void testUtilties (BTREE *tree);

char   doMenu (void);

int    compare (void *newDataPtr, void *rootDataPtr);

void   process (void *dataPtr);
	
int main ( void )
{
/*  Local Declarations */
char      option;

BTREE* tree;

/*  Statements  */
	printf(	"Start B-Tree\n" );
	
	tree = BTree_Create (compare);
	if (!tree)
	   printf("\aERROR: Cannot create tree\a\n"), exit (100);

	while ( (option = doMenu () ) != 'q' )
	    {
	     switch ( option )
	        {
	         case 'i' :  insert (tree);
	                     break;
	         case 'd' :  delete (tree);
	                     break;
	         case 'p' :  BTree_Print (tree);
	                     break;
	         case 's' :  search (tree);
	                     break;
	         case 't' :  printf("\nBegin Traversal\n");
	                     BTree_Traverse (tree, process);
	                     printf("\nEnd Traversal\n");
	                     break;
	         case 'x' :  testUtilties (tree);
	                     break;
	         case 'z' :  BTree_Destroy (tree);
	                     printf("Destroy selected\n");
	                     printf("\nEnd of B-Tree Test\n");
	                     exit (0);
	                     break;
	         case '!' :  /* Create test tree */
	                     {
	                     	int dataAry[] ={100, 200, 300, 400, 500, 600, 700, 800,
	                     	                900, 111, 222, 333, 444, 555, 666, 777,
	                     	                888, 999, 11};
	                     	int *newPtr;
							int i;
	                     	for (i = 0; i < 19; i++)
	                     	   {
	                     	    newPtr = (int *) malloc (sizeof(int));
	                     	    if (!newPtr )
	                     	    printf( "\aERROR: Cannot allocate data.\n" ), exit (101);
	 
	                     	    *newPtr = dataAry[i];
	                     	    BTree_Insert (tree, newPtr);
	                     	   } /* for */
	                     } /* create initial tree */
	                     break;
	
	         default  :  printf( "\a\a\nInvalid option. Please try again.\n" );
			} /* switch */
		} /* while */
	
	printf( "End B-Tree\n" );
	return 0;	
}	/* main */
/* ============================= doMenu ============================= */
/*	This function prints a menu and reads the user selection.
	   Pre	Nothing.
	   Post option returned.
*/
char	doMenu ( void ) 
{
 /* Local Declarations */
 char	option;
 
 /* Statements */
 	printf( "\n=============== Menu ===============\n" );
 	printf( " i: Insert       | t: Traverse      \n" );
 	printf( " d: Delete       | x: Test utilities\n" );
 	printf( " p: Print        | z: Destroy & Quit\n" );
 	printf( " s: Search       | q: Quit          \n" );
 	printf( "====================================\n" );
 	printf( "Please enter your choice:  " );
 		 
 	scanf( " %c", &option );
 	option = tolower ( option );
 	
 	return option;
} /* doMenu */


/* ============================= search ============================= */
/*	This function locates a node in the tree.
	Pre	 B-Tree exists.
	Post Node retrieved and printed.
*/
void search (BTREE *tree)
{
/*	Local Declarations */
	int key;
	
	int *addr;

/*	Statements */
	printf("Please enter key to be found: ");
	scanf ("%d", &key);
	
	addr = (int *)BTree_Search (tree, &key);
	if (addr)
	    printf("\nKey found. Contains %d\n", *addr);
	else
	    printf("\n\aKey %d not found\n", key);
	
	return;
}	/* search */

/* ============================= insert ============================= */
/*	This function gets input from the user and passes it to the BTree insert
 	function.
	Pre	 B-Tree exists.
	Post Node has been inserted.
*/
void insert (BTREE *tree) 
{
/*  Prototype Statements */
 
/*  Local Declarations */
int *newPtr;

/*  Statements */
newPtr = (int *) malloc (sizeof(int));
if (!newPtr )
    printf( "\aERROR: Cannot allocate data.\n" ), exit (101);
 
printf("\nPlease enter interger to be inserted: ");
scanf ("%d", newPtr);

BTree_Insert (tree, newPtr);
printf("%3d inserted\n", *newPtr);
   
return;
} /* insert */

/* ============================= delete ============================= */
/*	This function deletes a node from the tree. It asks the user for the
	key of the node to be deleted and then removes it from the tree.
	Pre	 Tree must be initialized. Null tree is OK.
	Post The node is deleted and its space recylced
		-or- An error message is printed.
*/
void delete ( BTREE *tree ) 
{
 /* Prototype Statements */
 	 
 /* Local Declarations */
 	int	 dltKey;
 	int  success;
 	int *dltDataPtr;
 	 
 /* Statements */
 printf( "\nPlease enter integer to be deleted: " );
 scanf(  "%d", &dltKey );
 
 dltDataPtr = BTree_Search(tree, &dltKey);
 if (dltDataPtr)
    {
     success = BTree_Delete (tree, &dltKey);
     if (success)
        {
         printf("%3d deleted\n", dltKey);
/*         free (dltDataPtr); */
        } /* if success */
     else
        {
         printf("\aIMPOSSIBLE ERROR 200 in delete.\a\n");
         exit (200);
        } /* not success */
    } /* if found */
else
    printf("\aData %d not found.\a\n", dltKey);
 return;
}/* delete */

/*	=================== compare ================== */
/*	This function compares two integers identified
	by pointers to integers.
	Pre		arguPtr and listPtr are pointers to integers
	Return	-1: arguPtr value <  listPtr value
			-0: arguPtr value == listPtr value
			+1: arguPtr value > listPtr value
*/
int compare (void *arguPtr, void *listPtr)
{
/*	Local Declarations */
	int arguValue;
	int listValue;
	
/*	Statements */
	arguValue = *(int *)arguPtr;
	listValue = *(int *)listPtr;
	
	if (arguValue < listValue)
		return -1;
	else if (arguValue == listValue)
		return 0;
	else
		return +1;
}	/* compare */

/*	=================== process ================== */
/*	This function "processes" a node by printing 
	the node data.
	   Pre    dataPtr is pointer to user data structure
	   Post   Data (integer) printed
*/
void process (void *dataPtr)
{
/*	Statements */
	printf("Data: %5d @ %p\n", *(int *)dataPtr, dataPtr);
	return;
}	/* process */

/*	=================== testUtilties ================== 
	This function tests the ADT utilities by calling
	each in turn and printing their results.
	Pre     tree has been created.
	Post	Results printed.
*/
void testUtilties (BTREE *tree)
{
	printf("Tree contains %3d nodes: \n", BTree_Count(tree));
	if (BTree_Empty(tree))
	    printf("The tree IS empty\n");
	else
	    printf("The tree IS NOT empty\n");
	if (BTree_Full(tree))
	    printf("The tree IS full\a\n");
	else
	    printf("The tree IS NOT full\n");
	return;
}	/* testUtilities */
/*	====================== End of Program ====================== */
