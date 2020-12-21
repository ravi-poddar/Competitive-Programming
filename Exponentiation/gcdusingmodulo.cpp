#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define C 1000000007
using namespace std;

ll power(ll base, ll p, ll mod){
    ll res=1;
    while(p>0){
        if(p%2){
            res=((res%mod)*(base%mod))%mod;
            p--;
        }
        base = ((base%mod) * (base%mod))%mod;
        p/=2;
    }
    return res;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll a2n = power(a,n,C)%C;
        ll b2n = power(b,n,C)%C;
        if(a==b){
            cout<<(a2n+b2n)%C<<"\n";
            continue;
        }
        ll diff = a-b;
        ll gcd=1;
        for(ll i=1;i*i<=diff;i++){
            if(diff%i==0){
                ll temp = (power(a,n,i) + power(b,n,i))%i;
                if(temp==0){
                    gcd = max(gcd,i);
                } 
                temp = (power(a,n,diff/i) + power(b,n,diff/i))%(diff/i); 
                if(temp==0){
                    gcd = max(gcd,diff/i);
                } 
            }
        }
        cout<<gcd%C<<"\n";
    }
    return 0;
}