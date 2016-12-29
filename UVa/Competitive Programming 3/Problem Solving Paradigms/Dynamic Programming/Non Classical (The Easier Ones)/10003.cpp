//Title: Cutting Sticks
//Type: DP
//Complexity: O(N^3)
//Solution: There is no greedy solution to this, must try every cut possible from memoization. There is an optimal solution so DP is possible.
//State: dp[i][j] = minimum cost to cut from i to j, with base case dp[i][i+1] = 0, because there is no cut need to be made from index i to i+1
//Transition: dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]), k iterate from i+1 to j-1; dp[i][j] += cost[j] - cost[i] eventually,
//			  where j > i+1, cost[0] = 0, and cost[max cuts+1] = length of stick
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

#define INF 10000000
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len;
	while(~readInt(len) && len){
		int cuts;
		readInt(cuts);
		int cost[cuts+2], dp[cuts+2][cuts+2];
		for(int i = 1; i <= cuts; i++)
			readInt(cost[i]);
		cost[0] = 0; cost[++cuts] = len;
		for(int j = 1; j <= cuts; j++){
			for(int i = j-1; i >= 0; i--){
				if(i + 1 == j) dp[i][j] = 0;
				else{
					dp[i][j] = INF;
					for(int k = i+1; k < j; k++)
						if(dp[i][j] > dp[i][k] + dp[k][j])
							dp[i][j] = dp[i][k] + dp[k][j];
					dp[i][j] += cost[j] - cost[i];
				}
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][cuts]);
	}
	return 0;
}