/*	==================== B-Tree.h ====================
	This header file contains the functions for the AVL
	Tree abstract data type.
	   Written by:
	   Date:
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node NODE;
typedef struct entry ENTRY;
typedef struct btree BTREE;	
typedef struct btree BTREE;

//	=========== Prototype Declarations =========== 

//	User interfaces 
BTREE* BTree_Create(int  (*compare) (void* argu1, void* argu2));
void   BTree_Traverse(BTREE* tree, void (*process) (void* dataPtr));
BTREE* BTree_Destroy (BTREE* tree);
void   BTree_Insert  (BTREE* tree, void* dataInPtr);
bool   BTree_Delete  (BTREE* tree, void* dltKey);
void*  BTree_Search  (BTREE* tree, void* dataPtr);
bool   BTree_Empty   (BTREE* tree);
bool   BTree_Full    (BTREE* tree);
int    BTree_Count   (BTREE* tree);
void   BTree_Print   (BTREE* tree);

//	Internal BTree functions 
static void* _search 
                (BTREE* tree, void*  targetPtr,
                 NODE*  root);
static int   _searchNode 
                (BTREE* tree, NODE* nodePtr,
                 void*  target);
static bool  _delete 
                (BTREE* tree,      NODE* root,  
                 void*  dltKeyPtr, bool* success);
static bool _insert    
                (BTREE* tree,      NODE*  root,
                 void*  dataInPtr, ENTRY* upEntry);
static void _traverse 
                (NODE* root, 
                 void  (*process)(void* dataPtr));
static void _splitNode 
                (NODE*  root,    int    entryNdx, 
                 int compResult, ENTRY* upEntry);
static void _insertEntry 
                (NODE*  root, int entryNdx,
                 ENTRY  upEntry);
static bool _deleteEntry 
                (NODE*  node, int entryNdx);
static bool _deleteMid   
                (NODE*  root, int entryNdx,
                 NODE*  leftPtr);
static bool _reFlow      
                (NODE*  root, int entryNdx);
static void _borrowLeft  
                (NODE*  root,     int   entryNdx,
                 NODE*  leftTree, NODE* rightTree);
static void _borrowRight 
                (NODE*  root,     int   entryNdx,
                 NODE*  leftTree, NODE* rightTree);
static void _combine     
                (NODE*  root,       int   entryNdx,
                 NODE*  leftTree,   NODE* rightTree);
static void _destroy (NODE* root);

static void _printNode (NODE* node, int level);
