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
	
	#define MOD (1000000007)
	int dp[60][131][131], arr[60], N;

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	int f(const int& loc, int a1, int a2);
	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

void FastIO::solve(){
	int T;
	readInt(T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		readInt(N);
		for(int i = 0; i < N; i++)
			readInt(arr[i]);
		printf("%d\n", f(0, arr[0], arr[1]));
	}
}

int FastIO::f(const int& loc, int a1, int a2){
	if(loc >= N-1 && (!a1 || !a2))
		return (dp[loc][a1][a2] = 1);
	int sum = 0;
	for(int i = 0; i <= a1 && i <= a2; i++)
		sum = (sum + (dp[loc+1][a2-i][arr[loc+2]+i] ? dp[loc+1][a2-i][arr[loc+2]+i] : f(loc+1, a2-i, arr[loc+2]+i)))%MOD;
	return (dp[loc][a1][a2] = sum);
}