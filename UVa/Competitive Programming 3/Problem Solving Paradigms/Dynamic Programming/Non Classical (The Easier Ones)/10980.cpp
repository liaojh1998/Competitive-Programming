//Title: Lowest Price in Town
//Type: DP
//Complexity: O(200*M)
//Solution: Knapsack, then iterate backwards to minimize cost, since max(weight[j]) = 100, and max(requested weight) = 100, 200 states will suffice
//State: dp[i] = minimum cost required to buy i items
//Transition: dp[i] = min(dp[i], dp[i-weight[j]] + price[j]), where weight[j] = amount, and price[j] = cost, thus cost per amount, and 0 <= j <= M (unit cost as well)
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
	//required for this problem
	if(c == 10) return 10;
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

#define INF (1000000)
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int weight[105], M, K, index = 1;
	double dp[205], price[105];
	while(~readDouble(price[0])){
		weight[0] = 1;
		readInt(M);
		for(K = 1; K <= M; K++){
			readInt(weight[K]);
			readDouble(price[K]);
		}
		dp[0] = 0;
		for(int i = 1; i <= 200; i++){
			dp[i] = INF;
			for(int j = 0; j < K; j++)
				if(i - weight[j] >= 0 && dp[i-weight[j]] + price[j] < dp[i])
					dp[i] = dp[i-weight[j]] + price[j];
		}
		for(int i = 200; i >= 1; i--)
			if(dp[i-1] > dp[i])
				dp[i-1] = dp[i];
		int ans, c;
		printf("Case %d:\n", index++);
		while(c = readInt(ans)){
			printf("Buy %d for $%.2lf\n", ans, dp[ans]);
			if(c == 10) break;
		}
	}
	return 0;
}