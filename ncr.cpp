#include<bits/stdc++.h>
using namespace std;
long long int ncr[1001][1001];
#define mx 1000
void precal()
{
    for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++){
            if(j>i) ncr[i][j]=0;
            else if(j==i) ncr[i][j]=1;
            else if(j==0) ncr[i][j]=1;
            else ncr[i][j]= ncr[i-1][j-1]+ ncr[i-1][j];
        }
    }
}
int main()
{

    long long int a,b;
    precal();
    while(cin>>a){
     cout<<ncr[2*a][a]- ncr[2*a][a+1]<<endl;

    }

    return 0;
}
