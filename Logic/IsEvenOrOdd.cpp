// IS number Odd or even
#include<iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter Num to check Wheather even or odd : ";
    cin>>num;
    if(num%2==0){
        cout<<"Num is even i.e. "<<num;
    } else {
        cout<<"Num is odd i.e. "<<num;
    }
    return 0;
}