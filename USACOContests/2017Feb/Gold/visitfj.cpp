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

#define INF ((long long)100000000000005)
struct path{
	int y, x, steps;
	long long weight;
	path(int a, int b, int c, long long d){
		y = a;
		x = b;
		steps = c;
		weight = d;
	}
};
class cmp{
	public:
	bool operator()(const path* a, const path* b){
		return a->weight > b->weight;
	}
};
bool check(long long a, long long b){
	return a < b;
}
int xdir[4] = {1, 0, -1, 0};
int ydir[4] = {0, 1, 0, -1};
void solve(){
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	int N;
	long long T;
	readInt(N);
	readLL(T);
	long long G[N+5][N+5], dist[N+5][N+5][3];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			readLL(G[i][j]);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			fill_n(dist[i][j], 3, INF);
	dist[0][0][0] = 0;
	bool queued[N][N][3];
	memset(queued, 0, sizeof(queued));
	priority_queue<path*, vector<path*>, cmp> q;
	bool found = false;
	q.push(new path(0, 0, 0, 0));
	while(!q.empty()){
		path* p = q.top(); q.pop();
		int y = p->y, x = p->x, steps = p->steps;
		long long weight = p->weight;
		queued[y][x][steps] = false;
		if(y == N-1 && x == N-1){
			printf("%lld\n", weight);
			return;
		}
		//printf("%d %d %d %lld\n", y, x, steps, weight);
		delete p;
		for(int i = 0; i < 4; i++)
			if(y+ydir[i] >= 0 && y+ydir[i] < N && x+xdir[i] >= 0 && x+xdir[i] < N)
				if(steps == 2 && check(weight + T + G[y+ydir[i]][x+xdir[i]], dist[y+ydir[i]][x+xdir[i]][0])){
					dist[y+ydir[i]][x+xdir[i]][0] = weight + T + G[y+ydir[i]][x+xdir[i]];
					if(!queued[y+ydir[i]][x+xdir[i]][0]){
						queued[y+ydir[i]][x+xdir[i]][0] = true;
						q.push(new path(y+ydir[i], x+xdir[i], 0, dist[y+ydir[i]][x+xdir[i]][0]));
					}
				}else if(steps != 2 && check(weight + T, dist[y+ydir[i]][x+xdir[i]][steps+1])){
					dist[y+ydir[i]][x+xdir[i]][steps+1] = weight + T;
					if(!queued[y+ydir[i]][x+xdir[i]][steps+1]){
						queued[y+ydir[i]][x+xdir[i]][steps+1] = true;
						q.push(new path(y+ydir[i], x+xdir[i], steps+1, dist[y+ydir[i]][x+xdir[i]][steps+1]));
					}
				}
	}
}
int main(){
	solve();
	return 0;
}