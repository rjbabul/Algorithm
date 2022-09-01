#include<bits/stdc++.h>
using namespace std;

map<long long int, long long int > mp;
long long int m=1000000007;
long long int fib(long long int n){
    long int k = n/2;
    if(mp[n]>0) return mp[n];
    if(n%2==0){
        return mp[n]= ((fib(k)*fib(k))+ fib(k-1)*fib(k-1))%m;
    }
     else {
        return mp[n]= ((fib(k)*fib(k+1))+ fib(k)*fib(k-1))%m;
    }

}
int main()
{
    long long int num;
    mp[0]=mp[1]=1;
    while(cin>>num){
        if(num==0) cout<<"0"<<endl;
        else{
            cout<<fib(num-1)<<endl;
        }
    }
    return 0;
}

