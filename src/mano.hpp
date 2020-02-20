#include <vector>
#include <queue>

struct Book
{
    int score;
    bool isScanned;
};

struct Library
{
    std::vector<Book> books;
    int time;
    int booksPerDay;
    Library(std::vector<Book> books, int time, int booksPerDay):
    books(std::move(books)), time(time), booksPerDay(booksPerDay){};
};


int calculateSignupTime(Library* lib)
{
    int amount;
    for (auto book:lib->books) if (book.isScanned) amount++;
}

void schedule(const std::vector<Library*> &libraries)
{
    std::queue<Library*> queue;

}

