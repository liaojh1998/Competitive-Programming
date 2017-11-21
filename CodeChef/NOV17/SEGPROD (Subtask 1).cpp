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
	long long modinverse(long long a, long long n){
		long long t = 0, newt = 1, r = n, newr = a, div, temp;
		int count = 0;
		while(newr){
			div = r/newr;
			temp = newt;
			newt = t - div*newt;
			t = temp;
			temp = newr;
			newr = r - div*newr;
			r = temp;
		}
		if(t < 0)
			t = t + n;
		return t;
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
	FastIO fio(true);
	fio.solve();
	return 0;
}

void FastIO::solve(){
	//clock_t start = clock();
	int T;
	readInt(T);
	while(T--){
		int N, Q;
		long long P, t;
		readInt(N);
		readLL(P);
		readInt(Q);
		long long prefix[N+5], inv[N+5];
		prefix[0] = 1;
		inv[0] = 1;
		for(int i = 1; i <= N; i++){
			readLL(t);
			prefix[i] = (prefix[i-1]*t)%P;
			inv[i] = modinverse(prefix[i], P);
		}
		int size = Q/64 + 2;
		long long q[size];
		for(int i = 0; i < size; i++)
			readLL(q[i]);
		long long x = 0, L, R;
		for(int i = 0; i < Q; i++){
			//printf("%d\n", i);
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
			x = ((prefix[R+1]*inv[L])%P + 1)%P;
			printf("%lld %lld %lld\n", L, R, x);
		}
		printf("%lld\n", x);
	}
	//clock_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
}