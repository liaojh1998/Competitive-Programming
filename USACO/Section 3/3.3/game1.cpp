/*
ID: liaojh11
PROG: game1
LANG: C++
*/
//Title: A Game
//Type: DP
//Complexity: O(N^2)
//Solution: Seemed like an exceptionally hard problem until I can find the recurrence, use prefix sum - previous optimal strategy = next player optimal strategy to advantage
//State: dp[i][j] = the maximum sum player 1 can get from the sequence, base case dp[i][i] = arr[i]
//Transition: dp[i][j] = max(sum[i+1][j]-dp[i+1][j]+arr[i], sum[i][j-1]-dp[i][j-1]+arr[j]), where sum[i][j] represents the total sum between index i and j, 0 <= j < N, j-1 >= i >= 0
		//	For example: 4 7 2 9
		//	dp[0][1] = max(4, 7) = 7
		//	dp[1][2] = max(7, 2) = 7
		//	dp[0][2] = max(4 + (9 - 7), (11 - 7) + 2) = 6 //Either way player 1 will get 6
		//	dp[2][3] = max(2, 9) = 9
		//	dp[1][3] = max(7 + (11 - 9), (9 - 7) + 9) = 11 //Player 1 will take the sum - optimal strategy player 2 takes + leftovers
		//	dp[0][3] = max(4 + (18 - 11), (13 - 6) + 9) = 16 //9 and 7 is more optimal to take than 4 and 7
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
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	int N;
	readInt(N);
	int dp[N+5][N+5], arr[N+5], sum[N+5][N+5];
	for(int j = 0; j < N; j++){
		readInt(arr[j]);
		sum[j][j] = dp[j][j] = arr[j];
		for(int i = j-1; i >= 0; i--){
			sum[i][j] = sum[i+1][j] + arr[i];
			dp[i][j] = max(sum[i+1][j]-dp[i+1][j]+arr[i], sum[i][j-1]-dp[i][j-1]+arr[j]);
		}
	}
	printf("%d %d\n", dp[0][N-1], sum[0][N-1]-dp[0][N-1]);
	return 0;
}