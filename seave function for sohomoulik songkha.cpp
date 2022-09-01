#include<bits/stdc++.h>
using namespace std;
int mark[1000006], pi[1000006];
#define n 1000000
int main()
{

    pi[1]=1;
    mark[1]=1;

    for(int i=1;i<=n;i++) pi[i]=i;
    for(int i=2;i<=n;i++){
        if(mark[i]!=1){
            for(int j=i;j<=n;j+=i){
                mark[j]=1;
                pi[j]=(pi[j]/i)*(i-1);
            }
        }
    }
    int num;
    while(cin>>num){
        cout<<pi[num]<<endl;
    }

    return 0;
}
