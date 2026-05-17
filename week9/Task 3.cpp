#include <iostream>
using namespace std;

class node
{
public:
    int id;
    int score;
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
    void addPlayer(int id, int s)
    {
        node* temp = new node;
        temp->id = id;
        temp->score = s;
        if (head == NULL)
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        else
        {
            node* curr = head->prev;
            curr->next = temp;
            temp->prev = curr;
            temp->next = head;
            head->prev = temp;
        }
        cout << "Player Added Successfully!" << endl;
    }
    void removePlayer(int id)
    {
        if (head == NULL)
        {
            cout << "No Players In Game!" << endl;
            return;
        }
        node* curr = head;
        do
        {
            if (curr->id == id)
            {
                break;
            }
            curr = curr->next;
        } while (curr != head);
        if (curr->id != id)
        {
            cout << "Player Not Found!" << endl;
            return;
        }
        if (curr->next == curr)
        {
            delete curr;
            head = NULL;
            cout << "Player Removed!" << endl;
            return;
        }
        if (curr == head)
        {
            head = head->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        cout << "Player Removed!" << endl;
    }
    void nextTurn(node*& curr)
    {
        if (curr == NULL)
        {
            cout << "No Current Player!" << endl;
            return;
        }
        curr = curr->next;
        cout << "Now Player Turn: " << curr->id << endl;
    }
    void previousTurn(node*& curr)
    {
        if (curr == NULL)
        {
            cout << "No Current Player!" << endl;
            return;
        }
        curr = curr->prev;
        cout << "Previous Player Turn: " << curr->id << endl;
    }
    void skipPlayer(node*& curr)
    {
        if (curr == NULL)
        {
            cout << "No Current Player!" << endl;
            return;
        }
        cout << "Player " << curr->next->id << " Turn Skipped!" << endl;
        curr = curr->next->next;
        cout << "Now Player Turn: " << curr->id << endl;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "No Players In Game!" << endl;
            return;
        }
        node* curr = head;
        cout << "\nPlayers In Game"<<endl;
        do
        {
            cout << "Player ID: " << curr->id << " | Score: " << curr->score << endl;
            curr = curr->next;
        } while (curr != head);
    }
    bool gameOver()
    {
        if (head != NULL && head->next == head)
        {
            cout << "\nGame Over!" << endl;
            cout << "Winner is Player " << head->id << endl;
            return true;
        }
        return false;
    }
    node* getHead()
    {
        return head;
    }
};

int main()
{
    list l;
    node* cur = NULL;
    int choice;
    int id, score;
    while (true)
    {
        cout << "\n1. Add Player" << endl;
        cout << "2. Remove Player" << endl;
        cout << "3. Next Turn" << endl;
        cout << "4. Previous Turn" << endl;
        cout << "5. Skip Player" << endl;
        cout << "6. Display Players" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Player ID: ";
            cin >> id;
            cout << "Enter Score: ";
            cin >> score;
            l.addPlayer(id, score);
            if (cur == NULL)
            {
                cur = l.getHead();
            }
            break;
        }
        case 2:
        {
            cout << "Enter Player ID To Remove: ";
            cin >> id;
            if (cur != NULL && cur->id == id)
            {
                cur = cur->next;
            }
            l.removePlayer(id);
            if (l.gameOver())
            {
                return 0;
            }
            break;
        }
        case 3:
        {
            l.nextTurn(cur);
            break;
        }
        case 4:
        {
            l.previousTurn(cur);
            break;
        }
        case 5:
        {
            l.skipPlayer(cur);
            break;
        }
        case 6:
        {
            l.display();
            break;
        }
        case 7:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid Choice!" << endl;
        }
        }
    }

    return 0;
}