#include <iostream>
using namespace std;

int total_books;
int book_id[100];

void add_book(int book);
void delete_book(int book);
bool look(int book_code);
int count_books();

int main()
{

    // cscbbbhb
    int option, book, book_code;
    cout << "enter the number of books" << endl;
    cin >> total_books;
    cout << "hello github" << endl;
    cout << "enter the books ids" << endl;
    for (int i = 0; i < total_books; i++)
    {
        cin >> book_id[i];
    }
    cout << "enter an option" << endl;
    cout << "1.Add a book" << endl;
    cout << "2.Delete a book" << endl;
    cout << "3.Look up for a book" << endl;
    cout << "4.Count the total number of books" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "1.Add a book" << endl;
        break;
    case 2:
        cout << "2.Delete a book" << endl;
        break;
    case 3:
        cout << "3.Look up for a book" << endl;
        break;
    case 4:
        cout << "4.Count the total number of books" << endl;
        break;
    default:
        cout << "Enter a valid option" << endl;
    }
    if (option == 1)
    {
        cout << "Enter the number of books you would like to add:" << endl;
        cin >> book;
        add_book(book);
    }
    else if (option == 2)
    {
        cout << "enter the number of books you would like to delete:";
        cin >> book;
        delete_book(book);
    }
    else if (option == 3)
    {
        cout << "enter the code of the book that you would like to look up:";
        cin >> book_code;
        bool lookup = look(book_code);
        if (lookup == true)
        {
            cout << "the book exists" << endl;
        }
        else if (lookup == false)
        {
            cout << "the book does not exist" << endl;
        }
    }
    else if (option == 4)
    {
        int count = count_books();
        cout << total_books << endl;
    }
}
void add_book(int book)
{
    total_books = total_books + book;
    cout << "total number of books are:" << total_books << endl;
}
void delete_book(int book)
{
    total_books = total_books - book;
    cout << total_books << endl;
    cout << "total number of books are:" << total_books << endl;
}
bool look(int book_code)
{
    for (int i = 0; i < total_books; i++)
    {
        if (book_code == book_id[i])
        {
            return true;
        }
    }
    return false;
}
int count_books()
{
    return total_books;
}