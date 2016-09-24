#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
struct node{char first[30], last[30];}name[50000];
vector<int> lis;
int T, N, len;
bool cmp(node a, node b){
	if(!strcmp(a.last, b.last)){
		len = strlen(a.first) > strlen(b.first) ? strlen(b.first) : strlen(a.first);
		for(int i = 0; i < len; i++)
			if(a.first[i] != b.first[i])
				return a.first[i] < b.first[i];
		if(strlen(a.first) != strlen(b.first))
			return strlen(a.first) < strlen(b.first);
	}
	len = strlen(a.last) > strlen(b.last) ? strlen(b.last) : strlen(a.last);
	for(int i = 0; i < len; i++)
		if(a.last[i] != b.last[i])
			return a.last[i] < b.last[i];
	if(strlen(a.last) != strlen(b.last))
		return strlen(a.last) < strlen(b.last);
	return true;
}
int search(int lo, int hi, int i){
	if(lo == hi)
		return lo;
	int mid = (lo + hi)/2;
	if(cmp(name[lis[mid]], name[i]))
		return search(mid+1, hi, i);
	else
		return search(lo, mid, i);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%s%s", &name[i].first, &name[i].last);
			if(i){
				int index = search(0, lis.size(), i);
				if(index == lis.size())
					lis.push_back(i);
				else
					lis[index] = i;
			}else
				lis.push_back(i);
		}
		printf("%d\n", N-lis.size());
		lis.clear();
	}
	return 0;
}