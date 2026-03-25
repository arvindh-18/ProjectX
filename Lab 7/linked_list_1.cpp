// Program to make linked lists and merge them using classes

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
        Node(int);
        Node(int, Node *);
    };

    Node *head;

public:
    LinkedList();

    void SortedInsert(int);

    void PrintList();

    Node *getHead();

    void setHead(Node *);

    Node *MergeList(Node *, Node *);
};

int main()
{

    int ch = 0, size, val;
    pair<LinkedList *, LinkedList *> lists = {NULL, NULL};
    while (ch != 4)
    {
        cout << "\nMENU\n"
             << endl;
        cout << "1. List 1" << endl;
        cout << "2. List 2" << endl;
        cout << "3. Merge Lists" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            LinkedList *list1 = new LinkedList();
            cout << "Enter the size of the list: ";
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element " << (i + 1) << ": ";
                cin >> val;
                list1->SortedInsert(val);
            }
            cout << "The List is: " << endl;
            list1->PrintList();
            lists.first = list1;
            break;
        }
        case 2:
        {
            LinkedList *list2 = new LinkedList();
            cout << "Enter the size of the list: ";
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element " << (i + 1) << ": ";
                cin >> val;
                list2->SortedInsert(val);
            }
            cout << "The List is: " << endl;
            list2->PrintList();
            lists.second = list2;
            break;
        }
        case 3:
        {
            if (!(lists.first && lists.second))
            {
                cout << "\nPlease create the lists first" << endl;
                break;
            }
            LinkedList *merged = new LinkedList();
            merged->setHead(merged->MergeList(lists.first->getHead(), lists.second->getHead()));
            cout << "Merged List is: " << endl;
            merged->PrintList();
            break;
        }
        case 4:
            cout << "\nExiting\n"
                 << endl;
            break;
        default:
            cout << "\nEnter a valid choice\n"
                 << endl;
        }
    }
    return 0;
}

// Default Constructor for Node
LinkedList::Node::Node() : data(0), next(NULL) {}

// Parametrized Constructor for Node
LinkedList::Node::Node(int x) : data(x), next(NULL) {}

// Node Constructor with 2 parameters
LinkedList::Node::Node(int x, Node *next) : data(x), next(next) {}

// Default Constructor for LinkedList
LinkedList::LinkedList() : head(NULL) {}

// Inserting element in sorted order
void LinkedList::SortedInsert(int x)
{
    Node *newNode = new Node(x);

    if (head == NULL || head->data >= x)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL && temp->next->data < x)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// Printing elements of the Linked List
void LinkedList::PrintList()
{
    Node *temp = this->head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// This function returns the head of the Node
LinkedList::Node *LinkedList::getHead()
{
    return this->head;
}

// This function sets the head of the Node
void LinkedList::setHead(Node *head)
{
    this->head = head;
}

// Merging 2 sorted linked list and returning its head
LinkedList::Node *LinkedList::MergeList(Node *list1, Node *list2)
{
    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy->next;
}