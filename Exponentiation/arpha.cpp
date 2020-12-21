#include<iostream>
#define ll long long
using namespace std;

int lastDigit(ll base, ll power, ll mod){
    ll res=1;
    while(power){
        if(power%2){
            res = (res*base)%mod;
            power--;
        }
        base = ((base%mod) * (base%mod))%mod;
        power/=2;
    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    cout<<lastDigit(1378,n,10)<<"\n";
    return 0;
}