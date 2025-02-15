#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(string auth, string ttl, double prc, string pub, int stk)
        : author(auth), title(ttl), price(prc), publisher(pub), stock(stk) {}

    bool isAvailable(const string& reqTitle, const string& reqAuthor) const {
        return (title == reqTitle && author == reqAuthor);
    }

    void displayDetails() const {
        cout << "Title: " << title << ", Author: " << author
                  << ", Price: " << price << ", Publisher: " << publisher
                  << ", Stock: " << stock << endl;
    }

    void sellCopies(int requestedCopies) {
        if (requestedCopies <= stock) {
            stock -= requestedCopies;
            cout << "Total Cost: " << requestedCopies * price << endl;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    Book book("author1", "title1", 100, "publisher", 10);
    if (book.isAvailable("title1", "author1")) {
        book.displayDetails();
        book.sellCopies(5);
    } else {
        cout << "Book not available" << endl;
    }
    return 0;
}