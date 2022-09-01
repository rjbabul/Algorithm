#include<bits/stdc++.h>
using namespace std;
set<int > stl;
int lps(string str)
{
    int n = str.length();

    int lp[n][n];
    memset(lp,0,sizeof(lp));
    for(int i=0; i<n; i++)
        lp[i][i]=1;

    for(int st=2; st<=n; st++)
    {

        for(int i=0; i<n-st+1; i++)
        {
            int j= i+st-1;
            if(str[i]==str[j] && st==2)
                lp[i][j]=2;
            else if(str[i]==str[j])
                lp[i][j]=2+lp[i+1][j-1];
            else
                lp[i][j]= max(lp[i+1][j],lp[i][j-1]);
        }
    }

    /// Find palindrome sub sequence

    int i=0,j=n-1;
    while(1)
    {

        if(i==j)
        {
            stl.insert(i);
            break;
        }
        else if(lp[i][j]==2)
        {
            stl.insert(i);
            stl.insert(j);
            break;
        }

        if(lp[i][j]== lp[i][j-1])
            j--;
        else if(lp[i][j]== lp[i+1][j])
            i++;

        else
        {
            stl.insert(i);
            stl.insert(j);
            i++;
            j--;
        }
    }

    set<int>::iterator it;
    for(it=stl.begin(); it!=stl.end(); it++)
        cout<<str[*it];
    cout<<endl;


    return lp[0][n-1];

}
int main()
{


    string str;
    cin>>str;

    cout<<"LPS is : "<<lps(str)<<endl;

    return 0;
}
