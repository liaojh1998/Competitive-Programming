#include <bits/stdc++.h>
using namespace std;

template<typename T> class FenTree{
private:
	T* fwt;
	size_t N;

	T applyfunc(const T& a, const T& b){
		return a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}

public:
	FenTree(size_t n){
		N = n + 1;
		fwt = new T[N]();
	}
	~FenTree(){
		delete[] fwt;
	}
	void update(size_t i, T value){
		for(i++; i < N; i += (i & -i))
			fwt[i] = applyfunc(fwt[i], value);
	}
	T query(size_t i){
		T ans = 0;
		for(i++; i; i &= (i - 1))
			ans = queryfunc(ans, fwt[i]);
		return ans;
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

struct dat{
	long long s;
	int idx;
};

bool cmp(const dat& a, const dat &b){
	return a.s < b.s;
}

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

void FastIO::solve(){
	int T;
	readInt(T);
	while(T--){
		int N;
		readInt(N);
		long long arr[N+5];
		for(int i = 0; i < N; i++)
			readLL(arr[i]);
		long long fsum[N+5], bsum[N+5];
		dat pfsum[N+5], pbsum[N+5];
		int ans[N+5];
		//Forward prefix sums
		fsum[0] = arr[0];
		for(int i = 1; i < N; i++)
			fsum[i] = fsum[i-1] + arr[i];
		for(int i = 0; i < N; i++){
			pfsum[i].s = fsum[i] + arr[i];
			pfsum[i].idx = i;
		}
		sort(pfsum, pfsum+N, cmp);
		FenTree<int> fwt(N);
		//Search and accumulate
		int j = N-1;
		ans[0] = 0;
		for(int i = N-1; i > 0; i--){
			while(j >= 0 && pfsum[j].s >= fsum[i-1])
				fwt.update(pfsum[j--].idx, 1);
			ans[i] = fwt.query(i-1);
		}
		//Backward prefix sums
		bsum[0] = arr[N-1];
		for(int i = N-2; i >= 0; i--)
			bsum[i] = bsum[i+1] + arr[i];
		for(int i = N-1; i >= 0; i--){
			pbsum[i].s = bsum[i] + arr[i];
			pbsum[i].idx = i;
		}
		sort(pbsum, pbsum+N, cmp);
		FenTree<int> fwt2(N);
		//Search and accumulate
		j = N-1;
		for(int i = 0; i < N-1; i++){
			while(j >= 0 && pbsum[j].s >= bsum[i+1])
				fwt2.update(N-pbsum[j--].idx-1, 1);
			ans[i] += fwt2.query(N-i-2);
		}
		//Print
		for(int i = 0; i < N; i++)
			printf("%d%c", ans[i], i == N-1 ? '\n' : ' ');
	}
}