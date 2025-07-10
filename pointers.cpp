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






// pass by reference
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;
    swap(a, b);
    cout << a << " " << b;  // Output: 20 10
}
