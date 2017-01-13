/*
ID: liaojh11
PROG: camelot
LANG: C++
*/
//Title: camelot
//Type: BFS
//Solution: First bfs the knight and the minimum distance to reach a spot, second bfs the knight with the king and find the minimum distance for the king to reach a spot
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

#define pa(a, b) (pair<int, int>(a, b))
int ab(int a){
	return (a < 0) ? -a: a;
}
int main(){
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	int movex[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int movey[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int R, C, kx, ky, kodist[35][35], kdist[35][35], kcost[35][35], dist[35][35], cost[35][35];
	bool vis[35][35];
	readInt(R);
	readInt(C);
	kx = getchar() - 'A';
	readInt(ky);
	ky--;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			kodist[i][j] = ab(j - kx) > ab(i - ky) ? ab(j - kx) : ab(i - ky);
	char c = getchar();
	bool hasKnight = false;
	memset(cost, 0, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	memset(kcost, 1, sizeof(kcost));
	while(~c){
		hasKnight = true;
		int y, x = c - 'A';
		readInt(y);
		y--;
		//First bfs, knight only
		memset(dist, 1, sizeof(dist));
		queue<pair<int, int> > q;
		dist[y][x] = 0;
		q.push(pa(y, x)); //R, C : y, x
		while(!q.empty()){
			pair<int, int> temp = q.front(); q.pop();
			cost[temp.first][temp.second] += dist[temp.first][temp.second];
			vis[temp.first][temp.second] = true;
			for(int i = 0; i < 8; i++)
				if(temp.first+movey[i] >= 0 && temp.first+movey[i] < R && temp.second+movex[i] >= 0 && temp.second+movex[i] < C
					&& dist[temp.first+movey[i]][temp.second+movex[i]] > dist[temp.first][temp.second] + 1){
					dist[temp.first+movey[i]][temp.second+movex[i]] = dist[temp.first][temp.second] + 1;
					q.push(pa(temp.first+movey[i], temp.second+movex[i]));
				}
		}
		//Second bfs, king with knight
		//Fill first with original distance
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				kdist[i][j] = kodist[i][j];
		//bfs
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++){
				q.push(pa(i, j));
				while(!q.empty()){
					pair<int, int> temp = q.front(); q.pop();
					for(int k = 0; k < 8; k++)
						if(temp.first+movey[k] >= 0 && temp.first+movey[k] < R && temp.second+movex[k] >= 0 && temp.second+movex[k] < C
							&& kdist[temp.first+movey[k]][temp.second+movex[k]] + dist[temp.first+movey[k]][temp.second+movex[k]] > kdist[temp.first][temp.second] + dist[temp.first][temp.second] + 1){
							//Subtraction to substitute the new knight to carry the king
							kdist[temp.first+movey[k]][temp.second+movex[k]] = kdist[temp.first][temp.second] + dist[temp.first][temp.second] + 1 - dist[temp.first+movey[k]][temp.second+movex[k]];
							q.push(pa(temp.first+movey[k], temp.second+movex[k]));
						}
				}
			}
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(kdist[i][j] < kcost[i][j])
					kcost[i][j] = kdist[i][j];
		c = getchar();
	}
	if(!hasKnight)
		printf("0\n");
	else{
		int minSum = 1e9;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(vis[i][j] && cost[i][j] + kcost[i][j] < minSum)
					minSum = cost[i][j] + kcost[i][j];
		printf("%d\n", minSum);
	}
	return 0;
}