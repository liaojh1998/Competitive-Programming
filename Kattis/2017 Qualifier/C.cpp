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
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

void FastIO::solve(){
	int N;
	readInt(N);
	int arr[N+5];
	for(int i = 0; i < N; i++)
		readInt(arr[i]);
	int stop = arr[N-1]+arr[N-2];
	int dp[stop+5];
	memset(dp, 1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < stop; i++)
		for(int j = 0; j < N; j++)
			if(i-arr[j] >= 0 && dp[i] > dp[i-arr[j]]+1)
				dp[i] = dp[i-arr[j]]+1;
	if(N <= 2){
		printf("canonical\n");
	}else{
		bool nope = false;
		for(int i = arr[2]+2; i < stop && !nope; i++){
			int cur = i, amount = 0;
			for(int j = N-1; j >= 0; j--)
				while(cur >= arr[j]){
					amount += cur/arr[j];
					cur %= arr[j];
				}
			if(amount != dp[i])
				nope = true;
		}
		if(nope)
			printf("non-canonical\n");
		else
			printf("canonical\n");
	}
}