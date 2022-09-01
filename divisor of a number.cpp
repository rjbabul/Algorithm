#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int > vt[100002];
#define mx 100000
int main()
{
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            vt[j].push_back(i);
        }
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
           cout <<i<<" : ";
        for(int j=0;j<vt[i].size();j++){
            cout<<vt[i][j]<<" ";
        }
    cout<<endl;
    }

    return 0;
}
