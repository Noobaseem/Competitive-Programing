/*
	This is the c++ code to demonstate the implementation of the AVl tree datastructure
	AVL tree ADT was created by Georgy Adelson-Velsky and Landis, they are BST with height balancing factor
	The HB(k) in AVL must line in {-1,0,1}.
*/

/*
	Descibing the structure of the node of the AVL tree
*/

struct node{
	int info;
	int height;
	struct node* left;
	struct node* right;
	node(int k) { info = k; left = right = 0; height = 1; }
}*root;

/*
	AVL tree class that contains the method supported by this ADT
*/
class avl{
	public:
		int height(node* p);			    //Return the height of the node
		int bFactor(node* p);			    //Return the balance factor of the node
		int fixHeight(node* p);			    //Fixes or corrects of the node by checking the heights of the children subtrees
		node* insert(node* p, int item);	//insert an elemnt in the avl tree
		node* rotateRight(node* p); 		//This is one of the rotation used in the AVL tree to remove unbalancing caused by LL insertion
		node* rotateLeft(node* p);			//his is one of the rotation used in the AVL tree to remove unbalancing caused by RR insertion
		node* balance(node* p);				//It is a generic function to balance the AVL tree. It uses rotateRight and rotateLeft methods
		node* findMin(node* p);				//THis is a utility function which is used when we delete some node. It's main task is to find element in the subtree from where the node is deleted.
		node* removeMin(node* p);			//
		node* remove(node* p, int item);	//This procedures removes/deletes the node from the avl tree
		avl(){
			root = NULL;
		}
};

int avl::height(node* p){
	return p ? p->height : 0;
}

/*
	It takes the height of the right subtree and the height of the left subtree
	The difference of rightHeight and leftHeight is the balance factor of the node under consideration.
*/
int avl::bFactor(node* p){
	int rightHeigth = height(p->right);
	int leftHeight  = height(p->left);
	return (rightHeight-leftHeight);
}

int avl::fixHeight(node* p){
	int rightHeigth = height(p->right);
	int leftHeight  = height(p->left);
	p->height = ((rightHeight > leftHeight) ? rightHeight : leftHeight) + 1;
}

node* avl::insert(node* p, int item){
	if(!p) return new node(item);
	if(item < p->info) 
		p->left = insert(p->left, item);
	if(item > p->info)
		p->right = insert(p->right, item);
	return balance(p);
}

/*
	This type of Rotation generally fixes the unbalacing caused by the LL insertions.
	After the balancing the height of the root nodes are fixed.
	Complexity to run this code is O(1)
*/
node* avl::rotateRight(node* p){
	node* q  = p->left;
	p->left  = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

node* avl::rotateleft(node* p){
	node* q  = p->right;
	p->right = q->left;
	q->left  = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

/*
	THis is a generic function to perform the balancing
*/
node* avl::balance(node* p){
	int bf = bFactor(p);
	/*
		Balance factor of 2 means that the right subtree is causing unbalancing i.e some element is added from right subtree
		or some element is removed from the left subtree thus creating a height imbalance.
	*/
	if(bf == 2){
		if(bFactor(p->right) < 0){
			p->right = rotateRight(p->right);
		}
		return rotateLeft(p);
	}
	if(bf == -2){
		/*
			If bFactor of left child of p is greated than 0. Then it simply means that the unbalancing is due to insertion of 
			new node in the right subtree of the left child of p. Thus LR roation will be applied where the left child of p goes
			under leftRotation first and then the root i.e p goes under rightRotation.
			If this is not the case then only rightRotation is enough to solve the problem
		*/
		if(bFactor(p->left) > 0){
			p->left = rotateLeft(p->left);
		}
		return rightRotate(p);
	}
}

node* avl::findMin(node* p){

}

node* avl::removeMin(node* p){

}

node* avl::remove(node* p, int item){

}