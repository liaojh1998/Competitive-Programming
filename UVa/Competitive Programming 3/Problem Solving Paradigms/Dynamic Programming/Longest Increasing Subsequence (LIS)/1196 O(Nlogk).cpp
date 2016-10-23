//Title: Tilting Up Blocks
//Type: DP
//Complexity: O(Nlogk)
//Solution: Classic LIS, O(Nlogk) greedy solution.
#include <cstdio>
#include <algorithm>
using namespace std;
struct b{
	int l, m;
} blocks[10010];
int n, arr[10010], len, maxlen;
bool cmp(b a, b c){
	if(a.l == c.l)
		return a.m > c.m;
	return a.l > c.l;
}
int search(int lo, int hi, int i){
	if(lo == hi)
		return lo;
	int mid = (lo + hi)/2;
	if(blocks[i].l > blocks[arr[mid]].l || blocks[i].m > blocks[arr[mid]].m)
		return search(lo, mid, i);
	else
		return search(mid+1, hi, i);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d", &n) && n){
		for(int i = 0; i < n; i++)
			scanf("%d%d", &blocks[i].l, &blocks[i].m);
		sort(blocks, blocks+n, cmp);
		for(int i = 0; i < n; i++){
			if(!i){
				arr[len++] = i;
				//printf("0\n");
			}else{
				int index = search(0, len, i);
				//printf("%d\n", index);
				if(index == len)
					arr[len++] = i;
				else
					arr[index] = i;
				if(maxlen < len) maxlen = len;
			}
		}
		printf("%d\n", maxlen);
		maxlen = len = 0;
	}
	printf("*\n");
	return 0;
}