#include<bits/stdc++.h>
#define maxN 1000001 
using namespace std;

vector<int> isPrime(maxN);
vector<int> primeRank(maxN);
vector<int> primePrime(maxN);

void seive(){
	for(int i=1;i<=maxN;i++)
		isPrime[i]=1;
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=maxN;i++){
		if(isPrime[i]){
			for(int j=i*i;j<=maxN;j+=i)
				isPrime[j]=0;
		}
	}
	primeRank=isPrime;
	primePrime[0]=0;
	for(int i=1;i<=maxN;i++){
		primeRank[i]+=primeRank[i-1];
		if(isPrime[primeRank[i]]){
			primePrime[i]=1;
		}
		else{
			primePrime[i]=0;
		}
	}

	for(int i=1;i<=maxN;i++){
		primePrime[i]+=primePrime[i-1];
	}

}

int main(){
	seive();
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int primePrimeCount = primePrime[r] - primePrime[l-1];
		cout<<primePrimeCount<<endl;
	}
	return 0;
}