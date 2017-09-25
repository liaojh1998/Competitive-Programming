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
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
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

void FastIO::solve(){
	int N, t;
	readInt(N);
	int x1[N+5], y1[N+5], x2[N+5], y2[N+5];
	for(int i = 0; i < N; i++){
		readInt(x1[i]);
		readInt(y1[i]);
		readInt(x2[i]);
		readInt(y2[i]);
		if(x1[i] > x2[i]){
			t = x1[i];
			x1[i] = x2[i];
			x2[i] = t;
			t = y1[i];
			y1[i] = y2[i];
			y2[i] = t;
		}
	}
	vector<int> edges[N+5];
	int count[N+5];
	memset(count, 0, sizeof(count));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if((i != j) && ((x1[j] <= x1[i] && x2[j] >= x1[i] && x2[j] <= x2[i] && y2[j] > y1[i]) || (x2[j] >= x2[i] && x1[j] <= x2[i] && x1[j] >= x1[i] && y1[j] > y2[i]) || ((x1[j] <= x1[i] && x2[j] >= x2[i] && y1[j] > y1[i] && y2[j] > y2[i]) || (x1[j] >= x1[i] && x2[j] <= x2[i] && (y1[j] > y1[i] || y2[j] > y2[i]))))){
				count[j]++;
				edges[i].push_back(j);
			}
		}
	}
	bool vis[N+5];
	int u, v, size;
	memset(vis, 0, sizeof(vis));
	vector<int> ans;
	queue<int> q;
	for(int i = 0; i < N; i++){
		if(!count[i] && !vis[i]){
			q.push(i);
			vis[i] = true;
			while(!q.empty()){
				u = q.front(); q.pop();
				ans.push_back(u);
				size = edges[u].size();
				for(int j = 0; j < size; j++){
					v = edges[u][j];
					count[v]--;
					if(!count[v] && !vis[v]){
						q.push(v);
						vis[v] = true;
					}
				}
			}
		}
	}
	for(int i = 0; i < N; i++)
		printf("%d%s", ans[i]+1, i == N-1 ? "\n" : " ");
}