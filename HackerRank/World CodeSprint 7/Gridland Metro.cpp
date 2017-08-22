#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int K, len, k, p, q, row[1000];
long long N, M;
bool added;
struct ra{
	int lo, hi;
	bool operator<(ra a){
		if(lo == a.lo)
			return hi < a.hi;
		return lo < a.lo;
	}
}temp;
vector<ra> range[1000];
void unique(int v){
	sort(range[v].begin(), range[v].end());
	for(int i = 0; i < range[v].size()-1; i++){
		//printf("%d %d %d %d %d\n", row[v], range[v][i].lo, range[v][i].hi, range[v][i+1].lo, range[v][i+1].hi);
		if(range[v][i+1].lo <= range[v][i].hi && range[v][i+1].hi > range[v][i].hi){
			range[v][i].hi = range[v][i+1].hi;
			range[v].erase(range[v].begin()+i+1);
			i--;
		}else if(range[v][i+1].lo <= range[v][i].hi && range[v][i+1].hi <= range[v][i].hi){
			range[v].erase(range[v].begin()+i+1);
			i--;
		}
	}
}
void add(int v, int l, int h){
	for(int i = 0; i < range[v].size(); i++){
		if(range[v][i].lo <= l && range[v][i].hi >= h)
			return;
		else if(range[v][i].lo <= l && range[v][i].hi >= l && range[v][i].hi < h){
			range[v][i].hi = h;
			return unique(v);
		}else if(range[v][i].lo > l && range[v][i].lo <= h && range[v][i].hi >= h){
			range[v][i].lo = l;
			return unique(v);
		}
	}
	temp.lo = l;
	temp.hi = h;
	range[v].push_back(temp);
	unique(v);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld%lld%d", &N, &M, &K);
	for(int i = 0; i < K; i++){
		scanf("%d%d%d", &k, &p, &q);
		added = false;
		for(int j = 0; j < len; j++){
			if(row[j] == k){
				add(j, p, q);
				added = true;
				break;
			}
		}
		if(!added){
			row[len] = k;
			add(len, p, q);
			len++;
		}
	}
	long long sum = N*M;
	for(int i = 0; i < len; i++)
		for(int j = 0; j < range[i].size(); j++){
			//printf("%d %d %d\n", row[i], range[i][j].lo, range[i][j].hi);
			sum -= range[i][j].hi - range[i][j].lo + 1;
		}
	printf("%lld\n", sum);
	return 0;
}