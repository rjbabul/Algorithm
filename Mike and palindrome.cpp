#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n;
    while(cin>>str){
        n=str.length();
        int c=0;
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1])c++;
        }
        if(n%2==0 && c==1)cout<<"YES"<<endl;
        else if(n%2==1 && c<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
