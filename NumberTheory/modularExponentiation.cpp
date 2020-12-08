#include<iostream>

using namespace std;

int power(int base, int exp, int mod){
    int res=1;
    while(exp){
        if(exp%2)
            res = (res*base)%mod,exp--;
        base = (base*base)%mod,exp/=2; 
    }
    return res;
}

int main(){
    int base,exp,mod;
    cout<<"\nEnter base, exponent, mod: ";
    cin>>base>>exp>>mod;
    cout<<"( "<<base<<" ^ "<<exp<<" ) % "<<mod<<" : "<<power(base,exp,mod)<<endl;
    return 0;
}