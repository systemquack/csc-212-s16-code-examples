//URI C++ Boot Camp Session 1
//Example 2

#include <iostream>
using namespace std;

int main(){
    int number, reversed = 0;
    cout<<"What number should we reverse?\n";
    cin>>number;
    while(number != 0){
        reversed *= 10;
        reversed += number%10;
        number /= 10;
    }
    cout<<"The result is...... "<<reversed;
    return 0;
}
