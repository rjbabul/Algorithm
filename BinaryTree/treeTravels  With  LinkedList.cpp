#include<bits/stdc++.h>
using namespace std;

struct Node{

  int data;
  Node*left ;
  Node* right;

};


void preorder(Node* tree){

  cout<<tree->data<<" ";
  if(tree->left!=NULL) preorder(tree->left);
  if(tree->right!=NULL) preorder(tree->right);

}

void inorder(Node* tree){


  if(tree->left!=NULL) inorder(tree->left);
  cout<<tree->data<<" ";
  if(tree->right!=NULL) inorder(tree->right);

}

void postorder(Node* tree){

  if(tree->left!=NULL) postorder(tree->left);
  if(tree->right!=NULL) postorder(tree->right);
  cout<<tree->data<<" ";

}
void levelorder(Node* tree){
  Node*temp;
  queue< Node* > q;
  q.push(tree);
  while(!q.empty()){
  temp =  q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left!= NULL)q.push(temp->left);
    if(temp->right!=NULL) q.push(temp->right);
  }

}
int main()
{
    Node* tree=NULL;
    tree= (struct Node*)malloc( sizeof(struct Node));

    tree->data= 1;
    tree->left= new Node();
    tree->left->data= 2;
    tree->right= new Node();
    tree->right->data= 3;

    tree->left->left= new Node();
    tree->left->left->data = 4;

    tree->left->right= new Node();
    tree->left->right->data=5;

    tree->right->left = new Node();
    tree->right->left->data= 6;

    tree->right->right= new Node();
    tree->right->right->data=7;

    tree->left->left->left= new Node();
    tree->left->left->left->data = 8;

    tree->left->left->right= new Node();
    tree->left->left->right->data=9;

    tree->left->right->left= new Node();
    tree->left->right->left->data= 10;

    tree->left->right->right= new Node();
    tree->left->right->right->data = 11;

    tree->right->left->left= new Node();
    tree->right->left->left->data = 12;

    tree->right->left->right= new Node();
    tree->right->left->right->data= 13;

    tree->right->right->left = new Node();
    tree->right->right->left->data=14;

    tree->right->right->right = new Node();
    tree->right->right->right->data=15;

    cout<<"\nLevel Order Travels :" ; levelorder(tree);

    cout<<"\nPreOrder Travels :"; preorder(tree);

    cout<<"\nInOrder Travels :"; inorder(tree);

    cout<<"\nPostOrder Travels :"; postorder(tree);

    return 0;
}
