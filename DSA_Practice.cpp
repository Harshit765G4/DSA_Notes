#include<iostream>
using namespace std;



// // printing a message to the console
// int main() {
//     cout << "Restart" << endl;
//     return 0;
// }



// // sum of two numbers
// int main() {
//     int a,b;
//     cout<<"enter two number"<<endl;
//     cin>>a>>b;
//     cout<<"sum of two numbers are: "<< a+b << endl;
//     return 0;
// }



// // Area of Square
// int main() {
//     int a;
//     cout<<"enter side of the square : ";
//     cin>>a;
//     cout<<"Area of square : "<< a*a <<endl;
//     return 0;
// }




// // Minimum of two Numbers
// int main() {
//     int a,b;
//     cout<<"Enter two Numbers: ";
//     cin>>a>>b;
//     if(a<b){
//         cout<<"a is minimum i.e. "<<a<<endl;
//     }else{
//         cout<<"b is minimum i.e. "<<b<<endl;
//     }
//     return 0;
// }




// // IS number Odd or even
// int main() {
//     int num;
//     cout<<"Enter Num to check Wheather even or odd : ";
//     cin>>num;
//     if(num%2==0){
//         cout<<"Num is even i.e. "<<num;
//     } else {
//         cout<<"Num is odd i.e. "<<num;
//     }
//     return 0;
// }





// // Sum of numbers from 1 to n
// int main() {
//     int n,sum = 0;
//     cout<<"Enter the Number: ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         sum = sum + i;
//     }
//     cout<<"sum of 1 to "<<n<<" is : "<<sum<<endl;
//     return 0;
// }




// // Check if a number is prime
// int main() {
//     int num;
//     bool isPrime = true;
//     cout<<"Enter the Number To Check Whether Prime or Not : ";
//     cin>>num;
//     if(num <= 1){
//         isPrime = false;
//     } else {
//         for(int i = 2; i * i <= num; i++){
//             if (num % i == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
//     }
//     if(isPrime){
//         cout<<"Prime"<<endl;
//     } else {
//         cout<<"Not Prime"<<endl;
//     }
//     return 0;
// }




// int main() {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;

//     if (n <= 1) {
//         cout << "Non Prime";
//         return 0;
//     }

//     int i = 2;
//     while (i <= n - 1) {
//         if (n % i == 0) {
//             cout << "Non Prime";
//             break;
//         }
//         i++;
//     }

//     if (i == n) {
//         cout << "Prime";
//     }

//     return 0;
// }







// // Calculate Simple Interest
// float calculateSimpleInterest(float principal,float rate,float time){
//     return (principal*rate*time)/100;
// } 

// int main() {
//     float principal, rate, time;

//     cout<<"Enter Principal Amount : ";
//     cin>>principal;

//     cout<<"Enter Rate of Interest : ";
//     cin>>rate;

//     cout<<"Enter Time (in Years): ";
//     cin>>time;

//     float simpleInterest = calculateSimpleInterest(principal,rate,time);

//     cout<<"Simple Interest Calcualted : "<< simpleInterest << endl;
//     return 0;
// }






// // find Maximum of two Nos.
// int findMax(int a , int b) {
//     if( a > b ) {
//         return a;
//     } else {
//         return b;
//     }
// }

// int main() {
//     int a , b;
//     cout<<"Enter Two Numbers to Find Maximum : ";
//     cin>>a>>b;

//     int maxVal = findMax(a,b);
//     cout<<"Maximum of Two Nos. i.e. "<<a<<" and "<<b<<" is : "<< maxVal;

//     return 0;
// }






// // Calculate factorial of a Number N
// unsigned long long calculateFactorial(int n) {
//     unsigned long long fact = 1;
//     for(int i = 1 ; i <= n ; ++i ) {
//         fact *= i;
//     }
//     return fact;
// }

// int main() {
//     int N;
//     cout << "Enter a Number : ";
//     cin>>N;

//     if ( N < 0 ) {
//         cout << "Factorial of a Number is Not defined a Negative Number";
//     } else {
//         unsigned long long result = calculateFactorial(N);
//         cout << "Factorial of " << N << " is " << result << endl;  
//     }
//     return 0;
// }





// // Given a person's age, Find if they should get a driving License or not
// bool ageEligibilityChecker(int age) {
//     return age >=18 ;
// }

// int main() {
//     int age;
//     cout<<"Enter the age to find Eligibility for the Driving License or Not : ";
//     cin >> age;

//     bool isChecked = ageEligibilityChecker(age);

//     if( isChecked ) {
//         cout << "Eligible for the Driving License"<<endl;
//     } else {
//         cout << "Not Eligible for the Driving License"<<endl;
//     }

//     return 0;  
// }





// //type conversion from int to char
// int main() {
//     int num = 5;
//     char type = '0' + num;
//     cout<<type;
// }





// // Simple Calculator
// int main(){
//     int a,b;
//     char opt;
//     cout<<"Enter a : ";
//     cin>>a;

//     cout<<"Enter b : ";
//     cin>>b;

//     cout<<"Enter The Operator(+,-,*,/,%) : ";
//     cin>>opt;

//     if(opt == '+'){
//         cout<<"Sum of Two Nos a and b is "<<a+b<<endl;
//     } else if(opt == '-'){
//         cout<<"Difference of Two Nos a and b is "<<a-b<<endl;
//     } else if (opt == '*'){
//         cout<<"Multiplication of Two Nos a and b is "<<a*b<<endl;
//     } else if(opt == '/'){
//         if(b != 0){
//             cout<<"Quotient of Two Nos a and b is "<<a/b<<endl;
//         } else {
//             cout<<"Divion by Zero is not Allowed"<<endl;
//         }
//     } else if(opt == '%'){
//         if(b != 0){
//             cout<<"Remainder of Two Nos a and b is "<<a%b<<endl;
//         } else {
//             cout<<"Modulo by Zero is not allowed"<<endl;
//         }
//     } else {
//         cout<<"Invalid Operator"<<endl;
//     }
    
//     return 0;

// }





// // Vote Eligibility checker
// int main() {
//     int age;
//     cout<<"Enter age of the Person : ";
//     cin>>age;

//     if(age<=0) {
//         cout<<"Invalid Age"<<endl; 
//         return 1;
//     }

//     if(age>=18){
//         cout<<"Person with age "<<age<<" has Right to Vote.";
//     } else {
//         cout<<"Person with age "<<age<<" is Not Eligible For voting.";
//     }

//     return 0;

// }






// // Find Character Lowercase or Uppercase
// int main() {
//     char ch;
//     cout<<"Enter Character : ";
//     cin>>ch;

//     if(ch>='a'&&ch<='z'){
//         cout<<"LowerCase";
//     } else {
//         cout<<"UpperCase";
//     }

//     return 0;
// }






// // Ternary Operator - condition ? str1 : str2;

// int main() {
//     cout<<"Enter the Number : ";
//     int n;
//     cin>>n;

//     cout<<(n >= 0 ? "Positive" : "Negative")<<endl;
// }





// LOOPS - while() loop

// // Print the numbers from 1 to n
// int main() {
//     int count = 1;
//     int limit;

//     cout<<"Set Limit : ";
//     cin>>limit;

//     while(count<=limit){
//         cout<<count<<endl;;
//         count++;
//     }
// }





// // for loop 

// int main(){
//      int count = 1;
//      int limit;
//      cout<<"Enter Limit : ";
//      cin>>limit;
//      for(int i=count;i<=limit;i++){
//         cout<<i<<endl;
//      }
//      return 0;
// }





// // sum of nos from 1 to n
// int main() {
//     int n,sum=0;
//     cout<<"Enter the Number n : ";
//     cin>>n;
//     for( int i = 1;i <= n; i++ ){
//         sum = sum + i;
//     }
//     cout<< "sum of nos from 1 to n : " << sum << endl ;

//     return 0;
// }






// // sum of all odd nos from 1 to n
// int main() {
//     int n , sum = 0;
//     cout<<"Enter the Number : ";
//     cin>>n;

//     for(int i = 1; i <= n; i+=2){
//         sum = sum + i;
//     }
//     cout<<"Sum = "<< sum <<endl;

//     return 0;

// }








// // d0 while loop

// int main() {
//     int n = 10;
//     int i = 1;

//     do{
//         cout << i << " ";
//         i++;
//     } while (i <= n);

//     cout<<endl;
//     return 0;
// }







// // Prime No Logic
// int main() {
//     int num;
//     bool isPrime = true;
//     cout<<"Enter the Number: ";
//     cin>>num;

//     if(num<=1){
//         isPrime = false;
//     } else {
//         for(int i = 2; i*i<=num;i++){
//             if(num%i==0){
//                 isPrime = false;
//                 break;
//             }
//         }
//     }

//     if (isPrime){
//         cout << "Prime No";
//     } else {
//         cout << "Not a Prime No";
//     }
// }





// // Nested Loop
// int main(){
//     int n,m;
//     cout<<"Enter n and m : ";
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     } 
// }






// Patterns - Square Pattern


// // 1 2 3 4 
// // 1 2 3 4
// // 1 2 3 4
// // 1 2 3 4

// int main() {
//     int n=4;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }





// // * * * * 
// // * * * *
// // * * * *
// // * * * *

// int main(){
//     int n = 4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }      
// }






// // A B C D 
// // A B C D
// // A B C D
// // A B C D

// int main(){
//     int n = 4;
//     for(int i = 0; i<n;i++){
//         char ch=65;
//         for(int j=0;j<n;j++){
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
// }





// // 1 2 3 
// // 4 5 6
// // 7 8 9

// int main(){
//     int n=3;
//     int num = 1;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<num<<" ";
//             num++;
//         }
//         cout<<endl;
//     }
// }






// // A B C 
// // D E F
// // G H I

// int main() {
//     int n = 3;
//     char ch = 65;
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
// }







// // * 
// // * *
// // * * *
// // * * * *

// int main() {
//     int n=4;
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<(i+1);j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }





// // 1 
// // 2 2 
// // 3 3 3 
// // 4 4 4 4

// int main() {
//     int n=4;
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<(i+1);j++){
//             cout<<i+1<<" ";
//         }
//         cout<<endl;
//     }
// }





// // A 
// // B B
// // C C C
// // D D D D
// // E E E E E

// int main(){
//     int n=5;
//     char ch=65;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i+1;j++){
//             cout<<ch<<" ";
//         }
//         ch++;
//         cout<<endl;
//     }
// }




// // 1 
// // 1 2
// // 1 2 3
// // 1 2 3 4

// int main(){
//     int n = 4;
//     for(int i = 0; i < n; i++){
//         for(int j = 1; j <= i+1 ; j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }





// // 1 
// // 2 1
// // 3 2 1
// // 4 3 2 1

// int main(){
//     int n = 4;
//     for(int i=0;i<n;i++){
//         for (int j=i+1;j>=1;j--){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }







//Floyd's Triangle pattern

// // 1 
// // 2 3
// // 4 5 6
// // 7 8 9 10

// int main(){
//     int n = 4;
//     int num = 1;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < i+1 ; j++){
//             cout<<num<<" ";
//             num++;
//         }
//         cout<<endl;
//     }
// }





// // A 
// // B C
// // D E F
// // G H I J

// int main(){
//     int n = 4;
//     char ch=65;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i+1;j++){
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
// }




// // A 
// // B A
// // C B A
// // D C B A

// int main(){
//     int n = 4;
//     for(int i = 0; i < n; i++){
//         char ch = 'A'+i;
//         for(int j = 0; j<i+1; j++){
//             cout<<(char)(ch-j)<<" ";
//         }
//         cout<<endl;
//     } 
//     return 0;
// }






// Inverted Triangle Pattern

// Reverse numbers n=4




// // 1111
// //  222
// //   33
// //    4

// int main() {
//     int n = 4;
//     for(int i = 0; i < n; i++){
        // for(int j = 0; j < i ; j++){
        //     cout<<" ";
        // }
        // for(int k=0;k<n-i;k++){
        //     cout<<i+1;
        // }
//         cout<<endl;
//     }
//     return 0;
// }





// // AAAA
// //  BBB
// //   CC
// //    D

// int main() {
//     int n = 4;
//     char ch='A';
//     for(int i = 0; i < n; i++){
        // for(int j = 0; j < i ; j++){
        //     cout<<" ";
        // }
//         for(int k=0;k<n-i;k++){
//             cout<<ch;
//         }
//         ch++;
//         cout<<endl;
//     }
//     return 0;
// }






// Pyramid Pattern


// //    1
// //   121
// //  12321
// // 1234321

// int main(){
//     int n = 4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-(i+1);j++){
//             cout<<" ";
//         }
//         for(int j=0;j<i+1;j++){
//             cout<<j+1;
//         }
//         for(int j=i;j>0;j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }





// Hollow Diamond Pattern


//       * 
//     *   * 
//   *       * 
// *           * 
//   *       * 
//     *   * 
//       * 
      


// My Logic

// int main(){
//     int n=4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-(i+1);j++){
//             cout<<"  ";
//         }
//         cout<<"* ";
//         if(i!=0){
//         for(int j=2*i-1;j>0;j--){
//             cout<<"  ";
//         }
//         cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(int i=n;i>1;i--){
//         for(int j=n-i;j>=0;j--){
//             cout<<"  ";
//         }
//         cout<<"* ";
//         for(int j=i-1;j>1;j--){
//             cout<<"  ";
//         }
//         for(int j=i;j>3;j--){
//             cout<<"  ";
//         }
//         if(n!=i+2){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }



// optimized logic for Hollow Diamond pattern

// int main(){
//     int n = 4;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n - i - 1; j++) {
//             cout << "  ";
//         }
//         cout << "* ";
//         if(i != 0){
//             for(int j = 0; j < 2*i - 1; j++) {
//                 cout << "  ";
//             }
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for(int i = n - 2 ; i >= 0; i--) {
//         for(int j = 0; j < n - i - 1; j++) {
//             cout << "  ";
//         }
//         cout << "* ";
//         if(i != 0){
//             for(int j = 0; j < 2*i - 1; j++) {
//                 cout << "  ";
//             }
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }








// Butterfly Pattern Logic

// *                    *  
// *  *              *  *  
// *  *  *        *  *  *  
// *  *  *  *  *  *  *  *  
// *  *  *  *  *  *  *  *  
// *  *  *        *  *  *  
// *  *              *  *  
// *                    *


// int main(){
//     int n=4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i+1;j++){
//             cout<<"*  ";
//         }
//         for(int j=0;j<2*(n-i-1);j++){
//             cout<<"   ";
//         }
//         for(int j=0;j<i+1;j++){
//             cout<<"*  ";
//         }
//         cout<<endl;
//     }
//     for(int i=n;i>0;i--){
//         for(int j=0;j<i;j++){
//             cout<<"*  ";
//         }
//         for(int j=2*(n-i);j>0;j--){
//             cout<<"   ";
//         }
//         for(int j=0;j<i;j++){
//             cout<<"*  ";
//         }
//     cout<<endl;
//     }
// }








// Functions

// returnType printHello(){
//         cout<<"hello";
// }


// Hello Function

// void printHello(){
//     cout<<"Hello"<<endl;
// } 

// int main(){
//     printHello();
//     return 0;
// }




// // sum of 2 numbers

// double sum(double a , double b){
//     double s = a + b;
//     return s;
// }

// int main(){
//     cout<<sum(10.354,52.65)<<endl;
//     return 0;
// }





// // min of 2 nos

// int minOfTwo(int a, int b){
//     if(a<b){
//         return a;
//     } else {
//         return b;
//     }
// }

// int main(){
//     int a,b;
//     cout<<"Enter a and b: ";
//     cin>>a>>b;
//     cout<<"Minimum of 2 nums is : "<<minOfTwo(a,b);
//     return 0;
// }







// // sum of NOs from 1 to n

// int sumN(int n){
//    int sum=0;
//    for(int i=1;i<=n;i++){
//       sum=sum+i;
//    }
//    return sum;
// }
// int main(){
//    int sum = sumN(10);
//    cout<<sum;
// }




// // N factorial

// int factN(int n){
//    int fact=1;
//    for(int i=1;i<=n;i++){
//       fact = fact*i;
//    }
//    return fact;
// }

// int main(){
//    int factorial = factN(5);
//    cout<<factorial;
// }






// // Calculate sum of digits of a number

// int digitSum(int num){
//    int dSum = 0;
//    while(num>0){
//       int lastDig = num % 10;
//       num = num / 10;
//       dSum += lastDig;
//    }
//    cout<<"Sum is "<< dSum;
// }

// int main(){
//    int n;
//    cout<<"Enter number: ";
//    cin>>n;
//    digitSum(n);
// }






// // Calculate nCr binomial coefficeint for n and r

// double factorial(int n){
//    double fact = 1;
//    for(int i=1;i<=n;i++){
//       fact = fact*i;
//    }
//    return fact;
// }

// double nCr(int n,int r){
//    double binomial = factorial(n) / (factorial(r) * factorial(n - r));
//    return binomial;
// }

// int main(){
//    int n , r;
//    cout<<"Enter n and r to calculate nCr: ";
//    cin>>n>>r;
//    double nCrBinomial = nCr(n,r);
//    cout<<nCrBinomial;
// }




// // WAF to check if it is a prime no or not

// int primeCheck(int num){
//    int isPrime=true;
   // if(num<=1){
   //    isPrime=false;
   // } else {
   //    for(int i = 2; i * i <= num; i++){
   //       if(num%i==0){
   //          isPrime=false;
   //       }
   //    }
   // }
//    if(isPrime){
//       cout<<"It is a Prime No.";
//    } else {
//       cout<<"It is not a Prime No.";
//    }
// }

// int main(){
//    int num;
//    cout<<"Enter The Number: ";
//    cin>>num;
//    primeCheck(num);
// }





// WAF to print all prime numbers from 1 to N.

bool isPrime(int num){
   if(num<=1){
      return false;
   } else {
      for(int i = 2; i * i <= num; i++){
         if(num%i==0){
            return false;
         }
      }
   }
   return true;
}

void printPrime(int num){
   cout<<"Prime No. from 1 to "<<num<<" are: ";
   for(int i = 1;i<=num;i++){
      if(isPrime(i)){
         cout<<i<<" ";
      }
   }
   cout<<endl;
}

int main(){
   int num;
   cout<<"Enter the value of num: ";
   cin>>num;

   printPrime(num);

   return 0;
}