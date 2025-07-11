#include<bits/stdc++.h>
using namespace std;


// // Memory Address
// int main(){
//    int a = 10;
//    cout<< &a << endl;
//    return 0;
// }


// // pointers
// int main(){
//    int x = 10;
//    int* ptr = &x;
//    cout<< ptr << endl;
//    cout<< &x << endl;
//    cout<< &ptr << endl;


//    // stores the adress of another pointer
//    int** ptr2 = &ptr;
//    cout << ptr2 << endl;
//    return 0;
// }





// // dereferencing operator
// int main(){
//    int x = 10;
//    int* ptr = &x;
//    cout<< *ptr << endl;
//    return 0;
// }



// // Null Pointer
// int main(){
//    int* ptr = nullptr;
//    return 0;
// }






// // pass by reference
// void swap(int &x, int &y) {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 10, b = 20;
//     swap(a, b);
//     cout << a << " " << b;  // Output: 20 10
// }






// // Array pointer
// int main(){
//    int arr[5] = {10, 20, 30, 40, 50};

//    cout << *arr << endl;     // 10
//    cout << *(arr+1); // 20

// }



// // Pointer Arithmetic
// int main(){
//    int arr[] = {1,2,3,4,5};

//    int a = 10;
//    int *ptr  = &a;

//    cout << ptr << endl;
//    ptr = ptr + 2;
//    cout << ptr << endl;

//    return 0;
// }





int main(){
   int arr[] = {10,20,30,40};
   int *ptr = arr;

   cout << *ptr <<endl;
   cout << *(ptr + 1) << endl;
   cout << *(ptr + 3) << endl;
   ptr++;
   cout<< *ptr << endl;
   return 0;
}