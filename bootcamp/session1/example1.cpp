// C++ BootCamp Example 1
// 2/4/2016

#include<iostream>
using namespace std;

int powLoop(int base, int exp);
int powRecur(int base, int exp);

int main(){
    int base, exp;

    cout<<"Enter a base\n";
    cin>>base;

    cout<<"What power shall we raise it to?\n";
    cin>>exp;

    cout<<"The result with a loop is: "<< powLoop(base,exp) << endl;

    cout<<"The result with recursion is: "<< powRecur(base,exp) << endl;

    return 0;
}

int powLoop(int base,int exp){
    if(exp) {
        int result = base;
        for(int i = 1;i < exp; i++){
            result = base*result;
        }
        return result;
    }

    return 1;
}

int powRecur(int base,int exp){
    if(exp) {
        return base * powRecur(base,exp - 1);
    }

    return 1;
}
