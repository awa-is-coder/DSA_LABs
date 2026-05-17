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
    void insert(int value)
    {
        node* curr = head;
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
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
    int n, value;
    cout << "How many elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        l.insert(value);
    }
    cout << endl;
    cout << "Linked List elements: ";
    l.print(l.head);

    return 0;
}