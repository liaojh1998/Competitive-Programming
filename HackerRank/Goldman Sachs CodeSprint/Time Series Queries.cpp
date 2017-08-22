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

void FastIO::solve(){
	int N, Q, type, v, c;
	readInt(N);
	readInt(Q);
	int t[N+5], p[N+5];
	for(int i = 0; i < N; i++)
		readInt(t[i]);
	for(int i = 0; i < N; i++)
		readInt(p[i]);
	int height = ceil(log2(N));
	int top = 1<<height;
	int tree[top+N], a, b, maxi[N+5];
	for(int i = top; i < top+N; i++)
		tree[i] = p[i-top];
	for(int i = top-1; i > 0; i--){
		a = ((i<<1) >= top+N) ? -1 : tree[i<<1];
		b = ((i<<1|1) >= top+N) ? -1 : tree[i<<1|1];
		tree[i] = max(a, b);
	}
	maxi[N-1] = p[N-1];
	for(int i = N-2; i >= 0; i--)
		maxi[i] = max(maxi[i+1], p[i]);
	while(Q--){
		readInt(type);
		readInt(v);
		if(type == 1){
			if(tree[1] < v)
				printf("-1\n");
			else{
				c = 1;
				while(c < top){
					if(tree[c<<1] >= v)
						c <<= 1;
					else
						c = c<<1|1;
				}
				c -= top;
				printf("%d\n", t[c]);
			}
		}else{
			c = lower_bound(t, t+N, v)-t;
			if(c == N)
				printf("-1\n");
			else
				printf("%d\n", maxi[c]);
		}
	}
}