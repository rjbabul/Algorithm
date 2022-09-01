#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int factorial(int arr[], int arr_size,int x);
void fact(int num){
    arr[0]=1;
    int arr_size=1;
    for(int i=2;i<=num;i++){

        arr_size=factorial(arr, arr_size,i);
    }
    for(int i=arr_size-1;i>=0;i--) cout<<arr[i];
    cout<<endl;
}
int factorial(int arr[],int arr_size,int x){
      int p,c=0;
      for(int i=0;i<arr_size;i++){
        p=(arr[i]*x)+c;
        arr[i]=p%10;
        c=p/10;
      }
      while(c){
        arr[arr_size++]=c%10;
        c/=10;
      }

      return arr_size;
}
int main()
{
    int num;
    while(cin>>num){
       fact(num);
    }
    return 0;
}
