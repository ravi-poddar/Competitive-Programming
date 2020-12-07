//Sieve of Eratosthenes 
//Print the numbers from 0 to 10^6 which are prime
//n is range upto which we want prime numbers
//max value will be 10^6 , since 10^6 size max array would be declared
//Time Complexity: n*log(logn)

#include<iostream>
#define maxN 1000000

using namespace std;

int isPrime[maxN+1];

void seive(){
    for(int i=1;i<=maxN;i++)
        isPrime[i]=1;
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=maxN;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxN;j+=i){
                isPrime[j]=0;
            }
        }
    }
}

int main(){
    seive();
    cout<<"\nThe prime numbers from 1 to 1000000 are: ";
    for(int i=1;i<=maxN;i++)
        if(isPrime[i])
            cout<<i<<" ";
    return 0;
}