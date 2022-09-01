#include<bits/stdc++.h>
using namespace std;
long long int  typedef i64;
int BigMod(i64 n,i64 p, i64 m){
    i64 num;
    if(p==0) return 1%m;
    if(p%2==0){
        num = BigMod(n,p/2,m);
        return ((num%m)*(num%m))%m;
    }
    else{
        return ((n%m)*BigMod(n,p-1,m)%m)%m;
    }
}
int main()
{

    i64 num,p,m;
    while(cin>>num>>p){
            m=42;
        cout<<BigMod(num,p,m)<<endl;
    }

    return 0;
}
