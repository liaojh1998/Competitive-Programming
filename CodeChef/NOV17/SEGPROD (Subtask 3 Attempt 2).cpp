#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked

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
	void sieve(vector<long long>& primes){
		bool s[31625];
		memset(s, 0, sizeof(s));
		for(int i = 2; i < 31625; i++){
			if(!s[i]){
				primes.push_back(i);
				for(int j = 2; j*i < 31625; j++)
					s[j*i] = true;
			}
		}
	}
	long long getprime(const vector<long long>& primes, long long P, vector<long long>& prime, vector<int>& count){
		long long mul, cprime;
		int size = primes.size(), c;
		for(int i = 0; i < size; i++){
			if(!(P%primes[i])){
				mul = 1;
				c = 0;
				cprime = primes[i];
				prime.push_back(cprime);
				while(!(P%cprime)){
					mul *= cprime;
					c++;
					P /= cprime;
				}
				count.push_back(c);
			}
		}
		if(P != 1){
			prime.push_back(P);
			count.push_back(1);
			return P;
		}
		return mul;
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
	//How to have no life... SPENT 6 DAYS ON THIS?!
	//clock_t start = clock();
	vector<long long> primes;
	sieve(primes);
	int primessize = primes.size();
	//Algorithm
	int T;
	readInt(T);
	while(T--){
		int N, Q;
		long long P;
		readInt(N);
		readLL(P);
		readInt(Q);
		vector<long long> prime;
		vector<int> count;
		//New Mod
		long long newmod = getprime(primes, P, prime, count), cprime;
		//Read
		int psize = prime.size(), maxcount = 0;
		int primesumprefix[psize][N+5];
		long long prodprefix[N+5], prefixinv[N+5], primeprodprefix[N+5], primeprefixinv[N+5], inv = modinverse(P/newmod, newmod), t, tt;
		prodprefix[0] = prefixinv[0] = primeprodprefix[0] = primeprefixinv[0] = 1;
		for(int i = 0; i < psize; i++)
			primesumprefix[i][0] = 0;
		for(int i = 1; i <= N; i++){
			readLL(t);
			//Using the last prime first (by greedy assumption that it's the l e a s t u s e d)
			cprime = prime[psize-1];
			primesumprefix[psize-1][i] = primesumprefix[psize-1][i-1];
			while(!(t%cprime)){
				primesumprefix[psize-1][i]++;
				t /= cprime;
			}
			if(primesumprefix[psize-1][i] > maxcount)
				maxcount = primesumprefix[psize-1][i];
			//New product prefix and inverse using newmod
			tt = primeprodprefix[i-1]*t;
			primeprodprefix[i] = (tt >= newmod ? tt%newmod : tt);
			primeprefixinv[i] = modinverse(primeprodprefix[i], newmod);
			//New x^k where x is prime
			for(int j = 0; j < psize-1; j++){
				primesumprefix[j][i] = primesumprefix[j][i-1];
				cprime = prime[j];
				while(!(t%cprime)){
					primesumprefix[j][i]++;
					t /= cprime;
				}
				if(primesumprefix[j][i] > maxcount)
					maxcount = primesumprefix[j][i];
			}
			//New product prefix and inverse for P
			tt = prodprefix[i-1]*t;
			prodprefix[i] = (tt >= P ? tt%P : tt);
			prefixinv[i] = modinverse(prodprefix[i], P);
		}
		//Precalc for all power prime (might MLE and TLE for 2^k)
		long long pow[psize][maxcount+5];
		for(int i = 0; i < psize; i++){
			pow[i][0] = 1;
			maxcount = primesumprefix[i][N];
			cprime = prime[i];
			for(int j = 1; j <= maxcount; j++){
				tt = pow[i][j-1]*cprime;
				pow[i][j] = (tt >= newmod ? tt%newmod : tt);
			}
		}
		//Query
		int size = Q/64 + 2;
		int q[size];
		for(int i = 0; i < size; i++)
			readInt(q[i]);
		int L, R, x = 0, intt;
		for(int i = 0; i < Q; i++){
			if(i%64){
				intt = L + x;
				L = (intt >= N ? intt%N : intt);
				intt = R + x;
				R = (intt >= N ? intt%N : intt);
			}else{
				intt = q[i/64] + x;
				L = (intt >= N ? intt%N : intt);
				intt = q[i/64 + 1] + x;
				R = (intt >= N ? intt%N : intt);
			}
			if(L > R){
				t = L;
				L = R;
				R = t;
			}
			bool need = false;
			for(int j = 0; j < psize-1 && !need; j++)
				if(primesumprefix[j][R+1]-primesumprefix[j][L] < count[j])
					need = true;
			if(need){
				tt = prodprefix[R+1] * prefixinv[L];
				x = (tt >= P ? tt%P : tt);
				for(int j = 0; j < psize; j++){
					tt = x*pow[j][primesumprefix[j][R+1]-primesumprefix[j][L]];
					x = (tt >= P ? tt%P : tt);
				}
			}else{
				tt = primeprodprefix[R+1] * primeprefixinv[L];
				x = (tt >= newmod ? tt%newmod : tt);
				tt = x * inv;
				x = (tt >= newmod ? tt%newmod : tt);
				tt = x * (P/newmod);
				x = (tt >= P ? tt%P : tt);
				tt = x * pow[psize-1][primesumprefix[psize-1][R+1]-primesumprefix[psize-1][L]];
				x = (tt >= P ? tt%P : tt);
			}
			tt = x + 1;
			x = (tt >= P ? tt%P : tt);
		}
		printf("%d\n", x);
	}
	//clock_t end = clock();
	//printf("%.6lf\n", ((double)end-start)/CLOCKS_PER_SEC);
}