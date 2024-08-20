#include "AVL_Tree.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
	void*        dataPtr;
	struct node* left;
	struct node* right;
};

struct bst_tree
{
	int   count;
	int  (*compare) (void* argu1, void* argu2);
	NODE*  root;
};


/*	================= BST_Create ================
	Allocates dynamic memory for an BST tree head
	node and returns its address to caller
	   Pre    compare is address of compare function 
	          used when two nodes need to be compared 
	   Post   head allocated or error returned 
	   Return head node pointer; null if overflow 
*/
BST_TREE* BST_Create 
        (int  (*compare) (void* argu1, void* argu2))
{
//	Local Definitions 
	BST_TREE* tree;

//	Statements 
	tree = (BST_TREE*) malloc (sizeof (BST_TREE));
	if (tree)
	   {
	    tree->root    = NULL;
	    tree->count   = 0;
	    tree->compare = compare;
	   } // if 

	return tree;
}	// BST_Create 


/*	================= BST_Insert ===================
	This function inserts new data into the tree.
	   Pre    tree is pointer to BST tree structure
	   Post   data inserted or memory overflow 
	   Return Success (true) or Overflow (false)
*/
bool BST_Insert (BST_TREE* tree, void* dataPtr)
{
//	Local Definitions 
	NODE* newPtr;

//	Statements 
	newPtr = (NODE*)malloc(sizeof(NODE));
	if (!newPtr)
	   return false;

	newPtr->right   = NULL;
	newPtr->left    = NULL;
	newPtr->dataPtr = dataPtr;
   
	if (tree->count == 0)
	    tree->root  =  newPtr;
	else
	    _insert(tree, tree->root, newPtr);
	    
	(tree->count)++;
	return true;
}  // BST_Insert 


/* ================== BST_Delete ================== 
	This function deletes a node from the tree and 
	rebalances it if necessary. 
	   Pre    tree initialized--null tree is OK
	          dltKey is pointer to data structure 
	                 containing key to be deleted 
	   Post   node deleted and its space recycled 
	          -or- An error code is returned 
	   Return Success (true) or Not found (false)
*/
bool BST_Delete (BST_TREE* tree, void* dltKey)
{
//	Local Definitions 
	bool  success;
	NODE* newRoot;
	
//	Statements 
	newRoot = _delete (tree, tree->root, dltKey, &success);
	if (success)
	   {
	    tree->root = newRoot;
	    (tree->count)--;
	    if (tree->count == 0)
	        // Tree now empty 
	        tree->root = NULL;
	   } // if 
	return success;
}  // BST_Delete


/*	==================== BST_Retrieve ===================  
	Retrieve node searches tree for the node containing 
	the requested key and returns pointer to its data.
	   Pre     Tree has been created (may be null) 
	           data is pointer to data structure 
	                containing key to be located 
	   Post    Tree searched and data pointer returned 
	   Return  Address of matching node returned 
	           If not found, NULL returned 
*/
void* BST_Retrieve  (BST_TREE* tree, void* keyPtr)
{
//	Statements 
	if (tree->root)
	    return _retrieve (tree, keyPtr, tree->root);
	else
	    return NULL;
}	// BST_Retrieve 


/*	=================== BST_Traverse =================== 
	Process tree using inorder traversal. 
	   Pre   Tree has been created (may be null) 
	         process ÒvisitsÓ nodes during traversal 
	   Post  Nodes processed in LNR (inorder) sequence 
*/
void BST_Traverse (BST_TREE* tree, 
                   void (*process) (void* dataPtr)) 
{
//	Statements 
	_traverse (tree->root, process);
	return;
}  // end BST_Traverse 


/*	=================== BST_Empty ==================
	Returns true if tree is empty; false if any data.
	   Pre      Tree has been created. (May be null) 
	   Returns  True if tree empty, false if any data 
*/
bool BST_Empty (BST_TREE* tree)
{
//	Statements 
	return (tree->count == 0);
}	// BST_Empty 


/*	===================== BST_Full ==================== 
	If there is no room for another node, returns true.
	   Pre      tree has been created 
	   Returns  true if no room for another insert
	            false if room
*/
bool BST_Full (BST_TREE* tree)
{
//	Local Definitions 
	NODE* newPtr;
	
//	Statements 
	newPtr = (NODE*)malloc(sizeof (*(tree->root)));
	if (newPtr)
	   {
	    free (newPtr);
	    return false;
	   } // if 
	else
	     return true;
}	// BST_Full 


/*	=================== BST_Count ==================
	Returns number of nodes in tree.
	   Pre     tree has been created 
	   Returns tree count 
*/
int BST_Count (BST_TREE* tree)
{
//	Statements 
	return (tree->count);
}	// BST_Count 


/*	=============== BST_Destroy ============== 
	Deletes all data in tree and recycles memory.
	The nodes are deleted by calling a recursive
	function to traverse the tree in inorder sequence.
	   Pre      tree is a pointer to a valid tree 
	   Post     All data and head structure deleted 
	   Return   null head pointer
*/
BST_TREE* BST_Destroy (BST_TREE* tree) 
{
//	Statements 
	if (tree)
		_destroy (tree->root);
		
	// All nodes deleted. Free structure 
	free (tree);
	return NULL;
}	// BST_Destroy 




/*	==================== _insert ====================
	This function uses recursion to insert the new data 
	into a leaf node in the BST tree.
	   Pre    Application has called BST_Insert, which  
	          passes root and data pointer
	   Post   Data have been inserted
	   Return pointer to [potentially] new root
*/
NODE* _insert (BST_TREE* tree, NODE* root, NODE* newPtr)
{
//	Statements 
	if (!root)
	   // if NULL tree 
	   return newPtr;
 
	// Locate null subtree for insertion 
	if (tree->compare(newPtr->dataPtr, 
	                  root->dataPtr) < 0)
	   {
	    root->left = _insert(tree, root->left, newPtr);
	    return root; 
	   } // new < node 
	else 
	   // new data >= root data 
	   {
	    root->right = _insert(tree, root->right, newPtr);
	    return root;
	     } // else new data >= root data 
	return root;
}	// _insert 



/*	==================== _delete ==================== 
	Deletes node from the tree and rebalances 
	tree if necessary. 
	   Pre    tree initialized--null tree is OK.
	          dataPtr contains key of node to be deleted
	   Post   node is deleted and its space recycled
	          -or- if key not found, tree is unchanged 
	   Return success is true if deleted; false if not found
	          pointer to root
*/
NODE*  _delete (BST_TREE* tree,    NODE* root, 
                void*     dataPtr, bool* success)
{
// Local Definitions 
	NODE* dltPtr;
	NODE* exchPtr;
	NODE* newRoot;
	void* holdPtr;

//	Statements 
	if (!root)
	   {
	    *success = false;
	    return NULL;
	   } // if 
	
	if (tree->compare(dataPtr, root->dataPtr) < 0)
	     root->left  = _delete (tree,    root->left, 
	                            dataPtr, success);
	else if (tree->compare(dataPtr, root->dataPtr) > 0)
	     root->right = _delete (tree,    root->right, 
	                            dataPtr, success);
	else
	    // Delete node found--test for leaf node 
	    {
	     dltPtr = root;
	     if (!root->left)
	         // No left subtree 
	         {
	          free (root->dataPtr);       // data memory
	          newRoot = root->right;
	          free (dltPtr);              // BST Node
	          *success = true;
	          return newRoot;             // base case 
	         } // if true 
	     else
	         if (!root->right)
	             // Only left subtree 
	             {
	              newRoot = root->left;
	              free (dltPtr);
	              *success = true;
	              return newRoot;         // base case 
	            } // if 
	         else
	             // Delete Node has two subtrees 
	             {
	              exchPtr = root->left;
	              // Find largest node on left subtree
	              while (exchPtr->right)
	                  exchPtr = exchPtr->right;

	              // Exchange Data 
	              holdPtr          = root->dataPtr;
	              root->dataPtr    = exchPtr->dataPtr;
	              exchPtr->dataPtr = holdPtr;
	              root->left       = 
	                 _delete (tree,   root->left, 
	                          exchPtr->dataPtr, success);
	             } // else 
	    } // node found 
	return root; 
}	// _delete 


/*	===================== _retrieve ===================== 
	Searches tree for node containing requested key 
	and returns its data to the calling function.
	   Pre     _retrieve passes tree, dataPtr, root 
	           dataPtr is pointer to data structure 
	              containing key to be located 
	   Post    tree searched; data pointer returned 
	   Return  Address of data in matching node 
	           If not found, NULL returned 
*/
void* _retrieve (BST_TREE* tree, 
	              void* dataPtr, NODE* root)
{
//	Statements 
	if (root)
	    {
	     if (tree->compare(dataPtr, root->dataPtr) < 0)
	         return _retrieve(tree, dataPtr, root->left);
	     else if (tree->compare(dataPtr, root->dataPtr) > 0)
	         return _retrieve(tree, dataPtr, root->right);
	     else
	         // Found equal key 
	         return root->dataPtr;
	    }  // if root 
	else
	    // Data not in tree 
	    return NULL;
}	// _retrieve 


/*	=================== _traverse =================== 
	Inorder tree traversal. To process a node, we use 
	the function passed when traversal was called.
	   Pre   Tree has been created (may be null) 
	   Post  All nodes processed 
*/
void _traverse (NODE* root, 
                void (*process) (void* dataPtr)) 
{
//	Statements 
if  (root)
    {
     _traverse (root->left, process);
     process   (root->dataPtr);
     _traverse (root->right, process);
    } // if 
return;
}  // _traverse


/*	=============== _destroy ============== 
	Deletes all data in tree and recycles memory.
	It also recycles memory for the key and data nodes.
	The nodes are deleted by calling a recursive 
	function to traverse the tree in inorder sequence.
	   Pre      root is pointer to valid tree/subtree 
	   Post     All data and head structure deleted 
	   Return   null head pointer 
*/
void _destroy (NODE* root)
{
//	Statements 
	if (root)
	   {
	    _destroy (root->left);
	    free (root->dataPtr);
	    _destroy (root->right);
	    free (root);
	   } // if 
	return;
}	// _destroy
