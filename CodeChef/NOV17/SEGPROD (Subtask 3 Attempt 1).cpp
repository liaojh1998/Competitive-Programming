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
	long long gcd(long long a, long long b){
		return b ? gcd(b, a%b) : a;
	}
	long long fexp(long long b, long long p, long long MOD){
		long long ans = 1;
		while(p){
			if(p&1)
				ans = (ans * b)%MOD;
			b = (b * b)%MOD;
			p >>= 1;
		}
		return ans;
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
		int N, Q, primesize, maxcount = 0;
		long long P, t, div, mul, mulcount;
		readInt(N);
		readLL(P);
		readInt(Q);
		long long prefix[N+5], inv[N+5];
		prefix[0] = 1;
		inv[0] = 1;
		//Get primes
		vector<long long> prime, exp, expcount;
		t = P;
		for(int i = 0; i < primessize && primes[i] <= t; i++){
			if(!(t%primes[i])){
				prime.push_back(primes[i]);
				mul = 1;
				mulcount = 0;
				while(!(t%primes[i])){
					t /= primes[i];
					mul *= primes[i];
					mulcount++;
				}
				exp.push_back(mul);
				expcount.push_back(mulcount);
				if(maxcount < mulcount)
					maxcount = mulcount;
			}
		}
		if(t != 1){
			prime.push_back(t);
			exp.push_back(t);
			expcount.push_back(1);
		}
		primesize = prime.size();
		//The great divide
		if(primesize == 1){
			long long primeprefix[N+5];
			primeprefix[0] = 0;
			//Read
			for(int i = 1; i <= N; i++){
				readLL(t);
				div = gcd(t, P);
				t /= div;
				primeprefix[i] = primeprefix[i-1];
				while(!(div%prime[0])){
					primeprefix[i]++;
					div /= prime[0];
				}
				prefix[i] = (prefix[i-1]*t)%P;
				inv[i] = modinverse(prefix[i], P);
			}
			long long pow[expcount[0]];
			pow[0] = 1;
			for(int i = 1; i < expcount[0]; i++)
				pow[i] = pow[i-1]*prime[0];
			//Query
			int size = Q/64 + 2;
			long long q[size];
			for(int i = 0; i < size; i++)
				readLL(q[i]);
			long long x = 0, L, R, count;
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
				count = primeprefix[R+1]-primeprefix[L];
				if(count < expcount[0])
					x = ((((prefix[R+1]*inv[L])%P)*pow[count])%P + 1)%P;
				else
					x = 1;
			}
			printf("%lld\n", x);
		}else{
			long long primeprefix[primesize][N+5], primeinverse[primesize][N+5], primeprefixcount[primesize][N+5], newmod[primesize], inversenewmod[primesize], pow[primesize][maxcount], curprime, count;
			for(int i = 0; i < primesize; i++){
				newmod[i] = P/exp[i];
				primeprefix[i][0] = primeinverse[i][0] = 1;
				primeprefixcount[i][0] = 0;
				inversenewmod[i] = modinverse(exp[i], newmod[i]);
				pow[i][0] = 1;
				count = expcount[i];
				for(int j = 1; j < count; j++)
					pow[i][j] = (pow[i][j-1]*prime[i])%P;
			}
			//Read
			for(int i = 1; i <= N; i++){
				readLL(t);
				for(int j = 0; j < primesize; j++){
					mul = 1;
					curprime = prime[j];
					count = 0;
					while(!(t%curprime)){
						t /= curprime;
						mul *= curprime;
						count++;
					}
					if(mul == 1){
						primeprefix[j][i] = primeprefix[j][i-1];
						primeinverse[j][i] = primeinverse[j][i-1];
						primeprefixcount[j][i] = primeprefixcount[j][i-1];
					}else{
						primeprefix[j][i] = (primeprefix[j][i-1]*mul)%newmod[j];
						primeinverse[j][i] = modinverse(primeprefix[j][i], newmod[j]);
						primeprefixcount[j][i] = primeprefixcount[j][i-1]+count;
					}
				}
				prefix[i] = (prefix[i-1]*t)%P;
				inv[i] = modinverse(prefix[i], P);
			}
			//Query
			int size = Q/64 + 2;
			long long q[size];
			for(int i = 0; i < size; i++)
				readLL(q[i]);
			long long x = 0, L, R;
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
				x = (prefix[R+1]*inv[L])%P;
				for(int j = 0; j < primesize; j++){
					count = primeprefixcount[j][R+1]-primeprefixcount[j][L];
					if(count < expcount[j])
						x = (x*pow[j][count])%P;
					else{
						mul = ((((primeprefix[j][R+1]*primeinverse[j][L])%newmod[j])*inversenewmod[j])%newmod[j]*exp[j])%P;
						x = (x*mul)%P;
					}
					//printf("%lld %lld %lld %lld\n", prime[j], count, mul, newmod[j]);
					//printf("Newmod inversed: %lld\n", (primeprefix[j][R+1]*primeinverse[j][L])%newmod[j]);
					//printf("Reduce by exp: %lld\n", (((primeprefix[j][R+1]*primeinverse[j][L])%newmod[j])*inversenewmod[j])%newmod[j]);
				}
				x = (x + 1)%P;
				//printf("%lld %lld %lld\n", L, R+1, x);
			}
			printf("%lld\n", x);
		}
	}
	//clock_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
}