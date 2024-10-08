#include <stdbool.h>

//	Structure Declarations 
typedef struct node NODE;

typedef struct bst_tree BST_TREE;
	
//	Prototype Declarations 
	BST_TREE* BST_Create 
	         (int (*compare) (void* argu1, void* argu2));
	BST_TREE* BST_Destroy (BST_TREE* tree);

	bool  BST_Insert   (BST_TREE* tree, void* dataPtr);
	bool  BST_Delete   (BST_TREE* tree, void* dltKey);
	void* BST_Retrieve (BST_TREE* tree, void* keyPtr);
	void  BST_Traverse (BST_TREE* tree,
	                    void (*process)(void* dataPtr));

	bool BST_Empty (BST_TREE* tree);
	bool BST_Full  (BST_TREE* tree);
	int  BST_Count (BST_TREE* tree);

	static NODE* _insert
	               (BST_TREE* tree, NODE* root,
	                NODE* newPtr); 
	static NODE* _delete
	               (BST_TREE* tree,    NODE* root,
	                void*     dataPtr, bool* success);
	static void* _retrieve
	               (BST_TREE* tree,
	              void* dataPtr, NODE* root);
	static void _traverse 
	               (NODE* root,
	                void (*process) (void* dataPtr));
	static void _destroy (NODE* root);
