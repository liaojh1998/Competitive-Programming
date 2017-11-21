#include <bits/stdc++.h>
using namespace std;
//#define getchar getchar_unlocked
 
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
	FastIO fio;
	fio.solve();
	return 0;
}

void FastIO::solve(){
	//clock_t start = clock();
	int T;
	readInt(T);
	bool sieve[31625];
	memset(sieve, 0, sizeof(sieve));
	vector<long long> primes;
	for(int i = 2; i < 31625; i++){
		if(!sieve[i]){
			primes.push_back(i);
			for(int j = 2; j*i < 31625; j++)
				sieve[j*i] = true;
		}
	}
	int primessize = primes.size();
	while(T--){
		int N, Q, primesize;
		long long P, t;
		readInt(N);
		readLL(P);
		readInt(Q);
		long long prefix[N+5], inv[N+5];
		prefix[0] = 1;
		inv[0] = 1;
		//Get primes
		vector<long long> prime;
		t = P;
		for(int i = 0; i < primessize && primes[i] < t; i++){
			if(!(t%primes[i])){
				prime.push_back(primes[i]);
				while(!(t%primes[i]))
					t /= primes[i];
			}
		}
		if(t != 1)
			prime.push_back(t);
		primesize = prime.size();
		int primeprefix[primesize][N+5];
		long long curprime;
		for(int i = 0; i < primesize; i++)
			primeprefix[i][0] = 0;
		//Read
		int maxcount = 0;
		for(int i = 1; i <= N; i++){
			readLL(t);
			for(int j = 0; j < primesize; j++){
				primeprefix[j][i] = primeprefix[j][i-1];
				curprime = prime[j];
				while(!(t%prime[j])){
					primeprefix[j][i]++;
					t /= curprime;
				}
				if(primeprefix[j][i] > maxcount)
					maxcount = primeprefix[j][i];
			}
			if(!t) t = P;
			prefix[i] = prefix[i-1]*t;
			if(prefix[i] >= P) prefix[i] %= P;
			inv[i] = modinverse(prefix[i], P);
		}
		//printf("%d\n", maxcount);
		//Precalc for all powers of prime factors
		long long pow[primesize][maxcount+5];
		for(int i = 0; i < primesize; i++){
			pow[i][0] = 1;
			curprime = prime[i];
			for(int j = 1; j <= primeprefix[i][N]; j++){
				pow[i][j] = pow[i][j-1]*curprime;
				if(pow[i][j] >= P) pow[i][j] %= P;
			}
		}
		//Query
		int size = Q/64 + 2;
		int q[size];
		for(int i = 0; i < size; i++)
			readInt(q[i]);
		int L, R;
		long long x = 0;
		for(int i = 0; i < Q; i++){
			//printf("%d\n", i);
			if(i%64){
				L += x;
				if(L >= N) L %= N;
				R += x;
				if(R >= N) R %= N;
			}else{
				L = q[i/64] + x;
				if(L >= N) L %= N;
				R = q[i/64+1] + x;
				if(R >= N) R %= N;
			}
			if(L > R){
				t = L;
				L = R;
				R = t;
			}
			x = prefix[R+1]*inv[L];
			if(x >= P) x %= P;
			for(int j = 0; j < primesize; j++){
				x = pow[j][primeprefix[j][R+1]-primeprefix[j][L]]*x;
				if(x >= P) x %= P;
			}
			x++;
			if(x >= P) x %= P;
		}
		printf("%lld\n", x);
	}
	//clock_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
}