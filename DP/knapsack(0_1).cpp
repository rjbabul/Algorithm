#include<bits/stdc++.h>
using namespace std;
 long long int knpsck[1004][1004];
int p[1004], a[1004];
void knapsack(int n, int w,int price[],int wt[]){

  for(int i=1;i<=n;i++){
    for(int j=0;j<=w;j++){

        if(wt[i]>j) knpsck[i][j]= knpsck[i-1][j];
        else{
            knpsck[i][j]= max(knpsck[i-1][j], price[i]+knpsck[i-1][j-wt[i]]);
        }
    }
  }

  cout<<knpsck[n][w]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int  w, n,value;
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>a[i]>>p[i];

    knapsack(n, w, p, a);
    return 0;
}

