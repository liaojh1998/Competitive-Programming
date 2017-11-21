#include <bits/stdc++.h>
using namespace std;

struct segnode{
	bool lowfill, inrangefill;
	long long lowleft, lowright, inrangeleft, inrangeright, lowsum, inrangesum;
	segnode(){}
	segnode(bool lf, bool irf, long long ll, long long lr, long long irl, long long irr, long long ls, long long irs){
		lowfill = lf;
		inrangefill = irf;
		lowleft = ll;
		lowright = lr;
		inrangeleft = irl;
		inrangeright = irr;
		lowsum = ls;
		inrangesum = irs;
	}
	segnode operator+(const segnode& b) const{
		segnode temp;
		temp.lowfill = lowfill && b.lowfill;
		temp.inrangefill = inrangefill && b.inrangefill;
		if(!temp.lowfill){
			temp.lowleft = lowfill ? b.lowleft : lowleft;
			temp.lowright = b.lowfill ? lowright : b.lowright;
			temp.lowsum = lowfill ? b.lowsum : (b.lowfill ? lowsum : lowsum + b.lowsum + (b.lowleft-lowright+1)*(b.lowleft-lowright+2)/2);
		}else{
			temp.lowleft = lowleft; //Actually useless
			temp.lowright = b.lowright; //Actually useless
			temp.lowsum = 0;
		}
		if(!temp.inrangefill){
			temp.inrangeleft = inrangefill ? b.inrangeleft : inrangeleft;
			temp.inrangeright = b.inrangefill ? inrangeright : b.inrangeright;
			temp.inrangesum = inrangefill ? b.inrangesum : (b.inrangefill ? inrangesum : inrangesum + b.inrangesum + (b.inrangeleft-inrangeright+1)*(b.inrangeleft-inrangeright+2)/2);
		}else{
			temp.inrangeleft = inrangeleft; //Actually useless
			temp.inrangeright = b.inrangeright; //Actually useless
			temp.inrangesum = 0;
		}
		return temp;
	}
};

template<typename T> class SegTree{
private:
	T* sgt;
	T* arr;
	size_t N;

	T applyfunc(const T& a, const T& b){
		return b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}
	
	T push(size_t node, size_t l, size_t r){
		if(l^r)
			sgt[node] = queryfunc(push(node<<1, l, (l+r)/2), push(node<<1|1, (l+r)/2+1, r));
		else
			sgt[node] = applyfunc(sgt[node], arr[l]);
		return sgt[node];
	}
	void update(size_t node, size_t l, size_t r, size_t pos, const T& value){
		if(l^r){
			size_t m = (l+r)/2;
			if(pos > m)
				update(node<<1|1, m+1, r, pos, value);
			else
				update(node<<1, l, m, pos, value);
			sgt[node] = queryfunc(sgt[node<<1], sgt[node<<1|1]);
		}else{
			sgt[node] = applyfunc(sgt[node], value);
			arr[pos] = applyfunc(arr[pos], value);
		}
		//printf("In range? %d\nLower? %d\nirl: %lld irr: %lld\nll: %lld lr: %lld\nirs: %lld ls: %lld\n", sgt[node].inrangefill, sgt[node].lowfill, sgt[node].inrangeleft, sgt[node].inrangeright, sgt[node].lowleft, sgt[node].lowright, sgt[node].inrangesum, sgt[node].lowsum);
	}
	T query(size_t node, size_t ql, size_t qr, size_t l, size_t r){
		if(ql > r || qr < l || r < l)
			return T(true, true, l-1, r+1, l-1, r+1, 0, 0); //Actually useless, only needs first 2 condition to be true
		if(!((ql^l) | (qr^r)))
			return sgt[node];
		size_t m = (l+r)/2;
		return queryfunc(query(node<<1, ql, min(qr, m), l, m), query(node<<1|1, max(ql, m+1), qr, m+1, r));
	}

public:
	SegTree(size_t n){
		N = n;
		sgt = new T[(1<<((size_t)ceil(log2(N))+1))+5];
		arr = new T[N+5];
	}
	~SegTree(){
		delete[] sgt;
		delete[] arr;
	}
	T& operator[](size_t i){
		return arr[i];
	}

	void build(){
		push(1, 0, N-1);
	}
	void update(size_t pos, const T& value){
		if(pos < 0 || pos >= N) return;
		arr[pos] = applyfunc(arr[pos], value);
		update(1, 0, N-1, pos, value);
	}
	T query(size_t l, size_t r){
		return query(1, l, r, 0, N-1);
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
	int N, Q, q;
	long long L, R, l, r;
	readInt(N);
	readInt(Q);
	readLL(L);
	readLL(R);
	SegTree<segnode> sgt(N);
	segnode temp;
	temp.lowsum = temp.inrangesum = 0;
	for(int i = 0; i < N; i++)
		sgt[i] = segnode(true, true, i-1, i+1, i-1, i+1, 0, 0);
	sgt.build();
	while(Q--){
		readInt(q);
		readLL(l);
		readLL(r);
		if(q == 1){
			l--;
			temp.inrangefill = (r <= R) ? true : false;
			temp.lowfill = (r < L) ? true : false;
			if(!temp.inrangefill){
				temp.inrangeleft = l-1;
				temp.inrangeright = l+1;
			}else
				temp.inrangeleft = temp.inrangeright = l; //Actually useless
			if(!temp.lowfill){
				temp.lowleft = l-1;
				temp.lowright = l+1;
			}else
				temp.lowleft = temp.lowright = l; //Actually useless
			//printf("In range? %d\nLower? %d\nirl: %lld irr: %lld\nll: %lld lr: %lld\nirs: %lld ls: %lld\n", temp.inrangefill, temp.lowfill, temp.inrangeleft, temp.inrangeright, temp.lowleft, temp.lowright, temp.inrangesum, temp.lowsum);
			sgt.update(l, temp);
		}else{
			l--;
			r--;
			segnode ans = sgt.query(l, r);
			//printf("In range? %d\nLower? %d\nirl: %lld irr: %lld\nll: %lld lr: %lld\nirs: %lld ls: %lld\n", ans.inrangefill, ans.lowfill, ans.inrangeleft, ans.inrangeright, ans.lowleft, ans.lowright, ans.inrangesum, ans.lowsum);
			if(ans.lowfill)
				printf("0\n");
			else{
				long long subarrays = (ans.inrangefill) ? (r-l+1)*(r-l+2)/2 : ans.inrangesum+(ans.inrangeleft-l+1)*(ans.inrangeleft-l+2)/2+(r-ans.inrangeright+1)*(r-ans.inrangeright+2)/2;
				subarrays -= ans.lowsum+(ans.lowleft-l+1)*(ans.lowleft-l+2)/2+(r-ans.lowright+1)*(r-ans.lowright+2)/2;
				printf("%lld\n", subarrays);
			}
		}
	}
}