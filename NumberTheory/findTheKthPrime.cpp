#include<iostream>
#include<vector>
#define maxN 100000000
using namespace std;

bool isPrime[maxN+1];
vector<int>kthPrime;

void seive(){
    for(int i=1;i<=maxN;i++)
        isPrime[i]=true;
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=maxN;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxN;j+=i)
                isPrime[j]=false;
        }
    }
}


int main(){
    seive();
    for(int i=0;i<=maxN;i++){
        if(isPrime[i])
            kthPrime.push_back(i);
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<kthPrime[n-1]<<endl;
    }
    return 0;
}