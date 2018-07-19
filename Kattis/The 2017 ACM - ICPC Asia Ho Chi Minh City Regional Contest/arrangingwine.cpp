#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000007)

long long dp[2][2005][2005];

long long dfs(int c, int R, int W, const int& d){
	if(dp[c][R][W])
		return dp[c][R][W];
	if(R && W){
		long long ans = 0;
		if(c){
			for(int i = 1; i <= d && i <= R; i++)
				ans = (ans + dfs(1-c, R-i, W, d))%MOD;
			return (dp[c][R][W] = ans);
		}else{
			int t = W-(R/d-1-((R%d) ? 1 : 0));
			for(int i = 1; i <= W && i <= t; i++)
				ans = (ans + dfs(1-c, R, W-i, d))%MOD;
			return (dp[c][R][W] = ans);
		}
	}
	return (dp[c][R][W] = 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int R, W, d;
	cin >> R >> W >> d;
	//time_t start = clock();
	printf("%lld\n", (dfs(0, R, W, d) + dfs(1, R, W, d))%MOD);
	//time_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
	return 0;
}