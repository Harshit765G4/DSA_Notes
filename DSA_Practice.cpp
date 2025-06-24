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







