// Hallow Pattern Logic

//       * 
//     *   * 
//   *       * 
// *           * 
//   *       * 
//     *   * 
//       * 
 

#include<iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-(i+1);j++){
            cout<<"  ";
        }
        cout<<"* ";
        if(i!=0){
        for(int j=2*i-1;j>0;j--){
            cout<<"  ";
        }
        cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n;i>1;i--){
        for(int j=n-i;j>=0;j--){
            cout<<"  ";
        }
        cout<<"* ";
        for(int j=i-1;j>1;j--){
            cout<<"  ";
        }
        for(int j=i;j>3;j--){
            cout<<"  ";
        }
        if(n!=i+2){
            cout<<"* ";
        }
        cout<<endl;
    }
}
