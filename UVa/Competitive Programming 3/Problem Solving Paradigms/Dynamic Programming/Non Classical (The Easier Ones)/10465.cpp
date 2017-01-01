//Title: Homer Simpson
//Type: DP/Math Theory
//Complexity: O(t)/O(t/m)
//Solution: Unbounded Knapsack / Use mod
//State: dp[i] = maximum number of burgers homer can eat at time i, with dp[0] = 0 as base case
//Transition: dp[i] = max(dp[i], dp[i-m]+1, dp[i-n]+1), since time > dp[i], go backward in dp[i] to search
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
	int m, n, t;
	while(~readInt(m) && ~readInt(n) && ~readInt(t)){
		//Using mod
		int mmax = t/m, ans = 0, timewasted = 10000;
		for(int mi = mmax; mi >= 0; mi--){
			int tempans = mi + (t-mi*m)/n, temptime = (t-mi*m)%n;
			if(temptime < timewasted){
				ans = tempans;
				timewasted = temptime;
			}
			if(temptime == timewasted && ans < tempans)
				ans = tempans;
		}
		if(!timewasted)
			printf("%d\n", ans);
		else printf("%d %d\n", ans, timewasted);
		/* //DP Solution
		int dp[t+1], ans = 0, timewasted = t;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= t; i++)
			if(i-m >= 0 && (dp[i-m] || i-m == 0) && dp[i] < dp[i-m]+1)
				dp[i] = dp[i-m]+1;
		for(int i = 1; i <= t; i++)
			if(i-n >= 0 && (dp[i-n] || i-n == 0) && dp[i] < dp[i-n]+1)
				dp[i] = dp[i-n]+1;
		for(int i = t; i >= 0 && !ans; i--)
			if(dp[i]){
				ans = dp[i];
				timewasted = t-i;
			}
		if(!timewasted)
			printf("%d\n", ans);
		else
			printf("%d %d\n", ans, timewasted);
		*/
	}
	return 0;
}