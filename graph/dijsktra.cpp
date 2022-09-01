#include<bits/stdc++.h>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int > pi;

vector< pi > node[1000000];
priority_queue< pi,vector< pi>, greater<pi > > q;
vector< long int > dist(1000002,INT_MAX);

int level[1000002] ;
int s_dist[1000002];
int cost;

int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("I:\\dijktra.txt", "r", stdin);
    int n,u,v,w;
    cin>>n;

    while(n--)
    {
        cin>>u>>v>>w;
        node[u].push_back(make_pair(v,w));
        node[v].push_back(make_pair(u,w));
    }
    int s;
    q.push(make_pair(0,0));
    level[0]=0;
    dist[0]=0;
    int sorce[100000];
    sorce [0]=0;
    while(!q.empty())
    {
        s= q.top().second;
        cost= q.top().first;
        q.pop();
        for(int i=0; i<node[s].size(); i++)
        {

            v= node[s][i].first;
            if(cost+ node[s][i].second< dist[v] )
            {
                s_dist[v]= dist[v];
                dist[v]= cost+ node[s][i].second;
                sorce[v]=s;
                q.push(make_pair(dist[v],v));
                level[v]= level[s]+1;
            }

        }
    }
    for(int i=0; i<=100; i++)
    {
        if(dist[i]<1000)
        {
            cout<<i<<"    "<<dist[i]<<"  " ;
            int s=i;
            cout<<setw(10)<<"path from "<<i<<" to 0 is : ";
            while(s!=0)
            {
                cout<<s<<"->";
                s=sorce[s];
            }
            cout<<"0"<<endl;
        }

    }
    return 0;
}
