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

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("mootube.in", "r", stdin);
			freopen("mootube.out", "w", stdout);
		}
	}

	void solve();
};

class UFDS{
private:
	int* count;
	size_t* parent;
	size_t* rank;
	size_t N, disjointSetNum;

public:
	void makeSet(size_t i){
		parent[i] = i;
		rank[i] = 0;
		count[i] = 1;
	}

	UFDS(size_t n){
		N = disjointSetNum = n;
		parent = new size_t[N+5];
		rank = new size_t[N+5];
		count = new int[N+5];
		for(size_t i = 0; i <= N; i++)
			makeSet(i);
	}
	~UFDS(){
		delete[] parent;
		delete[] rank;
		delete[] count;
	}
	size_t findSet(size_t i){
		return (parent[i] != i) ? (parent[i] = findSet(parent[i])) : i;
	}
	void unionSets(size_t i, size_t j){
		size_t parenti = findSet(i), parentj = findSet(j);
		if(parenti == parentj)
			return;
		if(rank[parenti] < rank[parentj]){
			parent[parenti] = parentj;
			count[parentj] += count[parenti];
			count[parenti] -= count[parenti];
		}else{
			parent[parentj] = parenti;
			count[parenti] += count[parentj];
			count[parentj] -= count[parentj];
			if(rank[parenti] == rank[parentj])
				rank[parenti]++;
		}
		disjointSetNum--;
	}
	bool isSameSet(size_t i, size_t j){
		return findSet(i) == findSet(j);
	}
	size_t getDisjointSetNum(){
		return disjointSetNum;
	}
	int getCount(int i){
		return count[findSet(i)];
	}
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

struct tple{
	int a, b, c;
};

bool cmp(const tple& f, const tple& s){
	return f.c > s.c;
}

void FastIO::solve(){
	//Get data
	int N, Q;
	readInt(N);
	readInt(Q);
	tple G[N+5];
	for(int i = 0; i < N-1; i++){
		readInt(G[i].a);
		readInt(G[i].b);
		readInt(G[i].c);
	}
	sort(G, G+N-1, cmp);
	tple qs[Q+5];
	for(int i = 0; i < Q; i++){
		readInt(qs[i].c);
		readInt(qs[i].b);
		qs[i].a = i;
	}
	sort(qs, qs+Q, cmp);
	//Offline Querying
	UFDS sets(N);
	int k = 0, ans[Q+5];
	for(int i = 0; i < Q; i++){
		while(k < N-1 && G[k].c >= qs[i].c){
			sets.unionSets(G[k].a, G[k].b);
			k++;
		}
		ans[qs[i].a] = sets.getCount(qs[i].b) - 1;
	}
	for(int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
}