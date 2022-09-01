#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
vector< pair< int, pair<int , int > > > node;
vector< pair< int, pair<int , int > > >  ::iterator it;
int father[100000];
int fnd(int n){
   if(father[n]==n) return n;
   else fnd(father[n]);
}

void unit(int u, int v){
    int x= fnd(u);
    int y= fnd(v);
    father[y]=x;

}
int main()
{
   /// freopen("I:\\mst.txt","r",stdin);

    int n,m;
    while(cin>>m>>n)
   {
       for(int i=0;i<100000;i++) father[i]=i;
       if(n==0 && m==0) break;
        int   u,v,w,t_sum;
        t_sum=0;
    while(n--){

        cin>>u>>v>>w;
        t_sum+=w;
        node.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(node. begin(),node. end());
    int  sum=0;

    vector< pair< int, pair<int , int > > >  ::iterator it;
    for(int i=0;i<node.size();i++){

        if(fnd(node[i].second.first)!=fnd(node[i].second.second)){
            unit(node[i].second.first,node[i].second.second);
            sum+= node[i].first;
        }
    }

    cout<< sum<<endl;
    node.clear();
   }

    return 0;
}
