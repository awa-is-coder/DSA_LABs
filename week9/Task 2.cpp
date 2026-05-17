#include <iostream>
using namespace std;

class node
{
public:
	int songID;
	string songName;
	float duration;
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
	void insertSong(int id, string name, float dur)
	{
		node* temp = new node;
		temp->songID = id;
		temp->songName = name;
		temp->duration = dur;
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
	void deleteSong(string name)
	{
		if (head == NULL)
		{
			cout << "Playlist Empty!" << endl;
			return;
		}
		node* curr = head;
		while (curr != NULL && curr->songName != name)
		{
			curr = curr->next;
		}
		if (curr == NULL)
		{
			cout << "Song Not Found!" << endl;
			return;
		}
		if (curr == head)
		{
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
		}
		else
		{
			if (curr->next != NULL)
			{
				curr->next->prev = curr->prev;
			}
			if (curr->prev != NULL)
			{
				curr->prev->next = curr->next;
			}
		}
		delete curr;
		cout << "Song Deleted!" << endl;
	}
	void playNext(node*& curr)
	{
		if (curr == NULL)
		{
			cout << "No song playing!" << endl;
			return;
		}
		if (curr->next == NULL)
		{
			cout << "This is last song!" << endl;
			return;
		}
		curr = curr->next;
		cout << "Now Playing: " << curr->songName << endl;
	}
	void playPrev(node*& curr)
	{
		if (curr == NULL)
		{
			cout << "No song playing!" << endl;
			return;
		}
		if (curr->prev == NULL)
		{
			cout << "This is first song!" << endl;
			return;
		}
		curr = curr->prev;
		cout << "Now Playing: " << curr->songName << endl;
	}
	void reverseList()
	{
		node* curr = head;
		node* temp = NULL;
		while (curr != NULL)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}
		if (temp != NULL)
		{
			head = temp->prev;
		}
		cout << "Playlist Reversed!" << endl;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "Playlist Empty!" << endl;
			return;
		}
		node* curr = head;
		cout << "Playlist:\n";
		while (curr != NULL)
		{
			cout << "ID: " << curr->songID << " | Name: " << curr->songName << " | Duration: " << curr->duration << endl;
			curr = curr->next;
		}
	}
	node* getHead()
	{
		return head;
	}
};
int main()
{
	list l;
	node* curr = NULL;
	int choice, id;
	string name;
	float dur;
	while (true)
	{
		cout << "\n1. Insert Song" << endl;
		cout << "2. Delete Song" << endl;
		cout << "3. Play Next" << endl;
		cout << "4. Play Previous" << endl;
		cout << "5. Display Playlist" << endl;
		cout << "6. Reverse Playlist" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Duration: ";
			cin >> dur;
			l.insertSong(id, name, dur);
			if (curr == NULL)
			{
				curr = l.getHead();
			}
			break;

		case 2:
			cout << "Enter Name: ";
			cin >> name;
			l.deleteSong(name);
			break;

		case 3:
			l.playNext(curr);
			break;

		case 4:
			l.playPrev(curr);
			break;

		case 5:
			l.display();
			break;

		case 6:
			l.reverseList();
			break;

		case 7:
			return 0;

		default:
			cout << "Invalid Choice!";
		}
	}

	return 0;
}