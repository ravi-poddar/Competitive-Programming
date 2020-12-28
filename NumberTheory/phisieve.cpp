// find an efficient way to find the phi of number from 1 to n, n<=10^6

#include<iostream>
#define maxN 1000001

using namespace std;

int phi[maxN];

//Time complexity: O(n*log(log n))
void init(){
    for(int i=1;i<maxN;i++)
        phi[i]=i;

    for(int i=2;i<maxN;i++){
        if(i==phi[i]){
            for(int j=i;j<maxN;j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}


int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"phi["<<n<<"] = "<<phi[n]<<endl;
    }
    return 0;   
}

