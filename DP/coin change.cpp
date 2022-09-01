#include<bits/stdc++.h>
using namespace std;
int totalway[1000][1000];

void coinchange(int n, int w, int coins[]){

  for(int i=0;i<=w;i++) totalway[i][0]= 1;

  for(int i=1;i<=n;i++){
    for(int j=0;j<=w;j++){
        if(j==0 ) totalway[i][j]=1;
        else if(coins[i]>j) totalway[i][j]= totalway[i-1][j];
        else totalway[i][j]= totalway[i-1][j]+ totalway[i][j-coins[i]];
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){
        cout<<totalway[i][j]<<" ";
    }
    cout<<endl;
  }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("coinchange.txt", "r", stdin);
    int coins[1000], totalamount ,n;
    cin>>n;
    for(int i =1;i<=n;i++) cin>> coins[i];
    cin>>totalamount;
    coinchange(n,totalamount,coins);

    return 0;
}
