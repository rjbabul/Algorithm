#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a,x,k,ans,n;
    while(cin>>n>>k){
            ans=0;
        for(float i=0;i<n;i++){
            cin>>x;
             ans+=x;
        }
        x=(k+k-1)/2;
        float i=0;
        while( ((ans+(i*k))/(i+n))<x)i++;
        cout<<i<<endl;
    }
    return 0;
}
