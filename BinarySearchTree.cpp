#include <iostream>
#include <string>

typedef struct BSTree* BSTptr;
typedef struct BSTree BSTNode;

struct BSTree{
	int element;
	int height;
	BSTptr leftChild;
	BSTptr rightChild;
};

class BinarySearchTree{
	BSTNode rootNode;
	BSTptr root = &rootNode;
public:
	int initTree(){
		//init the tree, the root node
		root->leftChild = NULL;
		root->rightChild = NULL;
		root->height = -1;
		root->element = -1;
		return 1;
	}

	int insertNode(int elementX){
		//insert node to the tree
	}

	int deleteNode(int elementX){
		//delete some node in the tree
	}

	int searchNode(int elementX){
		//search a node in the tree
	}

	int printTree(BSTptr node){
		//print the tree, whose root is node
	}
};