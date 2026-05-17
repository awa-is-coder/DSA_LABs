#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class list
{
public:
	node* head;

	list()
	{
		head = NULL;
	}
	void insertBegin(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insertEnd(node*& temp, int value)
	{
		if (temp == NULL)
		{
			temp = new node;
			temp->data = value;
			temp->next = NULL;
			return;
		}
		insertEnd(temp->next, value);
	}
	void insertPosition(node*& temp, int value, int pos)
	{
		if (pos == 1)
		{
			node* curr = new node;
			curr->data = value;
			curr->next = temp;
			temp = curr;
			return;
		}
		if (temp == NULL)
		{
			cout << "Position not found" << endl;
			return;
		}
		insertPosition(temp->next, value, pos - 1);
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
			delete curr;
			cout << "Delete successfully" << endl;
			return;
		}
		deleteValue(temp->next, value);
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
			delete curr;
			cout << "Delete successfully" << endl;
			return;
		}
		deletePosition(temp->next, pos - 1);
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
	void print(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		cout << temp->data << " ";
		print(temp->next);
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
		cout << "7.Print" << endl;
		cout << "0.Exit" << endl;
		cout << "EnterChoice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "EnterValue:";
			cin >> value;
			l.insertBegin(value);
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
			l.print(l.head);
			cout << endl;
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