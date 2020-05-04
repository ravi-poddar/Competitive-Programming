#include<bits/stdc++.h>

using namespace std;

//Recursive function to find a to the power b in complexity O(log b)
long long fast1(long long a , long long b){

    if(b==0) //if power is 0 return 1
        return 1;

    long long p = fast1(a,b/2); //recursive call until b becomes 0 i.e. winding phase
                                //(calling itself again and again till base case becomes true and starts resturning back)

    //codes executed in unwinding phase i.e. while returning values back
    p=p*p;

    return b&1?a*p:p;
}

//Iterative Function to find a to the power b in complexity O(log b)
long long fast2(long long a , long long b){

    long long res=1; //Initializes result to 1
    while(b>0){

        if(b&1) //b&1 is same as (b%2!=0) i.e checks whether b is odd
            res=res*a;
        
        b=b>>1; //b>>1 is same as b/2 i.e. 'b' is divided by 2 and then assigns back to 'b'
        a=a*a;  //squaring a and then assigns back to a
    }
    return res;
}

int main(){
    long long a; //variable declared for base
    long long b; //variable declared for power
    cout<<"Enter base:"<<endl;
    cin>>a;
    cout<<"Enter power:"<<endl;
    cin>>b;

    //we have to find a^b i.e. a to the power b in O(log b)
    cout<<a<<" to the power "<<b<<" is: "<<fast1(a,b)<<endl; //Recursive call
    cout<<a<<" to the power "<<b<<" is: "<<fast2(a,b)<<endl; //Iterative call
    
    return 0;
}