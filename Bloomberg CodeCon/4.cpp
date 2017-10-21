#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
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
		for(; c != '.' && ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c != '.' && c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
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

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

struct tple{
	int x, y, vis;
	long long w;
	tple(int a, int b, int c, long long d){
		x = a;
		y = b;
		vis = c;
		w = d;
	}
};

class cmp{
public:
	bool operator()(const tple& a, const tple& b){
		return a.w < b.w;
	}
};

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};
int N, M, MAX, xstart;
int ystart, x2, y2;
bool vis[15][15];
long long dp[105];
long long mat[15][15];
long long ans;

void dfs(int x, int y, int cur, long long amount){
	if(x == x2 && y == y2 && amount > ans){
		ans = amount;
		return;
	}
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nexty = y+diry[i];
		int nextx = x+dirx[i];
		if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < M && cur+1 <= MAX && !vis[nextx][nexty])
			dfs(nextx, nexty, cur+1, amount+mat[nextx][nexty]);
	}
	vis[x][y] = false;
}

void FastIO::solve(){
	readInt(N);
	readInt(M);
	readInt(MAX);
	readInt(xstart);
	readInt(ystart);
	readInt(x2);
	readInt(y2);
	memset(mat, 0, sizeof(mat));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			readLL(mat[i][j]);
	dfs(xstart, ystart, 0, mat[xstart][ystart]);
	printf("%lld\n", ans);
}