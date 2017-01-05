//Title: Bar Codes
//Type: DP
//Complexity: O(k*n*m)
//Solution: I looked at multiple solution and found the one that made the most sense.
		//	My old solution tried dp[n][k][m], which was possible but I lost track of the recurrence due to this example:
		//	dp[i][j][k] = dp[i-1][j][k-1] + dp[i-1][j-1][k];
		//	dp[4][2][2] = dp[3][1][2] + dp[3][2][1] = 0;
		//	Of course, dp[4][2][2] = state 1100 = should be 1
		//	And looking at dp[4][2][3] = dp[3][1][3] + dp[3][2][2] = 3 is correct, the recurrence had me confused
		//	For example: dp[4][2][3] = 1100, 1000, 1110 = 3, which came from:
		//	dp[3][1][3] = 111(0) = 1
		//	dp[3][2][2] = 110(0), 100(0) = 2
		//	And relates perfectly.

		//	One online solution gave dp[i][j][k] = dp[i-1][j-1][m] + dp[i-1][j][k-1],
		//	Which allowed dp[4][2][2] to miraculously traverse dp[3][2][1] = dp[2][1][2] + dp[2][2][0] = 1
		//	To which I don't understand the logic but know that the state transitioned from dp[2][1][2] = 11 = 1
		//	Which gave dp[4][2][2] = 11(00) = 1100 = 1

		//	Presenting a much more understandable solution:
//State: dp[i][j] = total number of bar code combinations with i bars in j units, base case dp[1][i] = 1, i <= n && i <= m, since all 1 bar i units has 1 bar code
//Transition: dp[i][j] = sum(dp[i-1][j-k]), 1 <= k <= m, j-k >= 1
		//	Since m limits combinations, the limit recurs throughout all states
		//	Take n = 5, k = 3, m = 2 for example
		//	dp[3][5] = dp[2][4] + dp[2][3] = 11011, 11001, 10011 = 3
		//	where dp[2][4] = n = 4, k = 2, m = 2 = 1100(1) = 1
		//	and dp[2][3] = n = 3, k = 2, m = 2 = 110(11), 100(11) = 2

		//	which eliminates the m = 3 states from
		//	dp[2][4] = n = 4, k = 2, m = 3 = 1110(1), 1000(1) = 2
		//	dp[2][2] = n = 2, k = 2, m = 3 = 10(111) = 1
		//	and keeps dp[2][3] = n = 3, k = 2, m = 3 = 110(11), 100(11) = dp[2][3] when m = 2 since increase in limit m doesn't
		//	change the possible amount of combinations for dp[2][3]
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

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	long long dp[55][55];
	while(~readInt(n)){
		readInt(k);
		readInt(m);
		memset(dp, 0, sizeof(dp));
		//limit at n and m because this affects later dp
		for(int i = 1; i <= n && i <= m; i++)
			dp[1][i] = 1; //1 bar, i unit = always 1 bar code
		for(int i = 2; i <= k; i++)
			for(int j = i; j <= n; j++)
				for(int l = 1; l < j && l <= m; l++)
					dp[i][j] += dp[i-1][j-l];
		printf("%lld\n", dp[k][n]);
	}
	return 0;
}