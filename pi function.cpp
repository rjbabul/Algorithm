#include<bits/stdc++.h>
using namespace std;
int mark[1000006],pi[1000006];
int main()
{
    for(int i=0;i<=1000000;i++) pi[i]=i;
    mark[1]=1;
    mark[0]=1;
    for(int i=2;i<=sqrt(1000000);i++){
            if(mark[i]==0)
        for(int j=i;j<=1000000;j+=i){
            mark[j]=1;
            pi[j]= (pi[j]/i)*(i-1);
        }
    }
    int num;
    while(cin>>num){
        cout<<(pi[num]*num)/2<<endl;
    }
    return 0;
}
