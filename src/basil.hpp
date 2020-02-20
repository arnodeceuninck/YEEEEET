/**
 * @file basil.cpp
 * @author Basil Rommens
 * @date 2/20/20
 * @brief 
 */

#include "mano.hpp"

void output(std::string filename, std::vector<Library*>& libraries)
{
    std::ofstream outputFile(filename);

    outputNumberOfLibraries(filename, libraries);

    for (auto library: libraries) {
        // Mateo
        outputAmountOfBooks(filename, library);

        // Basil
        outputBookNumbers(filename, library);
    }
}

void outputNumberOfLibraries(std::ofstream& filename, std::vector<Library*>& libraries)
{
    outputFile << libraries.size() << std::endl;
}

void outputAmountOfBooks(std::ostream& outputFile, Library* library) {

}

void outputBookNumbers(std::ostream& outputFile, Library* library) {

}