/*
ID: liaojh11
PROG: milk6
LANG: C++
*/
//Title: Pollutant Control
//Type: Network Flow
//Complexity: O(V^2*E + V^2*E^2)
//Solution: Implementing Dinic's algorithm instead of Edmond-Karp due to size of E, but tbh, it doesn't matter.
		//	Sort the edges by largest capacity since minimum cut is minimized with maximum capacities and minimum edges, then on lesser edges between 2 nodes, then on earlier id.
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

#define INF (2000000005)
struct edge{
	int u, v, w, id;
	edge(int from, int to, int weight, int identification){
		u = from;
		v = to;
		w = weight;
		id = identification;
	}
};
vector<edge*> edges;
vector<int> G[35];
int C[35][35], F[35][35], routes[35][35];
bool dinic_levelgraph(int* dist, int s, int t){
	memset(dist, -1, sizeof(int)*(t+1));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int len = G[u].size();
		for(int i = 0; i < len; i++){
			int v = G[u][i];
			if(dist[v] == -1 && C[u][v] > F[u][v]){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] != -1;
}
int dinic_blockingflow(int* checkededge, int* dist, int u, int t, int flow){
	if(u == t)
		return flow;
	int len = G[u].size();
	for(int &i = checkededge[u]; i < len; i++){
		int v = G[u][i];
		if(C[u][v] <= F[u][v])
			continue;
		if(dist[v] == dist[u] + 1){
			int curflow = dinic_blockingflow(checkededge, dist, v, t, min(flow, C[u][v] - F[u][v]));
			if(curflow > 0){
				F[u][v] += curflow;
				F[v][u] -= curflow;
				return curflow;
			}
		}
	}
	return 0;
}
int dinic(int s, int t){
	int flow = 0, dist[t+1], checkededge[t+1];
	while(dinic_levelgraph(dist, s, t)){
		memset(checkededge, 0, sizeof(checkededge));
		while(int f = dinic_blockingflow(checkededge, dist, s, t, INF)){
			flow += f;
		}
	}
	return flow;
}
bool cmp(edge* a, edge* b){
	if(C[a->u][a->v] == C[b->u][b->v]){
		if(routes[a->u][a->v] == routes[b->u][b->v])
			return a->id < b->id;
		return routes[a->u][a->v] < routes[b->u][b->v];
	}
	return C[a->u][a->v] > C[b->u][b->v];
}
void solve(){
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);
	int N, M, u, v, w;
	readInt(N);
	readInt(M);
	for(int i = 1; i <= M; i++){
		readInt(u);
		readInt(v);
		readInt(w);
		C[u][v] += w;
		routes[u][v]++;
		if(find(G[u].begin(), G[u].end(), v) == G[u].end())
			G[u].push_back(v);
		if(find(G[v].begin(), G[v].end(), u) == G[v].end())
			G[v].push_back(u);
		edges.push_back(new edge(u, v, w, i));
	}
	int maxFlow = dinic(1, N);
	int tmpFlow = maxFlow, flow, arr[M+5], count = 0;
	memset(arr, 0, sizeof(arr));
	sort(edges.begin(), edges.end(), cmp);
	for(int i = 0; i < M && tmpFlow; i++){
		if(edges[i]->w > maxFlow) continue;
		memset(F, 0, sizeof(F));
		C[edges[i]->u][edges[i]->v] -= edges[i]->w;
		flow = dinic(1, N);
		if(tmpFlow - flow == edges[i]->w){
			count++;
			arr[edges[i]->id] = true;
			tmpFlow -= edges[i]->w;
		}else C[edges[i]->u][edges[i]->v] += edges[i]->w;
	}
	printf("%d %d\n", maxFlow, count);
	for(int i = 1; i <= M; i++)
		if(arr[i]) printf("%d\n", i);
}
int main(){
	solve();
	return 0;
}