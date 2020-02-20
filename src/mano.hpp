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


int calculateScanningTime(Library* lib)
{
    int amount{};
    for (auto book:lib->books) if (book->isScanned) amount++;
    return (amount + lib->booksPerDay - 1) / lib->booksPerDay;  // upper rounding
}

std::queue<Library*> scheduleLongestBookScanningTime(std::vector<Library*> libraries)
{
    std::queue<Library*> queue;
    std::vector<bool> bools (libraries.size());

    while (!libraries.empty())
    {
        int lowest = std::numeric_limits<int>::max(); int index{};

        for (int i{};i<libraries.size();i++)
        {
            if (bools[i]) continue; // book already entered in queue
            int time = calculateScanningTime(libraries[i]);
            if (lowest > time)
            {
                lowest = time;
                index = i;
            }
        }
        queue.push(libraries[index]);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}

std::queue<Library*> shortestSignupTimeFirst(std::vector<Library*> libraries)
{
    std::queue<Library*> queue;
    std::vector<bool> bools (libraries.size());

    while (!libraries.empty())
    {
        int lowest = std::numeric_limits<int>::max(); int index{};

        for (int i{};i<libraries.size();i++)
        {
            if (bools[i]) continue; // book already entered in queue
            if (lowest > libraries[i]->time)
            {
                lowest = libraries[i]->time;
                index = i;
            }
        }
        queue.push(libraries[index]);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}
