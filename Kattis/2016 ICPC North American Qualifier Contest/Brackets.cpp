#include <bits/stdc++.h>
using namespace std;

class FastIO{
private:
	int readStr(char *str){
		register char c = getchar();
		register int len = 0;
		if(!(~c)) return -1;
		while(c < 33 && ~c) c = getchar();
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
		return 1;
	}

	int size;
	char str[5005];
	int dp[5005][5005][3];

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
		memset(dp, -1, sizeof(dp));
	}

	int f(const int&, const char&);
	bool rec(int, int, int);
	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

int FastIO::f(const int& s, const char& c){
	if(s != 1 && c == '(') return 1;
	else if(s == 1 && c == ')') return 1;
	return 0;
}

bool FastIO::rec(int d, int l, int s){
	if(dp[d][l][s] != -1) return dp[d][l][s];
	if(d == size) return (dp[d][l][s] = (d - l == l));
	return dp[d][l][s] = (d-l > l) ? 0 : (rec(d+1, l+f(s, str[d]), s) || (s == 0 && rec(d+1, l+f(s+1, str[d]), s+1)) || (s == 1 && rec(d+1, l+f(s+1, str[d]), s+1)));
}

void FastIO::solve(){
	readStr(str);
	size = strlen(str);
	printf("%s\n", rec(0, 0, 0) ? "possible" : "impossible");
}