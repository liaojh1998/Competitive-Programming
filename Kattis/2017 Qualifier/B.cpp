#include <bits/stdc++.h>
using namespace std;

class FastIO{
private:
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

public:
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
	long long a;
	int b;
	bool c;
	tple(long long aa, int bb, bool cc){
		a = aa;
		b = bb;
		c = cc;
	}
};

class cmp{
public:
	bool operator()(const tple& a, const tple& b){
		return a.a > b.a;
	}
};

void FastIO::solve(){
	int n, m, f, s, t, u, v;
	long long w;
	readInt(n);
	readInt(m);
	readInt(f);
	readInt(s);
	readInt(t);
	long long dist[n][2];
	for(int i = 0; i < n; i++)
		dist[i][0] = dist[i][1] = (long long)(100000000000);
	dist[s][0] = 0;
	vector<pair<int, long long>> edges[n];
	for(int i = 0; i < m; i++){
		readInt(u);
		readInt(v);
		readLL(w);
		edges[u].push_back(pair<int, long long>(v, w));
		edges[v].push_back(pair<int, long long>(u, w));
	}
	vector<int> flight[n];
	for(int i = 0 ; i < f; i++){
		readInt(u);
		readInt(v);
		flight[u].push_back(v);
	}
	long long cur;
	priority_queue<tple, vector<tple>, cmp> q;
	q.push(tple(0, s, false));
	while(!q.empty()){
		tple temp = q.top(); q.pop();
		u = temp.b;
		cur = temp.a;
		if(dist[u][temp.c] < cur) continue;
		int len = edges[u].size();
		for(int i = 0; i < len; i++){
			v = edges[u][i].first;
			w = edges[u][i].second;
			if(dist[v][temp.c] > dist[u][temp.c]+w){
				dist[v][temp.c] = dist[u][temp.c]+w;
				q.push(tple(dist[v][temp.c], v, temp.c));
			}
		}
		if(!temp.c){
			len = flight[u].size();
			for(int i = 0; i < len; i++){
				v = flight[u][i];
				if(dist[v][1] > dist[u][temp.c]){
					dist[v][1] = dist[u][temp.c];
					q.push(tple(dist[v][1], v, true));
				}
			}
		}
	}
	printf("%lld\n", dist[t][0] < dist[t][1] ? dist[t][0] : dist[t][1]);
}