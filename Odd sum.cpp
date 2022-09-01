#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,sum;
    vector<int> me,mo,pe,po;
    cin>>n;
    sum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>0){
            sum+=x;
            if(x%2==1)po.push_back(x);
        }
        else{
            if(x%2==0)me.push_back(x);
            else mo.push_back(x);
        }

    }
    sort(mo.begin(), mo.end());

     sort(po.begin(), po.end());
     if(sum%2!=0){
        cout<<sum<<endl;
        return 0;
     }
     else if(po.size()>0 && mo.size()>0){
        sum-= min(po[0],abs(mo[mo.size()-1]));
     }
     else if(po.size()>1) sum-= po[0];
     else sum-= abs(mo[mo.size()-1]);

     cout<<sum<<endl;

    return 0;
}
