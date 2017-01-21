/*
ID: liaojh11
PROG: stall4
LANG: C++
*/
//Title: The Perfect Stall
//Type: Network Flow
//Complexity: O(V*E^2)
//Solution: Maximum matching that can be modified into network flow, simply use Edmond-Karp again
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

#define INF (400)
int N, M, C[405][405], Mflow[405], P[405];
vector<int> G[405];
int bfs(int s, int t){
	memset(P, -1, sizeof(P));
	memset(Mflow, 0, sizeof(Mflow));
	Mflow[s] = INF;
	P[s] = -2;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int len = G[u].size();
		for(int i = 0; i < len; i++){
			int v = G[u][i];
			if(C[u][v] > 0 && !(~P[v])){
				P[v] = u;
				Mflow[v] = C[u][v] > Mflow[u] ? Mflow[u] : C[u][v];
				if(v != t)
					q.push(v);
				else
					return Mflow[t];
			}
		}
	}
	return 0;
}
int main(){
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);
	readInt(N);
	readInt(M);
	M += N;
	for(int i = 1; i <= N; i++){
		C[0][i] = 1;
		G[0].push_back(i);
		G[i].push_back(0);
	}
	for(int i = N+1; i <= M; i++){
		C[i][M+1] = 1;
		G[M+1].push_back(i);
		G[i].push_back(M+1);
	}
	int n, v;
	for(int i = 1; i <= N; i++){
		readInt(n);
		for(int j = 0; j < n; j++){
			readInt(v);
			C[i][N+v] = 1;
			G[i].push_back(N+v);
			G[N+v].push_back(i);
		}
	}
	int flow = 0;
	int m = bfs(0, M+1);
	while(m){
		flow += m;
		for(int i = M+1; i != 0; i = P[i]){
			C[P[i]][i] -= m;
			C[i][P[i]] += m;
		}
		m = bfs(0, M+1);
	}
	printf("%d\n", flow);
	return 0;
}