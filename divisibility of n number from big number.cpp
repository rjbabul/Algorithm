#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int num;
    while(cin>>str>>num){
            int r=0;
        for(int i=0;i<str.length();i++){
            r=(r*10)+(str[i]-'0');
            r=r%num;
        }
        if( r==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
