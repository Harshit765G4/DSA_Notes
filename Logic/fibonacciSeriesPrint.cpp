#include<iostream>
using namespace std;

void printFibonacci(int n){
    if(n <= 0) return;

    int a = 0, b = 1;

    for(int i = 0; i < n; i++){
        cout << a << " ";
        int fib = a + b;
        a = b;
        b = fib;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Series: ";
    printFibonacci(n);

    return 0;
}