#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 코드 작성
	int A,B;
	cin>>A>>B;

	vector<int> v;

	for(int i=1; i<=50; i++){
		for(int j=1; j<=i; j++){
			v.push_back(i);
		}
	}

	int sum=0;

	for(int i=A-1; i<B; i++){
		sum+=v[i];
	}

	cout<<sum<<"\n";
	return 0;
}