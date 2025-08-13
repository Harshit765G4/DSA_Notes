#include<iostream>
using namespace std;

int main(){
    int arr[]={3,2,3};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int nBykTimes = n/k; 
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[i + 1]){
            count++;
        } else {
            if(count >= nBykTimes){
                cout << arr[i] << " ";
            }
        }
    }
    cout<< count;  
}