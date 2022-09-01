#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>vt[100005];
#define mx 100000
int main()
{
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i)
            vt[j].push_back(i);
    }
    int num;
    while(cin>>num){
        for(int i=1;i<=num;i++){
                cout<<i<<"  :  ";
            for(int j=0;j<vt[i].size();j++) cout<<vt[i][j]<<" ";
        cout<<endl;
        }
    }
    return 0;
}
