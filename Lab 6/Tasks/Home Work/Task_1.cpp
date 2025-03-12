#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}
    virtual void display() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n" << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n" << endl;
    }
};

int main() {
    Novel novel1("Title1", "Author1");
    Mystery mystery1("Title2", "Author2");
    
    novel1.display();
    mystery1.display();
    
    return 0;
}