#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, a[100005],x;
    while(cin>>n>>k){
        set<int>st;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<k;i++){
            cin>>x;
            st.insert(x);
        }
        if(st.size()>1){
            cout<<"YES"<<endl;
            continue;
        }
        int c=1;
        for(int i=0;i<n-1;i++){
            if(a[i]==0)a[i]=x;
            if(a[i+1]==0)a[i+1]=x;

            if(a[i]<=a[i+1])c++;
            else break;
        }
        if(c==n)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}
