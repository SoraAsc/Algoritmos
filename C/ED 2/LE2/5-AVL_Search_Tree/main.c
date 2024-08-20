#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "AVL_Search_Tree.h"

//	Structures 
typedef struct 
   {
    char word[51];                     // One word 
    int  count;
   } DATA;

//	Prototype Declarations 
void  buildList    (AVL_TREE*      wordList);
void  insertWord   (AVL_TREE*      words);
void  deleteWord   (AVL_TREE*      words);
void  printList    (AVL_TREE*      wordList);
void  printWord    (void* aWord);
bool  getWord      (DATA* aWord,   FILE* fpWords);
int   compareWords (void* arguPtr, void* listPtr);

int main(int argc, char *argv[]) {
	
	//	Local Definitions 
	AVL_TREE* wordList;

//	Statements 
	printf("Start count words in document\n");
	wordList = AVL_Create (compareWords);
	
	buildList (wordList);
	printList (wordList);
	   
	printf("End count words\n");
	return 0;
	return 0;
}


/*	=================== buildList ==================
	Reads file and creates AVL tree containing list 
	of all words used in the file with count of the
	number of times each word is found in the file.
	   Pre   wordList has been created
	   Post  AVL tree (list) built or error returned
*/
void buildList (AVL_TREE* wordList)
{
//	Local Definitions 
	char  fileName[25];
	FILE* fpWords;

	bool  success;
	DATA* aWord;
	DATA  newWord;
		
//	Statements 
	printf("Enter name of file to be processed: ");
	scanf ("%24s", fileName);
	
	fpWords = fopen (fileName, "r");
	if (!fpWords)
	   {
	    printf("%-s could not be opened\a\n",fileName);
	    printf("Please verify name and try again.\n");
	    exit (100);
	   } // !fpWords 

	while (getWord (&newWord, fpWords))
	   {
	    aWord = AVL_Retrieve(wordList, &(newWord));
	    if (aWord)
	       (aWord->count)++;
	    else
	       {
	        aWord = (DATA*) malloc (sizeof (DATA));
	        if (!aWord)
	           {
	            printf("Error 120 in buildList\n");
	            exit (120);
	           } // if 
	        // Add word to list 
	        *aWord       = newWord;
	        aWord->count = 1;
	        success      = AVL_Insert (wordList, aWord);
	        if (!success)
	           {
	            printf("Error 121 in buildList\a\n");
	            exit (121);
	           } // if overflow test 
	       } // else 
	   } // while 
	
	printf("End AVL Tree\n");
	return;
} // buildList 


/*	=================== getWord ==================
	Reads one word from file.
	   Pre  nothing
	   Post word read into reference parameter
*/
bool getWord (DATA* aWord, FILE* fpWords)
{
//	Local Definitions 
	char strIn[51];
	int  ioResult;
	int  lastChar;

//	Statements 
	ioResult = fscanf(fpWords, "%50s", strIn);
	if (ioResult != 1)
	    return false;
	// Copy and remove punctuation at end of word.
	strcpy (aWord->word, strIn);
	lastChar = strlen(aWord->word) - 1;
	if (ispunct(aWord->word[lastChar]))
	   aWord->word[lastChar] = '\0';
	return true;
}	// getWord 


/*	================== compareWords ================= 
	This function compares two integers identified
	by pointers to integers.
	   Pre    arguPtr and listPtr are pointers to DATA
	   Return -1: arguPtr value <  listPtr value
	          -0: arguPtr value == listPtr value
	          +1: arguPtr value >  listPtr value
*/
int compareWords (void* arguPtr, void* listPtr)
{
//	Local Declarations 
	DATA arguValue;
	DATA listValue;
	
//	Statements 
	arguValue = *(DATA*)arguPtr;
	listValue = *(DATA*)listPtr;
	
	return (strcmp(arguValue.word, listValue.word));
}	// compare 


/*	=================== printList ==================
	Prints the list with the count for each word.
	   Pre  list has been built
	   Post list printed 
*/
void printList (AVL_TREE* wordList) 
{
//	Statements 
	printf("\nWords found in list\n");
	AVL_Traverse (wordList, printWord);
	printf("\nEnd of word list\n");
	return;
}	// printList 

/*	=================== printWord ==================
	Prints one word from the list with its count.
	   Pre  ADT calls function to print data
	   Post data printed 
*/
void printWord (void* aWord)
{
//	Statements 
	printf("%-25s %3d\n", 
	      ((DATA*)aWord)->word, ((DATA*)aWord)->count);
	return;
}	// printWord 




/*	Results:
Start count words in document
Enter name of file to be processed: gtsybrg.txt
End AVL Tree

Words found in list
But                         1
Fourscore                   1
God                         1
It                          3
Now                         1
The                         2
We                          2
a                           7
above                       1
add                         1
advanced                    1
ago                         1
all                         1
altogether                  1
and                         6
any                         1
are                         3
as                          1
battlefield                 1
be                          2
before                      1
birth                       1
brave                       1
brought                     1
but                         1
by                          1
can                         2
cannot                      3
cause                       1
civil                       1
come                        1
conceived                   2
consecrate                  1
consecrated                 1
continent                   1
created                     1
dead                        3
dedicate                    2
dedicated                   4
detract                     1
devotion                    2
did                         1
died                        1
do                          1
earth                       1
endure                      1
engaged                     1
equal                       1
far                         2
fathers                     1
field                       1
final                       1
fitting                     1
for                         5
forget                      1
forth                       1
fought                      1
freedom                     1
from                        2
full                        1
gave                        2
government                  1
great                       3
ground                      1
hallow                      1
have                        5
here                        8
highly                      1
honored                     1
in                          4
increased                   1
is                          3
it                          2
larger                      1
last                        1
liberty                     1
little                      1
live                        1
lives                       1
living                      2
long                        2
measure                     1
men                         2
met                         1
might                       1
nation                      5
never                       1
new                         2
nobly                       1
nor                         1
not                         2
note                        1
of                          5
on                          2
or                          2
our                         2
people                      3
perish                      1
poor                        1
portion                     1
power                       1
proper                      1
proposition                 1
rather                      2
remaining                   1
remember                    1
resolve                     1
resting-place               1
say                         1
sense                       1
seven                       1
shall                       3
should                      1
so                          3
struggled                   1
take                        1
task                        1
testing                     1
that                       13
the                         9
their                       1
these                       2
they                        3
this                        4
those                       1
thus                        1
to                          8
under                       1
unfinished                  1
us                          3
vain                        1
war                         2
we                          8
what                        2
whether                     1
which                       2
who                         3
will                        1
work                        1
world                       1
years                       1

End of word list
End count words
*/
