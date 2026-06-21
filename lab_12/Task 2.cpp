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
	void preorder(node* p)
	{
		if (p != NULL)
		{
			//printing root node
			cout << p->data << endl;
			//visiting left subtree
			preorder(p->LTree);
			//visiting right subtree
			preorder(p->RTree);
		}
	}
	void postorder(node* p)
	{
		if (p != NULL)
		{
			//visiting left subtree
			postorder(p->LTree);
			//visiting right subtree
			postorder(p->RTree);
			//printing root node
			cout << p->data << endl;
		}
	}
	//recursive search function
	node* search(node* curr, int num)
	{
		//if current node becomes NULL value does not exist
		if (curr == NULL)
		{
			return NULL;
		}
		//if value matches with current node return node
		if (curr->data == num)
		{
			return curr;
		}
		//if value is smaller move toward left subtree
		else if (num < curr->data)
		{
			return search(curr->LTree, num);
		}
		//if value is greater move toward right subtree
		else
		{
			return search(curr->RTree, num);
		}
	}
	node* findMin(node* curr)
	{
		//if tree is empty or left child becomes NULL
		//current node contains minimum value
		if (curr == NULL || curr->LTree == NULL)
		{
			return curr;
		}
		//moving continuously toward left subtree
		return findMin(curr->LTree);
	}
	//function to get parent of a node
	node* getParent(node* curr, node* prev, int num)
	{
		//if current node becomes NULL
		//it means value does not exist in BST
		if (curr == NULL)
		{
			return NULL;
		}
		//if required value is found
		//return previous node because it is parent
		if (curr->data == num)
		{
			return prev;
		}
		//if value is smaller move toward left subtree
		//current node becomes previous node
		else if (num < curr->data)
		{
			return getParent(curr->LTree, curr, num);
		}
		//if value is greater move toward right subtree
		//current node becomes previous node
		else
		{
			return getParent(curr->RTree, curr, num);
		}
	}
	void deleteNode(int num)
	{
		//searching node which user wants to delete
		node* temp = search(root, num);
		//if node does not exist stop function
		if (temp == NULL)
		{
			cout << "node not found" << endl;
			return;
		}
		//finding parent of node to reconnect tree after deletion
		node* parent = getParent(root, NULL, num);
		//Case 1: Node is leaf node
		if (temp->LTree == NULL && temp->RTree == NULL)
		{
			//if deleting root node
			if (parent == NULL)
			{
				root = NULL;
			}
			//disconnecting node from left side of parent
			else if (parent->LTree == temp)
			{
				parent->LTree = NULL;
			}
			//disconnecting node from right side of parent
			else
			{
				parent->RTree = NULL;
			}
			//freeing memory of deleted node
			delete temp;

			cout << "Leaf node deleted successfully\n";
		}
		//Case2: Node has only right child
		//right child directly replaces deleted node
		else if (temp->LTree == NULL && temp->RTree != NULL)
		{
			//if root node has only right child
			if (parent == NULL)
			{
				root = temp->RTree;
			}
			//connecting parent's left with right child
			else if (parent->LTree == temp)
			{
				parent->LTree = temp->RTree;
			}
			//connecting parent's right with right child
			else
			{
				parent->RTree = temp->RTree;
			}
			//deleting old node
			delete temp;
			cout << "node with only right child deleted successfully\n";
		}
		//Case2: Node has only left child
		//left child directly replaces deleted node
		else if (temp->LTree != NULL && temp->RTree == NULL)
		{
			//if root node has only left child
			if (parent == NULL)
			{
				root = temp->LTree;
			}
			//connecting parent's left with left child
			else if (parent->LTree == temp)
			{
				parent->LTree = temp->LTree;
			}
			//connecting parent's right with left child
			else
			{
				parent->RTree = temp->LTree;
			}
			//deleting old node
			delete temp;

			cout << "node with only left child deleted successfully" << endl;
		}
		//Case3: node has two children
		else
		{
			//finding minimum node from right subtree
			//this node is inorder successor
			node* minNode = findMin(temp->RTree);
			int minValue = minNode->data;
			//deleting duplicate node from right subtree
			deleteNode(minValue);
			//copying inorder successor value into current node
			temp->data = minValue;
			cout << "node with two children deleted successfully" << endl;
		}
	}
};
int main()
{
	BST obj;
	int key, del;
	obj.create();
	cout << "\ninorder: " << endl;
	obj.inorder(obj.root);
	cout << "preorder: " << endl;
	obj.preorder(obj.root);
	cout << "postorder: " << endl;
	obj.postorder(obj.root);
	
	cout << "enter value to search: ";
	cin >> key;
	if (obj.search(obj.root, key) != NULL)
	{
		cout << "key found in BST" << endl;
	}
	else
	{
		cout << "key not found in BST" << endl;
	}
	cout << "enter value to delete: ";
	cin >> del;
	obj.deleteNode(del);
	cout << "inorder: " << endl;
	obj.inorder(obj.root);
	cout << "preorder: " << endl;
	obj.preorder(obj.root);
	cout << "postorder: " << endl;
	obj.postorder(obj.root);
	return 0;
}