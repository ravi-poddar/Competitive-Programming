#include<iostream>
#define P 1000000007
#define maxN 10000001
using namespace std;
//We have to calculate C(n,k)%P = (n!/(k! * (n-k)!))%P
//C(n,k)%P = (n! % P)/((k! %P) * ((n-k)!%P))

int fact[maxN];

void factorial(){
    fact[0]=fact[1]=1;
    for(int i=2;i<maxN;i++)
        fact[i] = (fact[i-1]*1LL*i)%P;
}

int power(int a,int b){
    int res=1;
    while(b>0){
        if(b%2){
            res = (res*1LL*a)%P;
            b--;
        }
        a = (a*1LL*a)%P;
        b/=2;
    }
    return res;
}

int C(int n, int k){
    if(k>n)
        return 0;
    int res = fact[n]; //fact[n] = (n! % P)
    // cout<<fact[n]<<endl;
    // cout<<power(fact[k],P-2)<<endl;
    // cout<<power(fact[n-k],P-2)<<endl;
    res = (res*1LL*power(fact[k],P-2))%P;  //power(fact[k],P-2) = 1/k!
    res = (res*1LL*power(fact[n-k],P-2))%P; //power(fact[n-k],P-2) = 1/(n-k)!
    return res;
}

int main(){
    factorial();
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<"C( "<<n<<", "<<k<<" ) = "<<C(n,k)<<endl;
    }
}