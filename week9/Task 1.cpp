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
private:
	node* head;
public:
	list()
	{
		head = NULL;
	}
	void insertAtEnd(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			node* curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
			temp->prev = curr;
		}
	}
	void insertAtStart(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}
	void insertPos(int val, int pos)
	{
		if (pos == 1)
		{
			insertAtStart(val);
			return;
		}
		node* curr = head;
		
		for (int i = 1; i < pos && curr != NULL; i++)
		{
			curr = curr->next;
		}
		if (curr == NULL)
		{
			cout << "Invalid Position!" << endl;
			return;
		}
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		if (curr->next == NULL)
		{
			curr->next = temp;
			temp->next = NULL;
			temp->prev = curr;
		}
		else
		{
			temp->next = curr->next;
			temp->next->prev = temp;
			curr->next = temp;
			temp->prev= curr;

		}
	}
	void deleteNode(int val)
	{
		if (head == NULL)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		node* curr = head;
		while (curr != NULL && curr->data != val)
		{
			curr = curr->next;
		}
		if (curr == NULL)
		{
			cout << "Value not Found!" << endl;
			return;
		}
		if (curr == head)
		{
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			delete curr;
			return;
		}
		if (curr->next != NULL)
		{
			curr->next->prev = curr->prev;
		}
		if (curr->prev != NULL)
		{
			curr->prev->next = curr->next;
		}
		delete curr;
	}
	void displayForward()
	{
		if (head == NULL)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		node* curr = head;
		cout << "Forward: ";
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	void displayReverse()
	{
		if (head == NULL)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		node* curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		cout << "Reverse: ";
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->prev;
		}
		cout << endl;
	}
};

int main()
{
	list l;
	int choice, val, pos;

	while (true)
	{
		cout << "\n1. Insert at End" << endl;
		cout << "2. Insert at Start" << endl;
		cout << "3. Insert at Position" << endl;
		cout << "4. Delete Node by Value" << endl;
		cout << "5. Display Forward" << endl;
		cout << "6. Display Reverse" << endl;
		cout << "7. Exit" << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter value: ";
			cin >> val;
			l.insertAtEnd(val);
			break;

		case 2:
			cout << "Enter value: ";
			cin >> val;
			l.insertAtStart(val);
			break;

		case 3:
			cout << "Enter value: ";
			cin >> val;
			cout << "Enter position: ";
			cin >> pos;
			l.insertPos(val, pos);
			break;

		case 4:
			cout << "Enter value to delete: ";
			cin >> val;
			l.deleteNode(val);
			break;

		case 5:
			l.displayForward();
			break;

		case 6:
			l.displayReverse();
			break;

		case 7:
			cout << "Exiting program..." << endl;
			return 0;

		default:
			cout << "Invalid choice!" << endl;
		}
	}

	return 0;
}