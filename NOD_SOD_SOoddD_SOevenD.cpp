
#include<bits/stdc++.h>
#include<set>
#include<iterator>
#include<set>
#define unsinged long long int long
using namespace std;
int main()
{
    set<long long int> st;
    set<long long int >:: iterator it;
    map< long long int,long long int > mp;

    unsigned long long int num,i=2;
    while(cin>>num)
    {
        i=2;
        while(num>1)
        {
            if(num%i==0)
            {
                st.insert(i);
                while(num%i==0)
                {
                    mp[i]++;
                    num=num/i;
                }

            }
            else
                i++;
        }
        unsigned long long int  nod=1,sod=1, ans=1,odd_sum=1;
        for( it=st.begin(); it!=st.end(); it++)
        {
            //cout<<*it<<endl;
            nod*= (mp[*it]+1);
            {
                for(int i=0; i<=mp[*it]; i++)
                {
                    ans*= *it;
                }
                sod=sod*((ans-1)/(*it-1));
                ans=1;
            }
        }
        for( it=st.begin(); it!=st.end(); it++)
        {
            //cout<<*it<<endl;
            // nod*= (mp[*it]+1);
            if(*it%2==1)
            {
                for(int i=0; i<=mp[*it]; i++)
                {
                    ans*= *it;
                }
                odd_sum=odd_sum*((ans-1)/(*it-1));
                ans=1;
            }
        }
        cout<<"Number Of Divisor is : "<<nod<<endl;
        cout<<"Sum of divisor is "<<sod<<endl;
        cout<<"Sum of even divisor is : "<<sod-odd_sum<<endl;
        cout<<"Sum of odd divisor is "<<odd_sum<<endl;
        st.clear();
        mp.clear();
        cout<<endl<<endl;
    }
    return 0;
}
