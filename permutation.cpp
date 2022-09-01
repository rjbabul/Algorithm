#include<bits/stdc++.h>
using namespace std;
int used[100], num[100];

void permutation(int t, int n){
    if(t==n+1) { for(int i=1;i<=n;i++)
        printf("%c", num[i]+65);
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++) if(!used[i]){
        used[i]=1;
        num[t]=i;
        permutation(t+1,n);
        used[i]=0;
    }

}
int main()
{
    int n;
    while(cin>>n){
        permutation(1,n);
    }
    return 0;
}
