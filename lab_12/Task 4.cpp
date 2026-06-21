#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	node* LTree;
	node* RTree;
	node* next;
	int isbn;
	string title;
};
class BST
{
public:
	node* root;
	node* head;
	node* tail;
	BST()
	{
		root = NULL;
		head = NULL;
		tail = NULL;
	}
	void insertBook()
	{
		int n;
		cout << "enter number of books: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			node* newNode = new node;
			cout << "enter ISBN: ";
			cin >> newNode->isbn;
			cin.ignore();
			cout << "enter title: ";
			getline(cin, newNode->title);
			newNode->LTree = NULL;
			newNode->RTree = NULL;
			newNode->next = NULL;
			if (root == NULL)
			{
				root = newNode;
			}
			else
			{
				node* temp = root;
				while (true)
				{
					//moving toward left subtree
					if (newNode->isbn < temp->isbn)
					{
						if (temp->LTree == NULL)
						{
							temp->LTree = newNode;
							break;
						}
						temp = temp->LTree;
					}
					//moving toward right subtree
					else if (newNode->isbn > temp->isbn)
					{
						if (temp->RTree == NULL)
						{
							temp->RTree = newNode;
							break;
						}
						temp = temp->RTree;
					}
					//duplicate ISBN not allowed
					else
					{
						cout << "duplicate ISBN not allowed" << endl;
						delete newNode;
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
			inorder(p->LTree);
			cout << p->isbn << " - " << p->title << endl;
			inorder(p->RTree);
		}
	}
	//adding book into linked list
	void addToList(int isbn, string title)
	{
		node* temp = new node;
		temp->isbn = isbn;
		temp->title = title;
		temp->next = NULL;
		temp->LTree = NULL;
		temp->RTree = NULL;
		//if list is empty
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	//converting BST into linked list using inorder traversal
	void BSTtoList(node* p)
	{
		if (p != NULL)
		{
			//visiting left subtree
			BSTtoList(p->LTree);
			//adding current node into list
			addToList(p->isbn, p->title);
			//visiting right subtree
			BSTtoList(p->RTree);
		}
	}
	//displaying linked list
	void printList()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->isbn << " - " << temp->title << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	BST obj;
	obj.insertBook();
	cout << endl << "books in BST inorder:" << endl;
	obj.inorder(obj.root);
	obj.BSTtoList(obj.root);
	cout << endl << "books in linked list:" << endl;
	obj.printList();

	return 0;
}