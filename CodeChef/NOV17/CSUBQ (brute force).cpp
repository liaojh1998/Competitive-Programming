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
	int N, Q, L, R, q, l, r;
	readInt(N);
	readInt(Q);
	readInt(L);
	readInt(R);
	int arr[N+5];
	memset(arr, 0, sizeof(arr));
	while(Q--){
		readInt(q);
		readInt(l);
		readInt(r);
		if(q == 1)
			arr[l] = (r < L) ? 0 : (r > R) ? 2 : 1;
		else{
			long long ans = 0, low = 0, inrange = 0;
			for(int i = l; i <= r; i++){
				if(arr[i] < 2){
					if(!arr[i])
						low++;
					inrange++;
				}else{
					ans += inrange*(inrange+1)/2 - low*(low+1)/2;
					inrange = 0;
					low = 0;
				}
			}
			if(inrange)
				ans += inrange*(inrange+1)/2 - low*(low+1)/2;
			printf("%lld\n", ans);
		}
	}
}