#include <iostream>
#include <vector>

using namespace std;


bool isPrime(int n){
	if(n==1) return false;

	int cnt=0;

	for(int i=1; i<=n; i++){
		if(n%i==0) cnt++;
	}

	if(cnt==2) return true;
	else return false;
}



int main() {
	// 코드 작성
	int T;
	cin>>T;
	vector<int> v;


	for(int i=0; i<T; i++){
		int k;
		cin>>k;
		v.push_back(k);
	}


	int count=0;
	for(int i=0; i<T; i++){
		if(isPrime(v[i])) count++;
	}

	cout<<count<<"\n";
	return 0;
}