#include <bits/stdc++.h>
using namespace std;

template<typename T> class Dinic{
#define INF (1<<28) //Change this if there's a bigger infinity, remember to avoid overflow
private:
	size_t V;
	T* C; //C - residual capacity
	T* F; //F - legal flow matrix
	size_t* P; //P - parent table
	int* rank; //Ranking for Dinic's level graph
	size_t* checkededge; //Edge counter for every node in Dinic's blocking flow
	vector<size_t>* G; //Edge List

public:
	//Constructor, n - number of vertices
	Dinic(size_t n){
		V = n;
		C = new T[V*V+1]();
		F = new T[V*V+1]();
		P = new size_t[V]();
		rank = new int[V];
		checkededge = new size_t[V]();
		G = new vector<size_t>[V];
	}
	//Destructor
	~Dinic(){
		delete[] C;
		delete[] F;
		delete[] P;
		delete[] rank;
		delete[] checkededge;
		delete[] G;
	}

	//Add capacity
	void add(size_t from, size_t to, const T& capacity){
		G[from].push_back(to);
		C[from*V + to] += capacity; //Capacity is added in this case scenario, change if assignment
		F[from*V + to] = 0;
		//Reverse edge
		G[to].push_back(from);
		//C[to*V + from] += capacity; //Include if bidirectional
		F[to*V + from] = 0;
		//Unless there's anything special about residual capacity
		//If there really is, then:
		//Make new parameter for function: const T& flowed
		//F[from*V + to] = flowed;
		//F[to*V + from] = -flowed;
	}

	//Dinic's Algorithm
	//Level Graph construction, basically a shortest path but no weight
	//Only accessible if C > F (can have more flow)
	bool dinic_levelgraph(size_t s, size_t t){
		memset(rank, -1, sizeof(int)*V);
		rank[s] = 0;
		queue<size_t> q;
		q.push(s);
		while(!q.empty()){
			size_t u = q.front(); q.pop();
			size_t len = G[u].size();
			for(size_t i = 0; i < len; i++){
				size_t v = G[u][i];
				if(rank[v] == -1 && C[u*V + v] > F[u*V + v]){
					rank[v] = rank[u] + 1;
					q.push(v);
				}
			}
		}
		return rank[t] != -1;
	}
	//Blocking flow search
	T dinic_blockingflow(size_t u, size_t t, const T& flow){
		if(u == t) //Possible flowed to sink
			return flow;
		size_t len = G[u].size();
		for(size_t &i = checkededge[u]; i < len; i++){
			size_t v = G[u][i];
			if(C[u*V + v] <= F[u*V + v]) //Either filled or not fully filled
				continue;
			if(rank[v] == rank[u] + 1){
				//Ford Fulkerson's method in dfs
				T curflow = dinic_blockingflow(v, t, min(flow, C[u*V + v] - F[u*V + v]));
				if(curflow > 0){ //Do not return no flow until all has been checked
					F[u*V + v] += curflow;
					F[v*V + u] -= curflow;
					return curflow;
				}
			}
		}
		return 0; //No flow
	}
	//Dinic's Algorithm Execution
	//Time Complexity: O((V^2)(E))
	//s - source, t - sink
	T exec(size_t s, size_t t){
		T f = 0;
		//While Level Graph exists and flowable
		while(dinic_levelgraph(s, t)){
			memset(checkededge, 0, sizeof(size_t)*V);
			//Search blocking flow
			while(T flow = dinic_blockingflow(s, t, INF)){
				f += flow;
			}
		}
		return f;
	}
};

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

void FastIO::solve(){
	int N, M;
	readInt(N);
	readInt(M);
	Dinic<int> dinic(N);
	int u, v;
	for(int i = 0; i < M; i++){
		readInt(u);
		readInt(v);
		dinic.add(u, v, 1);
	}
	int maxflow = dinic.exec(0, N-1);
	printf("%d\n", maxflow-1);
}