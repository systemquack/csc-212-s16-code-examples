//
//  main.cpp
//  Testing Binary Trees
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "bst.h"

int main(int argc, const char * argv[]) {

    // create a tree for your use
    BSTree dictionaryTree;  // or
    BSTree classicTextTree;
    
    //std::ifstream infile("Test.txt");
    
    std::string line;
    std::string word;
    
    while(std::getline(infile, line))
    {
        std::istringstream iss(line);
        while(iss >> word)
        {
            word.erase(std::remove_if (word.begin(), word.end(), ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

//            dictionaryTree.insert(word);  // insert this word into the dictionary
        }
    }
    

    // Now, how would you look up each word?
    
    
    //  ...
    
    
    return 0;
}
