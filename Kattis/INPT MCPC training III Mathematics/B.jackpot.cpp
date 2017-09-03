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

long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}

void FastIO::solve(){
	int T, N;
	readInt(T);
	while(T--){
		readInt(N);
		long long arr[N];
		for(int i = 0; i < N; i++)
			readLL(arr[i]);
		long long lcm = arr[0];
		for(int i = 1; i < N && lcm <= 1000000000; i++)
			lcm = lcm/gcd(lcm, arr[i])*arr[i];
		if(lcm > 1000000000)
			printf("More than a billion.\n");
		else
			printf("%lld\n", lcm);
	}
}