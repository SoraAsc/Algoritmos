
#include "AVL_Search_Tree.h"
#define LH +1                          // Left High 
#define EH  0                          // Even High 
#define RH -1                          // Right High 


struct node
{
	void*        dataPtr;
	struct node* left;
	int          bal;
	struct node* right;
};

struct avl_tree
{
	int    count;
	int   (*compare) (void* argu1, void* argu2);
	NODE*   root;
};


/*	================= AVL_Create ================
	Allocates dynamic memory for an AVL tree head
	node and returns its address to caller
	   Pre    compare is address of compare function 
	          used when two nodes need to be compared 
	   Post   head allocated or error returned 
	   Return head node pointer; null if overflow 
*/
AVL_TREE* AVL_Create 
        (int  (*compare) (void* argu1, void* argu2))
{
//	Local Definitions 
	AVL_TREE* tree;

//	Statements 
	tree = (AVL_TREE*) malloc (sizeof (AVL_TREE));
	if (tree)
	   {
	    tree->root  = NULL;
	    tree->count   = 0;
	    tree->compare = compare;
	   } // if 

	return tree;
}	// AVL_Create 


/*	================= AVL_Insert ===================
	This function inserts new data into the tree.
	   Pre    tree is pointer to AVL tree structure
	   Post   data inserted or memory overflow 
	   Return Success (true) or Overflow (false)
*/
bool AVL_Insert (AVL_TREE* tree, void* dataInPtr)
{
//	Local Definitions 
	NODE* newPtr;
	bool  forTaller;

//	Statements 
	newPtr = (NODE*)malloc(sizeof(NODE));
	if (!newPtr)
	   return false;

	newPtr->bal     = EH;
	newPtr->right   = NULL;
	newPtr->left    = NULL;
	newPtr->dataPtr = dataInPtr;
   
	tree->root = _insert(tree,  tree->root, 
	              newPtr,      &forTaller);
	(tree->count)++;
	return true;
}  // AVL_Insert 


/* ====================== AVL_Delete ====================== 
	This function deletes a node from the tree and 
	rebalances it if necessary. 
	   Pre    tree initialized--null tree is OK
	          dltKey is pointer to key to be deleted 
	   Post   node deleted and its space recycled 
	          -or- An error code is returned 
	   Return Success (true) or Not found (false)
*/
bool AVL_Delete (AVL_TREE* tree, void* dltKey)
{
//	Local Definitions 
	bool  shorter;
	bool  success;
	NODE* newRoot;

//	Statements 
newRoot = _delete (tree,    tree->root, dltKey, 
                  &shorter, &success);
if (success)
   {
    tree->root = newRoot;
    (tree->count)--;
    return true;
   } // if 
else
   return false;
}  // AVL_Delete 


/*	==================== AVL_Retrieve ===================  
	Retrieve node searches the tree for the node containing 
	the requested key and returns pointer to its data.
	   Pre     Tree has been created (may be null) 
	           data is pointer to data structure 
	                containing key to be located 
	   Post    Tree searched and data pointer returned 
	   Return  Address of matching node returned 
	           If not found, NULL returned 
*/
void* AVL_Retrieve  (AVL_TREE* tree, void* keyPtr)
{
//	Statements 
	if (tree->root)
	    return _retrieve (tree, keyPtr, tree->root);
	else
	    return NULL;
}	// AVL_Retrieve 


/*	==================== AVL_Traverse ==================== 
	Process tree using inorder traversal. 
	   Pre   Tree has been created (may be null) 
	         process "visits" nodes during traversal 
	   Post  Nodes processed in LNR (inorder) sequence 
*/
void AVL_Traverse (AVL_TREE* tree,
                   void (*process) (void* dataPtr))
{
//	Statements 
	_traversal (tree->root, process);
	return;
}  // end AVL_Traverse 

/*	=================== AVL_Empty ==================
	Returns true if tree is empty; false if any data.
	   Pre      Tree has been created. May be null 
	   Returns  True if tree empty, false if any data 
*/
bool AVL_Empty (AVL_TREE* tree)
{
//	Statements 
	return (tree->count == 0);
}	// AVL_Empty 


/*	=============== AVL_Full ============== 
	If there is no room for another node, returns true.
	Pre      Tree has been created 
	Returns  True if no room for another insert,
	         false if room.
*/
bool AVL_Full (AVL_TREE* tree)
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
}	// AVL_Full 


/*	=============== AVL_Count ==============
	Returns number of nodes in tree.
	   Pre     Tree has been created 
	   Returns tree count 
*/
int AVL_Count (AVL_TREE* tree)
{
//	Statements 
	return (tree->count);
}	// AVL_Count 



/*	=============== AVL_Destroy ============== 
	Deletes all data in tree and recycles memory.
	The nodes are deleted by calling a recursive
	function to traverse the tree in inorder sequence.
	   Pre      tree is a pointer to a valid tree 
	   Post     All data and head structure deleted 
	   Return   null head pointer
*/
AVL_TREE* AVL_Destroy (AVL_TREE* tree) 
{
//	Statements 
	if (tree)
		_destroy (tree->root);
		
	// All nodes deleted. Free structure 
	free (tree);
	return NULL;
}	// AVL_Destroy 


/*	================== _destroy ================= 
	Deletes all data in tree and recycles memory.
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

/*	=================== _traversal =================== 
	Inorder tree traversal. To process a node, we use 
	the function passed when traversal was called.
	   Pre   Tree has been created (may be null) 
	   Post  All nodes processed 
*/
void _traversal (NODE* root, 
                 void (*process) (void* dataPtr))
{
//	Statements 
if  (root)
    {
     _traversal  (root->left, process);
     process     (root->dataPtr);
     _traversal  (root->right, process);
    } // if 
return;
}  // _traversal 


/*	==================== _insert ====================
	This function uses recursion to insert the new data 
	into a leaf node in the AVL tree.
	Pre    Application has called AVL_Insert, which passes 
	       root and data pointers.
	Post   Data have been inserted.
	Return pointer to [potentially] new root.
*/
NODE* _insert (AVL_TREE* tree,   NODE* root, 
               NODE*     newPtr, bool* taller)
{
//	Statements 
	if (!root)
	   {
	    // Insert at root 
	    root     = newPtr;
	    *taller  = true;
	    return   root;
	   } // if NULL tree 
 
	if (tree->compare(newPtr->dataPtr, 
	                  root->dataPtr) < 0)
	   {
	    // newData < root -- go left 
	    root->left = _insert(tree,   root->left, 
	                         newPtr, taller);
	    if (*taller)
	       // Left subtree is taller 
	       switch (root->bal)
	          {
	           case LH:  // Was left high--rotate 
	                   root = insLeftBal (root, taller);
	                   break;

	           case EH:  // Was balanced--now LH 
	                   root->bal = LH;
	                   break;

	           case RH:  // Was right high--now EH 
	                   root->bal = EH;
	                   *taller   = false;
	                   break;
	          } // switch 
	       return root; 
	   } // new < node 
	else 
	    // new data >= root data 
	    {
	     root->right = _insert (tree,   root->right, 
	                            newPtr, taller);
	     if (*taller)
	        // Right subtree is taller 
	        switch (root->bal)
	            {
	             case LH:  // Was left high--now EH 
	                       root->bal = EH;
	                       *taller   = false;
	                       break;
	             
	             case EH:  // Was balanced--now RH 
	                       root->bal = RH;
	                       break;
	
	             case RH:  // Was right high--rotate 
	                       root = insRightBal
	                                  (root, taller);
	                       break;
	            } // switch 
	     return root;
	     } // else new data >= root data 
	return root;
}	// _insert 



/* ===================== insLeftBal ===================== 
	Tree out-of-balance to the left. This function 
	rotates the tree to the right.
	   Pre  The tree is left high 
	   Post Balance restored; returns potentially new root
*/
NODE* insLeftBal (NODE* root, bool* taller) 
{
//	Local Definitions 
	NODE* rightTree;
	NODE* leftTree;

//	Statements 
	leftTree = root->left;
	switch (leftTree->bal)
	   {
	    case LH: // Left High--Rotate Right 
	             root->bal     = EH;
	             leftTree->bal = EH;
	             
	             // Rotate Right 
	             root     = rotateRight (root);
	             *taller  = false;
	             break;
	    case EH: // This is an error 
	             printf ("\n\aError in insLeftBal\n");
	             exit (100); 
	    case RH: // Right High-Requires double 
	             // rotation: first left, then right 
	             rightTree = leftTree->right;
	             switch (rightTree->bal)
	                {
	                 case LH: root->bal     = RH;
	                          leftTree->bal = EH;
	                          break;
	                 case EH: root->bal     = EH;
	                          leftTree->bal = EH;
	                          break;
	                 case RH: root->bal     = EH;
	                          leftTree->bal = LH;
	                          break;
	                } // switch rightTree 
	             
	             rightTree->bal = EH;
	             // Rotate Left 
	             root->left = rotateLeft (leftTree);
	             
	             // Rotate Right 
	             root     = rotateRight (root);
	             *taller  = false;
	   } // switch 
	return root;
}	// insLeftBal 


/* ===================== insRightBal ===================== 
	Tree out-of-balance to the right. This function 
	rotates the tree to the left.
	   Pre  The tree is left high 
	   Post Balance restored; returns potentially new root
*/
NODE* insRightBal (NODE* root, bool* taller) 
{
//	Local Definitions 
	NODE* rightTree;
	NODE* leftTree;

//	Statements 
	rightTree = root->right;
	switch (rightTree->bal)
	   {
	    case RH: // Right High--Rotate Left 
	             root->bal     = EH;
	             rightTree->bal = EH;
	             
	             // Rotate Right 
	             root     = rotateLeft(root);
	             *taller  = false;
	             break;
	    case EH: // This is an error 
	             printf ("\n\aError in insRightBal\n");
	             exit (100); 
	    case LH: // Left High-Requires double 
	             // rotation: first right, then left 
	             leftTree = rightTree->left;
	             switch (leftTree->bal)
	                {
	                 case RH: root->bal     = LH;
	                          rightTree->bal = EH;
	                          break;
	                 case EH: root->bal     = EH;
	                          rightTree->bal = EH;
	                          break;
	                 case LH: root->bal     = EH;
	                          rightTree->bal = RH;
	                          break;
	                } // switch rightTree 
	             
	             rightTree->bal = EH;
	             // Rotate Left 
	             root->right = rotateRight(rightTree);
	             
	             // Rotate Left 
	             root     = rotateLeft(root);
	             *taller  = false;
	   } // switch 
	return root;
}	// insLeftBal 



/* ===================== rotateLeft ====================== 
	Exchanges pointers to rotate the tree to the left.
	   Pre  root points to tree to be rotated 
	   Post Node rotated and new root returned 
*/
NODE* rotateLeft (NODE* root) 
{
//	Local Definitions 
	NODE* tempPtr;

//	Statements 
	tempPtr        = root->right;
	root->right    = tempPtr->left;
	tempPtr->left  = root;

	return tempPtr;
}	// rotateLeft 

/* ================== rotateRight ================== 
	Exchange pointers to rotate the tree to the right. 
	   Pre  root points to tree to be rotated 
	   Post Node rotated and new root returned 
*/
NODE* rotateRight (NODE* root) 
{
//	Local Definitions 
	NODE* tempPtr;

//	Statements 
	tempPtr         = root->left;
	root->left      = tempPtr->right;
	tempPtr->right  = root;

	return tempPtr;
}	// rotateRight 




/*	==================== _delete ==================== 
	Deletes node from the tree and rebalances 
	tree if necessary. 
	   Pre    tree initialized--null tree is OK.
	          dltKey contains key of node to be deleted
	          shorter indicates tree is shorter
	   Post   node is deleted and its space recycled
	          -or- if key not found, tree is unchanged 
	   Return true if deleted; false if not found
	          pointer to root
*/

NODE* _delete (AVL_TREE* tree,   NODE* root, 
               void*     dltKey, bool* shorter,
               bool*     success)
{
// Local Definitions 
	NODE* dltPtr;
	NODE* exchPtr;
	NODE* newRoot;

//	Statements 
	if (!root)
	   {
	    *shorter = false;
	    *success = false;
	    return NULL;
	   } // if 
	
	if (tree->compare(dltKey, root->dataPtr) < 0)
	    {
	     root->left = _delete (tree,   
	                           root->left, dltKey, 
	                           shorter,    success);
	     if (*shorter)
	         root   = dltRightBal (root, shorter);
	    } // if less 
	else if (tree->compare(dltKey, root->dataPtr) > 0)
	    {
	     root->right = _delete (tree,    
	                            root->right, dltKey,
	                            shorter,     success);
	     if (*shorter)
	         root = dltLeftBal (root, shorter);
	    } // if greater 
	else
	    // Found equal node 
	    {
	     dltPtr = root;
	     if (!root->right)
	         // Only left subtree 
	         {
	          newRoot  = root->left;
	          *success = true;
	          *shorter = true;
	          free (dltPtr);
	          return newRoot;              // base case 
	         } // if true 
	     else
	         if (!root->left)
	             // Only right subtree 
	             {
	              newRoot  = root->right;
	              *success = true;
	              *shorter = true;
	              free (dltPtr);
	              return newRoot;         // base case
	            } // if 
	         else
	             // Delete Node has two subtrees 
	             {
	              exchPtr = root->left;
	              while (exchPtr->right)
	                  exchPtr = exchPtr->right;
	              root->dataPtr = exchPtr->dataPtr;
	              root->left = _delete (tree,  
	                    root->left, exchPtr->dataPtr,
	                    shorter,    success);
	              if (*shorter)
	                  root = dltRightBal (root, shorter); 
	             } // else 
	    } // equal node 
	return root; 
}	// _delete 



/*	=================== dltLeftBal ==================  
	The tree is shorter after a delete on the right. This 
	function adjusts the balance factors and rotates the tree 
	to the right if necessary.
	   Pre     tree shorter 
	   Post    Balance factors reset-balance restored 
	   Returns potentially new root 
*/
NODE* dltLeftBal (NODE* root, bool* shorter)
{
//	Local Definitions 
	NODE* rightTree;
	NODE* leftTree;
	
//	Statements 
	switch (root->bal)
	    {
	     case RH:       // Deleted Right--Now balanced 
	          root->bal  = EH;
	          break;
	          
	     case EH:       // Now Left high 
	          root->bal  = LH;
	          *shorter   = false;
	          break;
	          
	     case LH:       // Left High - Rotate Right
	          leftTree = root->left;
	          if (leftTree->bal == RH)
	              // Double rotation required 
	              {
	               rightTree  = leftTree->right;
	               
	               switch (rightTree->bal)
	                   {
	                    case RH: leftTree->bal = LH;
	                             root->bal      = EH;
	                             break;
	                    case EH: root->bal      = EH;
	                             leftTree->bal = EH;
	                             break;
	                    case LH: root->bal      = RH;
	                             leftTree->bal = EH;
	                             break;
	                   } // switch 
	                   
	               rightTree->bal = EH;
	               
	               // Rotate Right then Left 
	               root->left = rotateLeft(leftTree);
	               root = rotateRight(root);
	              } // if leftTree->bal == RH 
	          else
	              {
	               // Single Rotation Only 
	               switch (leftTree->bal)
	                   {
	                    case RH:
	                    case LH: root->bal      = EH;
	                             leftTree->bal = EH;
	                             break;
	                    case EH: root->bal      = LH;
	                             leftTree->bal = RH;
	                             *shorter       = false;
	                             break;
	                   } // switch leftTree->bal 
	               root = rotateRight(root);
	              } // else 
	    } // switch 
	return root;
}	// dltLeftBal 


/*	=================== dltRightBal ==================  
	The tree is shorter after a delete on the left. This 
	function adjusts the balance factors and rotates the tree 
	to the left if necessary.
	   Pre     tree shorter 
	   Post    Balance factors reset-balance restored 
	   Returns potentially new root 
*/
NODE* dltRightBal (NODE* root, bool* shorter)
{
//	Local Definitions 
	NODE* rightTree;
	NODE* leftTree;
	
//	Statements 
	switch (root->bal)
	    {
	     case LH:       // Deleted Left--Now balanced 
	          root->bal  = EH;
	          break;
	          
	     case EH:       // Now Right high 
	          root->bal  = RH;
	          *shorter   = false;
	          break;
	          
	     case RH:       // Right High - Rotate Left
	          rightTree = root->right;
	          if (rightTree->bal == LH)
	              // Double rotation required 
	              {
	               leftTree  = rightTree->left;
	               
	               switch (leftTree->bal)
	                   {
	                    case LH: rightTree->bal = RH;
	                             root->bal      = EH;
	                             break;
	                    case EH: root->bal      = EH;
	                             rightTree->bal = EH;
	                             break;
	                    case RH: root->bal      = LH;
	                             rightTree->bal = EH;
	                             break;
	                   } // switch 
	                   
	               leftTree->bal = EH;
	               
	               // Rotate Right then Left 
	               root->right = 
	                      rotateRight (rightTree);
	               root = rotateLeft  (root);
	              } // if rightTree->bal == LH 
	          else
	              {
	               // Single Rotation Only 
	               switch (rightTree->bal)
	                   {
	                    case LH:
	                    case RH: root->bal      = EH;
	                             rightTree->bal = EH;
	                             break;
	                    case EH: root->bal      = RH;
	                             rightTree->bal = LH;
	                             *shorter       = false;
	                             break;
	                   } // switch rightTree->bal 
	               root = rotateLeft (root);
	              } // else 
	    } // switch 
	return root;
}	// dltRightBal 




/*	===================== _retrieve ===================== 
	Searches tree for node containing requested key 
	and returns its data to the calling function.
	   Pre     AVL_Retrieve passes tree, keyPtr, root 
	           keyPtr is pointer to data structure 
	              containing key to be located 
	   Post    tree searched; data pointer returned 
	   Return  Address of matching node returned 
	            If not found, NULL returned 
*/
void*  _retrieve (AVL_TREE* tree, 
	               void*     keyPtr, NODE* root)
{
//	Statements 
	if (root)
	    {
	     if (tree->compare(keyPtr, root->dataPtr) < 0)
	         return _retrieve(tree, keyPtr, root->left);
	     else if (tree->compare(keyPtr, root->dataPtr) > 0)
	         return _retrieve(tree, keyPtr, root->right);
	     else
	         // Found equal key 
	         return root->dataPtr;
	    }  // if root 
	else
	    // Data not in tree 
	    return NULL;
}	// _retrieve 
