#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
using namespace std;
int T, N, P, a, b, nimsum;
set<int> heap;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	//Just what question is this? LMAO
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d", &P);
			for(int j = 0; j < P; j++){
				scanf("%d%d", &a, &b);
				heap.insert(a);
			}
			nimsum ^= heap.size();
			heap.clear();
		}
		if(nimsum) printf("SCOTT\n");
		else printf("JARED\n");
		nimsum = 0;
	}
	return 0;
}