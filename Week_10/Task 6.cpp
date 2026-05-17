#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;
};
class list
{
public:
	node* head;
	list()
	{
		head = NULL;
	}
	void insertBegin(node*& temp, int value)
	{
		node* curr = new node;
		curr->data = value;
		curr->prev = NULL;
		curr->next = temp;
		if (temp != NULL)
		{
			temp->prev = curr;
		}
		temp = curr;
	}
	void insertEnd(node*& temp, int value)
	{
		if (temp == NULL)
		{
			node* curr = new node;
			curr->data = value;
			curr->next = NULL;
			curr->prev = NULL;
			temp = curr;
			return;
		}
		insertEnd(temp->next, value);
		if (temp->next != NULL)
		{
			temp->next->prev = temp;
		}
	}
	void insertPosition(node*& temp, int value, int pos)
	{
		if (pos == 1)
		{
			node* curr = new node;
			curr->data = value;
			curr->prev = NULL;
			curr->next = temp;
			if (temp != NULL)
			{
				temp->prev = curr;
			}
			temp = curr;
			return;
		}
		if (temp == NULL)
		{
			cout << "Position not found" << endl;
			return;
		}
		insertPosition(temp->next, value, pos - 1);
		if (temp->next != NULL)
		{
			temp->next->prev = temp;
		}
	}
	void deleteValue(node*& temp, int value)
	{
		if (temp == NULL)
		{
			cout << "Value not found" << endl;
			return;
		}
		if (temp->data == value)
		{
			node* curr = temp;
			temp = temp->next;
			if (temp != NULL)
			{
				temp->prev = NULL;
			}
			delete curr;
			cout << "Delete successfully" << endl;
			return;
		}
		deleteValue(temp->next, value);
		if (temp != NULL && temp->next != NULL)
		{
			temp->next->prev = temp;
		}
	}
	void deletePosition(node*& temp, int pos)
	{
		if (pos < 1)
		{
			cout << "Invalid position" << endl;
			return;
		}
		if (temp == NULL)
		{
			cout << "Position not found" << endl;
			return;
		}
		if (pos == 1)
		{
			node* curr = temp;
			temp = temp->next;
			if (temp != NULL)
			{
				temp->prev = NULL;
			}
			delete curr;
			cout << "Delete successfully" << endl;
			return;
		}
		deletePosition(temp->next, pos - 1);
		if (temp != NULL && temp->next != NULL)
		{
			temp->next->prev = temp;
		}
	}
	int search(node* temp, int value, int pos)
	{
		if (temp == NULL)
		{
			cout << "Value not found" << endl;
			return -1;
		}
		if (temp->data == value)
		{
			cout << "Found at:" << pos << endl;
			return pos;
		}
		return search(temp->next, value, pos + 1);
	}
	void printForward(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		cout << temp->data << " ";
		printForward(temp->next);
	}
	void printReverse(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		printReverse(temp->next);
		cout << temp->data << " ";
	}
	bool palindrome(node* left, node* right)
	{
		if (left == NULL)
		{
			return true;
		}
		if (left == right)
		{
			return true;
		}
		if (left->data != right->data)
		{
			return false;
		}
		node* nextLeft = left->next;
		node* prevRight = right->prev;
		if (nextLeft == NULL || prevRight == NULL)
		{
			return true;
		}
		return palindrome(nextLeft, prevRight);
	}
	node* getTail(node* temp)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		if (temp->next == NULL)
		{
			return temp;
		}
		return getTail(temp->next);
	}
};

int main()
{
	list l;
	int choice, value, pos;
	do
	{
		cout << "\n1.InsertBegin" << endl;
		cout << "2.InsertEnd" << endl;
		cout << "3.InsertPosition" << endl;
		cout << "4.DeleteValue" << endl;
		cout << "5.DeletePosition" << endl;
		cout << "6.Search" << endl;
		cout << "7.PrintForward" << endl;
		cout << "8.PrintReverse" << endl;
		cout << "9.Palindrome" << endl;
		cout << "0.Exit" << endl;
		cout << "EnterChoice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "EnterValue:";
			cin >> value;
			l.insertBegin(l.head, value);
			break;
		case 2:
			cout << "EnterValue:";
			cin >> value;
			l.insertEnd(l.head, value);
			break;
		case 3:
			cout << "EnterValue:";
			cin >> value;
			cout << "EnterPos:";
			cin >> pos;
			l.insertPosition(l.head, value, pos);
			break;
		case 4:
			cout << "EnterValue:";
			cin >> value;
			l.deleteValue(l.head, value);
			break;
		case 5:
			cout << "EnterPos:";
			cin >> pos;
			l.deletePosition(l.head, pos);
			break;
		case 6:
			cout << "EnterValue:";
			cin >> value;
			l.search(l.head, value, 1);
			break;
		case 7:
			cout << "List:";
			l.printForward(l.head);
			cout << endl;
			break;
		case 8:
			cout << "List:";
			l.printReverse(l.head);
			cout << endl;
			break;
		case 9:
		{
			node* tail = l.getTail(l.head);
			if (l.palindrome(l.head, tail))
			{
				cout << "Palindrome" << endl;
			}
			else
			{
				cout << "Not Palindrome" << endl;
			}
		}
		break;
		case 0:
			cout << "Exit" << endl;
			break;
		default:
			cout << "Invalid" << endl;
		}
	} 
	while (choice != 0);

	return 0;
}