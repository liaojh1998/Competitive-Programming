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
		long long arr[N+5];
		for(int i = 0; i < N; i++)
			readLL(arr[i]);
		for(int i = 0; i < N; i++)
			for(int j = i; j < N; j++){
				long long ans = 1, ansa = 1;
				for(int k = i; k <= j; k++){
					ans = (ans*arr[k])%P;
					ansa *= arr[k];
				}
				printf("%d %d %lld %lld\n", i, j, ansa, ans);
			}
	}
	//clock_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
}