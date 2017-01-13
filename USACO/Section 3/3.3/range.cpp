/*
ID: liaojh11
PROG: range
LANG: C++
*/
//Title: Home on the Range
//Type: DP
//Complexity: O(N^2)
//Solution: Refer to state transition below:
//State: dp[i][j] = maximum square that can be made at current spot
//Transition: dp[i][j] = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) + 1, N-1 >= i >= 0, N-1 >= j >= 0, then answer add up if dp[i][j] >= 2.
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
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
int readLL(long long &n){
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
int readDouble(double &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	if(!(~c)) return -1;
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	if(c != '.'){
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
	}
	double div = 1;
	for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
	n /= div;
	if(neg) n = -n;
	return 1;
}
int readStr(char *str){
	register char c = getchar();
	register int len = 0;
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len++] = c;
		c = getchar();
	}
	str[len] = '\0';
	//Just in case if needs to return arriving at end of line
	//if(c == 10) return 10;
	return 1;
}
int readStr(char *str, int len){
	//Reading string of size len
	for(int i = 0; i < len; i++){
		str[i] = getchar();
		if(!(~str[i])){
			str[i] = '\0';
			return -1;
		}
		//Remove this if str can't go to next line
		/*if(str[i] == 10){
			str[i] = '\0';
			return 10;
		}*/
	}
	str[len] = '\0';
	return 1;
}
void readIntArr(int *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readInt(n[i]))){
			n[i] = 0;
			return;
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
			return;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
			return;
		}
}

int min(int a, int b, int c){
	if(a > b) a = b;
	if(a > c) a = c;
	return a;
}
int main(){
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	int N;
	readInt(N);
	int dp[N+5][N+5];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			dp[i][j] = getchar() - '0';
		getchar();
	}
	int ans[255];
	memset(ans, 0, sizeof(ans));
	for(int i = N-1; i >= 0; i--)
		for(int j = N-1; j >= 0; j--){
			if(dp[i][j])
				dp[i][j] = min(dp[i][j+1], dp[i+1][j], dp[i+1][j+1]) + 1;
			if(dp[i][j] >= 2)
				for(int k = 2; k <= dp[i][j]; k++)
					ans[k]++;
		}
	for(int i = 2; i <= 250 && ans[i]; i++)
		printf("%d %d\n", i, ans[i]);
	return 0;
}