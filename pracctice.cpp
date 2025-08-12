#include<iostream>
using namespace std;

int main(){
    int arr[]={3,1,2,2,1,2,3,3,4,5,4,4,6,6,6,4};
    int k = 8;
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