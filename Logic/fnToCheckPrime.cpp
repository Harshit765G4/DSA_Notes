#include<iostream>
using namespace std;

int primeCheck(int num){
   int isPrime=true;
   if(num<=1){
      isPrime=false;
   } else {
      for(int i = 2; i * i <= num; i++){
         if(num%i==0){
            isPrime=false;
         }
      }
   }
   if(isPrime){
      cout<<"It is a Prime No.";
   } else {
      cout<<"It is not a Prime No.";
   }
}

int main(){
   int num;
   cout<<"Enter The Number: ";
   cin>>num;
   primeCheck(num);
}