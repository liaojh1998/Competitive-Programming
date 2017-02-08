/*
ID: liaojh11
PROG: telecow
LANG: C++
*/
//Title: Telecowmunication
//Type: Network Flow
//Complexity: O(V^2*E + <V^3*E) //pruned as V decreases, each V may be only used once in a flow
//Solution: Exact same solution as USACO 4.4 Pollutant Control, use Dinic's and enumerate all vertices to find which one must be cut.
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

#define INF (105)
vector<int> G[105];
int N, went[105];
bool dinic_levelgraph(int* dist, bool* used, int s, int t){
	memset(dist, -1, sizeof(int)*(N+5));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(went[u]) continue;
		int len = G[u].size();
		for(int i = 0; i < len; i++){
			int v = G[u][i];
			if(dist[v] == -1 && !went[v] && !used[v]){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] != -1;
}
int dinic_blockingflow(int* checkededge, int* dist, bool* used, int u, int t, int flow){
	if(u == t)
		return flow;
	int len = G[u].size();
	for(int &i = checkededge[u]; i < len; i++){
		int v = G[u][i];
		if(dist[v] == dist[u] + 1 && !used[v]){
			int curflow = dinic_blockingflow(checkededge, dist, used, v, t, min(flow, 1));
			if(curflow > 0){
				used[u] = true;
				return curflow;
			}
		}
	}
	return 0;
}
int dinic(int s, int t){
	int flow = 0, dist[N+5], checkededge[N+5];
	bool used[N+5];
	memset(used, 0, sizeof(used));
	while(dinic_levelgraph(dist, used, s, t)){
		memset(checkededge, 0, sizeof(checkededge));
		while(int f = dinic_blockingflow(checkededge, dist, used, s, t, INF))
			flow += f;
		used[s] = false;
	}
	return flow;
}
void solve(){
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	readInt(N);
	int M, s, t;
	readInt(M);
	readInt(s);
	readInt(t);
	int u, v;
	for(int i = 0; i < M; i++){
		readInt(u);
		readInt(v);
		//Because graph is unweighted, no need to backtrack flow
		//If computers were weighted then need to turn computers into edges to backtrack flow
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int mincut = dinic(s, t);
	printf("%d\n", mincut);
	for(int i = 1; i <= N && mincut; i++){
		if(i == s || i == t) continue;
		went[i] = 1;
		int tempcut = dinic(s, t);
		if(tempcut+1 == mincut){
			mincut--;
			printf("%d%c", i, mincut ? ' ' : '\n');
		}else
			went[i] = 0;
	}
}
int main(){
	solve();
	return 0;
}