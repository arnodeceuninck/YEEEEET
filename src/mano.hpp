#include <vector>


struct Book
{
    int score;
};

struct Library
{
    std::vector<Book> books;
    int time;
    int booksPerDay;
    Library(std::vector<Book> books, int time, int booksPerDay):
    books(std::move(books)), time(time), booksPerDay(booksPerDay){};
};

void solution()
{

}
