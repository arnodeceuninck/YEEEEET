#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <fstream>
#include "src/mano.hpp"
using namespace std;  // since cin and cout are both in namespace std, this saves some text


void readInput(std::vector<Library*>& libraries, std::vector<Book*>& books);

/**
 * Redirects the cin >> var requests to a given file
 * @param filename The file to read the input from
 */
void loadFileInCin(const string& filename);

int main() {
    std::vector<bool> bools (5);

    // Leg de datastructuren hier vast
    std::vector<Library*> libraries;
    std::vector<Book*> books;

    // Lees de gegevens uit het inputbestand
    readInput(libraries, books);

    // Verwerk de gegevens

    // Schrijf de gegevens naar een outputbestand

    return 0;
}

void readInput(std::vector<Library*>& libraries, std::vector<Book*>& books) {

    // Load a filename to de cin buffer (comment these lines when you want to run the program like ./YEEEEEET < input.txt)
    std::ifstream in("datasets/a_example.txt");
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
    }
}

void loadFileInCin(const string& filename) {

}
