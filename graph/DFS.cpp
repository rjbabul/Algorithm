#include<bits/stdc++.h>
#include<map>
#include<vector>

using namespace std;
vector<int >vt[1000000];
map<int,int>mp;
stack<int> st;
int ar[1000000];
int j=0;
void dfs()
{
    int s;
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        if(mp[s]==0)
        {
            ///cout<<s<<" ";

            mp[s]=1;
            for(int i=0; i<vt[s].size(); i++)
            {
                if(mp[vt[s][i]]==0)
                {
                    st.push(vt[s][i]);
                    dfs();
                }
            }
        }
    }
}
int main()
{
    int n,v,u;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    st.push(1);
    dfs();
    return 0;
}
