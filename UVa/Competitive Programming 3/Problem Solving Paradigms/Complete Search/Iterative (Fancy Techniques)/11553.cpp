//Title: Grid Game
//Type: Complete Search + DP
//Complexity: O(n*2^n)
//Solution: Importance of this problem is to notice that the way alice crosses her rows doesn't matter,
		//	Bob's optimal play determines everything, thus, find the smallest number possible from different columns.
//State: dp[i][j] = minimum candies given at row i and bitmasked j columns
//Transition: dp[i][j|(1<<k)] = min(dp[i][j|(1<<k)], dp[i-1][j] + mat[i][k]), where mat[i][k] represent candies in ith row, jth column.
		//	0 <= i < n, 0 <= k < n, 1 <= j < (1<<n), where j should contain only i columns and !(j & (1<<k)) == true.
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
	int t;
	readInt(t);
	while(t--){
		int n;
		readInt(n);
		int mat[n+5][n+5];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				readInt(mat[i][j]);
		int dp[n+5][1<<n];
		memset(dp, 1, sizeof(dp));
		for(int i = 0; i < n; i++)
			dp[0][1<<i] = mat[0][i];
		for(int i = 1; i < n; i++)
			for(int j = 1; j < 1<<n; j++){
				int ctr = 0;
				for(int k = 0; k < n; k++)
					if(j & (1 << k)) ctr++;
				if(ctr != i) continue;
				for(int k = 0; k < n; k++)
					if(!(j & (1 << k)) && dp[i][j|(1<<k)] > dp[i-1][j] + mat[i][k])
						dp[i][j|(1<<k)] = dp[i-1][j] + mat[i][k];
			}
		printf("%d\n", dp[n-1][(1<<n)-1]);
	}
	return 0;
}