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

	int trouble_sort();

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output-brute.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

int FastIO::trouble_sort(){
	int N;
	readInt(N);
	int arr[N+5];
	for(int i = 0; i < N; i++)
		readInt(arr[i]);
	bool done = false;
	while(!done){
		done = true;
		for(int i = 0; i < N-2; i++)
			if(arr[i] > arr[i+2]){
				done = false;
				int t = arr[i];
				arr[i] = arr[i+2];
				arr[i+2] = t;
			}
	}
	int ans = -1;
	for(int i = 0; i < N-1 && ans == -1; i++)
		if(arr[i] > arr[i+1])
			ans = i;
	return ans;
}

void FastIO::solve(){
	int T;
	readInt(T);
	for(int idx = 1; idx <= T; idx++){
		printf("Case #%d: ", idx);
		int ans = trouble_sort();
		if(ans != -1)
			printf("%d\n", ans);
		else
			printf("OK\n");
	}
}