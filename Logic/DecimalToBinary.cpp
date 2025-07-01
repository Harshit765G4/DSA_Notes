#include<iostream>
using namespace std;

double Dec2Bin(int num){
    double ans = 0;
    int pow = 1;
    while(num > 0){
        int rem = num % 2;
        num = num / 2;
        ans += (rem*pow);
        pow = pow * 10;
    }
    return ans;
}
int main(){
    int num;
    cout<<"Enter num: ";
    cin>>num;
    cout<<Dec2Bin(num);
}