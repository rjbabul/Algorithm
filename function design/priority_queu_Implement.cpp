#include<bits/stdc++.h>
using namespace std;
int a[100000], n=-1;


void heapify(int a[], int n, int i){
   int mx=i;
   int l = 2*i+1;
   int r = 2*i+2;
   if(l<=n && a[l]<a[mx])mx=l;
   if(r<=n && a[r]<a[mx])mx=r;
   if(mx!=i){
    swap(a[i], a[mx]);
    heapify(a,n,mx);
   }

}

void push(int x){

   a[++n]= x;
   for(int i = (n/2);i>=0;i--) heapify(a,n,i);
}
void pop(){
  if(n<0){
    cout<<"EMPTY!!!!"<<endl;
    return ;
  }
  swap(a[0], a[n]);
  n--;
  heapify(a,n,0);

}
int top(){

  return a[0];

}
int call(){

  cout<<"\t1 for push"<<endl;
  cout<<"\t2 for top()"<<endl;
  cout<<"\t3 for pop()"<<endl;
  cout<<"\t0 for exit"<<endl;
  return 1;
}
int main()
{
    int x;
    while(call()&& cin>>x && x!=0){
        if(x==1){
            cin>>x;
            push(x);
        }
        else if(x==2){
            if(n<0)
                cout<<"EMPTY!!!!"<<endl;
            else
                cout<<"Top element is: "<<top()<<endl;
        }
        else if(x==3){
            pop();
        }
        else{
            cout<<"Enter wrong Number"<<endl;
        }
    }
    return 0;
}
