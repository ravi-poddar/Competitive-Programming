#include<iostream>
#define M 51
#define C 1000000007

using namespace std;

typedef long long ll;

//A for base
//I for identity 
ll A[M][M],I[M][M];

//mult for multiplication of two matrices
//Complexity: O(dimension^3)
void mult(ll A[][M],ll B[][M],ll dimension){
    //declaring res to store multiplication of matrices
    ll res[M][M];
    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            res[i][j]=0;
            for(ll k=0;k<dimension;k++){
                res[i][j]=((res[i][j]%C)+((A[i][k]%C)*(B[k][j]%C))%C)%C;
            }
        }
    }

    //copying result back to A
    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            A[i][j]=res[i][j];
        }
    }
}

//power function to find matrix exponentiation
//linear multiplication
//complextiy O(exp*(dimension^3))
// M - dimension
// N - power
// find (Mat A)^N 
//Time complexity: O(N*(M^3))
void power(ll A[][M],ll dimension, ll exp){
    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }

    //linear multiplication
    //complexity O(exp)
    for(ll i=0;i<exp;i++){
        mult(I,A,dimension);
    }

    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            A[i][j]=I[i][j];
        }
    }
}

//power function to find matrix exponentiation
//binary multiplication
//complextiy O((log exp)*(dimension^3))
// M - dimension
// N - power
// find (Mat A)^N 
//Time complexity: O(Log N*(M^3))
void binPower(ll A[][M],ll dimension, ll exp){
    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }

    while(exp>0){
        if(exp%2){
            mult(I,A,dimension);
            exp--;
        }

        mult(A,A,dimension);
        exp/=2;
    }


    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            A[i][j]=I[i][j];
        }
    }
}

//prllMatrix for printing matrix element
void prllMatrix(ll A[][M],ll dimension){
    for(ll i=0;i<dimension;i++){
        for(ll j=0;j<dimension;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    //t for testcases
    ll t;
    cin>>t;

    while(t--){
        ll dimension,exp;
        cin>>dimension>>exp;

        //taking input for base matrix A
        for(ll i=0;i<dimension;i++){
            for(ll j=0;j<dimension;j++){
                cin>>A[i][j];
            }
        }

        //call to power function to find (Mat A) ^ exp
        // power(A,dimension,exp);
        binPower(A,dimension,exp);

        prllMatrix(A,dimension);
    }
    return 0;
}