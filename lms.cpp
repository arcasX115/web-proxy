#include <iostream>
#include <algorithm>
using namespace std;

int total_books;
int total_books_ids[100];
int book_id[100];

void add_book(int book, int *new_books_id);
void delete_book(int book, int *delete_book_id);
bool look(int book_code);
int count_books();
void file(char *x);

int main()
{
    int option, book, book_code, new_books_id[100], delete_book_id[100];
    cout << "enter the number of books" << endl;
    cin >> total_books;
    cout << "enter the books ids" << endl;
    for (int i = 0; i < total_books; i++)
    {
        cin >> book_id[i];
    }
    for (int i = 0; i < 100; i++)
    {
        total_books_ids[i] = book_id[i];
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
        cout << "Enter the code of the new book:" << endl;
        for (int i = 0; i < book; i++)
        {
            cin >> new_books_id[i];
        }
        add_book(book, new_books_id);
    }
    else if (option == 2)
    {
        cout << "enter the number of books you would like to delete:";
        cin >> book;
        cout << "Enter the code of the book you would like to delete" << endl;
        for (int i = 0; i < book; i++)
        {
            cin >> delete_book_id[i];
        }
        delete_book(book, delete_book_id);
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
void add_book(int book, int *new_books_id)
{
    total_books = total_books + book;
    cout << "total number of books are:" << total_books << endl;
    cout << "The books ids are:" << endl;
    for (int j = 0; j < book; j++)
    {
        total_books_ids[j + (total_books - book)] = new_books_id[j];
    }
    for (int k = 0; k < total_books; k++)
    {
        cout << total_books_ids[k] << endl;
    }
}
void delete_book(int book, int *delete_book_id)
{
    total_books = total_books - book;
    cout << "total number of books are:" << total_books << endl;
    cout << "The book ids are" << endl;
    for (int i = 0; i < total_books; i++)
    {
        if (total_books_ids[i] == delete_book_id[i])
        {
            total_books_ids[i] = total_books_ids[i + 1];
        }
        else
        {
            total_books_ids[i] = total_books_ids[i];
        }
    }
    for (int k = 0; k < total_books; k++)
    {
        cout << total_books_ids[k] << endl;
    }
}
bool look(int book_code)
{
    for (int i = 0; i < total_books; i++)
    {
        if (book_code == total_books_ids[i])
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
void file(char *x)
{
    FILE *librecords;

    librecords = fopen("library.txt", "w");

    if (librecords != NULL)
    {
        fputs(x, librecords);
        fclose(librecords);
    }
}