#include "B_Tree.h"
//	=============== CONSTANTS & MACROS ============== 
#define ORDER 5
const int MIN_ENTRIES = (((ORDER + 1) / 2) - 1);


// ================== STRUCTURES ================== 
struct entry
{
	void*        dataPtr;
	struct node* rightPtr;
};

struct node
{
	struct node* firstPtr;
	int          numEntries;
	ENTRY        entries[ORDER - 1];
};
	
struct btree
{
    int count; 
    NODE* root; 
    int  (*compare) (void* argu1, void* argu2); 
};
   
   
BTREE* BTree_Create (int (*compare) (void* argu1, void* argu2)) {
    BTREE* tree = (BTREE*) malloc(sizeof(BTREE));
    if (tree == NULL) {
        return NULL; // falha na alocação de memória
    }

    // inicializa a B-Tree
    tree->root = NULL;
    tree->compare = compare;

    return tree;
}

void BTree_Print (BTREE* tree) {
    _printNode(tree->root, 0);
}

void _printNode (NODE* node, int level) {
	int i, j;
    if (node == NULL) {
        return;
    }

    for (i = 0; i < node->numEntries; i++) {
        _printNode(node->entries[i].rightPtr, level + 1);

        for (j = 0; j < level; j++) {
            printf("  ");
        }

        printf("%d\n", *(int*)node->entries[i].dataPtr);
    }

    _printNode(node->firstPtr, level + 1);
}


int BTree_Count(BTREE* tree)
{
	return tree->count;
}

bool BTree_Empty (BTREE* tree) {
    return (tree->root == NULL);
}

BTREE* BTree_Destroy (BTREE* tree) {
    if (tree == NULL) {
        return tree;
    }

    _destroy(tree->root);
    free(tree);
    tree = NULL;

    return tree;
}

bool BTree_Full (BTREE* tree) {
    NODE* newNode;
    newNode = (NODE*) malloc(sizeof(NODE));
    if (newNode) {
        free(newNode);
        return false; // A B-Tree não está cheia
    }
    return true;
}


void _destroy (NODE* root) {
	int i;
    if (root == NULL) {
        return;
    }

    for (i = 0; i < root->numEntries; i++) {
        _destroy(root->entries[i].rightPtr);
    }

    free(root);
}


/*	================== BTree_Search ==================
	Search the tree for the node containing
	requested key and returns pointer to its data.
	   Pre    tree has been created (may be null)
	          targetPtr is pointer to data structure
	               containing key to be located
	   Post   tree searched and data pointer returned
	   Return pointer to data
*/
void* BTree_Search (BTREE* tree, void* targetPtr)
{
//	Statements 
	if (tree->root)
	    return _search 
	             (tree, targetPtr, tree->root);
	else
	    return NULL;
}	// BTree_Search 


/*	================ BTree_Traverse ================
	Process tree using inorder traversal. 
	   Pre  Tree has been created (may be null)
	        tree is pointer to B-Tree 
	        process used to "visit" nodes in traversal
	   Post Entries processed in LNR sequence
*/
void BTree_Traverse (BTREE* tree,
                     void (*process) (void* dataPtr))
{
//	Statements 
	if (tree->root)
	    _traverse (tree->root, process);
	return;
}  // end BTree_Traverse 


/* 	================== BTree_Insert ==================
	This function inserts new data into the tree.
	   Pre  tree is pointer to valid B-Tree structure 
	   Post data inserted or abort if memory O/F 
*/
void BTree_Insert (BTREE* tree, void* dataInPtr)
{
//	Local Definitions 
	bool  taller;
	NODE* newPtr;
	ENTRY upEntry;
	int i;
	
//	Statements 
	if (tree->root == NULL)
	    // Empty Tree. Insert first node 
	    if (newPtr = (NODE*)malloc(sizeof (NODE)))
	       {
	        newPtr->firstPtr            = NULL;
	        newPtr->numEntries          = 1;
	        newPtr->entries[0].dataPtr  = dataInPtr;
	        newPtr->entries[0].rightPtr = NULL;
	        tree->root                  = newPtr;
	        (tree->count)++;
	        
	        for (i = 1; i < ORDER - 1; i++)
	            {
	             newPtr->entries[i].dataPtr  = NULL;
	             newPtr->entries[i].rightPtr = NULL;
	            } // for *
	        return;
	       } // if malloc
	    else
	       printf("Overflow error 100 in BTree_Insert\a\n"), 
	               exit (100);
	   
	taller = _insert (tree,       tree->root, 
	                  dataInPtr, &upEntry);
	if (taller)
	   {
	    // Tree has grown. Create new root 
	    newPtr = (NODE*)malloc(sizeof(NODE));
	    if (newPtr)
	       {
	        newPtr->entries[0]    = upEntry;
	        newPtr->firstPtr      = tree->root;
	        newPtr->numEntries    = 1;
	        tree->root            = newPtr;
	       } // if newPtr
	    else
	       printf("Overflow error 101\a\n"), 
	               exit (100);
	   } // if taller 

	(tree->count)++;
	return;
}  // BTree_Insert 


/* ================= BTree_Delete ==================== 
	Delete entry with key target from B-Tree
	   Pre    tree must be initialized. Null tree OK
	          dltKey is pointer to key to be deleted
	   Post   Node entry deleted & data space freed 
	          -or- An error code is returned 
	   Return Success (true) or Not found (false)
*/
bool BTree_Delete (BTREE* tree, void* dltKey)
{
//	Local Definitions 
	bool  success;
	NODE* dltPtr;

//	Statements 
	if (!tree->root)
	    return false;
	
	_delete (tree, 
	         tree->root, 
	         dltKey, 
	        &success);
	    
	if (success)
	   {
	    (tree->count)--;
	    if (tree->root->numEntries == 0)
	       {
	        dltPtr     = tree->root;
	        tree->root = tree->root->firstPtr;
	        free (dltPtr);
	       } // root empty 
	   } // success 
	return success;
}  // BTree_Delete 


/*	================= _search ================= 
	Search tree for node containing requested
	key and returns its data to the calling function.
	   Pre    BTree_Search passes tree, targetPtr, root
	          targetPtr is pointer to data structure 
	             containing key to be located 
	   Post   Tree searched and data pointer returned 
	   Return Address of matching node returned. 
	          If not found, NULL returned.
*/
void* _search (BTREE* tree, void* targetPtr,
               NODE*  root)
{
//	Local Definitions 
	int   entryNo;
	
// Statements 
	if (!root)
	   return NULL;
	
	if (tree->compare(targetPtr, 
	                  root->entries[0].dataPtr) < 0)
	    return _search (tree, 
	                    targetPtr,
	                    root->firstPtr);

	entryNo = root->numEntries - 1;
	while (tree->compare(targetPtr, 
	                  root->entries[entryNo].dataPtr) < 0)
	   entryNo--;
	if (tree->compare(targetPtr, 
	                  root->entries[entryNo].dataPtr) == 0)
	    return (root->entries[entryNo].dataPtr);
	
	return (_search (tree,
	     targetPtr, root->entries[entryNo].rightPtr));
}	// _search 


/*	=================== _traverse ===================
	Traverse tree using inorder traversal. To "process" 
	node, using function passed when traversal called
	   Pre  tree validated in BTree_Traversal 
	        root is pointer to B-Tree node 
	        process is function to process an entry 
	   Post All nodes processed 
*/
 void _traverse (NODE* root, 
                  void (*process) (void* dataPtr))
{
//	Local Definitions 
	int   scanCount;
	NODE* ptr;
	
//	Statements 
	
	scanCount = 0;
	ptr = root->firstPtr;
	
	while (scanCount <= root->numEntries)
	  {
	   // Test for subtree 
	   if (ptr)
	       _traverse  (ptr, process);
	
	   // Subtree processed -- get next entry 
	   if (scanCount < root->numEntries)
	      {
	       process  (root->entries[scanCount].dataPtr);
	       ptr     = root->entries[scanCount].rightPtr;
	      } // if scanCount 
	   scanCount++;
	  } // if 
	return;
}  // _traverse 



/*	==================== _insert ===================
	This function uses recursion to insert the new data  
	into a leaf node in the B-Tree.
	   Pre    Application has called BTree_Insert,   
	             which passes root and data pointers
	   Post   Data have been inserted
	   Return taller boolean
*/
bool _insert (BTREE* tree,      NODE*  root,
              void*  dataInPtr, ENTRY* upEntry)
{
//	Local Declarations 
	int  compResult;
	int  entryNdx;
	bool taller;
	
	NODE* subtreePtr;
	
//	Statements 
	if (!root)
	   {
	    // Leaf found -- build new entry 
	    (*upEntry).dataPtr  = dataInPtr;
	    (*upEntry).rightPtr = NULL;
	    return true;                   // tree taller 
	   } // if NULL tree 
	
	entryNdx   = _searchNode (tree, root, dataInPtr);
	compResult = tree->compare(dataInPtr, 
	                  root->entries[entryNdx].dataPtr);
	if (entryNdx <= 0 && compResult < 0)
	    // in node's first subtree 
	    subtreePtr = root->firstPtr;
	else
	    // in entry's right subtree 
	    subtreePtr = root->entries[entryNdx].rightPtr;
	taller = _insert (tree,      subtreePtr, 
	                  dataInPtr, upEntry);

	// Entry inserted -- back out of tree 
	if (taller)
	   {
	    if (root->numEntries >= ORDER - 1)
	       {
	        // Need to create new node 
	        _splitNode (root,       entryNdx, 
	                    compResult, upEntry);
	        taller = true;
	       } // node full 
	    else
	       {
	        if (compResult >= 0)
	           // New data >= current entry -- insert after
	            _insertEntry(root, entryNdx + 1, *upEntry);
	        else
	           // Insert before current entry 
	            _insertEntry(root, entryNdx, *upEntry);
	        (root->numEntries)++;
	        taller = false;
	       } // else 
	   } // if taller 
	   
	return taller;
}	// _insert 




void _splitNode (NODE* node, int entryNdx, int compResult, ENTRY* upEntry)
{
	// Local Definitions
	int fromNdx;
	int toNdx;
	NODE* rightPtr;
	// Statements
	rightPtr = (NODE*)malloc(sizeof (NODE));
	if (!rightPtr)
		printf("Overflow Error 101 in _splitNode\a\n"), exit (100);
	// Build right subtree node
	if (entryNdx < MIN_ENTRIES)
		fromNdx = MIN_ENTRIES;
	else
		fromNdx = MIN_ENTRIES + 1;
	toNdx = 0;
	rightPtr->numEntries = node->numEntries - fromNdx;
	while (fromNdx < node->numEntries)
		rightPtr->entries[toNdx++] = node->entries[fromNdx++];
	node->numEntries = node->numEntries - rightPtr->numEntries;
	// Insert new entry
	if (entryNdx < MIN_ENTRIES)
	{
		if (compResult < 0)
			_insertEntry (node, entryNdx, *upEntry);
		else
		_insertEntry (node, entryNdx + 1, *upEntry);
	} // if
	else
	{
		_insertEntry (rightPtr, entryNdx - MIN_ENTRIES, *upEntry);
		(rightPtr->numEntries)++;
		(node->numEntries)--;
	} // else
	upEntry->dataPtr=node->entries[MIN_ENTRIES].dataPtr;
	upEntry->rightPtr = rightPtr;
	rightPtr->firstPtr = node->entries[MIN_ENTRIES].rightPtr;
	return;
	
} // _splitNode

void _insertEntry (NODE* root, int entryNdx, ENTRY upEntry) {
	int i;
    for (i = root->numEntries; i > entryNdx; i--) {
        root->entries[i] = root->entries[i - 1];
    }
    root->entries[entryNdx] = upEntry;
}

static int _searchNode (BTREE* tree, NODE* nodePtr, void* target) {
    int entryNdx;
    int result;

    if (nodePtr == NULL)
        return -1;

    entryNdx = 0;
    while (entryNdx < nodePtr->numEntries) {
        result = tree->compare(target, nodePtr->entries[entryNdx].dataPtr);
        if (result == 0)
            return entryNdx;
        else if (result < 0)
            break;
        entryNdx++;
    }
    return entryNdx;
}

/*	==================== _delete ==================== 
	Delete entry with key dltKey from B-Tree 
	   Pre    tree must be initialized--Null tree OK 
	          root is pointer to tree or subtree
	          dltKey is key of entry to be deleted
	          success indicates entry deleted or failed
	   Post   node is deleted and its space recycled
	          -or- if key not found, tree is unchanged.
	          success is true / false
	   Return underflow true / false 
*/
bool _delete (BTREE* tree,        NODE* root, 
              void*  dltKeyPtr,   bool* success)
{
// Local Definitions 
	NODE* leftPtr;
	NODE* subTreePtr;
	int   entryNdx;
	int   underflow;

//	Statements 
	if (!root)
	   {
	    *success = false;
	    return     false;
	   } // null tree 

	entryNdx  = _searchNode (tree, root, dltKeyPtr);
	if (tree->compare(dltKeyPtr, 
	    root->entries[entryNdx].dataPtr) == 0)
	    {
	     // found entry to be deleted 
	     *success = true;
	     if (root->entries[entryNdx].rightPtr == NULL)
	         // entry is a leaf node 
	         underflow = _deleteEntry (root, entryNdx);
	     else
	         // entry is in an internal node 
	         {
	          if (entryNdx > 0)
	             leftPtr = 
	                root->entries[entryNdx - 1].rightPtr;
	          else
	             leftPtr = root->firstPtr;
	          underflow = _deleteMid 
	               (root, entryNdx, leftPtr);
	          if (underflow)
	             underflow = _reFlow (root, entryNdx);
	         } // else internal node 
	    } // else found entry 
	else
	    {
	     if (tree->compare (dltKeyPtr, 
	            root->entries[0].dataPtr) < 0)
	         // delete key < first entry 
	         subTreePtr = root->firstPtr;
	     else
	         // delete key in right subtree 
	         subTreePtr = root->entries[entryNdx].rightPtr;
	         
	     underflow = _delete (tree,      subTreePtr, 
	                          dltKeyPtr, success);   
	     if (underflow)
	         underflow = _reFlow (root, entryNdx);
	    } // else not found *

	return underflow;
}	// _delete 


static bool _deleteEntry (NODE* node, int entryNdx) {
	int i;
    for (i = entryNdx; i < node->numEntries - 1; i++) {
        node->entries[i] = node->entries[i + 1];
    }
    node->numEntries--;
    return true;
}


/*	=================== _deleteMid =================== 
	Deletes entry from internal node in B-Tree 
	   Pre    Tree initialized--null tree OK 
	          node points to node data to be deleted 
	          subtreePtr is pointer to root's subtree 
	          entryNdx is entry to be deleted 
	   Post   predecessor's data replaces delete data
	          predecessor deleted from tree
	   Return underflow true / false 
*/
bool _deleteMid   (NODE* root,
                   int   entryNdx, 
                   NODE* subtreePtr)
{
//	Local Definitions 
	int  dltNdx;
	int  rightNdx;
	bool underflow;
	
//	Statements 
	if (subtreePtr->firstPtr == NULL)
	    {
	    // leaf located. Exchange data & delete leaf 
	     dltNdx = subtreePtr->numEntries - 1;
	     root->entries[entryNdx].dataPtr =
	           subtreePtr->entries[dltNdx].dataPtr;
	     --subtreePtr->numEntries;
	     underflow  = subtreePtr->numEntries < MIN_ENTRIES;
	    } // if leaf 
	else
	   {
	    // Not located. Traverse right for predecessor 
	    rightNdx  = subtreePtr->numEntries - 1;
	    underflow = _deleteMid (root, entryNdx,
	           subtreePtr->entries[rightNdx].rightPtr);
	    if (underflow)
	       underflow = _reFlow (subtreePtr, rightNdx);
	   } // else traverse right 
	return underflow;
}	// _deleteMid 



/*	===================== _reFlow ===================== 
	An underflow has occurred in a subtree to root. 
	Correct by balancing or concatenating. 
	   Pre    root is pointer to underflow tree/subtree
	          entryNdx is parent of underflow subtree
	   Post   Underflow corrected
	   Return underflow true / false 
*/
bool _reFlow  (NODE* root, int entryNdx)
{
//	Local Definitions 
	NODE* leftTreePtr;
	NODE* rightTreePtr;
	bool  underflow;
	
//	Statements 
	if (entryNdx == 0)
	   leftTreePtr = root->firstPtr;
	else
	   leftTreePtr = root->entries[entryNdx - 1].rightPtr;
	rightTreePtr   = root->entries[entryNdx].rightPtr;

	// Try to borrow first 
	if (rightTreePtr->numEntries > MIN_ENTRIES)
	       {
	        _borrowRight (root,        entryNdx, 
	                      leftTreePtr, rightTreePtr);
	        underflow   = false;
	       } // if borrow right 
	else
	   {
	    // Can't borrow from right--try left 
	    if (leftTreePtr->numEntries > MIN_ENTRIES)
	       {
	        _borrowLeft (root,        entryNdx,
	                     leftTreePtr, rightTreePtr);
	        underflow  = false;
	       } // if borrow left *
	   else
	       {
	        // Can't borrow. Must combine nodes. 
	       _combine (root,        entryNdx, 
	                 leftTreePtr, rightTreePtr);
	        underflow = (root->numEntries < MIN_ENTRIES);
	       } // else combine 
	   } // else borrow right 
	return underflow;
}	// _reFlow 



static void _borrowLeft (NODE* root, int entryNdx, NODE* leftTree, NODE* rightTree) {
	int i;
    for (i = rightTree->numEntries; i > 0; i--) {
        rightTree->entries[i] = rightTree->entries[i - 1];
    }
    rightTree->entries[0] = root->entries[entryNdx];
    root->entries[entryNdx] = leftTree->entries[leftTree->numEntries - 1];
    rightTree->numEntries++;
    leftTree->numEntries--;
}



/*	================= _borrowRight ================ 
	Root left subtree underflow. Borrow from right 
	and rotate. 
	   Pre    root is parent node to underflow node
	          entryNdx is parent entry
	          leftTreePtr is underflowed subtree 
	          rightTreePtr is subtree w/ extra entry
	   Post   Underflow corrected
*/
void _borrowRight (NODE* root,
                   int   entryNdx, 
                   NODE* leftTreePtr, 
                   NODE* rightTreePtr)
{
//	Local Definitions 
	int toNdx;
	int shifter;

//	Statements 
	// Move parent and subtree pointer to left tree 
	toNdx = leftTreePtr->numEntries;
	leftTreePtr->entries[toNdx].dataPtr
	      = root->entries[entryNdx].dataPtr;
	leftTreePtr->entries[toNdx].rightPtr 
	      = rightTreePtr->firstPtr;
	++leftTreePtr->numEntries;
	
	// Move right data to parent 
	root->entries[entryNdx].dataPtr
	      = rightTreePtr->entries[0].dataPtr;
	
	// Set right tree first pointer. Shift entries left 
	rightTreePtr->firstPtr 
	      = rightTreePtr->entries[0].rightPtr;
	shifter = 0;
	while (shifter < rightTreePtr->numEntries - 1)
	   {
	    rightTreePtr->entries[shifter] 
	          = rightTreePtr->entries[shifter + 1];
	    ++shifter;
	   } // while 
	--rightTreePtr->numEntries;
	return;
}	// _borrowRight 



/*	==================== _combine ==================== 
	Underflow cannot be corrected by borrowing. 
	Combine two subtrees.
	   Pre  root contains parent to underflow node
	        entryNdx is parent entry
	        leftTreePtr & rightTreePtr are subtree ptrs
	   Post Parent & subtrees combined-right node freed
*/
void _combine (NODE* root,        int   entryNdx, 
               NODE* leftTreePtr, NODE* rightTreePtr)
{
//	Local Definitions 
	int toNdx;
	int fromNdx;
	int shifter;
	
//	Statements 
	// Move parent & set its right pointer from right tree 
	toNdx = leftTreePtr->numEntries;
	leftTreePtr->entries[toNdx].dataPtr 
	        = root->entries[entryNdx].dataPtr;
	leftTreePtr->entries[toNdx].rightPtr 
	        = rightTreePtr->firstPtr;
	++leftTreePtr->numEntries;
	--root->numEntries;
	
	// move data from right tree to left tree 
	fromNdx = 0;
	toNdx++;
	while (fromNdx < rightTreePtr->numEntries)
	    leftTreePtr->entries[toNdx++] 
	         = rightTreePtr->entries[fromNdx++];
	leftTreePtr->numEntries += rightTreePtr->numEntries;
	free (rightTreePtr);
	
	// Now shift data in root to the left 
	shifter = entryNdx;
	while (shifter < root->numEntries)
	   {
	    root->entries[shifter] = 
	          root->entries[shifter + 1];
	    shifter++;
	   } // while 
	return;
}	// _combine 
