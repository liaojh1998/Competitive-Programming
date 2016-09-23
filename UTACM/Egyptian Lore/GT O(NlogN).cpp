//Type: Data Structures
//Solution: Segment tree
#include <cstdio>
#include <cstring>
#include <cmath>
int T, N, M, h;
long long sgt[1<<19], n, initial, p, q;
char cmd[10];
long long update(int lv, int i, int value){
	if(lv == h){
		sgt[(1<<(lv-1))-1+i] = value;
		return value;
	}
	int parent = (1<<(lv-1))-1+i/(1<<(h-lv)), child = (1<<lv)-1+i/(1<<(h-lv-1));
	sgt[parent] = sgt[parent] - sgt[child] + update(lv+1, i, value);
	return sgt[parent];
}
long long range(int lv, int low, int high, int multi){
	if(high < low)
		return 0;
	if((1<<(h-lv))-1+low == high)
		return sgt[(1<<(lv-1))-1+multi];
	int lo = (1<<(h-lv-1))+multi*(1<<(h-lv)), hi = ((1<<(h-lv-1))-1)+multi*(1<<(h-lv));
	return range(lv + 1, low, high < hi ? high : hi, multi<<1) + range(lv + 1, low > lo ? low : lo, high, (multi<<1)+1);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		h = (int)ceil(log2(N))+1;
		for(int i = 0; i < N; i++){
			scanf("%lld", &n);
			update(1, i, n);
		}
		initial = sgt[0];
		for(int i = 0; i < M; i++){
			scanf("%s", &cmd);
			if(!strcmp(cmd, "ADD")){
				scanf("%lld%lld", &p, &q);
				update(1, p, sgt[(1<<(h-1))-1+p]+q);
			}else if(!strcmp(cmd, "MULTIPLY")){
				scanf("%lld%lld", &p, &q);
				update(1, p, sgt[(1<<(h-1))-1+p]*q);
			}else if(!strcmp(cmd, "GET")){
				scanf("%lld%lld", &p, &q);
				printf("%lld\n", range(1, p, q, 0));
			}else if(!strcmp(cmd, "BUHNUBIS")){
				printf("%lld\n", initial-sgt[0]);
			}
		}
		memset(sgt, 0, sizeof(sgt));
	}
}