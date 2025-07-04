#include<bits/stdc++.h>
#include<vector>
using namespace std;




// // Accessing elements of vector
// int main(){
//    vector<char> vec = {'a','b','c','d','e'};
//    for(char val : vec){    // for each to access vector
//       cout<<val<<endl;
//    }
//    return 0;
// }





// // Accessing elements of vector
// int main(){
//    vector<int> vec(5,0);
//    for(int val : vec){
//       cout<<val<<endl;
//    }
//    return 0;
// }




// // size of vector
// int main(){
//    vector<char> vec = {'a','b','c','d','e'};
//    cout<< "Size: " << vec.size();
// }




// Inserting and Removing an element in a vector
int main(){
   vector<int> vec;
   cout<< "Size: " << vec.size()<<endl;
   vec.push_back(25);
   vec.push_back(55);
   vec.push_back(75);
   cout<< "After Push_back: " << vec.size()<<endl;
   for(int val : vec){
      cout<<val<<endl;
   } 
   vec.pop_back();
   cout<< "After Pop_back: " << vec.size()<<endl;
   for(int val : vec){
      cout<<val<<endl;
   } 
   return 0;
}





