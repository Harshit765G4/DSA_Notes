#include<bits/stdc++.h>
using namespace std;


// // output array
// int main(){
//     int marks[5] = {50,65,84,75,69};
//     for(int i = 0;i<5;i++){
//       cout<<marks[i]<<endl;
//     }
//     cout<<"MarksSize: "<<sizeof(marks)/sizeof(int);
// }




// // input array
// int main(){
//    int size = 5;
//    int marks[size];
//    cout<<"Enter Marks: ";

//    // input array 
//    for(int i = 0; i<size; i++){
//       cin>>marks[i];
//    }
//    for(int i = 0; i<size; i++){
//       cout<<"Marks: "<<marks[i]<<endl;
//    }
// }





// // Smallest element
// int main(){
//    int arr[] = {5,15,22,1,-15,24};
//    int smallest = INT_MAX;
//    int n = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0; i<n; i++){
//       if(arr[i]<smallest){
//          smallest = arr[i];
//       }
//    }
//    cout<<smallest;
// }




// // largest Element
// int main(){
//    int arr[] = {5,15,22,1,-15,24};
//    int largest = INT_MIN;
//    int n = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0; i<n; i++){
//       if(arr[i] > largest){
//          largest = arr[i];
//       }
//    }
//    cout << largest;
// }




// // Sum of elements of an array
// int main(){
//    int size = 5, sum = 0;
//    int arr[size] = {45,75,86,94,27};
//    for(int i = 0; i < size; i++){
//       sum = sum + arr[i];
//    }
//    cout<<sum<<endl;
//    return 0;
// }






// // Other Way to find smallest and largest usin min , max function

// int main(){
//    int arr[] = {5,15,22,1,-15,24};
//    int largest = INT_MIN;
//    int smallest = INT_MAX;
//    int n = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0; i<n; i++){
//       largest = max(arr[i],largest);
//       smallest = min(arr[i],smallest);
//    }
//    cout<<"Largest: "<<largest<<endl;
//    cout<<"Smallest: "<<smallest<<endl;
// }






// // Index of Largest Element
// int main(){
//    int arr[] = {2, 5, 8, 3, 45, 12};
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int largestIndex = 0;
//    for(int i = 1; i < size; i++){
//       if(arr[i] > arr[largestIndex]){
//          largestIndex = i;
//       }
//    }
//    cout << "Index of Largest Element: " << largestIndex;
// }







// // Index of Smallest Element
// int main(){
//    int arr[] = {2, 5, 8, 1, 45, -12};
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int smallestIndex = 0;
//    for(int i = 1; i < size; i++){
//       if(arr[i] < arr[smallestIndex]){
//          smallestIndex = i;
//       }
//    }
//    cout << "Index of Smallest Element: " << smallestIndex<<endl;
// }






// // Change array elements and Demonstration of pass by reference
// void  changeArray(int arr[],int size){
//    for(int i = 0; i<size; i++){
//       arr[i] = 2*arr[i];
//    }
// }
// int main(){
//    int arr[] = {1,2,3};

//    changeArray(arr,3);

//    for(int i = 0 ; i < 3 ; i++){
//       cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    return 0;
// }







// // Linear search

// int linearSearch(int arr[],int size,int target){
//    for(int i = 0; i < size; i++){
//       if(arr[i]==target){
//          return i;
//       }
//    }
//    return -1;
// }
// int main(){
//    int arr[] = {4,2,7,8,1,2,5};
//    int size = 7;
//    int target = 5;
//    cout << "Target Found at: " << linearSearch(arr,size,target);

//    return 0;
// }







// Reverse an array
void reverseArray(int arr[], int start, int end) {
   while(start < end) {
      swap(arr[start], arr[end]);
      start++;
      end--;
   }
}
int main() {
   int arr[] = {4,2,7,8,1,2,5};
   int start = 0;
   int size = sizeof(arr)/sizeof(arr[0]);
   int end = size - 1;
   reverseArray(arr, start, end);
   for(int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}








