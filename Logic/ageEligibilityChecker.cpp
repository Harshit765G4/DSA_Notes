#include<iostream>
using namespace std;

bool ageEligibilityChecker(int age) {
    return age >= 18 ;
}

int main() {
    int age;
    cout<<"Enter the age to find Eligibility for the Driving License or Not : ";
    cin >> age;

    bool isChecked = ageEligibilityChecker(age);

    if( isChecked ) {
        cout << "Eligible for the Driving License"<<endl;
    } else {
        cout << "Not Eligible for the Driving License"<<endl;
    }

    return 0;  
}