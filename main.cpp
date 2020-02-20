#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <fstream>
#include <algorithm>
#include "src/mano.hpp"
using namespace std;  // since cin and cout are both in namespace std, this saves some text


void readInput(std::vector<Library*>& libraries, std::vector<Book*>& books, const int &index);

/**
 * Redirects the cin >> var requests to a given file
 * @param filename The file to read the input from
 */
void loadFileInCin(const string& filename);

int main() {
    // Leg de datastructuren hier vast
    std::vector<Library*> libraries;
    std::vector<Book*> books;

    // Lees de gegevens uit het inputbestand
    readInput(libraries, books, 0);

    // Verwerk de gegevens
    auto a = 0;
    // Schrijf de gegevens naar een outputbestand

    return 0;
}

void readInput(std::vector<Library*>& libraries, std::vector<Book*>& books, const int &index) {

    vector<string> possibleFiles = {"datasets/a_example.txt", "datasets/b_read_on.txt", "datasets/c_incunabula.txt", "datasets/d_tough_choices.txt", "datasets/e_so_many_books.txt", "datasets/f_libraries_of_the_world.txt"};
    // Load a filename to de cin buffer (comment these lines when you want to run the program like ./YEEEEEET < input.txt)
    std::ifstream in(possibleFiles[index]);
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    int numBooks, numLibraries, numDays;

    cin >> numBooks >> numLibraries >> numDays;  // read t. cin knows that t is an int, so it reads it as such.

    // Read variable number of input from one line
    // src: https://stackoverflow.com/questions/26270724/input-unknown-number-of-variables-in-one-linein-c
    int bookScore;
    int idCount{0};
    while (numBooks--) {
        if (std::cin >> bookScore) {
            books.push_back(new Book(bookScore, idCount++));
        } else {
            throw std::runtime_error("numBooks is larger than the number of books");
        }
    }

    int booksInLibrary;
    int signupTime;
    int scanPerDay;
    idCount = 0;
    while (numLibraries--) {
        std::cin >> booksInLibrary >> signupTime >> scanPerDay;
        Library* library = new Library(signupTime, scanPerDay, idCount++);
        libraries.push_back(library);

        int bookID;
        while (booksInLibrary--) {
            if(std::cin >> bookID) {
                library->addBook(books[bookID]);
            } else {
                throw std::runtime_error("numLibraries is larger than the number of libraries");
            }
        }

        std::sort(library->books.begin(), library->books.end(),
                [](Book* a, Book* b) {return a->score > b->score;});
    }
}

void loadFileInCin(const string& filename) {

}
