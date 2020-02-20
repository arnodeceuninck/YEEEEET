#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <array>
#include <list>


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
    if (daysLeft < lib->time) return std::numeric_limits<int>::min();

    daysLeft -= lib->time;
    int score{0};
    int index{0};
    for (int i=0; i < daysLeft*lib->booksPerDay; i++)
    {
        if (index > lib->books.size()-1) return score;
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

void schedule(std::vector<Library*> libraries, int maxDays, std::string filename)
{
    std::ofstream outputFile(filename);
    std::vector<std::pair<Library*, int>> queue;
    std::vector<bool> bools (libraries.size());
    for (int i{};i<bools.size();i++) bools[i] = false;

    int daysPassed{0};

    while (true)
    {
        int highest  = std::numeric_limits<int>::min(); int index{};

        for (int i{};i<libraries.size();i++)
        {
            if (bools[i] or libraries[i]->books.empty()) continue; // library already entered in queue
            int score = calculateScore(libraries[i], maxDays-daysPassed);
            if (highest < score)
            {
                highest = score;
                index = i;
            }
        }
        daysPassed+=libraries[index]->time;
        if (daysPassed>maxDays) break;
        queue.emplace_back(std::make_pair(libraries[index], ((maxDays-daysPassed-libraries[index]->time) * libraries[index]->booksPerDay)));
        bools[index]=true;
    }

    outputFile << queue.size()-1 << "\n";
    
    for (int i = 0;i<queue.size()-1;i++)
    {
        outputFile << queue[i].first->ID << " " << queue[i].second << "\n";
        int index = 0;
        for (int j=0;j<queue[i].second;j++)
        {
            while (queue[i].first->books[index]->isScanned)
            {
                index++;
            }
            outputFile << queue[i].first->books[index]->ID << " ";
            index++;
        }
        outputFile << "\n";
    }
    outputFile.close();
}

