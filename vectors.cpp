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




// // Inserting and Removing an element in a vector
// // also accessing front and back values
// int main(){
//    vector<int> vec;
//    cout<< "Size: " << vec.size()<<endl;
//    vec.push_back(25);
//    vec.push_back(55);
//    vec.push_back(75);
//    cout<< "After Push_back: " << vec.size()<<endl;
//    for(int val : vec){
//       cout<<val<<endl;
//    } 
//    vec.pop_back();
//    cout<< "After Pop_back: " << vec.size()<<endl;
//    for(int val : vec){
//       cout<<val<<endl;
//    } 
//    cout<<endl;
//    cout<<endl;
//    cout<<"Front value: "<<vec.front()<<endl;
//    cout<<"Back Value: "<<vec.back()<<endl;
//    cout<<"Accessing at Index 1: "<<vec[1];
//    return 0;
// }





// // size and capacity

// int main(){
//    vector<int> vec;
//    vec.push_back(5);
//    vec.push_back(15);
//    vec.push_back(25);
//    cout<<"Size: "<<vec.size()<<endl;
//    cout<<"Capacity: "<<vec.capacity()<<endl;
// }






// Single Number

int singleNumber(vector<int>& nums){
   int sNum = 0;
   for(int val: nums){
      sNum ^= val;
   }
   return sNum;
}
int main(){
   vector<int> nums={4,1,2,1,2};
   cout<<"Single Number: "<<singleNumber(nums);
   return 0;
}