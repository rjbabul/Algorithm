#include<bits/stdc++.h>
using namespace std;
int main()
{
    double num,sum=0;
    while(cin>>num){
            sum=0;
        for(float i=1;i<=num;i++){
            sum+= log10(i);
        }
    cout<<(long int)(ceil(sum))<<endl;
    }
    return 0;
}
