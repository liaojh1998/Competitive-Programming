#include <bits/stdc++.h>
using namespace std;

class FastIO{
private:
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("D.in", "r", stdin);
			freopen("D.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

void FastIO::solve(){
	int T, N;
	readInt(T);
	vector<int> sq;
	for(int i = 1; i*i <= 10000; i++)
		sq.push_back(i*i);
	int dp[10005], size = sq.size();
	memset(dp, 1, sizeof(dp));
	dp[0] = 0;
	//Knapsack
	for(int i = 1; i <= 10000; i++)
		for(int j = 0; j < size; j++)
			if(i-sq[j] >= 0 && dp[i-sq[j]]+1 < dp[i])
				dp[i] = dp[i-sq[j]]+1;
	for(int idx = 1; idx <= T; idx++){
		readInt(N);
		printf("Case #%d: %d\n", idx, dp[N]);
	}
}