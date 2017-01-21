/*
ID: liaojh11
PROG: ditch
LANG: C++
*/
//Title: Drainage Ditches
//Type: Network Flow
//Complexity: O(V*E^2)
//Solution: Edmond-Karp, without legal flow matrix but incorporated Ford-Fulkerson's method and modified Dijkstra's
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

int C[205][205], P[205], Mflow[205], N, M;
vector<int> G[205];
bool checkedM[205];
int bfs(int s, int t){
	memset(P, -1, sizeof(P));
	memset(checkedM, 0, sizeof(checkedM));
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
				Mflow[v] = checkedM[u] ? C[u][v] < Mflow[u] ? C[u][v] : Mflow[u] : C[u][v];
				checkedM[v] = true;
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
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	readInt(N);
	readInt(M);
	int u, v, w;
	for(int i = 0; i < N; i++){
		readInt(u);
		readInt(v);
		readInt(w);
		C[u][v] += w;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int flow = 0;
	int m = bfs(1, M);
	while(m){
		flow += m;
		for(int i = M; i != 1; i = P[i]){
			C[P[i]][i] -= m;
			C[i][P[i]] += m;
		}
		m = bfs(1, M);
	}
	printf("%d\n", flow);
	return 0;
}