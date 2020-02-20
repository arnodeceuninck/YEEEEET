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
    int index{0};
    for (int i=0; i < daysLeft*lib->booksPerDay; i++)
    {
        while (lib->books[index]->isScanned)
        {
            if (index > lib->books.size()-1) return score;
            index++;
            if (index > lib->books.size()-1) return score;
        }
        score += lib->books[i]->score;
        index++;
    }
    return score;
}

std::queue<Library*> schedule(std::vector<Library*> libraries, int maxDays)
{
    std::queue<Library*> queue;
    std::vector<bool> bools (libraries.size());
    int daysPassed;

    while (!libraries.empty())
    {
        int lowest = std::numeric_limits<int>::max(); int index{};

        for (int i{};i<libraries.size();i++)
        {
            if (bools[i]) continue; // library already entered in queue
            int score = calculateScore(libraries[i], maxDays-daysPassed);
            if (lowest > score)
            {
                lowest = score;
                index = i;
            }
        }
        queue.push(libraries[index]);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}

std::queue<Library*> scheduleSomewhatSmart(std::vector<Library*> libraries, int maxDays)
{
    std::queue<Library*> queue;
    std::vector<bool> bools (libraries.size());
    int daysPassed;

    while (!libraries.empty())
    {
        int lowest = std::numeric_limits<int>::max(); int index{};

        for (int i{};i<libraries.size();i++)
        {
            if (bools[i]) continue; // library already entered in queue
            int score = calculateScore(libraries[i], maxDays-daysPassed);
            if (lowest > score)
            {
                lowest = score;
                index = i;
            }
        }
        queue.push(libraries[index]);
        libraries.erase(libraries.begin()+index);
    }
    return queue;
}