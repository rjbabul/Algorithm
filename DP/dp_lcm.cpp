#include<bits/stdc++.h>
using namespace std;
int lcm(int a[], int n){

  int x[n+1];

  memset(x,0,sizeof(x));
  for(int i=0;i<n;i++)x[i]=1;
  int mx=0;

  for(int i=0;i<n;i++){

    for(int j=i+1;j<n;j++){
        if(a[i]<a[j]) x[j]= max(x[j], x[i]+1);
        mx= max(mx, x[j]);

    }

  }
return mx;

}
int main()
{
    int a[10000];
    int i=0;
    freopen("H:\\input.txt","r",stdin);

    int x;
   int n,nn;
    cin>>n;
    nn=n;
    while(n-- && cin>>x){

            cout<<x<<" ";
            a[i++]=x;

    }
   // int n= (sizeof(a)/ sizeof(a[0]));
   cout<<endl;
    cout<< lcm(a, nn)<<endl;

    return 0;
}
