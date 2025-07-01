#include<iostream>
using namespace std;

int fibonacci(int n){
   if(n<=0) return 0;
   if(n==1) return 1;

   int a = 0,b = 1, fib;

   for(int i=2;i<=n;i++){
      fib = a + b;
      a = b;
      b = fib;
   }
   return b;
}

int main(){
   int n;
   cout<<"Enter the nth Position: ";
   cin>>n;

   cout<<n<<"th fibonacci number is: "<<fibonacci(n)<<endl;

   return 0;
}