#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int id;
    string title;
    bool issued;

public:
    Book();
    Book(int, string);

    int getId();
    string getTitle();
    bool isIssued();

    void issue();
    void display();
};

class Library
{
private:
    Book books[100];
    int count;

public:
    Library();

    void addBook(int, string);
    void displayAll();

    void search(int);
    void search(string);

    void issueBook(int);
    void issueBook(string);
};

int main()
{
    Library lib;
    int ch = 0, id;
    string title;

    while (ch != 6)
    {
        cout << "\nMENU\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search by ID\n";
        cout << "4. Search by Title\n";
        cout << "5. Issue Book\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin >> title;
            lib.addBook(id, title);
            break;

        case 2:
            lib.displayAll();
            break;

        case 3:
            cout << "Enter ID: ";
            cin >> id;
            lib.search(id);
            break;

        case 4:
            cout << "Enter Title: ";
            cin >> title;
            lib.search(title);
            break;

        case 5:
        {
            int opt;
            cout << "1. Issue by ID\n2. Issue by Title\nEnter choice: ";
            cin >> opt;

            if (opt == 1)
            {
                cout << "Enter ID: ";
                cin >> id;
                lib.issueBook(id);
            }
            else if (opt == 2)
            {
                cout << "Enter Title: ";
                cin >> title;
                lib.issueBook(title);
            }
            else
            {
                cout << "Invalid option\n";
            }
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

// default constructor for book
Book::Book()
{
    id = 0;
    title = "";
    issued = false;
}

// parameterized constructor for book
Book::Book(int i, string t)
{
    id = i;
    title = t;
    issued = false;
}

// function to get id
int Book::getId()
{
    return id;
}

// function to get title
string Book::getTitle()
{
    return title;
}

// function to check issued
bool Book::isIssued()
{
    return issued;
}

// funciton to issue book
void Book::issue()
{
    issued = true;
}

// function to display book
void Book::display()
{
    cout << "ID: " << id << " | Title: " << title
         << " | Status: " << (issued ? "Issued" : "Available") << endl;
}

// constructor for library
Library::Library()
{
    count = 0;
}

// function to add book
void Library::addBook(int id, string title)
{
    if (count >= 100)
    {
        cout << "Library full\n";
        return;
    }
    books[count++] = Book(id, title);
}

// function to display all books
void Library::displayAll()
{
    if (count == 0)
    {
        cout << "No books\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        books[i].display();
    }
}

// function to search book by id
void Library::search(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getId() == id)
        {
            books[i].display();
            return;
        }
    }
    cout << "Book not found\n";
}

// function to search book by title
void Library::search(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            books[i].display();
            return;
        }
    }
    cout << "Book not found\n";
}

// function to issue book by id
void Library::issueBook(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getId() == id)
        {
            if (books[i].isIssued())
                cout << "Already issued\n";
            else
            {
                books[i].issue();
                cout << "Issued successfully\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

// function for issuing book by title
void Library::issueBook(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            if (books[i].isIssued())
                cout << "Already issued\n";
            else
            {
                books[i].issue();
                cout << "Issued successfully\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}