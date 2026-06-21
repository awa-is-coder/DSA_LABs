#include <iostream>
using namespace std;

class node
{
public:
	node* LTree, * RTree;
	int data;
};
class BST
{
public:
	node* root;
	BST()
	{
		root = NULL;
	}
	void create()
	{
		node* p;
		int value, c;
		//taking total number of nodes from user
		cout << "enter no of nodes: ";
		cin >> c;
		//checking if entered nodes are valid if -ve or 0 return
		if (c <= 0)
		{
			return;
		}
		//loop runs according to total nodes
		for (int i = 0; i < c; i++)
		{
			//creating root node if tree is empty
			if (root == NULL)
			{
				root = new node;
				cout << "enter value of root node: ";
				cin >> root->data;
				root->LTree = NULL;
				root->RTree = NULL;
			}
			else
			{
				//starting pointer from root
				p = root;
				cout << "enter value of node: ";
				cin >> value;
				//finding correct position for new node
				while (true)
				{
					//moving toward left subtree
					if (value < p->data)
					{
						//inserting node if left side is empty
						if (p->LTree == NULL)
						{
							p->LTree = new node;
							p = p->LTree;
							p->data = value;
							p->LTree = NULL;
							p->RTree = NULL;
							cout << value << " entered in left to its parent" << endl;
							break;
						}
						else
						{
							//moving further left
							p = p->LTree;
						}
					}
					//moving toward right subtree
					else if (value > p->data)
					{
						//inserting node if right side is empty
						if (p->RTree == NULL)
						{
							p->RTree = new node;
							p = p->RTree;
							p->data = value;
							p->LTree = NULL;
							p->RTree = NULL;
							cout << value << " entered in right to its parent" << endl;
							break;
						}
						else
						{
							//moving further right
							p = p->RTree;
						}
					}
					//for duplicate values
					else
					{
						cout << "duplicate value not allowed" << endl;
						break;
					}
				}
			}
		}
	}
	//recursive inorder traversal
	void inorder(node* p)
	{
		if (p != NULL)
		{
			//visiting left subtree
			inorder(p->LTree);
			//printing root node
			cout << p->data << endl;
			//visiting right subtree
			inorder(p->RTree);
		}
	}
	//function to check whether two BSTs are identical or not
	bool isIdentical(node* root1, node* root2)
	{
		//if both nodes are NULL trees are identical till this point
		if (root1 == NULL && root2 == NULL)
		{
			return true;
		}
		//if one node is NULL and other is not structure of trees is different
		if (root1 == NULL || root2 == NULL)
		{
			return false;
		}
		//if data stored in nodes is different trees are not identical
		if (root1->data != root2->data)
		{
			return false;
		}
		//checking left and right subtrees recursively
		return isIdentical(root1->LTree, root2->LTree)&& isIdentical(root1->RTree, root2->RTree);
	}
};
int main()
{
	BST tree1, tree2;
	cout << "Create First BST" << endl;
	tree1.create();
	cout << endl << "Create Second BST" << endl;
	tree2.create();
	cout << endl << "Inorder of First BST:" << endl;
	tree1.inorder(tree1.root);
	cout << endl << "Inorder of Second BST:" << endl;
	tree2.inorder(tree2.root);
	if (tree1.isIdentical(tree1.root, tree2.root))
	{
		cout << endl << "Both BSTs are Identical" << endl;
	}
	else
	{
		cout << endl << "Both BSTs are Not Identical" << endl;
	}

	return 0;
}