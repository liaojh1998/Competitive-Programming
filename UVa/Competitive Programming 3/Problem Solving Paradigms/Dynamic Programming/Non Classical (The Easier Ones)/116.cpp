//Title: Unidirectional TSP
//Type: DP
//Solution: Recusion format gives O(M*3^N), DP then makes memoization table by O(M*N), start from last column due to lexicographic order (bottom-up DP)
//State: dp[i][j] = minimum weight to reach matrix(i)(j) from destination, base case: dp[i][N-1] = weights[i][N-1]
//Transition: dp[i][j] = min(dp[i][j+1] + weights[i][j], min(dp[(i-1+M)%M][j+1] + weights[i][j], dp[(i+1)%M][j+1] + weights[i][j]));
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
		str[len] = c;
		c = getchar();
		len++;
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
	int M, N;
	while(~readInt(M)){
		readInt(N);
		int weights[M][N];
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				readInt(weights[i][j]);
		//dp condition
		int dp[M][N], next[M][N];
		for(int i = 0; i < M; i++)
			dp[i][N-1] = weights[i][N-1];
		//dp
		for(int j = N-2; j >= 0; j--)
			for(int i = 0; i < M; i++){
				//dp[i][j] = min(dp[i][j+1] + weights[i][j], min(dp[(i-1+M)%M][j+1] + weights[i][j], dp[(i+1)%M][j+1] + weights[i][j]));
				dp[i][j] = dp[i][j+1] + weights[i][j];
				next[i][j] = i;
				if(dp[i][j] > dp[(i-1+M)%M][j+1] + weights[i][j] || (dp[i][j] == dp[(i-1+M)%M][j+1] + weights[i][j] && next[i][j] > (i-1+M)%M)){
					dp[i][j] = dp[(i-1+M)%M][j+1] + weights[i][j];
					next[i][j] = (i-1+M)%M;
				}
				if(dp[i][j] > dp[(i+1)%M][j+1] + weights[i][j] || (dp[i][j] == dp[(i+1)%M][j+1] + weights[i][j] && next[i][j] > (i+1)%M)){
					dp[i][j] = dp[(i+1)%M][j+1] + weights[i][j];
					next[i][j] = (i+1)%M;
				}
			}
		//paths, when dp problems make it harder for you
		int start = 0, mini = dp[0][0];
		for(int i = 1; i < M; i++)
			if(dp[i][0] < mini){
				start = i;
				mini = dp[i][0];
			}
		printf("%d", start+1);
		for(int j = 0; j < N-1; j++){
			printf(" %d", next[start][j]+1);
			start = next[start][j];
		}
		printf("\n%d\n", mini);
	}
	return 0;
}