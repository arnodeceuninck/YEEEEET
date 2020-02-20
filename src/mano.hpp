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


int calculateScore(Library* lib, int daysLeft)
{
    daysLeft -= lib->time;
    int score{0};
    for (int i=0; i < daysLeft*lib->booksPerDay; i++) score += lib->books[i]->score;
    return score;
}

