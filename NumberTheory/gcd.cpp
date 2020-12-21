#include<iostream>

using namespace std;


//Time Complexity: log(min(a,b))
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    int a,b;
    cout<<"\nEnter two numbers: ";
    cin>>a>>b;

    cout<<"\nGCD of "<<a<<" and "<<b<<" is: "<<gcd(a,b);

    return 0;
}