#include<bits/stdc++.h>
int number[1000000];
int factorial(int number[],int arr_size,int  x){

     int c=0,r;
     for(int i=0;i<arr_size;i++){
        r= (number[i]*x)+c;
        number[i]=r%10;
        c=r/10;
     }
     while(c){
        number[arr_size++]= c%10;
        c/=10;
     }
     return arr_size;
}
void fact(int num){
     number[0]=1;
     int arr_size=1;
     for(int i=2;i<=num ;i++){
        arr_size= factorial(number, arr_size, i);
     }

     for(int i=arr_size-1;i>=0;i--) std::cout<<number[i];
     std::cout<<"\n";
}
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        fact(n);
    }
    return 0;
}
