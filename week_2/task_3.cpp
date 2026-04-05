#include <iostream>
#include <string>
using namespace std;

template <typename T>
int linearSearch(T arr[], int size, string key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

class Item
{
public:
    virtual void display() = 0;
};

class Book : public Item
{
public:
    string title;
    string author;
    int pages;

    Book() {}
    Book(string t, string a, int p){
        title = t;
        author = a;
        pages = p;
    }

    void display(){
        cout << "Book:" << title << "|" << author << "|" << pages << "pages" << endl;
    }
    bool operator==(string key){
        return title == key;
    }
};
class Newspaper : public Item
{
public:
    string name;
    string date;
    string edition;

    Newspaper() {}
    Newspaper(string n, string d, string e){
        name = n;
        date = d;
        edition = e;
    }
    void display(){
        cout << "Newspaper:" << name << "|" << date << "|" << edition << endl;
    }
    bool operator==(string key){
        return name == key;
    }
};
class Library
{
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newsCount = 0;

public:
    void addBook(Book b){
        books[bookCount] = b;
        bookCount++;
    }
    void addNewspaper(Newspaper n){
        newspapers[newsCount] = n;
        newsCount++;
    }
    void displayCollection(){
        cout << "\nBooks: " << endl;
        for (int i = 0; i < bookCount; i++)
            books[i].display();

        cout << "\nNewspapers: " << endl;
        for (int i = 0; i < newsCount; i++)
            newspapers[i].display();
    }
    void sortBooksByPages(){
        for (int i = 0; i < bookCount - 1; i++){
            for (int j = i + 1; j < bookCount; j++){
                if (books[i].pages > books[j].pages){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    void sortNewspapersByEdition(){
        for (int i = 0; i < newsCount - 1; i++){
            for (int j = i + 1; j < newsCount; j++){
                if (newspapers[i].edition > newspapers[j].edition){
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }
    Book* searchBookByTitle(string title){
        int index = linearSearch(books, bookCount, title);

        if (index != -1) {
            return &books[index];
        }
        else {
            return NULL;
        }
    }
    Newspaper* searchNewspaperByName(string name){
        int index = linearSearch(newspapers, newsCount, name);

        if (index != -1) {
            return &newspapers[index];
        }
        else {
            return NULL;
        }
    }
};
int main()
{
    Book book1("To Kill a Mockingbird", "Harper Lee", 324);
    Book book2("The Catcher in the Rye", "J.D. Salinger", 277);

    Newspaper newspaper1("The Times", "2024-10-12", "Weekend Edition");
    Newspaper newspaper2("Washington Post", "2024-10-13", "Morning Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "before Sorting: " << endl;
    library.displayCollection();
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "after Sorting: " << endl;
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("To Kill a Mockingbird");
    if (foundBook){
        cout << "\nFound Book: " << endl;
        foundBook->display();
    }
    else{
        cout << "\nBook not found...!" << endl;
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("Washington Post");
    if (foundNewspaper){
        cout << "\nFound Newspaper: " << endl;
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found...!" << endl;
    }
    return 0;
}