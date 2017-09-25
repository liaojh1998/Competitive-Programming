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
	FastIO(bool useFile = true){
		if(useFile){
			freopen("A.in", "r", stdin);
			freopen("A.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

bool check(int* arr, const int& N, const int& start, const int& end){
	bool predicate = true;
	int maxi = end, mini = start;
	for(int i = N/2-1; i > 0 && predicate; i--){
		if(arr[i] == maxi)
			maxi--;
		else if(arr[i] == mini)
			mini++;
		else
			predicate = false;
		if(arr[N-i-1] == maxi)
			maxi--;
		else if(arr[N-i-1] == mini)
			mini++;
		else
			predicate = false;
	}
	return predicate;
}

void FastIO::solve(){
	int T, N;
	readInt(T);
	for(int idx = 1; idx <= T; idx++){
		readInt(N);
		int arr[N+5];
		for(int i = 0; i < N; i++)
			readInt(arr[i]);
		bool answer;
		if(N&1){
			if(arr[N/2] == N)
				answer = check(arr, N, 1, N-1);
			else if(arr[N/2] == 1)
				answer = check(arr, N, 2, N);
			else
				answer = false;
		}else
			answer = check(arr, N, 1, N);
		printf("Case #%d: %s\n", idx, answer ? "YES" : "NO");
	}
}