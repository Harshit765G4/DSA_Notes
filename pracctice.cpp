// #include<iostream>
// using namespace std;

// int main(){
//     int arr[]={3,2,3};
//     int k = 3;
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int nBykTimes = n/k; 
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == arr[i + 1]){
//             count++;
//         } else {
//             if(count >= nBykTimes){
//                 cout << arr[i] << " ";
//             }
//         }
//     }
//     cout<< count;  
// }






// // Majority element 2

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;

//         // Candidate Selection
//         for (int val : nums) {
//             if (val == cand1) {
//                 count1++;
//             } else if (val == cand2) {
//                 count2++;
//             } else if (count1 == 0) {
//                 cand1 = val;
//                 count1 = 1;
//             } else if (count2 == 0) {
//                 cand2 = val;
//                 count2 = 1;
//             } else {
//                 count1--;
//                 count2--;
//             }
//         }

//         // Validation
//         count1 = count2 = 0;
//         for (int val : nums) {
//             if (val == cand1) count1++;
//             else if (val == cand2) count2++;
//         }

//         vector<int> result;
//         if (count1 > n / 3) result.push_back(cand1);
//         if (count2 > n / 3) result.push_back(cand2);

//         return result;
//     }
// };
