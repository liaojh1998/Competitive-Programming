/*
ID: liaojh11
PROG: schlnet
LANG: C++
*/
//Title: Network of Schools
//Type: Graph Theory
//Complexity: O(V + E + V^2)
//Solution: Tarjan's algorithm to arrange a group of strongly connected components that can be considered as 1 component.
		//	We can assume that if any of such component has an in-degree, then it must be connected to another strongly connected component such that traversal through that component will lead to this component.
		//	Hence, the solution to the subtask A is to find components that do not have an in-degree, because they're the ones which inputed a software, it will get sent to every school in its own components and other connected components.
		//	Subtask B requires the search for any component that does not have an out-degree, because this means that they are strongly connected components that do not cycle to other strongly connected components.
		//	Matching the 0-in-degree strongly connected component with the 0-out-degree storngly connected component will give minimum edges needed to create a cyclable graph. Thus, the maximum of the two is the minimum paths required.
		//	Edge case exist when whole graph is a strongly connected component, in which no paths are needed for subtask B.
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

vector<int> G[105];
stack<int> s;
void tarjanDFS(int node, int &dfsCounter, bool* vis, int* dfs_state, int* dfs_least, int &SCCcount, int* SCC){
	dfs_state[node] = dfs_least[node] = dfsCounter++;
	s.push(node);
	vis[node] = true;
	int len = G[node].size();
	for(int i = 0; i < len; i++){
		int v = G[node][i];
		if(dfs_state[v] == -1)
			tarjanDFS(v, dfsCounter, vis, dfs_state, dfs_least, SCCcount, SCC);
		if(vis[v])
			dfs_least[node] = min(dfs_least[node], dfs_least[v]);
	}
	if(dfs_state[node] == dfs_least[node]){
		int v = -1;
		while(node != v){
			v = s.top(); s.pop(); vis[v] = false;
			SCC[v] = SCCcount;
		}
		SCCcount++;
	}
}
void solve(){
	freopen("schlnet.in", "r", stdin);
	freopen("schlnet.out", "w", stdout);
	int N;
	readInt(N);
	bool vis[N+5], connected[N+5][N+5];
	int dfs_state[N+5], dfs_least[N+5], dfsCounter = 0, v, inDeg[N+5], outDeg[N+5], SCCcount = 0, SCC[N+5];
	memset(connected, 0, sizeof(connected));
	memset(inDeg, 0, sizeof(inDeg));
	memset(outDeg, 0, sizeof(outDeg));
	for(int i = 1; i <= N; i++)
		while(readInt(v) && v){
			G[i].push_back(v);
			connected[i][v] = true;
		}
	memset(vis, 0, sizeof(vis));
	memset(dfs_state, -1, sizeof(dfs_state));
	memset(dfs_least, 0, sizeof(dfs_least));
	for(int i = 1; i <= N; i++)
		if(!(~dfs_state[i]))
			tarjanDFS(i, dfsCounter, vis, dfs_state, dfs_least, SCCcount, SCC);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if(SCC[i] != SCC[j] && connected[i][j]){
				inDeg[SCC[j]]++;
				outDeg[SCC[i]]++;
			}
	int zeroIn = 0, zeroOut = 0;
	for(int i = 0; i < SCCcount; i++){
		if(!inDeg[i]) zeroIn++;
		if(!outDeg[i]) zeroOut++;
	}
	printf("%d\n", zeroIn);
	printf("%d\n", SCCcount > 1 ? max(zeroIn, zeroOut) : 0);
}
int main(){
	solve();
	return 0;
}