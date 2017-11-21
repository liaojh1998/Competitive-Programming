#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int P;
	cin >> P;
	while(P--){
		int K, n, m, k;
		cin >> K >> n >> m >> k;
		long long dp[n+1];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++)
				if(j < m || (j-m)%k)
					dp[i] += dp[i-j];
			if(i < m || (i-m)%k) dp[i]++;
		}
		cout << K << " " << dp[n] << endl;
	}
	return 0;
}