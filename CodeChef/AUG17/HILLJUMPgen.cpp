#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
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
			//freopen("input.txt", "r", stdin);
			freopen("input.txt", "w", stdout);
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
	mt19937 rng(time(NULL));
	int N = 100000, Q = 100000, t, p, q, X;
	printf("%d %d\n", N, Q);
	for(int i = 0; i < N; i++)
		printf("%d%s", rng()%1000000+1, i == N-1 ? "\n" : " ");
	for(int i = 0; i < Q; i++){
		t = rng()%2+1;
		printf("%d ", t);
		if(t == 1){
			printf("%d %d\n", rng()%N+1, rng()%N+1);
		}else{
			p = rng()%N+1;
			if(N-p)
				q = rng()%(N-p)+p;
			else
				q = p;
			X = rng()%2000000-1000000;
			printf("%d %d %d\n", p, q, X);
		}
	}
}