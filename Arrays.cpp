#include<iostream>
#include<climits>
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
//    for(int i=0;i<sizeof(arr);i++){
//       if(arr[i]<smallest){
//          smallest = arr[i];
//       }
//    }
//    cout<<smallest;
// }




// largest Element
int main(){
   int arr[] = {5,15,22,1,-15,24};
   int largest = INT_MIN;
   for(int i=0;i<sizeof(arr);i++){
      if(arr[i]>largest){
         largest = arr[i];
      }
   }
   cout<<largest;
}