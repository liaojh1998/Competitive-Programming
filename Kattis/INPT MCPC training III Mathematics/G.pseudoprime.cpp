#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
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
	//Constructor, true if using file input/output, defaulted false
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

bool test(long long a, long long p, vector<long long>& primes){
	bool prime = true;
	int size = primes.size();
	for(int i = 0; i < size && primes[i]*primes[i] <= p && prime; i++)
		if(p%primes[i] == 0)
			prime = false;
	if(prime)
		return false;
	long long MOD = p, olda = a, ans = 1;
	while(p){
		if(p & 1)
			ans = (a*ans)%MOD;
		a = (a*a)%MOD;
		p >>= 1;
	}
	return (ans == olda); //Why doesn't (a^(p-1) == 1 % p) work...?
}

void FastIO::solve(){
	//Fermat pseudoprimes and Carmichael numbers are actually real...
	//I realized today that coprimes between base a and power p does not give 1 mod p if p is not prime.
	bool sieve[40000];
	vector<long long> primes;
	memset(sieve, 1, sizeof(sieve));
	for(long long i = 2; i*i <= 1000000000; i++)
		if(sieve[i]){
			primes.push_back(i);
			for(long long j = 2; j*i < 40000; j++)
				sieve[j*i] = false;
		}
	long long p, a;
	while(~readLL(p) && ~readLL(a) && p && a)
		printf("%s\n", test(a, p, primes) ? "yes" : "no");
}