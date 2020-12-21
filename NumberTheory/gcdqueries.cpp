#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
            cin>>v[i];
        vector<ll>leftGCD(n);
        vector<ll>rightGCD(n);
        leftGCD[0]=v[0];
        rightGCD[n-1]=v[n-1];
        for(ll i=1;i<n;i++){
            leftGCD[i]=__gcd(v[i],leftGCD[i-1]);
            rightGCD[n-i-1]=__gcd(v[n-i-1],rightGCD[n-i]);
        }
        while(q--){
            ll left,right;
            cin>>left>>right;
            left--;
            right--;
            if(left-1<0){
                cout<<rightGCD[right+1]<<"\n";
            }
            else if(right+1>=n){
                cout<<leftGCD[left-1]<<"\n";
            }
            else{
                cout<<__gcd(leftGCD[left-1],rightGCD[right+1])<<"\n";
            }
        }
    }
    return 0;
}