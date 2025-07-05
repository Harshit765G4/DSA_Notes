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






// // Single Number

// int singleNumber(vector<int>& nums){
//    int sNum = 0;
//    for(int val: nums){
//       sNum ^= val;
//    }
//    return sNum;
// }
// int main(){
//    vector<int> nums={4,1,2,1,2};
//    cout<<"Single Number: "<<singleNumber(nums);
//    return 0;
// }






// // linear search using vector

// int linearSearchVector(vector<int>& arr, int target){
//    for (int i = 0; i < arr.size(); i++) {
//       if (arr[i] == target) {
//          return i;
//       }
//    }
//    return -1;
// }
// int main(){
//    vector<int> arr = {5,2,1,7,6,8,4};
//    int target = 8;
//    cout<<"Target found at Index: "<<linearSearchVector(arr,target);
//    return 0;
// }






// // Maximum subarray sum

// int main(){
//    int n=7;
//    int arr[]={3,-4,5,4,-1,7,-8};
//    int maxSum = INT_MIN;
//    for(int st=0;st<n;st++){
//       int currSum = 0;
//       for(int end=st;end<n;end++){
//          currSum += arr[end];
//          maxSum = max(currSum,maxSum);
//       }
//    }
//    cout<<"Maximum Subarray Sum: "<<maxSum;
// }






// // Optimal Approach of Max. SubArray Sum Using Kadane's Algorithm
// int main(){
//    int arr[] = {-3, -4, -5, -4 ,-1, -7, -8};
//    int currSum = 0;
//    int maxSum = INT_MIN;
//    int size = sizeof(arr) / sizeof(arr[0]);
//    for(int i=0;i<size;i++){
//       currSum += arr[i];
//       maxSum = max(currSum,maxSum);
//       if(currSum<0){
//          currSum = 0;
//       }
//    }
//    cout<<maxSum<<endl;
//    return 0;
// }









// // Pair Sum Question-Brute Force Approach

// vector<int> pairSum(vector<int>& nums, int target) {
//    vector<int> ans;
//    int sz = nums.size();

//    for (int i = 0; i < sz; i++) {
//       for (int j = i + 1; j < sz; j++) {
//          if (nums[i] + nums[j] == target) {
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//          }
//       }
//    }
//    ans.push_back(-1);
//    return ans;
// }


// // Prints the Value of the Pairs
// int main() {
//    vector<int> nums = {2, 7, 11, 15};
//    int target = 17;

//    vector<int> ans = pairSum(nums, target);
//    for (int idx : ans) {
//       if (idx == -1) {
//          cout << idx;
//       } else {
//          cout << nums[idx] << " ";
//       }
//    }
//    return 0;
// }


// // Prints the index of the Pair Sum Values
// int main() {
//    vector<int> nums = {2, 7, 11, 15};
//    int target = 17;

//    vector<int> ans = pairSum(nums, target);
//    cout<<"Index of the Pair Sum Values: "<<ans[0]<<", "<<ans[1]<<endl;
//    return 0;
// }





// // Optimized Approach of Piar Sum

// vector<int> pairSum(vector<int> nums,int target){
//    vector<int> ans;
//    int n=nums.size();

//    int i=0,j=n-1;
//    while(i<j){
//       int pairSum = nums[i] + nums[j];
//       if(pairSum>target){
//          j--;
//       } else if(pairSum<target){
//          i++;
//       } else{
//          ans.push_back(i);
//          ans.push_back(j);
//          return ans;
//       }
//    }
// }

// int main() {
//    vector<int> nums = {2, 7, 11, 15};
//    int target = 26;

//    vector<int> ans = pairSum(nums, target);
//    cout<<"Index of the Pair Sum Values: "<<ans[0]<<", "<<ans[1]<<endl;
//    return 0;
// }