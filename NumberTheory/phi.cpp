//PHI , represents Euler's totient's function
//which is basically , for any number N,
//the numbers of numbers which are coprime with N , up to n
//Example: PHI(6) = 2
//gcd(1,6)=gcd(5,6)=1, i.e  
//the numbers of numbers which are coprime with 6 , up to 6 are 1 and 5
//PHI(N) = N*(P1-1)*(P2-1)*...*(PK-1)/(P1*P2*...*PK)
//Where, P1, P2,....,PK are prime factors of N

//Time complexity: O(SQRT(N))
#include<iostream>

using namespace std;

int phi(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res/=i;
            res*=(i-1);

            while(n%i==0){
                n/=i;
            }
        }
    }

    if(n>1){
        res/=n;
        res*=(n-1);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"PHI( "<<n<<" )="<<phi(n)<<endl;
    }
    return 0;
}