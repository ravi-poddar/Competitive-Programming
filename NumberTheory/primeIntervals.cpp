#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	if(n==1)
		return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main(){
	int left,right;
	cin>>left>>right;
	for(int i=left;i<=right;i++){
		if(isPrime(i))
			cout<<i<<" ";
	}
	return 0;
}