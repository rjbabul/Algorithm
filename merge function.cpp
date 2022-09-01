#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    string ev,od;
    int t;
    cin>>t;
    while(t--){
            cin>>str;
        for(int i=0;i<str.length();i++){
            if(str[i]%2==0) ev+= str[i];
            else od+=str[i];
        }
       merge(od.begin(), od.end(), ev.begin(), ev.end(),str.begin());
       cout<<str<<endl;
       str.clear();
       od.clear();
       ev.clear();
    }
    return 0;
}
