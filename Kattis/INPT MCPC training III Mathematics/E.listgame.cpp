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

void FastIO::solve(){
	int N, ans = 0;
	readInt(N);
	bool primes[40000];
	memset(primes, 1, sizeof(primes));
	for(int i = 2; i*i <= N; i++)
		if(primes[i]){
			while(!(N%i)){
				N /= i;
				ans++;
			}
			for(int j = 2; j*i < 40000; j++)
				primes[j*i] = false;
		}
	if(N != 1)
		ans++;
	printf("%d\n", ans);
}