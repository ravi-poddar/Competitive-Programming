#include<iostream>
#define C 1000000007

using namespace std;

typedef long long ll;

void mult(ll A[][2],ll B[][2]){
    ll res[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res[i][j] = 0;
            for(int k=0;k<2;k++){
                res[i][j] = (res[i][j]%C + ((A[i][k]%C)*(B[k][j]%C))%C)%C;
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j] = res[i][j];
        }
    }
}

void power(ll A[][2],ll n){
    ll I[2][2];
    I[0][0]=I[1][1]=1;
    I[0][1]=I[1][0]=0;

    while(n>0){
        if(n%2){
            mult(I,A);
            n--;
        }

        mult(A,A);
        n/=2;
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j] = I[i][j];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll A[2][2] = {{0,1},{1,1}};
        power(A,n);
        ll nthfib = (((a%C)*(A[0][0]%C))%C+((b%C)*(A[1][0]%C))%C)%C;
        cout<<nthfib<<endl;
    }
    
    return 0;
}