#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
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

bitset<100000010> primes;

void FastIO::solve(){
	int N;
	readInt(N);
	primes.flip();
	primes[1] = 0;
	for(int i = 2; i*i <= N; i++)
		if(primes[i])
			for(int j = 2; j*i <= N; j++)
				primes[j*i] = 0;
	int Q, x, sum = 0;
	readInt(Q);
	for(int i = 2; i <= N; i++)
		if(primes[i])
			sum++;
	printf("%d\n", sum);
	while(Q--){
		readInt(x);
		printf("%d\n", primes[x] ? 1 : 0);
	}
}