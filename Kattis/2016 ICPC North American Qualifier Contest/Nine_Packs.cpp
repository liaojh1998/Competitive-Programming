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
	int N, M, k;
	readInt(N);
	int dpa[N+1][N*1000+1];
	dpa[0][0] = 0;
	for(int i = 1; i <= N*1000; i++)
		dpa[0][i] = N+1;
	for(int i = 1; i <= N; i++){
		readInt(k);
		for(int j = 0; j < k; j++)
			dpa[i][j] = dpa[i-1][j];
		for(int j = k; j <= N*1000; j++)
			dpa[i][j] = min(dpa[i-1][j-k]+1, dpa[i-1][j]);
	}
	readInt(M);
	int dpb[M+1][M*1000+1];
	dpb[0][0] = 0;
	for(int i = 1; i <= M*1000; i++)
		dpb[0][i] = M+1;
	for(int i = 1; i <= M; i++){
		readInt(k);
		for(int j = 0; j < k; j++)
			dpb[i][j] = dpb[i-1][j];
		for(int j = k; j <= M*1000; j++)
			dpb[i][j] = min(dpb[i-1][j-k]+1, dpb[i-1][j]);
	}
	int minans = 999, minsize = min(N, M);
	for(int i = 1; i <= minsize*1000; i++)
		if(dpa[N][i] != N+1 && dpb[M][i] != M+1 && dpa[N][i] + dpb[M][i] < minans)
			minans = dpa[N][i] + dpb[M][i];
	if(minans == 999)
		printf("impossible\n");
	else
		printf("%d\n", minans);
}