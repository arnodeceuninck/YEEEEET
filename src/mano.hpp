#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <array>
#include <algorithm>

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

    int calculateScoreArno() const {
        int score{0};
        for(auto book: books){
            if(!book->isScanned){
                score += book->score;
            }
        }
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
            int time; // = calculateScanningTime(libraries[i]);
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
