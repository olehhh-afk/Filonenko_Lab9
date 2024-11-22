#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    int year;
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string isbn, int year) {
        Book book;
        book.title = title;
        book.author = author;
        book.isbn = isbn;
        book.year = year;
        books.push_back(book);
    }

    void removeBookByISBN(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    void searchByAuthor(string author) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].author == author) {
                cout << books[i].title << " (" << books[i].year << ")\n";
            }
        }
    }

    void listBooks() {
        for (int i = 0; i < books.size(); i++) {
            cout << books[i].title << " by " << books[i].author 
                 << " (" << books[i].year << "), ISBN: " << books[i].isbn << "\n";
        }
    }

    void searchByYearRange(int startYear, int endYear) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].year >= startYear && books[i].year <= endYear) {
                cout << books[i].title << " (" << books[i].year << ")\n";
            }
        }
    }
};

int main() {
    Library library;
    library.addBook("Book1", "Author1", "12345", 2001);
    library.addBook("Book2", "Author2", "67890", 2015);

    cout << "All books:\n";
    library.listBooks();

    cout << "\nBooks by Author1:\n";
    library.searchByAuthor("Author1");

    cout << "\nBooks from 2000 to 2010:\n";
    library.searchByYearRange(2000, 2010);

    library.removeBookByISBN("12345");

    cout << "\nAfter removal:\n";
    library.listBooks();

    return 0;
}
