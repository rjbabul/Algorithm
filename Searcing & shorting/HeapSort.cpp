#include<bits/stdc++.h>
using namespace std;
int b[100003];

void heapify(int b[], int n, int i){
  int mx=i;
  int l= 2*i+1;
  int r = 2*i+2;

  if(l<n && b[l]>=b[mx])mx = l;
  if(r<n && b[r]>=b[mx])mx=r;

  if(mx!=i) {
    swap(b[mx], b[i]);
    heapify(b,n,mx);
  }

}

vector<int > heapshort(int a[], int n){
    //for(int i=0;i<n;i++)b[i]=a[i];
    for(int i=n/2-1 ; i>=0;i--){
        heapify(a, n,i);
    }
    for(int j=n-1;j>0;j--){
        swap(a[0], a[j]);
        heapify(a,j,0);
    }
  vector<int > vt;
  for(int i=0;i<n;i++)vt.push_back(a[i]);
  return vt;

}
int main()
{
    int a[20004]; int n, t;
    freopen("H:\\input.txt","r", stdin);


    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        vector<int  > vt= heapshort(a, n);
        for(int i=0;i<n;i++)cout<<vt[i]<<" ";cout<<endl;

    }

    return 0;
}
