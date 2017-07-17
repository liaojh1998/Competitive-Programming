#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegTree{
private:
	T* sgt;
	size_t N, height;

	T applyfunc(const T& a, const T& b){
		return b;
	}
	T queryfunc(const T& a, const T& b){
		return a ^ b;
	}

public:
	SegTree(size_t n){
		N = n;
		height = (size_t)ceil(log2(N));
		sgt = new T[1<<(height+1)]();
	}
	~SegTree(){
		delete[] sgt;
	}
	T& operator[](const size_t& i){
		return sgt[i + (1<<height)];
	}
	void build(){
		for(size_t i = ((1<<height)-1); i > 0; i--)
			sgt[i] = queryfunc(sgt[i<<1], sgt[i<<1|1]);
	}
	void update(size_t pos, const T& value){
		if(pos < 0 || pos >= N) return;
		for(sgt[(pos + (1<<height))] = applyfunc(sgt[(pos += (1<<height))], value); pos > 1; pos >>= 1)
			sgt[pos>>1] = queryfunc(sgt[pos], sgt[pos^1]);
	}
	//Query [l, r)
	T query(size_t l, size_t r){
		if(l+1 == r) return (*this)[l];
		T resl = 0, resr = 0;
		for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
			if(l&1) resl = queryfunc(resl, sgt[l++]);
			if(r&1) resr = queryfunc(sgt[--r], resr);
		}
		return queryfunc(resl, resr);
	}
};

template<typename T> class HLD{
private:
	int root, V;
	vector<pair<int, T> >* edges;
	int *subtree, *parent, *heavy, *size, *depth, *head, *id;
	SegTree<T>* sgt;

	//Match query function with Segment Tree
	T queryfunc(const T& a, const T& b){
		return a ^ b;
	}
	void dfs(const int& u){
		subtree[u] = 1;
		int max = 0, v;
		for(int i = 0; i < size[u]; i++){
			v = edges[u][i].first;
			if(parent[u] != v){
				parent[v] = u;
				dfs(v);
				if(subtree[v] > max)
					max = subtree[v];
				subtree[u] += subtree[v];
			}
		}
		if(V-subtree[u] > max)
			max = V-subtree[u];
		if(max <= V/2)
			root = u;
	}
	void reverse_dfs(const int& u){
		if(parent[u] == -1)
			return;
		subtree[parent[u]] = V-subtree[u];
		reverse_dfs(parent[u]);
		parent[parent[u]] = u;
	}
	void hld_dfs(const int& u, int& cur, const T& cost){
		int v;
		T nextcost;
		if(head[u] == -1)
			head[u] = u;
		else
			head[u] = head[parent[u]];
		heavy[u] = -1;
		id[u] = cur;
		(*sgt)[cur++] = cost;
		for(int i = 0; i < size[u]; i++){
			v = edges[u][i].first;
			if(parent[u] != v){
				depth[v] = depth[u] + 1;
				if(heavy[u] == -1 || subtree[v] > subtree[heavy[u]]){
					heavy[u] = v;
					nextcost = edges[u][i].second;
				}
			}
		}
		if(heavy[u] != -1){
			hld_dfs(heavy[u], cur, nextcost);
			for(int i = 0; i < size[u]; i++){
				v = edges[u][i].first;
				if(v != heavy[u] && v != parent[u]){
					head[v] = -1;
					hld_dfs(v, cur, edges[u][i].second);
				}
			}
		}
	}

public:
	//0-indexing
	HLD(const int& N){
		V = N; //Please make sure V is not 1
		edges = new vector<pair<int, T> >[V];
		subtree = new int[V];
		parent = new int[V];
		heavy = new int[V];
		size = new int[V]();
		depth = new int[V];
		head = new int[V];
		id = new int[V];
		sgt = new SegTree<T>(V);
	}
	~HLD(){
		delete[] edges;
		delete[] subtree;
		delete[] parent;
		delete[] heavy;
		delete[] size;
		delete[] depth;
		delete[] head;
		delete[] id;
		delete sgt;
	}
	//Add edges
	void add(const int& u, const int& v, const T& w){
		edges[u].push_back(pair<int, T>(v, w));
		edges[v].push_back(pair<int, T>(u, w));
		size[u]++;
		size[v]++;
	}
	//Call this to run
	void exec(){
		parent[0] = -1;
		dfs(0); //Optimize by rooting at centroid, subtree size dfs
		reverse_dfs(root); //Reverse parent path of root
		parent[root] = -1;
		subtree[root] = V;
		depth[root] = 0;
		//Using information from previous dfs to generate HLD, also generate depth for LCA
		int cur = 0;
		head[root] = -1;
		hld_dfs(root, cur, 0);
		sgt->build(); //Build Segment Tree
	}
	//Update, O(log(N))
	void update(const int& v, const T& w){
		sgt->update(id[v], w);
	}
	//Query, O(log^2(N))
	T query(int a, int b){
		T ans = 0;
		//Follow up of LCA
		while(head[a] != head[b]){
			if(depth[head[a]] > depth[head[b]]){
				ans = queryfunc(ans, sgt->query(id[head[a]], id[a]+1));
				a = parent[head[a]];
			}else{
				ans = queryfunc(ans, sgt->query(id[head[b]], id[b]+1));
				b = parent[head[b]];
			}
		}
		if(depth[a] < depth[b])
			ans = queryfunc(ans, sgt->query(id[a]+1, id[b]+1));
		else
			ans = queryfunc(ans, sgt->query(id[b]+1, id[a]+1));
		return ans;
	}
	int getDepth(const int& u){
		return depth[u];
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
	int T, N, Q;
	readInt(T);
	while(T--){
		readInt(N);
		HLD<int> hld(N);
		pair<int, pair<int, int> > edges[N-1];
		for(int i = 0; i < N-1; i++){
			readInt(edges[i].second.first);
			readInt(edges[i].second.second);
			readInt(edges[i].first);
			edges[i].second.first--;
			edges[i].second.second--;
			hld.add(edges[i].second.first, edges[i].second.second, 0);
		}
		sort(edges, edges+N-1);
		hld.exec();
		readInt(Q);
		pair<pair<int, int>, pair<int, int> > queries[Q];
		for(int i = 0; i < Q; i++){
			readInt(queries[i].second.first);
			readInt(queries[i].second.second);
			queries[i].second.first--;
			queries[i].second.second--;
			readInt(queries[i].first.first);
			queries[i].first.second = i;
		}
		sort(queries, queries+Q);
		int ans[Q], loc = 0;
		for(int i = 0; i < Q; i++){
			while(loc < N-1 && edges[loc].first <= queries[i].first.first){
				if(hld.getDepth(edges[loc].second.first) > hld.getDepth(edges[loc].second.second))
					hld.update(edges[loc].second.first, edges[loc].first);
				else
					hld.update(edges[loc].second.second, edges[loc].first);
				loc++;
			}
			ans[queries[i].first.second] = hld.query(queries[i].second.first, queries[i].second.second);
		}
		for(int i = 0; i < Q; i++)
			printf("%d\n", ans[i]);
	}
}