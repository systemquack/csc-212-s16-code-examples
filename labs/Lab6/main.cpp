//
//  main.cpp
//  Reading in Text
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


int main(int argc, const char * argv[]) {
    
    
    std::ifstream infile(“FILENAME-TO-READ-IN”);
    
    std::string line;
    std::string word;
    
    while(std::getline(infile, line))
    {
        std::istringstream iss(line);
        while(iss >> word)
        {
            word.erase(std::remove_if (word.begin(), word.end(), ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            //
            // at this point word contains an all lower-case, punctuation free word from the file
            // 
        }
    }
    
    infile.close();
    
    
    return 0;
}
