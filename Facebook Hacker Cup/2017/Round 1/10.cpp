//Title: Pie Progress
//Type: DP
//Complexity: O(N^2*M + N*(M+M*logM))
//Solution: I am very unsure whether or not this will fit within bounds, knapsack definitely will not.
//State: dp[i][j] = minimum cost required to purchase j pies on ith day, base case dp[0][0] = 0.
//Transition: dp[i][j] = min(dp[i-1][j], dp[i-1][j-k] + arr[i][k]), 1 <= i <= N, 1 <= j <= N, 1 <= k <= M, use previous or use new, basically.
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
	//Required for this problem
	if(c == '-') return '-';
	if(c == '+') return '+';
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

#define INF (400000000)
int main(){
	freopen("10input.txt", "r", stdin);
	freopen("10output.txt", "w", stdout);
	int T;
	readInt(T);
	for(int index = 1; index <= T; index++){
		int N, M;
		readInt(N);
		readInt(M);
		int dp[N+5][N+5], arr[N+5][M+5];
		memset(arr, 0, sizeof(arr));
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++)
				readInt(arr[i][j]);
			sort(arr[i]+1, arr[i]+1+M);
			for(int j = 1; j <= M; j++)
				arr[i][j] = arr[i][j-1] - (j-1)*(j-1) + arr[i][j] + j*j;
		}
		fill_n(dp[0], N+1, INF);
		dp[0][0] = 0;
		for(int i = 1; i <= N; i++){
			memcpy(dp[i], dp[i-1], sizeof(dp[i-1]));
			for(int j = 1; j <= M; j++)
				for(int k = j; k <= i*M && k <= N; k++)
					if(dp[i][k] > dp[i-1][k-j] + arr[i][j])
						dp[i][k] = dp[i-1][k-j] + arr[i][j];
		}
		printf("Case #%d: %d\n", index, dp[N][N]);
	}
	return 0;
}