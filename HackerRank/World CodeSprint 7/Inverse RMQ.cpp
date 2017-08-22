#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
//#define bound (1000000000)
using namespace std;
struct n{
	int index, nm;
}num[1<<18+1];
int N, h, nc[1<<18+1], len, d, c[19];
bool added;
bool cmp(n a, n b){
	if(nc[a.index] == nc[b.index])
		return a.nm < b.nm;
	return nc[a.index] > nc[b.index];
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	h = log2(N)+1;
	for(int i = 0; i < 2*N-1; i++){
		scanf("%d", &d);
		added = false;
		for(int j = 0; j < len; j++){ // <- this needs optimization, stopping here for today
			if(num[j].nm == d){
				added = true;
				c[nc[j]]--;
				nc[j]++;
				c[nc[j]]++;
			}
		}
		if(!added){
			num[len].nm = d;
			num[len].index = len;
			nc[len]++;
			c[nc[len++]]++;
		}
	}
	sort(num, num+len, cmp);
	for(int i = 0; i < len; i++)
		printf("%d %d\n", num[i].nm, nc[num[i].index]);
	printf("\n");
	if(c[h] != 1){
		printf("NO\n");
		return 0;
	}
}