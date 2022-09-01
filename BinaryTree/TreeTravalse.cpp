#include<bits/stdc++.h>
using namespace std;


void preorder(vector<int> vt[], int s){

  cout<<s<<" ";
  if(vt[s].size()>0) preorder(vt, vt[s][0]);
  if(vt[s].size()>1)preorder(vt,  vt[s][1]);

}
void inorder(vector<int> vt[], int s){

  if(vt[s].size()>0) preorder(vt, vt[s][0]);
  cout<<s<<" ";
  if(vt[s].size()>1)preorder(vt,  vt[s][1]);

}

void postorder(vector<int> vt[], int s){

  if(vt[s].size()>0) preorder(vt, vt[s][0]);
  if(vt[s].size()>1)preorder(vt,  vt[s][1]);
  cout<<s<<" ";
}

void levelorder(vector<int> vt[], int s){

  queue<int> q;
  q.push(s);
  while(!q.empty()){

    s= q.front();
    cout<<s<<" ";
    q.pop();
    for(int i=0;i<vt[s].size();i++)q.push(vt[s][i]);
  }
  cout<<endl;

}
int main()
{
    freopen("H:\\input.txt","r", stdin);
    vector<int> vt[1000];
    int x, y;
    while(cin>>x>>y){
        vt[x].push_back(y);
    }
    cout<<"Level Order Travels : ";
    levelorder(vt,1);
    cout<<"\nPreOrder Travels : ";
    preorder(vt,1);
    cout<<"\n\nInOrder Travels : ";
    inorder(vt, 1);
    cout<<"\n\nPostOrder Travels : ";
    postorder(vt, 1);
    return 0;
}
