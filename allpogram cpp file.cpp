#include<bits/stdc++.h>
#include<map>
#include<vector>
#define mx 2000007
#define pimax 2000007
using namespace std;

typedef long long int ll;
ll no_pi[pimax],mark[pimax],so_pi[pimax];
ll sqr_prime = sqrt(mx);
vector< long long int > primes;
bool isprime[mx];

/// Prime generate function sieve()

void sieve()
{

    isprime[0]= isprime[1]= true;
    isprime[2]= false;
    isprime[3]=false;

    for(ll i =3 ; i<= sqr_prime; i+=2)
    {
        if(isprime[i]== false )
            for( ll j= i*2; j<mx; j+=i)
            {
                isprime[j]= true;
            }
    }
    primes.push_back(2);

    for(ll i=3; i<mx; i+=2)
        if( isprime[i]== false)
            primes.push_back(i);
}

///segment sieve
/// seg_prime generate


void segment_sieve(ll l, ll r)
{
    ll base, current_prime;
    bool seg_prime[r-l+1];
    if (l==1)
        seg_prime[0]=1;

    sieve();


    for(ll i = 0 ; primes[i]*primes[i]<=r; i++)
    {
        current_prime = primes[i];
        base = (l/current_prime)*current_prime;
        if(base< l)
            base+= current_prime;

        for(ll j = base; j<=r; j+=current_prime)
            seg_prime[j-l]=1;

        if(current_prime== base )
            seg_prime[base-l] =0;
    }

    for(ll i=0; i<=r-l; i++)
    {
        if(seg_prime[i]==0)
            cout<<i+l<<endl;
    }


}

///Pi function Generate co-prime


void pi_function(){
   for(int i =0; i<pimax;i++) no_pi[i]=i;

   for(int i=2;i<pimax;i++){
    if(mark[i]==0){
        for(int j=i;j<pimax;j+=i){
            mark[j]=1;
            no_pi[j]= (no_pi[j]/i)*(i-1);
        }
    }
   }
   for(int i= 2;i<pimax;i++) so_pi[i]= (no_pi[i]*i)/2;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
