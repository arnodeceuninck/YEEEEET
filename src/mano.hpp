#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <array>

struct Book
{
    int score;
    int id;
    bool isScanned;
};

struct Library
{
    std::vector<Book*> books;
    int time;
    int booksPerDay;
    Library(std::vector<Book*> books, int time, int booksPerDay):
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
        Library* best{};
        int lowest = std::numeric_limits<int>::max(); int index{};
        for (int i{};i<libraries.size();i++)
        {
            int temp = lowest;
            lowest = std::min(lowest, calculateScanningTime(libraries[i]));
            if (temp != lowest) best = libraries[i]; index = i;
        }
        queue.push(best);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}

std::queue<Library*> shortestSignupTimeFirst(std::vector<Library*> libraries)
{
    std::queue<Library*> queue;
    while (!libraries.empty())
    {
        Library* best{};
        int lowest = std::numeric_limits<int>::max(); int index{};
        for (int i{};i<libraries.size();i++)
        {
            int temp = lowest;
            lowest = std::min(lowest, libraries[i]->time);
            if (temp != lowest) best = libraries[i]; index = i;
        }
        queue.push(best);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}
