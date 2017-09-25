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

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("B.in", "r", stdin);
			freopen("B.out", "w", stdout);
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
	int T, N, E, maxH, H, cur, end;
	readInt(T);
	for(int idx = 1; idx <= T; idx++){
		readInt(E);
		readInt(N);
		H = maxH = 0;
		int arr[N+5];
		for(int i = 0; i < N; i++)
			readInt(arr[i]);
		//Greedy, addition and subtraction give the same results
		sort(arr, arr+N);
		cur = 0;
		end = N-1;
		while(cur <= end && E > arr[cur]){
			while(E > arr[cur] && cur <= end){
				E -= arr[cur++];
				H++;
			}
			if(maxH < H)
				maxH = H;
			if(H > 0 && end >= cur){
				E += arr[end--];
				H--;
			}
		}
		printf("Case #%d: %d\n", idx, maxH);
	}
}