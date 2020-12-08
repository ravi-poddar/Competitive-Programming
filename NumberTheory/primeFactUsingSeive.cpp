#include<iostream>
#define maxN 1000000
using namespace std;

int arr[maxN+1];

void seive(){
    for(int i=1;i<=maxN;i++)
        arr[i]=-1;

    for(int i=2;i<=maxN;i++){
        if(arr[i]==-1){
            for(int j=i;j<=maxN;j+=i)
                if(arr[j]==-1)
                    arr[j]=i;
        }
    }
}

void primeFact(int n){
    while(n>1){
        cout<<arr[n]<<" ";
        n/=arr[n];
    }
}


int main(){
    seive();
    int n;
    cout<<"\nEnter a number: ";
    cin>>n;
    cout<<"\nPrime factorization of "<<n<<" : \n";
    primeFact(n);
    return 0;
}