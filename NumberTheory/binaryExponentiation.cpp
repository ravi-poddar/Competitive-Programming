#include<iostream>

using namespace std;

int power(int base, int exp){
    int res=1;
    while(exp){
        if(exp%2)
            res*=base,exp--;
        base*=base,exp/=2;
    }
    return res;
}

int main(){
    int base,exp;
    cout<<"\nEnter base: ";
    cin>>base;
    cout<<"\nEnter power: ";
    cin>>exp;
    cout<<base<<" ^ "<<exp<<" : "<<power(base,exp)<<endl;;
    return 0;
}