#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <array>

struct Book
{
    Book(int score, int ID) : score(score), ID(ID) {}

    int ID;
    int score;
    bool isScanned;
};

struct Library
{
    Library(int time, int booksPerDay, int ID) : time(time), booksPerDay(booksPerDay), ID(ID) {}

    void addBook(Book* book){
        books.push_back(book);
    }

    int ID;
    std::vector<Book*> books;
    int time;
    int booksPerDay;
    Library(std::vector<Book*> books, int time, int booksPerDay) :
    books(std::move(books)), time(time), booksPerDay(booksPerDay){};
};


int calculateScore(Library* lib)
{
    int amount{};
    for (auto book:lib->books) if (book->isScanned) amount++;
    (amount + lib->booksPerDay - 1) / lib->booksPerDay;  // upper rounding
}

