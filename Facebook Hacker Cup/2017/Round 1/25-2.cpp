//Title: Manic Moving
//Type: Shortest Path
//Complexity: O(N^3 + K)
//Solution: Floyd Warshall + more DP, a whole load of DP today huh? dp[i][j] = minimum cost of path from i to j. I failed this question because of K = 1 tricky test case and dp[1][from] = INF test case, ugh Facebook.
//State: pdp[i][0] = minimum cost to reach i loading point, pdp[i][1] = minimum cost to reach i unloading point, base case pdp[i][0] = pdp[i][1] = dp[1][first loading point]
//Transition: pdp[i-1][0] assumes we've picked up and unloaded one completely, pdp[i-1][1] assumes we've picked up both and unloaded one only
		//	pdp[i][0] = min(pdp[i-1][0] + dp[from][to] + dp[to][nfrom], pdp[i-1][1] + dp[pto][to] + dp[to][nfrom])
		//	In this scenario we can decide from last loading point -> last unloading point -> current loading point, or last last unloading point -> last unloading point -> current loading point
		//	pdp[i][1] = min(pdp[i-1][0] + dp[from][nfrom] + dp[nfrom][to], pdp[i-1][1] + dp[pto][nfrom] + dp[nfrom][to])
		//	In this scenario we can decide from last loading point -> current loading point -> last unloading point, or last last unloading point -> current loading point -> last unloading point
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
	//Required for this problem
	if(c == '-') return '-';
	if(c == '+') return '+';
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

#define INF (200000)
int min(int a, int b){
	return a > b ? b : a;
}
int main(){
	freopen("25-2input.txt", "r", stdin);
	freopen("25-2output.txt", "w", stdout);
	int T;
	readInt(T);
	for(int index = 1; index <= T; index++){
		int N, M, K;
		if(index == 75)
			printf("%d %d %d\n", N, M, K);
		readInt(N);
		readInt(M);
		readInt(K);
		int dp[N+5][N+5];
		for(int i = 1; i <= N; i++){
			fill_n(dp[i], N+1, INF);
			dp[i][i] = 0;
		}
		int u, v, w;
		for(int i = 0; i < M; i++){
			readInt(u);
			readInt(v);
			readInt(w);
			dp[u][v] = w;
			dp[v][u] = w;
		}
		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
					if(dp[i][j] > dp[i][k] + dp[k][j])
						dp[i][j] = dp[i][k] + dp[k][j];
		bool disconnected = false;
		int pdp[K+5][2], from, to, nfrom, pto; //0 - s, 1 - e
		readInt(from);
		pdp[0][0] = pdp[0][1] = dp[1][from];
		if(dp[1][from] >= INF)
			disconnected = true;
		pto = from;
		for(int i = 1; i < K; i++){
			readInt(to);
			readInt(nfrom);
			bool dis1 = false, dis2 = false;
			if((dp[from][to] >= INF || dp[to][nfrom] >= INF) && (dp[pto][to] >= INF || dp[to][nfrom] >= INF))
				dis1 = true;
			pdp[i][0] = min(pdp[i-1][0] + dp[from][to] + dp[to][nfrom], pdp[i-1][1] + dp[pto][to] + dp[to][nfrom]);
			if((dp[from][nfrom] >= INF || dp[nfrom][to] >= INF) && (dp[pto][nfrom] >= INF || dp[nfrom][to] >= INF))
				dis2 = true;
			pdp[i][1] = min(pdp[i-1][0] + dp[from][nfrom] + dp[nfrom][to], pdp[i-1][1] + dp[pto][nfrom] + dp[nfrom][to]);
			if(dis1 && dis2)
				disconnected = true;
			from = nfrom;
			pto = to;
		}
		readInt(to);
		if(K == 1 && dp[from][to] >= INF)
			disconnected = true;
		int ans = min(pdp[K-1][0]+dp[from][to], pdp[K-1][1]+dp[pto][to]);
		printf("Case #%d: %d\n", index, disconnected ? -1 : ans);
	}
	return 0;
}