/**
 * @file basil.cpp
 * @author Basil Rommens
 * @date 2/20/20
 * @brief 
 */

#include <iostream>
#include <fstream>
#include "mano.hpp"

void outputNumberOfLibraries(std::ofstream& outputFile, std::queue<Library*>& libraries)
{
    outputFile << libraries.size() << std::endl;
}

void outputAmountOfBooks(std::ostream& outputFile, Library* library) {
    outputFile << std::to_string(library->ID);
    int scannedAmount = 0;
    for (auto book: library->books) {
        if (book->isScanned) {
            scannedAmount++;
        }
    }
    outputFile << " " << std::to_string(scannedAmount) << std::endl;
}

void outputBookNumbers(std::ostream& outputFile, Library* library) {
    int bookId = 0;
    for (auto book: library->books) {
        if (book->isScanned) {
            outputFile << std::to_string(++bookId) << " ";
        }
    }
    outputFile << std::endl;
}

void output(std::string filename, std::queue<Library*> libraries)
{
    std::ofstream outputFile(filename);

    outputNumberOfLibraries(outputFile, libraries);

    int amountOfLibraries = libraries.size();
    for (int element = 0; element<amountOfLibraries; ++element) {
        // Mateo
        outputAmountOfBooks(outputFile, libraries.front());
        libraries.pop();

        // Basil
        outputBookNumbers(outputFile, libraries.front());
        libraries.pop();
    }
}

