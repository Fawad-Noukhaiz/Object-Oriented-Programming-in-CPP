/*Task - 05: Create a class called Book to represent a book. A Book should include four pieces of information as instance variables‐a book name, an ISBN number, an author name and a publisher. Provide methods (query method) for each instance variable. Inaddition, provide a method named getBookInfo that returns the description of the book as a String (the description should include all the information about the book). You should use this keyword in member methods and constructor. Write a test application named BookTest to create an array of object for 5 elements for class Book to demonstrate the class Book's capabilities.*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string author;
    string publisher;

public:
    Book(string name, string isbn, string auth, string pub)
        : bookName(name), ISBN(isbn), author(auth), publisher(pub) {}

    string getBookInfo() {
        return "Book: " + bookName + "\nISBN: " + ISBN + "\nAuthor: " + author + "\nPublisher: " + publisher;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 21) {
        cout << "Usage: <program> <book1_name> <isbn1> <author1> <publisher1> ... <book5_name> <isbn5> <author5> <publisher5>" << endl;
        return 1;
    }

    Book books[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    for (int i = 0; i < 5; i++) {
        cout << books[i].getBookInfo() << endl << endl;
    }

    return 0;
}
