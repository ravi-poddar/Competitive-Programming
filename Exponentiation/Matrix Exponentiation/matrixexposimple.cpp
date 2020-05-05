#include<bits/stdc++.h>

using namespace std;

#define C 1000000007 //modulo c=10^9+7

//function for multiplication of 2d arrays
// multiplying matrix a and t and storing the result in a matrix again
void mul(long int a[2][2],long int t[2][2]){
    long int temp[2][2];
    for(long int i=0;i<2;i++){
        for(long int j=0;j<2;j++){
            temp[i][j]=0;
            for(long int k=0;k<2;k++){
                temp[i][j]=((temp[i][j]%C)+(((a[i][k]%C)*(t[k][j]%C))%C))%C; //since the value becomes very large we have to get in range by using modulo C
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j]=temp[i][j];
        }
    }
}

//function for getting exponent of matrix
void pow(long int a[2][2],long int n){
    long int b[2][2]={1,1,1,0}; // making a copy of original matrix so that we don't lost this matrix, (because we are overwriting the original matrix
    if(n==0){ //returns identity matrix
        a[0][0]=1;
        a[0][1]=0;
        a[1][0]=0;
        a[1][1]=1;
        return;
    }
    pow(a,n/2);
    mul(a,a);
    if(n%2==0){
        return;
    }
    else{
        mul(a,b);
        return;
    }
}

//function for getting the sequence i.e. value of f(n)
long int fib(long int x,long int y,long int n){
    long int a[2][2]={1,1,1,0};
    if(n==1)
        return y;
    
    pow(a,n-1);
    return (((a[0][0]%C)*(y%C))%C+((a[0][1]%C)*(x%C))%C)%C; 
}

int main(){
    long int t;
    cin>>t;
    while(t--){
        long int x,y,n;
        cin>>x>>y>>n;
        cout<<fib(x,y,n)<<endl; //fib function is called that returns the sequence value
    }
    return 0;
}