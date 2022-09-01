#include<bits/stdc++.h>
using namespace std;
int queen[100],colunm[100],diagonal1[100], diagonal2[100];
int flag =0;
int result[100][100];
void nqueen(int row, int n)
{
    if(row == n+1)
    {

        cout<<"\n\n (Row ,Column) "<<endl<<endl;
        for(int i=1; i<=n; i++)
        {
            result[i][queen[i]]=1;
            cout<<"   ("<<i<<"  ,  "<<queen[i]<<")"<<endl;
        }
        flag =1;
        return ;
    }

    for(int i=1; i<=n; i++)
    {

        if(colunm[i] || diagonal2[row+i] || diagonal1[n+row-i])
            continue;
        queen[row]= i;
        colunm[i]= diagonal2[row+i]= diagonal1[n+row-i] =1;
        if(flag ==0)
            nqueen(row+1, n);
        colunm[i]= diagonal2[row+i]= diagonal1[n+row-i]  =0;
    }
}
int main()
{
    int n;
    cout<<"input size of board: ";
    cin>>n;
    nqueen(1,n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

              cout<<result[i][j]<<"  ";

        } cout<<endl<<endl;
    }

    return 0;
}
