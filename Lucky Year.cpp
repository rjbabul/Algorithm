#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,s,c;
    while(cin>>n){
        s=n;
        c=0;
        while(s>=10){
            c++;
            s=s/10;
        }
        x=1;
        for(int i=1;i<=c;i++){
            x*=10;
        }
        cout<<(s+1)*x-n<<endl;
    }
    return 0;
}
