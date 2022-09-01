#include<bits/stdc++.h>
using namespace std;
long long int sod[100005];
int main()
{
    sod[0]=0;
    for(int i=1;i<=100002;i+=2){
        for(int j=i;j<=100002;j+=i){
            sod[j]+=i;
        }
    }
    long long int t,l,r,sum;
    cin>>t;
    while(t--){
            sum=0;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            sum+= sod[i];
        }
         cout<<sum<<endl;

    }
    return 0;
}
