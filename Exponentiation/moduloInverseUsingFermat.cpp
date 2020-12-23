#include<iostream>

using namespace std;


// Time Complexity: O(log (c-2))
// c must be prime
// gcd(a,c)=1

int modExp(int a,int b,int c){
    int res=1;
    while(b>0){
        if(b%2){
            res=(res*a)%c;
            b--;
        }
        a = (a*a)%c;
        b/=2;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int b,c;
        cin>>b>>c;
        cout<<"\n"<<b<<"^-1 = "<<modExp(b,c-2,c);
    }
    return 0;
}