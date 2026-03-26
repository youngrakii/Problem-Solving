#include <iostream>
using namespace std;


int gcd(int m, int n){
	return n==0 ? m : gcd(n,m%n);
}

int lcm(int m, int n){
	return m * n / gcd(m,n);
}
int main() {
	// 코드 작성
	int M ,N;
	cin>>M>>N;

	cout<<gcd(M,N)<<"\n"<<lcm(M,N);
	return 0;
}