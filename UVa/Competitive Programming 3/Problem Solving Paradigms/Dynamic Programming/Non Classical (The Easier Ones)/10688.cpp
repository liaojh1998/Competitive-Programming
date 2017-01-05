//Title: The Poor Giant
//Type: DP
//Complexity: O(n^3)
//Solution: Very misleading question, let's show how 6 0 works
		//	1 = 3 + 1
		//	2 = 3 + 1
		//	3 = 3
		//	4 = 3 + 5
		//	5 = 3 + 5
		//	6 = 3 + 5
		//	Total = 36
		//	For days I wondered whether it was 1 = 3 + 5 + 1 or 4 = 3 + 1 + 5
		//	It's not a sequence of eating apples, nor the minimum weight of finding out whether an apple is sweet
		//	But a minimum total that averages out all the minimum weight of finding out whether an apple is sweet with different sequences
		//	that all starts out by eating the same apple.
		//	Recurrence exists in the example above of eating weight 3 6 times, weight 1 2 times, and weight 5 3 times, thus the state:
//State: dp[i][j] = minimum total weight to find all sweetness of apples between i and j, inclusive
//Transition: dp[i][j] = min(dp[i][l-1] + dp[i][k+1] + (j-i+1)*(l + k (where k is the extra weight given)))
		//	For example: dp[1][2] (= 1*2) + dp[4][6] (= 5*3) + (j-i+1 = 6 times)(3 + 0 = weight 3) = 35
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

#define INF (10000000)
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	readInt(t);
	for(int index = 1; index <= t; index++){
		int n, c;
		readInt(n);
		readInt(c);
		int dp[n+5][n+5];
		memset(dp, 0, sizeof(dp));
		for(int j = 2; j <= n; j++)
			for(int i = j-1; i >= 1; i--){
				dp[i][j] = INF;
				for(int k = i; k <= j; k++)
					if(dp[i][k-1] + dp[k+1][j] + (k+c)*(j-i+1) < dp[i][j]){
						//printf("%d %d\n", k, dp[i][k-1] + dp[k+1][j] + (k+c)*(j-i+1));
						dp[i][j] = dp[i][k-1] + dp[k+1][j] + (k+c)*(j-i+1);
					}
			}
		printf("Case %d: %d\n", index, dp[1][n]);
	}
	return 0;
}