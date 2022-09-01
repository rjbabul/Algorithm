#include<bits/stdc++.h>
using namespace std;
long long int dp[100000][1000];
long long int nCr(int n, int r){
    if(n==r) return dp[n][r]=1;
    if(r==1) return dp[n][r]=n;
    if(r==0) return dp[n][r]=1;
    if(dp[n][r]) return dp[n][r];
    return  dp[n][r]=  nCr(n-1,r)+ nCr(n-1, r-1);
}
int main()
{
    long long int n,r;
    while(cin>>n>>r){
        cout<<nCr(n,r)<<endl;
    }
    return 0;
}
