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

#define LIMIT (10000000)
void sieve(int *list){
	memset(list, 0, sizeof(int)*LIMIT);
	list[2] = list[3] = 1;
	for(int x = 1; x*x <= LIMIT; x++)
		for(int y = 1; y*y <= LIMIT; y++){
			int n = 4*x*x+y*y;
			if(n <= LIMIT && (n%12 == 1 || n%12 == 5))
				list[n] = ~list[n];
			n = 3*x*x+y*y;
			if(n <= LIMIT && n%12 == 7)
				list[n] = ~list[n];
			n = 3*x*x-y*y;
			if(x > y && n <= LIMIT && n%12 == 11)
				list[n] = ~list[n];
		}
	for(int i = 5; i*i <= LIMIT; i++)
		if(list[i]){
			int j = 1;
			int k = j++*i*i;
			while(k <= LIMIT){
				list[k] = 0;
				k = j++*i*i;
			}
		}
}

void dfs(int cur, int d, const int& size, int *arr, int *primes, bool *vis, bool *used, int& ans){
	int next;
	for(int i = 0; i < size; i++){
		if(!used[i]){
			used[i] = true;
			next = cur*10+arr[i];
			if(primes[next] && !vis[next]){
				ans++;
				vis[next] = true;
			}
			if(d < size)
				dfs(cur*10+arr[i], d+1, size, arr, primes, vis, used, ans);
			used[i] = false;
		}
	}
}

void FastIO::solve(){
	int primes[LIMIT+1];
	bool vis[LIMIT+1], used[7];
	sieve(primes);
	int T, N, arr[7], size, ans;
	char c;
	readInt(T);
	while(T--){
		memset(vis, 0, sizeof(vis));
		size = ans = 0;
		c = getchar();
		while(c != 10 && ~c){
			arr[size++] = c-'0';
			c = getchar();
		}
		dfs(0, 1, size, arr, primes, vis, used, ans);
		printf("%d\n", ans);
	}
}