/*
 * BinTree Class Implementation File  @file bintree.cpp
 *
 * Class Specifications:
 * This project is to create a binary search tree class called BinTree 
 * 
 * For further specifications see README.txt
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 2 for CSS 343 
 *				i.e. Data Structures, Algorithms and Discrete Mathematics 
 * @Created on:	April 10, 2019
 * 				last Modification:	April 28, 2019
 */
 
#include "bintree.h"

//----------------------------------------------------------------------------
//----------------------------- Overload: Ostream ----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Overload: << Operator
 * @Param : 		 ostream 'output' and a BinTree object 'p'
 * @Post-condition: Returns ostream with formatted display of the BinTree object							 
*****************************************************************************/
ostream &operator<<(ostream &output, const BinTree &printTree){
	printTree.printInOrderTraversal(printTree.root);
						//sending to helper function
	output << endl;

    return output;
}

//--------------- Helper Function for << Overload Operator -------------------
/*****************************************************************************
 * Function: printInOrderTraversal
 * @Param : 		 BinTree is non-empty
 * @Post-condition:  Will print Node data in-order from the tree						 
*****************************************************************************/
void BinTree::printInOrderTraversal(Node* current) const{
	if (current != NULL) { 						
		printInOrderTraversal(current->left);			// Visit left Node
		cout << *current->data << " ";					// Print Current Node
		printInOrderTraversal(current->right);			// Visit Right Node
    }

}



//----------------------------------------------------------------------------
//------------------------------- Constructors -------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Default Constructor:
 * @Param : 		N/A
 * @Post-condition: instantiates root node, set to NULL
*****************************************************************************/
BinTree::BinTree(){
	this->root = NULL;
}
 

/*****************************************************************************
 * Copy Constructor:
 * @Param : 		BinTree p
 * @Post-condition: create a deep copy of BinTree p 
					using the overloaded = operator
*****************************************************************************/
BinTree::BinTree(const BinTree &toCopy){
    this->root = NULL;				
    *this = toCopy;			//sent to '=' overload operator to be copied
}

//----------------------------------------------------------------------------
//--------------------------------- Destructor -------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Destructor:
 * @Post-condition: deallocates memory at end of program to avoid memory leaks
*****************************************************************************/
BinTree::~BinTree(){
	this->makeEmpty();		//sent to make empty for deletion 
}




//----------------------------------------------------------------------------
//-------------------------------- Class Functions----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: IsEmpy
 * @Param : 		 n/a
 * @Post-condition:  Returns true if root is null						 
*****************************************************************************/
bool BinTree::isEmpty() const{
    if (this->root == NULL)
		return true;

	return false;		//root is not Null and Tree is non empty

}

/*****************************************************************************
 * Function: makeEmpy
 * @Param : 		 binTree is not empty
 * @Post-condition:  empties the binTree						 
*****************************************************************************/
void BinTree::makeEmpty(){
	if(!isEmpty())
		makeEmptyRecursiveHelper(root);
						//sending to helper function
}

//----------------------- Helper Function for make Empty ---------------------
/*****************************************************************************
 * Function: makeEmptyRecursiveHelper
 * @Param : 		 binTree is not empty
 * @Post-condition:  uses recursion to traverse and empty the entire binTree						 
*****************************************************************************/
void BinTree::makeEmptyRecursiveHelper(Node*& current){
    if (current != NULL){    							// post order traversal
		makeEmptyRecursiveHelper(current->left); 		// traverse to left side
		makeEmptyRecursiveHelper(current->right);    	// traverse to right side

		if (current->data != NULL){
			delete current->data;   
			current->data = NULL;
		}
		
		delete current; // sets pointer to NULL
		current = NULL;
    }
}




//----------------------------------------------------------------------------
//---------------------------- Assignment Operators --------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Overload: =	Operator
 * @Param : 		 	Both objects are of type BinTree
 * @Post-condition: 	This BinTree will be assigned a deep copy of BinTree p
*****************************************************************************/
BinTree& BinTree::operator=(const BinTree &toCopy){
    if (*this == toCopy) 				// check if both trees are the same
		return *this;

	this->makeEmpty();  				// empties the the left tree 
	copyNode(toCopy.root, this->root);
			//sending to helper function
	return *this;

}

//--------------- Helper Function for = Overload Operator -------------------
/*****************************************************************************
 * Function: copyNode
 * @Param : 		 binTree is not empty
 * @Post-condition:  Assist in generating a deep copy of the binTree "original"						 
*****************************************************************************/
void BinTree::copyNode(Node* original, Node* &copy){

    if (original != NULL){ 				// pre-order traverse right tree
		copy = new Node;   				// new node for left tree

        NodeData *temp = new NodeData(*original->data); // copies original NodeData to temp
		copy->data = temp; 								// set copy Node data to temp


		copyNode(original->left, copy->left); 			// copy left
		copyNode(original->right, copy->right);   		// copy right

    }
	else
        copy = NULL;  									// nothing to copy

}





//----------------------------------------------------------------------------
//---------------------------- Comparison Operators --------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Overload: == Operator
 * @Param : 		a BinTree object 'p'
 * @Post-condition: Returns the true of this BinTree is equal to
 *					p BinTree. False otherwise.
*****************************************************************************/
bool BinTree::operator==(const BinTree &toCompare) const{
    if (this->root == NULL && toCompare.root == NULL)
        return true;
	else
		return compareAllNodes(this->root, toCompare.root);
						//sending to helper function
}

//--------------- Helper Function for == Overload Operator -------------------
/*****************************************************************************
 * Function: compare all Nodes
 * @Param : 		 both objects to be compared are of type BinTree
 * @Post-condition:  will traverse every node within both trees to determine 
 *					 equality, will return false if an inequality is found 
*****************************************************************************/
bool BinTree::compareAllNodes(Node* original, Node* toCompare) const {
	if (original == NULL && toCompare == NULL)
		return true;    						// true if both nodes are NULL
	
	if (original == NULL || toCompare == NULL)
		return false;   						// false if only one node is null
		
	if(*original->data != *toCompare->data)		// false if data is not equal
		return false;
		
	if (original->left == NULL && toCompare->left == NULL 
							   && original->right == NULL && toCompare->right == NULL)
			return true;    // true if nodes being compared have no children

    // both nodes contain the same NodeData
	// both sides have children
	
	// continue to traverse both trees
	return (*original->data == *toCompare->data && compareAllNodes(original->left, toCompare->left)
											    && compareAllNodes(original->right, toCompare->right));
}

/*****************************************************************************
 * Overload: != Operator
 * @Param : 		a BinTree object 'p'
 * @Post-condition: Returns the oposite value of this == p
*****************************************************************************/
bool BinTree::operator!=(const BinTree &toCompare) const{
	return !(*this==toCompare);
}




//----------------------------------------------------------------------
//---------------- Accessor and Modification functions------------------
//----------------------------------------------------------------------
/***********************************************************************
 * Function: insert
 * @Param : 		 new node data is not null
 * @Post-condition:  will insert a new node at the appropriate location
 * @Help-Function:	 uses insert helper to recursively insert data 
************************************************************************/
bool BinTree::insert(NodeData* newData){
	return insertHelper(this->root, newData);
						//sending to helper function
}

//---------------------- Helper Function for Insert --------------------
/*****************************************************************************
 * Function: insertHelper
 * @Param : 		 current Node exists and Data is non-null
 * @Post-condition:  Will recursively find the appropriate location to insert
 * 					 the new data. Will not insert if Data exists 
*****************************************************************************/
bool BinTree::insertHelper(Node*& current, NodeData* toInsert){
    if (current == NULL) {   				// insert new node here
		current = new Node;   				// new node created
        current->data = toInsert;   		// NodeData set to node
        current->left = NULL;   			// left child set to NULL
        current->right = NULL;  			// right child set to NULL
    }
    else if (*toInsert < *current->data)
        return insertHelper(current->left, toInsert);  // traverse left

    else if (*toInsert > *current->data)
		return insertHelper(current->right, toInsert); // traverse right


    else
		return false;   					// node already exists(not inserted)
		
		
	return true;    						// node has been inserted

}
/***********************************************************************
 * Function: retrieve
 * @Param : 		 data to retrieve is not null
 * @Post-condition:  will return true if found and retreived will be set 
 *					 to the retrieved data
 * @Help-Function:	 uses recursiveFind to recursively retrieve data 
************************************************************************/
bool BinTree::retrieve(const NodeData &toRetrieve, NodeData* &retrieved){
	return recursiveFind(this->root, toRetrieve, retrieved);
						//sending to helper function
}

//---------------------- Helper Function for retrieve --------------------
/*****************************************************************************
 * Function: recursiveFind
 * @Param : 		 current Node exists and Data is non-null
 * @Post-condition:  Will recursively find the appropriate data
*****************************************************************************/
bool BinTree::recursiveFind(Node* &current, const NodeData &toRetrieve, 
												  NodeData *&retrieved) const{
	if (current == NULL){    	// NodeData is not found in entire branch
		retrieved = NULL;   	// return pointer set to NULL
        return false;
    }


    if (*current->data == toRetrieve){   	// NodeData found
		retrieved = current->data;  		// return pointer set to NodeData
        return true;
    }

    else if (*current->data < toRetrieve)
		return recursiveFind(current->right, toRetrieve, retrieved);  // traverse to the right

    else if (*current->data > toRetrieve)
		return recursiveFind(current->left, toRetrieve, retrieved);   // traverse to the left

    else
		return false;   // NodeData not found

}
/***********************************************************************
 * Function: getHeight
 * @Param : 		 the data exists
 * @Post-condition:  will return true if found and retreived will be set 
 *					 to the retrieved data
 * @Help-Function:	 uses recursiveFind to recursively retrieve data 
************************************************************************/
int BinTree::getHeight(const NodeData &toFind) const{
    return getHeightHelper(toFind, this->root);
						//sending to helper function

}

//---------------------- Helper Function for getHeight --------------------
/*****************************************************************************
 * Function: getHeightHelper
 * @Param : 		 current Node exists and Data is non-null
 * @Post-condition:  Will recursively find the location of the desired Node
 *					 will then send to helper function to calculate height 
*****************************************************************************/
int BinTree::getHeightHelper(const NodeData &toFind, Node* current) const{
	if (current == NULL)
		return 0;   						// Data is not in this branch

    else if (*current->data == toFind){		// node found
		return calculateHeight(current);    //Find height
	}

    else{									//keep searching
		int left = getHeightHelper(toFind, current->left);   // search left
		int right = getHeightHelper(toFind, current->right); // search right
		
		return max(left, right);
		
    }
}

//--------- Helper function to Calculates height for get height helper ------
/*****************************************************************************
 * Function: calculateHeight
 * @Param : 		 current Node exists in the BinTree
 * @Post-condition:  Uses recusion to find th longest branch from current node
*****************************************************************************/
int BinTree::calculateHeight(Node* current) const{
	if(current == NULL)
		return 0;
	
	return 1 + max(calculateHeight(current->left), calculateHeight(current->right));
}

/***********************************************************************
 * Function: bstreeToArray
 * @Param : 		 BinTree is non-empty
 * @Post-condition:  the BinTree will be transfered to an array, 
 *					 then deleted
 * @Help-Function:	 uses toArrayHelper to recursively transfer data
************************************************************************/
void BinTree::bstreeToArray(NodeData* arrayToFill[]){
	toArrayHelper(this->root, arrayToFill);
					//sending to helper function
	this->makeEmpty();
}

//-------------------- Helper Function for bsToArray -------------------
/*****************************************************************************
 * Function: toArrayHelper
 * @Param : 		 current Node exists and array exists
 * @Post-condition:  Will recursively add data to an array 
*****************************************************************************/
int BinTree::toArrayHelper(Node* current, NodeData* arrayToFill[]){
	if(current == NULL)		//end of branch
		return 0;
		

    int left = toArrayHelper(current->left, arrayToFill); 
	
    NodeData *temp;
    temp = current->data; 				// saves NodeData to temp
    current->data = NULL; 				// current no longer points to node
    *(arrayToFill + left) = temp; 		//arrayToFill points to temp
    temp = NULL;

    int right = toArrayHelper(current->right, arrayToFill + left + 1);
	
    return left + right + 1; // return position

}
/***********************************************************************
 * Function: ArrayToBSTree
 * @Param : 		 Array is non-empty
 * @Post-condition:  the Array will be transfered to an BinTree 
 *					 then deleted
 * @Help-Function:	 uses toArrayHelper to recursively transfer data
************************************************************************/
void BinTree::arrayToBSTree(NodeData* oldArray[]){
	this->makeEmpty();					//clears current BinTree to be filled
	
	int high=0;
	int MAXARRAYSIZE= 100;
	
	for(int i=0; i < MAXARRAYSIZE; i++){ //getting actual size of Array
		if(oldArray[i] != NULL)
			high++ ;
	}
	
	toBinTreeHelper(this->root, oldArray, 0, high-1);
					//sending to helper function
			
}

//-------------------- Helper Function for Array to BS -------------------
/*****************************************************************************
 * Function: toBinTreeHelper
 * @Param : 		 current Node exists and int low < int high
 * @Post-condition:  Will recursively find the location of the desired Node
 *					 will then send to helper function to calculate height 
*****************************************************************************/
void BinTree::toBinTreeHelper(Node *current, NodeData* array[], int low, int high){
	if (low > high)
		current = NULL; 				// end of array NodeData
										//or invalid parameters

    else{

        int mid = (low + high) / 2; 	// picks NodeData from array to build balanced tree

        NodeData* temp; 				// temp NodeData pointer
        temp = array[mid];    			// assigns mid element from array section to temp
        array[mid] = NULL;    			// sets that array element to NULL

        insert(temp);   								  // inserts NodeData int BST
        toBinTreeHelper(current, array, low, mid - 1);    // fill left
        toBinTreeHelper(current, array, mid + 1, high);   // fill right
    }
}



//----------------------------------------------------------------------
//----------------------- Provided Functions----------------------------
//----------------------------------------------------------------------

/************************** displaySideways *****************************/
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.

void BinTree::displaySideways() const {
	sideways(root, 0);
}

/****************************** Sideways *********************************/
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.

void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}



















