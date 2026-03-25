// Program to implement Linked List using classes

#include <iostream>
#include <utility>

using namespace std;

class LinkedList
{

private:
    struct Node
    {
        int data;
        Node *next;
        Node();
        Node(int, Node *);
    };
    Node *head;

public:
    LinkedList();

    void insertAtStart(int);
    void deleteAtStart();
    void rotate(int);
    void reversedata();
    void reverseLink();
    void search(int);
    void display();
};

int main()
{

    LinkedList list;
    int choice = 0, x, k;

    while (choice != 8)
    {
        cout << "\n1.Insert Beginning";
        cout << "\n2.Delete Beginning";
        cout << "\n3.Rotate";
        cout << "\n4.Reverse(Data)";
        cout << "\n5.Reverse(Link)";
        cout << "\n6.Search";
        cout << "\n7.Display";
        cout << "\n8.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value: ";
            cin >> x;
            list.insertAtStart(x);
            break;

        case 2:
            list.deleteAtStart();
            break;

        case 3:
            cout << "Enter k: ";
            cin >> k;
            list.rotate(k);
            break;

        case 4:
            list.reversedata();
            break;

        case 5:
            list.reverseLink();
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> x;
            list.search(x);
            break;

        case 7:
            list.display();
            break;

        case 8:
            cout << "Exiting";
            break;

        default:
            cout << "Invalid choice";
        }
    }
}

// Default Constructor for Node
LinkedList::Node::Node() : data(0), next(NULL) {}

// Parametrized Constructor for Node
LinkedList::Node::Node(int x, Node *next) : data(x), next(next) {}

// Default Constructor for LinkedList
LinkedList::LinkedList() : head(NULL) {}

// Inserting at Start of the list
void LinkedList::insertAtStart(int x)
{
    Node *temp = new Node(x, NULL);
    temp->next = head;
    head = temp;
    return;
}

// Deleting at Start of the list
void LinkedList::deleteAtStart()
{
    if (!head)
    {
        cout << "List Empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
}

// Rotate list to right by k times
void LinkedList::rotate(int k)
{
    if (!head || !head->next || k == 0)
        return;

    int len = 1;
    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    int steps = len - k;

    Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    head = newTail->next;
    newTail->next = NULL;

    return;
}

// Reversing List with only data
void LinkedList::reversedata()
{
    if (!head || !head->next)
        return;
    Node *top = head, *bottom = head;
    while (bottom->next != NULL)
        bottom = bottom->next;
    while (top != bottom)
    {
        swap(top->data, bottom->data);
        Node *prv = top;
        while (prv->next != bottom)
            prv = prv->next;
        if (top->next == bottom)
            break;
        bottom = prv;
        top = top->next;
    }
    return;
}

// Reversing List by links
void LinkedList::reverseLink()
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return;
}

// Searching element in list
void LinkedList::search(int x)
{
    Node *temp = head;
    int pos = 1;
    while (temp)
    {
        if (temp->data == x)
        {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not Found\n";
    return;
}

// Displaying the LinkedList
void LinkedList::display()
{
    Node *temp = this->head;
    cout << "List : ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}