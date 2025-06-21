#include<iostream>
using namespace std;

float calculateSimpleInterest(float principal,float rate,float time){
    return (principal*rate*time)/100;
} 

int main() {
    float principal, rate, time;

    cout<<"Enter Principal Amount : ";
    cin>>principal;

    cout<<"Enter Rate of Interest : ";
    cin>>rate;

    cout<<"Enter Time (in Years): ";
    cin>>time;

    float simpleInterest = calculateSimpleInterest(principal,rate,time);

    cout<<"Simple Interest Calcualted : "<< simpleInterest << endl;
    return 0;
}