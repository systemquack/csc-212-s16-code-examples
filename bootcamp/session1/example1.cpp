// C++ BootCamp Example 1
// 2/4/2016

#include<iostream>
using namespace std;

int pow(int base, int exp);

int main(){
    int base, exp;
    cout<<"Enter a base\n";
    cin>>base;
    cout<<"What power shall we raise it to?\n";
    cin>>exp;
    cout<<"The result is: "<< pow(base,exp);

    return 0;
}

int pow(int base,int exp){
    int i, result = base;
    for(int i = 1;i < exp; i++){
        result = base*result;
    }
    return result;
}
