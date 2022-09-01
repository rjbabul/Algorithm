#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
vector< int > node[1000002];
queue<int >q;
int dist[1000000], visit[1000002], level[1000002];
int main()
{

    int n,sorce, v,u;
    freopen("I:\\graph.txt","r", stdin);
    cin>>n;
    while(n--){
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    cin>>sorce;
    dist[sorce]= sorce;
    level[sorce]=0;
    int s;
    q.push(sorce);
    while(!q.empty()){
        s=q.front();
       // cout<<s<<" ";
        visit[s]=1;
        q.pop();
        for(int i=0;i<node[s].size();i++){
            if(visit[node[s][i]]==0){
                dist[node[s][i]]= s;
                level[node[s][i]]= level[s] + 1;
                visit[node[s][i]]=1;
                q.push(node[s][i]);
            }
        }
    }
    int dis;
    vector<int > distance;
    cin>>dis;
    if(visit[dis]==0) cout<<"This node is not visited"<<endl;
    else{

            distance.push_back(dis);
        while(dis!=sorce){
            dis= dist[dis];
             distance.push_back(dis);
        }
    }
    for(int i=distance.size()-1;i>=0;i--){
        cout<<distance[i];
        if(i>0) cout<<" -> ";
        else cout<<endl;
    }

    return 0;
}
