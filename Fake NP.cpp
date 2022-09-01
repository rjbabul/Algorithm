#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b;
    cin>>a>>b;
        if(a!=b)cout<<2<<endl;
        else{
            for(long long int i=2;i*i<=a;i++){
                if(a%i==0){
                    cout<<i<<endl;
                   return 0;
                }
            }
            cout<<a<<endl;
        }
    ;
    return 0;
}
