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
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; c != '.' && ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c != '.' && c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
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

#define INF (3e5)
#define EPS (1e-3)
struct mice{
	double x, y, t;
}arr[16];

int n;
double m;

double dp[16][1<<17];
bool checked[16][1<<17];

double dist(int from, int to){
	double x = (arr[to].x-arr[from].x);
	double y = (arr[to].y-arr[from].y);
	return sqrt(x*x+y*y);
}

bool dfs(int index, int bitmask, double time, double speed){
	int end = (1<<(n+1));
	//printf("%d %d %.6lf %.6lf\n", index, bitmask, time, speed);
	if(bitmask == end-1)
		return (time < arr[index].t);
	checked[index][bitmask] = true;
	dp[index][bitmask] = time;
	bool possible = false;
	for(int cur = 1; cur <= n && !possible; cur++)
		if(!(bitmask & (1<<cur)) && time+dist(index, cur)/speed < (arr[cur].t) && (!checked[cur][bitmask|(1<<cur)] || time+dist(index, cur)/speed < dp[cur][bitmask|(1<<cur)]))
			possible |= dfs(cur, bitmask|(1<<cur), time+dist(index, cur)/speed, speed*m);
	return possible;
}

void FastIO::solve(){
	readInt(n);
	for(int i = 1; i <= n; i++){
		readDouble(arr[i].x);
		readDouble(arr[i].y);
		readDouble(arr[i].t);
	}
	readDouble(m);
	//printf("%.6lf\n", m);
	double lo = 0, hi = INF;
	while(hi-lo >= EPS){
		memset(checked, 0, sizeof(checked));
		double mid = (hi+lo)/2;
		//printf("%.6lf\n", mid);
		if(dfs(0, 1, 0, mid))
			hi = mid;
		else
			lo = mid;
	}
	printf("%.6lf\n", lo);
}