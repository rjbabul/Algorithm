#include<bits/stdc++.h>
#define mx 1000000
#define mn  1000000007
using namespace std;
typedef long long int ll;
ll arr[mx];
ll tree[mx*3];


void segment_tree_build(ll node, ll l , ll r ){
   if(l == r){
    tree[node]= arr[l];
    return ;
   }
   ll mid= (l +r)/2;
   ll left = node*2;
   ll right  = node*2 +1;
   segment_tree_build(left, l, mid);
   segment_tree_build(right, mid+1, r);

   tree[node] =  (tree[left]+ tree[right]);
}

void segment_tree_update(ll node, ll l, ll r, ll pos, ll x){

   if(l==r){
    tree[node]= x;
    return ;
   }

   ll mid= (l +r)/2;
   ll left = node*2;
   ll right  = node*2 +1;
   if(pos<=mid) segment_tree_update(left, l, mid,pos,x);
   else segment_tree_update(right, mid+1, r,pos,x);
   tree[node] =  tree[left]+ tree[right];

}
ll segment_query(ll node, ll l, ll r, ll i , ll j){

   if(r< i || j<l) return mn;
   if(i<=l && r<=j) return tree[node];
   ll mid= (l +r)/2;
   ll left = node*2;
   ll right  = node*2 +1;
   ll x = segment_query(left,l, mid, i,j);
   ll y = segment_query(right,mid+1, r, i, j);
   return x+y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll  n;

    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    segment_tree_build(1,1,n);
    ll pos, x,i,j;

    cin>>pos>>x;
    cin>>i>>j;
    cout<<segment_query(1,1,n,i,j)<<endl;

    segment_tree_update(1,1,n,pos,x);
    cout<<segment_query(1,1,n,i,j)<<endl;

    return 0;
}
