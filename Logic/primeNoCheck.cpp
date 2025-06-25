#include<iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;
    cout<<"Enter the number to check wheather it is prime or not : ";
    cin>>num;

    if( num <= 1 ){
        isPrime = false;
    } else {
        for(int i = 2; i * i <= num; i++){
            if( num % i == 0){
                isPrime = false;
            }
        }
    }

    if(isPrime){
        cout<<"It is a Prime No.";
    } else {
        cout<<"It is Not a Prime No.";
    }
    return 0;
}