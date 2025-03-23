#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub)
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "\nTitle: " << title << "\nPublication Date: " << publicationDate << "\nID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    double duration;
    string rating;
public:
    DVD(string t, string pDate, string id, string pub, string d, double dur, string r)
        : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
    }
};

int main() {
    Book book1("C++ Programming", "2022", "B101", "O'Reilly", "Bjarne Stroustrup", "123456", 350);
    DVD dvd1("Inception", "2010", "D201", "Warner Bros", "Christopher Nolan", 148, "PG-13");

    cout << "\nBook Information:";
    book1.displayInfo();

    cout << "\nDVD Information:";
    dvd1.displayInfo();

    return 0;
}
