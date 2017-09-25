#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegTreeMax{
private:
	T* sgt;
	size_t N, height;
	T applyfunc(const T& a, const T& b){
		return a > b ? a : b;
	}
	T queryfunc(const T& a, const T& b){
		return a > b ? a : b;
	}

public:
	SegTreeMax(size_t n){
		N = n;
		height = (size_t)ceil(log2(N));
		sgt = new T[1<<(height+1)]();
	}
	~SegTreeMax(){
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
	T query(size_t l, size_t r){
		if(!((l+1)^r)) return (*this)[l];
		T resl = 0, resr = 0;
		for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
			if(l&1) resl = queryfunc(resl, sgt[l++]);
			if(r&1) resr = queryfunc(sgt[--r], resr);
		}
		return queryfunc(resl, resr);
	}
};

template<typename T> class SegTreeMin{
private:
	T* sgt;
	size_t N, height;
	T applyfunc(const T& a, const T& b){
		return a < b ? a : b;
	}
	T queryfunc(const T& a, const T& b){
		return a < b ? a : b;
	}

public:
	SegTreeMin(size_t n){
		N = n;
		height = (size_t)ceil(log2(N));
		sgt = new T[1<<(height+1)];
		for(int i = 0; i < (1<<(height+1)); i++)
			sgt[i] = 1000005;
	}
	~SegTreeMin(){
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
	T query(size_t l, size_t r){
		if(!((l+1)^r)) return (*this)[l];
		T resl = 1000005, resr = 1000005;
		for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
			if(l&1) resl = queryfunc(resl, sgt[l++]);
			if(r&1) resr = queryfunc(sgt[--r], resr);
		}
		return queryfunc(resl, resr);
	}
};

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
	int n, m, c;
	readInt(n);
	readInt(m);
	readInt(c);
	SegTreeMax<int> sgtmax(n);
	SegTreeMin<int> sgtmin(n);
	for(int i = 0; i < n; i++){
		readInt(sgtmax[i]);
		sgtmin[i] = sgtmax[i];
	}
	sgtmax.build();
	sgtmin.build();
	vector<int> ans;
	for(int i = 0; i < n-m+1; i++){
		if((sgtmax.query(i, i+m)-sgtmin.query(i, i+m)) <= c)
			ans.push_back(i+1);
	}
	if(ans.size())
		for(int i = 0; i < ans.size(); i++)
			printf("%d\n", ans[i]);
	else
		printf("NONE\n");
}