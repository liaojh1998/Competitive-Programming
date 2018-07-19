#include <bits/stdc++.h>
using namespace std;

struct cash{
	long long M, S, P;
};

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

	bool check(long long maxtime, const int& R, const long long &B, const int &C, const cash *c);

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

bool FastIO::check(long long maxtime, const int &R, const long long &B, const int &C, const cash *c){
	vector<long long> pos;
	for(int i = 0; i < C; i++){
		pos.push_back(min(c[i].M, max((maxtime-c[i].P)/c[i].S, static_cast<long long>(0))));
	}
	sort(pos.begin(), pos.end(), greater<long long>());
	long long ans = 0;
	for(int i = 0; i < R; i++)
		ans += pos[i];
	return (ans >= B);
}

void FastIO::solve(){
	int T;
	scanf("%d", &T);
	for(int idx = 1; idx <= T; idx++){
		printf("Case #%d: ", idx);
		long long B;
		int R, C;
		scanf("%d%lld%d", &R, &B, &C);
		cash c[C+5];
		long long hi = 0;
		for(int i = 0; i < C; i++){
			scanf("%lld%lld%lld", &c[i].M, &c[i].S, &c[i].P);
			if(c[i].M*c[i].S+c[i].P > hi)
				hi = c[i].M*c[i].S+c[i].P;
		}
		long long lo = 0;
		//Binary search
		while(lo < hi){
			long long mid = (lo + hi) >> 1;
			if(check(mid, R, B, C, c))
				hi = mid;
			else
				lo = mid+1;
		}
		printf("%lld\n", lo);
	}
}