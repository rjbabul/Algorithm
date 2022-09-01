#include<bits/stdc++.h>
#define mx 400000002
using namespace std;
bool isprime[mx];
typedef long long int ll;
vector<ll> primes;
void sieve( ){

   for(ll i =3;i<mx; i+=2){
    if(isprime[i]==0){
        for(ll j=i*i;j<mx;j+=i) isprime[j]=1;
    }
   }
   primes.push_back(2);

   for(ll i=3;i<mx;i+=2) if(isprime[i]==0) primes.push_back(i);

}

void sol(ll l, ll r){
    bool prime[r-l+1];
    ll base, current_prime;
    if(l==1) prime[0]=1;

    for(ll i = 0; primes[i]*primes[i]<=r;i++){
        current_prime = primes[i];
        base = (l/current_prime)* current_prime;
        if(base<l) base+= current_prime;
        for(ll j = base; j<=r;j+=current_prime) prime[j-l]= 1;
        if(base == current_prime) prime[base-l]=0;
    }

    for(ll i=0;i<=r-l;i++){
        if(prime[i]==0) cout<<i+l<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll l,r;
    while(cin>>l>>r)
    sol(l,r);
    return 0;
}
