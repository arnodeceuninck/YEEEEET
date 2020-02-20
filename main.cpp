#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <fstream>
#include "src/mano.hpp"
using namespace std;  // since cin and cout are both in namespace std, this saves some text


void readInput();

/**
 * Redirects the cin >> var requests to a given file
 * @param filename The file to read the input from
 */
void loadFileInCin(const string& filename);

int main() {
    // Leg de datastructuren hier vast

    // Lees de gegevens uit het inputbestand
    readInput();

    // Verwerk de gegevens

    // Schrijf de gegevens naar een outputbestand

    return 0;
}

void readInput() {

    // Load a filename to de cin buffer (comment these lines when you want to run the program like ./YEEEEEET < input.txt)
    loadFileInCin("filename.txt");

    int t, n, m;

    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;  // read n and then m.
        cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
    }
}

void loadFileInCin(const string& filename) {
    std::ifstream in(filename);
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
}
