//Title: Chest of Drawers
//Type: DP
//Complexity: O(n*s)
//Solution: Example n = 5, s = 1
		//	We'll keep a variable of whether the last drawer is locked or unlocked
		//	let f(n, s, d) represent the different combinations of having n drawers securing at least s with the last drawer being unlocked (0) or locked (1)
		//	Let U represent unlocked, L represent locked
		//	f(5, 1, 0) = LUUUU, LULUU, ULLUU, LUULU, UULLU = 5
		//	f(5, 1, 0) comes from 2 different combinations, 4 drawers secured 1 with last unlocked adding a locked drawer to the end, and 4 drawers secured 1 with last locked and adding an unlocked drawer to the end.
		//	or f(5, 1, 0) = f(4, 1, 0) (LUUU, LULU, ULLU) + f(4, 1, 1) (LUUL, UULL) = 5
		//	f(5, 1, 1) = UUULL, ULULL, LUUUL, LULUL, ULLUL = 5
		//	f(5, 1, 1) comes from 2 different combinations, 4 drawers secured 0 with last locked adding a locked drawer to the end, and 4 drawers secured 1 with last unlocked adding a locked drawer to the end.
		//	or f(5, 1, 1) = f(4, 0, 1) (UUUL, ULUL) + f(4, 1, 0) (LUUU, LULU, ULLU) = 5
		//	Thus:
//State: dp[i][j][k] = different combinations that represent i drawers secured j with last locked or unlocked, base case dp[1][0][0] = dp[1][1][1] = 1;
//Transition: dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1], dp[i][j][1] = (j-1 >= 0 ? dp[i-1][j-1][1] : 0) + d[i-1][j][0], where 2 <= i <= 65, 0 <= j <= i;
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
	long long dp[70][70][2];
	memset(dp, 0, sizeof(dp));
	dp[1][0][0] = 1;
	dp[1][1][1] = 1;
	for(int i = 2; i <= 65; i++)
		for(int j = 0; j <= i; j++){
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + (j-1 >= 0 ? dp[i-1][j-1][1] : 0);
		}
	int n, s;
	while(readInt(n) && readInt(s) && n >= 0 && s >= 0)
		printf("%lld\n", dp[n][s][0]+dp[n][s][1]);
	return 0;
}