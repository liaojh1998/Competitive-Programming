#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegTree{
private:
	T* sgt;
	T P;
	size_t N, height;
	#define defval (1)
	T applyfunc(const T& a, const T& b){
		return b % P;
	}
	T queryfunc(const T& a, const T& b){
		return (a * b)%P;
	}

public:
	SegTree(size_t n, const T& p){
		N = n;
		P = p;
		height = (size_t)ceil(log2(N));
		sgt = new T[1<<(height+1)];
		fill_n(sgt, (1<<(height+1)), defval);
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
	T query(size_t l, size_t r){
		if(!((l+1)^r)) return (*this)[l];
		T resl = defval, resr = defval;
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

void FastIO::solve(){
	int T;
	readInt(T);
	while(T--){
		int N, Q;
		long long P;
		readInt(N);
		readLL(P);
		readInt(Q);
		SegTree<long long> sgt(N, P);
		for(int i = 0; i < N; i++)
			readLL(sgt[i]);
		sgt.build();
		int size = Q/64 + 2;
		long long q[size];
		for(int i = 0; i < size; i++)
			readLL(q[i]);
		long long x = 0, t, L, R;
		for(int i = 0; i < Q; i++){
			if(i%64){
				L = (L + x)%N;
				R = (R + x)%N;
			}else{
				L = (q[i/64] + x)%N;
				R = (q[i/64 + 1] + x)%N;
			}
			if(L > R){
				t = L;
				L = R;
				R = t;
			}
			x = (sgt.query(L, R+1) + 1)%P;
			printf("%lld %lld %lld\n", L, R, x);
		}
		printf("%lld\n", x);
	}
}