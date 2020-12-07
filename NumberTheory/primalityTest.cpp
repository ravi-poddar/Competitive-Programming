#include<iostream>

using namespace std;

//Primality Test function: isPrime
//check whether a number 'n' is prime or not
//Time Complexity: O(sqrt(n))
bool isPrime(int n){
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

//driver program
int main(){
    int n;
    cout<<"\nEnter a number: ";
    cin>>n;
    if(isPrime(n)){
        cout<<n<<" is prime.";
    }
    else{
        cout<<n<<" is not prime.";
    }
    return 0;
}