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

template<typename T> class Dijkstra{
private:
	T* result;
	bool* checked;
	size_t V;
	struct path{
		int to, st, en;
		T time;
		path(int a, int b, int c, T d):to(a), st(b), en(c), time(d){}
	};
	vector<path>* G;

public:
	Dijkstra(size_t n){
		V = n;
		result = new T[V]();
		G = new vector<path>[V];
		checked = new bool[V]();
	}
	~Dijkstra(){
		delete[] result;
		delete[] G;
		delete[] checked;
	}
	void add(size_t from, size_t to, int start, int end, const T& dist){
		G[from].push_back(path(to, start, end, dist));
	}
	class cmp{
		public:
		bool operator()(const pair<size_t, T>& a, const pair<size_t, T>& b){
			return a.second > b.second;
		}
	};
	bool check(const T& a, const T& b){
		return a < b;
	}

	void exec(size_t s){
		size_t u, v;
		T w, cur;
		priority_queue<pair<size_t, T>, vector<pair<size_t, T> >, cmp> q;
		q.push(pair<size_t, T>(s, 0));
		result[s] = 0;
		checked[s] = true;
		while(!q.empty()){
			pair<size_t, T> p = q.top(); q.pop();
			u = p.first;
			cur = p.second;
			if(check(result[u], cur)) continue;
			size_t len = G[u].size();
			for(size_t i = 0; i < len; i++){
				if(G[u][i].en > cur){
					v = G[u][i].to;
					w = (G[u][i].st > cur ? G[u][i].st-cur : 0) + G[u][i].time;
					if(!checked[v] || check(cur + w, result[v])){
						checked[v] = true;
						q.push(pair<size_t, T>(v, (result[v] = cur + w)));
					}
				}
			}
		}
	}
	T operator[](size_t i){
		return checked[i] ? result[i] : -1; 
	}
};

void FastIO::solve(){
	int M, C;
	readInt(M);
	readInt(C);
	string start, end;
	cin >> start >> end;
	string s, t;
	map<string, int> cities;
	for(int i = 0; i < M; i++){
		cin >> s;
		cities[s] = i;
	}
	int a, b, c;
	Dijkstra<int> ans(M);
	for(int i = 0; i < C; i++){
		cin >> s >> t;
		readInt(a);
		readInt(b);
		readInt(c);
		ans.add(cities[s], cities[t], a, b, c);
	}
	ans.exec(cities[start]);
	if(ans[cities[end]] == -1)
		printf("TRAPPED!\n");
	else
		printf("%d\n", ans[cities[end]]);
}