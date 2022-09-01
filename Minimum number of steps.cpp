#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
int main()
{
    string str;
    long long int sum,c,ans,n;
    while(cin>>str){
        n=str.length()-1;
        c=-1;
        sum=1;
        ans=0;
        while(str[n]!='b'  && n>=0)n--;
        for(int i=n;i>=0;i--){
            if(str[i]=='b')c++;
            else{
                ans= (ans+c+sum)%m;
                ans=ans%m;
                sum=((sum+c)*2)%m;
                c=0;
            }
        }

       cout<<ans<<endl;
    }
    return 0;
}
