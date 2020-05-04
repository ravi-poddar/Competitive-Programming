#include<bits/stdc++.h>

using namespace std;

//Recursive function call to find (a^b)%c in complexity O(log b)
long long modexp1(long long a, long long b, long long c){

    if(b==0) //if power is 0 return 1 (base case)
        return 1;

    int p = modexp1(a,b/2,c)%c; //recursive call to function itself until base case becomes true (winding phase)
    p=(p*p)%c;

    return (b&1)?(a*p)%c:p; //returning back values in unwinding phase
}

//Iterative function call to find (a^b)%c in complexity O(log b)
long long modexp2(long long a, long long b, long long c){
    long long res=1; //result is initailized to 1

    if(a%c==0) //if base is divided by mod value 'c' then return 0
        return 0;

    while(b>0){

        if(b&1) //if b is odd multiply result with base no. (satisfies the condition when bit of 'b' is 1)
            res=(res*a)%c;

        b=b>>1; //divide b by 2 and assign back to b
        a=(a*a)%c; //squaring a and assign back to a
    }

    return res;
}

int main(){
    long long a=3; //variable for base
    long long b=3; //variable for power
    long long c=10; //variable for mod

    // cout<<"Enter base ,power and mod values:"<<endl;
    // cin>>a>>b>>c;

    cout<<"( "<<a<<" to the power "<<b<<" ) % "<<c<<" is: "<<modexp1(a,b,c)<<endl; //Recursive function call to find (a^b)%c

    cout<<"( "<<a<<" to the power "<<b<<" ) % "<<c<<" is: "<<modexp2(a,b,c)<<endl; //Iterative function call to find (a^b)%c

    return 0;
}