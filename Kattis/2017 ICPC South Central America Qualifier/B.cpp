#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegTree{
#define defval (0)
private:
	T* sgt;
	T* lazy;
	size_t N;
	T applyfunc(const T& a, const T& b){
		return b == -1 ? 0 : a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}
	
	T propfunc(const T& a, const T& b){
		return b == -1 ? b : a == -1 ? b : a + b;
	}
	void propagate(size_t node, size_t l, size_t r){
		if(l^r){
			lazy[node<<1] = propfunc(lazy[node<<1], lazy[node]);
			lazy[node<<1|1] = propfunc(lazy[node<<1|1], lazy[node]);
		}
		lazy[node] = 0;
	}
	void unlazy(size_t node, size_t l, size_t r){
		if(lazy[node]){
			sgt[node] = applyfunc(sgt[node], lazy[node] == -1 ? -1 : (r*(r+1)/2 - (l-1)*l/2)*lazy[node]);
			propagate(node, l, r);
		}
	}

	void update(size_t node, size_t ul, size_t ur, size_t l, size_t r, const T& value){
		if((l <= ul && r >= ur) || r < ul || l > ur){
			if(l <= ul && r >= ur)
				lazy[node] = propfunc(lazy[node], value);
			unlazy(node, ul, ur);
		}else{
			if(lazy[node])
				propagate(node, ul, ur);
			size_t m = (ul+ur)/2;
			update(node<<1, ul, m, l, r, value);
			update(node<<1|1, m+1, ur, l, r, value);
			sgt[node] = queryfunc(sgt[node<<1], sgt[node<<1|1]);
		}
	}
	T query(size_t node, size_t ql, size_t qr, size_t l, size_t r){
		if(l > qr || r < ql || r < l)
			return defval;
		unlazy(node, ql, qr);
		if(!((ql^l) | (qr^r)))
			return sgt[node];
		size_t m = (ql+qr)/2;
		T resl = defval, resr = defval;
		resl = queryfunc(resl, query(node<<1, ql, m, l, min(r, m)));
		resr = queryfunc(query(node<<1|1, m+1, qr, max(l, m+1), r), resr);
		return queryfunc(resl, resr);
	}

public:
	SegTree(size_t n){
		N = n;
		sgt = new T[(1<<((size_t)ceil(log2(N))+1))+5]();
		lazy = new T[(1<<((size_t)ceil(log2(N))+1))+5]();
	}
	~SegTree(){
		delete[] sgt;
		delete[] lazy;
	}
	void update(size_t l, size_t r, const T& value){
		if(l > r || l < 0 || r > N) return;
		update(1, 0, N, l, r, value);
	}
	T query(size_t l, size_t r){
		if(r < l) return defval;
		return query(1, 0, N, l, r);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, Q;
		cin >> N >> Q;
		SegTree<long long> sgt(N);
		while(Q--){
			int a, b, c;
			long long d;
			cin >> a;
			if(a == 1){
				cin >> b >> c >> d;
				sgt.update(b, c, d);
			}else if(a == 2){
				cin >> b >> c;
				sgt.update(b, c, -1);
			}else
				cout << sgt.query(0, N) << endl;
		}
	}
	return 0;
}