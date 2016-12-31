//Title: Flight Planner
//Type: DP
//Complexity: O((X/100)*10)
//Solution: Similar to UVa 116 Unidirectional TSP, flying should be done as: current position -> cost + wind -> new position, finishing position should be after cost + wind of last column, thus
//State: dp[i][j] = minimum fuel to reach altitude i at j*100 miles, base case dp[0][0] = 0, answer at dp[0][X] not dp[0][X-1]
//Transition: dp[i][j] = min(dp[i][j-1] + 30 - wind[i][j-1], dp[i-1][j-1] + 60 - wind[i-1][j-1], dp[i+1][j-1] + 20 - wind[i+1][j-1])
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
	if(c != '.'){
		if(neg) n = -n;
		return 1;
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
	int C;
	readInt(C);
	while(C--){
		int X;
		readInt(X);
		X /= 100;
		int dp[10][X+1], wind[10][X];
		memset(dp, 100, sizeof(dp));
		for(int i = 9; i >= 0; i--)
			for(int j = 0; j < X; j++)
				readInt(wind[i][j]);
		dp[0][0] = 0;
		for(int j = 1; j <= X; j++)
			for(int i = 0; i < 10; i++){
				if(dp[i][j] > dp[i][j-1] + 30 - wind[i][j-1])
					dp[i][j] = dp[i][j-1] + 30 - wind[i][j-1];
				if(i && dp[i][j] > dp[i-1][j-1] + 60 - wind[i-1][j-1])
					dp[i][j] = dp[i-1][j-1] + 60 - wind[i-1][j-1];
				if(i != 9 && dp[i][j] > dp[i+1][j-1] + 20 - wind[i+1][j-1])
					dp[i][j] = dp[i+1][j-1] + 20 - wind[i+1][j-1];
				//printf("%d%s", dp[i][j], i == 9 ? "\n" : " ");
			}
		printf("%d\n\n", dp[0][X]);
	}
	return 0;
}