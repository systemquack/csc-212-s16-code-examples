#include <iostream>

using namespace std;

//Function Prototype
void arrayPrint(char[], int size);

int main() {

    int intArray[10];
    
    //Why choose this number?
    intArray[0]=1094861636;
    int size = 4;
    
    arrayPrint((char*)intArray, size);

    return 0;
}
//What does this function do and why?
//Note that size was passed with the array
void arrayPrint(char charray[], int size) {

    for (int i = 0; i < size; i++)
        cout<<charray[i]<<endl;

}
