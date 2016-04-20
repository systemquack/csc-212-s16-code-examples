//
//  main.cpp
//  Reading in Text 3
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
//  add any other needed include files..

int main(int argc, const char * argv[]) {

    // declare your data structure here
    
    std::ifstream infile(argv[1]);

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
            // at this point word contains a punctuation free lower case word
            //  from the text  (HINT: do something with it)
            //   (you may also want to check the word to make sure it has 
            //   some characters in it)
            //
        }
    }

    infile.close();
        
    return 0;
}
