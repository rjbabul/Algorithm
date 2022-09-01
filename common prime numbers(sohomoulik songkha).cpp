#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int num,n,i;
    while(cin>>num){
            n=num;
     for(int i=2;i*i<=n;i++)
    {
        if(n%i==0){
                num-= num/ i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) num-= num/n;
    cout<<num<<endl;
    }
    return 0;
}
