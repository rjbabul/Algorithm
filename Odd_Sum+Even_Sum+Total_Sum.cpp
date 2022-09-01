#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int n, odd_sum, even_sum, total_sum,x;
    while(cin>>n){
        total_sum= (n*n+n)/2;
        x=n/2;
        even_sum = x+ (x*x);
        odd_sum = total_sum - even_sum;


        cout<<"Total Sum : "<<total_sum<<endl;
        cout<<"Odd Sum : "<<odd_sum<<endl;
        cout<<"Even Sum : "<<even_sum<<endl;
    }
    return 0;
}
