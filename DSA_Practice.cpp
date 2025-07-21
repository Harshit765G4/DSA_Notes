// #include<bits/stdc++.h>
// using namespace std;



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
//    if(num<=1){
//       isPrime=false;
//    } else {
//       for(int i = 2; i * i <= num; i++){
//          if(num%i==0){
//             isPrime=false;
//          }
//       }
//    }
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





// // WAF to print all prime numbers from 2 to N.

// bool isPrime(int num){
//    if(num<=1){
//       return false;
//    } else {
//       for(int i = 2; i * i <= num; i++){
//          if(num%i==0){
//             return false;
//          }
//       }
//    }
//    return true;
// }

// void printPrime(int num){
//    cout<<"Prime No. from 1 to "<<num<<" are: ";
//    for(int i = 1;i<=num;i++){
//       if(isPrime(i)){
//          cout<<i<<" ";
//       }
//    }
//    cout<<endl;
// }

// int main(){
//    int num;
//    cout<<"Enter the value of num: ";
//    cin>>num;

//    printPrime(num);

//    return 0;
// }



// // WAF to print nth Fibonacci

// int fibonacci(int n){
//    if(n<=0) return 0;
//    if(n==1) return 1;

//    int a = 0,b = 1, fib;

//    for(int i=2;i<=n;i++){
//       fib = a + b;
//       a = b;
//       b = fib;
//    }
//    return b;
// }

// int main(){
//    int n;
//    cout<<"Enter the nth Position: ";
//    cin>>n;

//    cout<<n<<"th fibonacci number is: "<<fibonacci(n)<<endl;

//    return 0;
// }




// // Fibonacci series print

// void printFibonacci(int n){
//     if(n <= 0) return;

//     int a = 0, b = 1;

//     for(int i = 0; i < n; i++){
//         cout << a << " ";
//         int fib = a + b;
//         a = b;
//         b = fib;
//     }
//     cout << endl;
// }

// int main(){
//     int n;
//     cout << "Enter the number of terms: ";
//     cin >> n;

//     cout << "Series: ";
//     printFibonacci(n);

//     return 0;
// }





// // Decimal to binary
// double Dec2Bin(int num){
//     double ans = 0;
//     int pow = 1;
//     while(num > 0){
//         int rem = num % 2;
//         num = num / 2;
//         ans += (rem*pow);
//         pow = pow * 10;
//     }
//     return ans;
// }
// int main(){
//     int num;
//     cout<<"Enter num: ";
//     cin>>num;
//     cout<<Dec2Bin(num);
// }





// // Decimal to binary series from 1 to n
// double Dec2Bin(int num){
//     double ans = 0;
//     int pow = 1;
//     while(num > 0){
//         int rem = num % 2;
//         num = num / 2;
//         ans += (rem*pow);
//         pow = pow * 10;
//     }
//     return ans;
// }
// int main(){
//     for(int i=1;i<=10;i++){
//         cout<<Dec2Bin(i)<<endl;
//     }
//     return 0;
// }







// // Binary to Decimal

// int Bin2Dec(int binNum){
// 	int ans = 0, pow = 1;
// 	while(binNum>0){
// 		int rem = binNum%10;
// 		ans += (rem*pow);
// 		binNum = binNum/10;
// 		pow *= 2;
// 	}
// 	return ans;
// }
// int main(){
// 	int binNum = 101010;
// 	cout<<Bin2Dec(binNum);
// 	return 0;
// }




// // Bitwise Operator

// int main(){
// 	cout<<(6&10)<<endl;
// }

// int main(){
// 	cout<<(6|10)<<endl;
// }

// int main(){
// 	cout<<(6^10)<<endl;
// }

// int main(){
// 	cout<<(10<<2)<<endl;
// }

// int main(){
// 	cout<<(10>>1)<<endl;
// }







// // WAF to Reverse an integer n

// int revInt(int num){
// 	int remainder, revInteger = 0;
// 	while(num > 0){
// 		remainder =	num % 10;
// 		num = num / 10;
// 		revInteger = (revInteger * 10) + remainder;
// 	}
// 	return revInteger;
// }
// int main(){
// 	int num;
// 	cout<<"Enter num: ";
// 	cin>>num;
// 	cout<<revInt(num)<<endl;
// }









// // optimal Approach Binary Search Algorithm
// int search(vector<int>& nums, int target) {
//    int st = 0, end = nums.size() - 1;
//    while(st <= end){
//       int mid = (st + end)/2;
//       if(target > nums[mid]){
//          st = mid + 1;
//       } else if(target < nums[mid]){
// 			st = mid - 1;
//       } else {
//          return mid;
//       }
//    }
//    return -1;
// }

// int main(){
// 	vector<int> nums = {-1,0,3,4,5,9,12};
// 	int target = 9;

// 	cout<<search(nums,target)<<endl;
// 	return 0;
// }






// // optimal Approach Binary Search Algorithm on even array
// int search(vector<int>& nums, int target) {
//    int st = 0, end = nums.size() - 1;
//    while(st <= end){
//       int mid = (st + end)/2;
//       if(target > nums[mid]){
//          st = mid + 1;
//       } else if(target < nums[mid]){
// 			end = mid - 1;
//       } else {
//          return mid;
//       }
//    }
//    return -1;
// }

// int main(){
	// vector<int> nums = {-1,0,3,5,9,12};
	// int target = 0;

	// cout<<search(nums,target)<<endl;
// }






// // Binary Search using recursion
// int recBinarySearch(vector<int> arr, int tar, int st, int end) {
//    if (st <= end) {
//       int mid = st + (end - st) / 2;
//       if (tar > arr[mid]) {
//          return recBinarySearch(arr, tar, mid + 1, end);
//       } else if (tar < arr[mid]) {
//          return recBinarySearch(arr, tar, st, mid - 1);
//       } else {
//          return mid;
//       }
//    }
//    return -1;
// }

// int main() {
//    vector<int> arr = {-1, 0, 3, 5, 9, 12};
//    int target = 9;

//    cout << recBinarySearch(arr, target, 0, arr.size() - 1) << endl;
//    return 0;
// }






// STL

// //Deque
// int main() {
//     deque<int> dq = {10, 20, 30};

//     dq.push_back(40);   // Insert at end
//     dq.push_front(5);   // Insert at front

//     for (int x : dq)
//         cout << x << " ";
// }




// // Pair
// int main() {
//     pair<int, string> p;

//     p.first = 1;
//     p.second = "Alice";

//     cout << p.first << " " << p.second;
// }





// // unordered map
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main() {
//     string s = "banana";
//     unordered_map<char, int> freq;

//     for (char c : s) freq[c]++;

//     for (auto it = freq.begin(); it != freq.end(); ++it){
//         cout << it->first << ": " << it->second << endl;
//     }
// }







// #include <iostream>
// using namespace std;

// int main() {
//     int x = 29; // Binary: 11101 → 4 ones
//     cout << "__builtin_popcount(29): " << __builtin_popcount(x) << endl;
//     return 0;
// }










// // sort
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> v = {4, 2, 8, 1};

//     sort(v.begin(), v.end());

//     for (int x : v)
//         cout << x << " ";
// }








// // unordered_set

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main() {
//     unordered_set<int> uset;

//     uset.insert(10);
//     uset.insert(20);
//     uset.insert(10); // Duplicate, ignored
//     uset.insert(5);

//     for (int x : uset)
//         cout << x << " ";
// }







// // multi_set

// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     multiset<int> ms;

//     ms.insert(10);
//     ms.insert(20);
//     ms.insert(10); // duplicate allowed
//     ms.insert(30);

//     for (int val : ms)
//         cout << val << " ";
// }







// // lower bound and upper bound

// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     set<int> s = {10, 20, 30, 40, 50};

//     auto lb = s.lower_bound(30); // Points to 30
//     auto ub = s.upper_bound(30); // Points to 40

//     if (lb != s.end())
//         cout << "Lower Bound of 30: " << *lb << endl;
//     else
//         cout << "Lower Bound of 30: Not found\n";

//     if (ub != s.end())
//         cout << "Upper Bound of 30: " << *ub << endl;
//     else
//         cout << "Upper Bound of 30: Not found\n";
// }







// // lower and upper bound in set

// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     set<int> s = {10, 20, 30, 40};

//     auto lb = s.lower_bound(25); // First ≥ 25 → 30
//     auto ub = s.upper_bound(30); // First > 30 → 40

//     cout << "Lower Bound: " << *lb << endl;
//     cout << "Upper Bound: " << *ub << endl;
// }








// strings
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s1 = "Hello";
//     string s2("World");
//     string s3;

//     cout << s1 << " " << s2 << endl;
//     return 0;
// }









// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string name;
//     cout << "Enter your name: ";
//     getline(cin, name);  // Reads spaces too

//     cout << "Hello, " << name << "!" << endl;

//     // String operations
//     cout << "Length: " << name.length() << endl;
//     cout << "First letter: " << name[0] << endl;
    
//     if (name.find("a") != string::npos)
//         cout << "'a' found at: " << name.find("a") << endl;

//     return 0;
// }







// // Reverse a string
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main() {
//     string str = "Hello";
//     reverse(str.begin(), str.end());
//     cout << "Reversed: " << str << endl;
//     return 0;
// }









// // Compare Two Strings (Case-Insensitive)

// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;

// string toLowerCase(string s) {
//     for (char &c : s) c = tolower(c);
//     return s;
// }

// int main() {
//     string a = "Hello";
//     string b = "hello";
    
//     if (toLowerCase(a) == toLowerCase(b))
//         cout << "Equal (case-insensitive)" << endl;
//     else
//         cout << "Not equal" << endl;

//     return 0;
// }









// // Convert to Uppercase

// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;

// int main() {
//     string str = "Hello";
//     for (char &c : str) {
//         c = toupper(c);
//     }
//     cout << "Uppercase: " << str << endl;
//     return 0;
// }
















// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str = "Hello";
//     str += " World";                    // Concatenate
//     str.insert(5, ",");                 // Insert
//     str.replace(6, 5, "Universe");      // Replace "World" with "Universe"
//     str.erase(13, 1);                   // Erase last character

//     cout << str << endl;                // Output: Hello,Universe

//     if (str.find("Universe") != string::npos)
//         cout << "Found 'Universe'" << endl;

//     cout << "Length: " << str.length() << endl;
//     cout << "First char: " << str[0] << endl;

//     return 0;
// }










// // Check Palindrome

// #include <iostream>
// #include <string>
// using namespace std;

// bool isPalindrome(string s) {
//     int i = 0, j = s.length() - 1;
//     while (i < j) {
//         if (s[i] != s[j]) return false;
//         i++; j--;
//     }
//     return true;
// }

// int main() {
//     string str = "madam";
//     cout << (isPalindrome(str) ? "Palindrome" : "Not Palindrome") << endl;
//     return 0;
// }









// // Count Words in a Sentence

// #include <iostream>
// #include <string>
// #include <sstream>
// using namespace std;

// int main() {
//     string sentence = "I love programming in C++";
//     stringstream ss(sentence);
//     string word;
//     int count = 0;

//     while (ss >> word) count++;

//     cout << "Word count: " << count << endl;
//     return 0;
// }











// // Capitalize First Letter of Each Word

// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;

// int main() {
//     string str = "hello world from harshit";
//     bool cap = true;

//     for (int i = 0; i < str.length(); i++) {
//         if (isspace(str[i])) {
//             cap = true;
//         } else if (cap) {
//             str[i] = toupper(str[i]);
//             cap = false;
//         }
//     }

//     cout << "Capitalized: " << str << endl;
//     return 0;
// }









//  LeetCode Problem 14: Longest Common Prefix 


// string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";

//         string prefix = strs[0];

//         for (int i = 1; i < strs.size(); ++i) {
//             while (strs[i].find(prefix) != 0) {
//                 prefix = prefix.substr(0, prefix.length() - 1);
//                 if (prefix.empty()) return "";
//             }
//         }

//         return prefix;
//     }










// // Valid Palindrome (LeetCode #125)
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0, right = s.size() - 1;

//         while (left < right) {
//             while (left < right && !isalnum(s[left])) left++;
//             while (left < right && !isalnum(s[right])) right--;

//             if (tolower(s[left]) != tolower(s[right])) return false;

//             left++;
//             right--;
//         }

//         return true;
//     }
// };
