/**
 * @file basil.cpp
 * @author Basil Rommens
 * @date 2/20/20
 * @brief 
 */

#include "mano.hpp"
#include <iostream>

void output(std::string filename, std::vector<Library*> libraries) {
    std::ifstream outputFile(filename);

    // number of libraries
    outputFile << libraries.size();
    outputFile <<
}