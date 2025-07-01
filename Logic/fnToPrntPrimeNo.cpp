#include<iostream>
using namespace std;

bool isPrime(int num){
   if(num<=1){
      return false;
   } else {
      for(int i = 2; i * i <= num; i++){
         if(num%i==0){
            return false;
         }
      }
   }
   return true;
}

void printPrime(int num){
   cout<<"Prime No. from 1 to "<<num<<" are: ";
   for(int i = 1;i<=num;i++){
      if(isPrime(i)){
         cout<<i<<" ";
      }
   }
   cout<<endl;
}

int main(){
   int num;
   cout<<"Enter the value of num: ";
   cin>>num;

   printPrime(num);

   return 0;
}