#include<iostream>
using namespace std;

unsigned long long calculateFactorial(int n) {
    unsigned long long fact = 1;
    for(int i = 1 ; i <= n ; ++i ) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N;
    cout << "Enter a Number : ";
    cin>>N;

    if ( N < 0 ) {
        cout << "Factorial of a Number is Not defined a Negative Number";
    } else {
        unsigned long long result = calculateFactorial(N);
        cout << "Factorial of " << N << " is " << result << endl;  
    }
    return 0;
}