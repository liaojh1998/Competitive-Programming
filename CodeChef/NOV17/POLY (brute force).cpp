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
	int T;
	readInt(T);
	while(T--){
		int N, Q;
		readInt(N);
		long long arr[N][4], x, ans, cal;
		for(int i = 0; i < N; i++){
			readLL(arr[i][0]);
			readLL(arr[i][1]);
			readLL(arr[i][2]);
			readLL(arr[i][3]);
		}
		readInt(Q);
		while(Q--){
			ans = ((long long)1)<<63-1;
			readLL(x);
			for(int i = 0; i < N; i++){
				cal = arr[i][0]+arr[i][1]*x+arr[i][2]*x*x+arr[i][3]*x*x*x;
				if(ans > cal)
					ans = cal;
			}
			printf("%lld\n", ans);
		}
	}
}