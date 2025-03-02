#include <iostream>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
};

class Catalog {
private:
    unordered_map<string, string> isbnToLocation;

public:
    void addBookToCatalog(const string& isbn, const string& location) {
        isbnToLocation[isbn] = location;
        cout << "Book with ISBN " << isbn << " added to catalog at location " << location << "." << endl;
    }

    string findBookLocation(const string& isbn) const {
        auto it = isbnToLocation.find(isbn);
        if (it != isbnToLocation.end()) {
            return it->second;
        }
        return "Book not found in catalog.";
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;
    vector<shared_ptr<Book>> books;

public:
    Library(string name, string address)
        : name(name), address(address) {
        cout << "Library '" << name << "' created at " << address << "." << endl;
    }

    void addBook(shared_ptr<Book> book, const string& location) {
        books.push_back(book);
        catalog.addBookToCatalog(book->getISBN(), location);
    }

    void removeBook(const string& isbn) {
        auto it = remove_if(books.begin(), books.end(),
            [&isbn](const shared_ptr<Book>& book) {
                return book->getISBN() == isbn;
            });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book with ISBN " << isbn << " removed from the library." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in the library." << endl;
        }
    }

    string findBookInCatalog(const string& isbn) const {
        return catalog.findBookLocation(isbn);
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const auto& book : books) {
                cout << " - " << book->getTitle() << " by " << book->getAuthor()
                     << " (ISBN: " << book->getISBN() << ")" << endl;
            }
        }
    }
};

int main() {
    auto book1 = make_shared<Book>("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    auto book2 = make_shared<Book>("1984", "George Orwell", "9780451524935");
    auto book3 = make_shared<Book>("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    Library library("Central Library", "123 Main St");

    library.addBook(book1, "Fiction Section A1");
    library.addBook(book2, "Fiction Section B2");
    library.addBook(book3, "Fiction Section C3");

    library.listBooks();

    string isbnToSearch = "9780451524935";
    cout << "\nSearching for book with ISBN " << isbnToSearch << "..." << endl;
    string location = library.findBookInCatalog(isbnToSearch);
    cout << "Book location: " << location << endl;

    library.removeBook("9780743273565");
    library.listBooks();

    return 0;
}