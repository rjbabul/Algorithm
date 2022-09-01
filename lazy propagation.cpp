#include<bits/stdc++.h>
using namespace std;
#define mx 100000

int arr[mx],lp[4*mx];

void update(int node, int L,int R, int l, int r)
{
    if(r<L || R<l)
        return ;
    if(L>=l && R<=r)
    {
        lp[node]^=1;
        return ;
    }
    int mid = (L+R)/2;
    update(node*2, L,mid, l, r);
    update( node*2+1, mid+1, R, l, r);
}
int query(int node, int L, int R, int pos)
{
    if(pos<L || pos>R)
        return 0;
    if(pos>=L && pos<=R && L==R)
        return lp[node];
    int mid = (L+R)/2;
    if(pos<=mid)
        return query(node*2,L,mid, pos) ^ lp[node];
    else
        return query(node*2+1,mid+1, R,pos) ^ lp[node];

}
int main()
{
    int n,pos;
    int l,r,u,v;
    cin>>n;
    while(1)
    {
        cin>>l>>r;
        update(1,1,n,l,r);
        for(int i=1; i<=n; i++)
        cout<<i<<"  "<<query(1,1,n,i)<<endl;
    }
    return 0;
}
