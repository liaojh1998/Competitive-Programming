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
			freopen("input.txt", "r", stdin);
			freopen("outputexpected.txt", "w", stdout);
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
	int N, Q, l, r, k, t, i;
	long long x;
	readInt(N);
	readInt(Q);
	long long arr[N+5];
	for(i = 0; i < N; i++)
		readLL(arr[i]);
	while(Q--){
		readInt(t);
		if(t == 1){
			readInt(l);
			l--;
			//printf("%d ", arr[l]);
			readInt(k);
			while(k--){
				for(i = 0; i+l < N && arr[i+l] <= arr[l] && i <= 100; i++);
				if(i > 100 || i+l == N)
					k = 0;
				else
					l += i;
				//printf("%d ", arr[l]);
			}
			printf("%d\n", l+1);
		}else{
			readInt(l);
			readInt(r);
			readLL(x);
			for(i = l-1; i <= r-1; i++)
				arr[i] += x;
			//for(i = max(l-1-100, 0); i <= r-1+100 && i < N; i++)
				//printf("%lld%s", arr[i], i == r-1+100 || i == N-1 ? "\n" : " ");
		}
	}
}