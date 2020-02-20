/**
 * @file basil.cpp
 * @author Basil Rommens
 * @date 2/20/20
 * @brief 
 */

#include "mano.hpp"
#include <iostream>
#include <fstream>

void outputNumberOfLibraries(std::ofstream& outputFile, std::vector<Library*>& libraries)
{
    outputFile << libraries.size() << std::endl;
}

void outputAmountOfBooks(std::ostream& outputFile, Library* library) {
    outputFile << std::to_string(library->ID);


}

void outputBookNumbers(std::ostream& outputFile, Library* library) {

}

void output(std::string filename, std::vector<Library*>& libraries)
{
    std::ofstream outputFile(filename);

    outputNumberOfLibraries(outputFile, libraries);

    for (auto library: libraries) {
        // Mateo
        outputAmountOfBooks(outputFile, library);

        // Basil
        outputBookNumbers(outputFile, library);
    }
}
