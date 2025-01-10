#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, h;
vector <int> vec[51];
int dp[51][1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> h;
	cin.ignore(1);

	for (int i = 1; i <= n; i++) {
		string temp;
		getline(cin, temp, '\n');
		
		for(int j=0;j<temp.size();j++)
			if(temp[j]==' '||j==0)
				vec[i].push_back(stoi(&temp[j]));

			
	}
	

	
	//solve

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= h; j++) {
			
			
			for (int k = 0; k < vec[i].size(); k++) {
				
				if (j >= vec[i][k]) {
					dp[i][j] += dp[i - 1][j - vec[i][k]];
					dp[i][j] %= 10007;
				}
			}		
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}


	cout << dp[n][h] << endl;


	return 0;
}