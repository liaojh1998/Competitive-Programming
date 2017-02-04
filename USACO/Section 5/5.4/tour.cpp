/*
ID: liaojh11
PROG: tour
LANG: C++
*/
//Title: Canadian Tour
//Type: DP
//Complexity: O(N^3)
//Solution: My initial thoughts for this was Hamiltonian Pathing with NP-hard searching.
		//	Then I resorted to trying maximum flow, to which I felt impossible due to enumeration of every flow and must touch last node.
		//	Then came the online solution which based off an interesting assumed optimal solution that combines the idea of Floyd's algorithm and USACO 3.3 A Game DP.
		//	I'm not sure how to prove this dp, but it does what A Game do by simulating 2 paths that are both optimal. Why do they not intersect is the interesting part.
//State: dp[i][j] = maximum amount of vertices that can be visited when one path is at i and one path is at j.
//Transition: dp[i][j] = dp[j][i] (for symmetry and optimal strategy of both path 1 and 2) = dp[i][k] > 0 && adj[k][j] ? max(dp[i][k]) + 1, 0 <= i < N, i+1 <= j < N, 0 <= k < j;
		//	If there is such a path that visited vertices between i and k and k is adjacent to j, then dp[i][j] can = dp[i][k] + 1;
		//	The reason why this might most likely work is because the dp assumes the maximum vertices possible when i FIRST changed position and j FIRST changed position, which assumes that i and j has never been visited before.
		//	Answer at dp[i][N-1], 0 <= i < N, because it enumerate which vertex i is directly connected to N and the maximum vertices visited in between when path 1 went to i and path 2 went to N.
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
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

void solve(){
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	int N, V;
	readInt(N);
	readInt(V);
	char names[N+5][20], stru[20], strv[20];
	for(int i = 0; i < N; i++)
		readStr(names[i]);
	bool adjmat[N+5][N+5];
	memset(adjmat, 0, sizeof(adjmat));
	int u, v;
	for(int i = 0; i < V; i++){
		readStr(stru);
		readStr(strv);
		u = v = -1;
		for(int j = 0; j < N && (!(~u) || !(~v)); j++){
			if(!strcmp(stru, names[j]))
				u = j;
			if(!strcmp(strv, names[j]))
				v = j;
		}
		adjmat[u][v] = adjmat[v][u] = true;
	}
	int dp[N+5][N+5], ans = 1;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++){
			for(int k = 0; k < j; k++)
				if(dp[i][k] > 0 && adjmat[k][j] && dp[i][k] > dp[i][j])
					dp[i][j] = dp[i][k];
			dp[j][i] = ++dp[i][j];
		}
	for(int i = 0; i < N; i++)
		if(adjmat[i][N-1] && dp[i][N-1] > ans)
			ans = dp[i][N-1];
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}