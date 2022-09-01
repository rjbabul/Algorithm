#include<bits/stdc++.h>
using namespace std;
int bs(int n[],int l,int r,int num){
    int mid;
    if(l<r){
        mid= (l+r)/2;
        if(n[mid]==num) return 1;
        else if(n[mid]>num) return bs(n,l, mid,num);
        else return bs(n,mid+1, r,num);
    }
    else return 0;
}
int main()
{
    int n[10000], num;
    for(int i=0;i<5;i++) cin>>n[i];
    sort(n,n+5);
    while(cin>>num)
    {
        int s;

        s= bs(n,0,5, num);
        if(s)  cout<<"yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
