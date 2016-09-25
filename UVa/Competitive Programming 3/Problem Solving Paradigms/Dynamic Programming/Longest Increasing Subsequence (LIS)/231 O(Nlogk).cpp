//Title: Testing the CATCHER
//Type: DP
//Complexity: O(Nlogk)
//Solution: Classic LDS, O(Nlogk) greedy solution for missiles.
#include <cstdio>
#include <cstring>
int lds[1000], len, mis, test;
int search(int lo, int hi, int i){
	if(lo == hi)
		return lo;
	int mid = (lo + hi)/2;
	if(lds[mid] < i)
		return search(lo, mid, i);
	else
		return search(mid+1, hi, i);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &mis) && ~mis){
		if(test)
			printf("\n");
		test++;
		printf("Test #%d:\n", test);
		lds[len++] = mis;
		while(~scanf("%d", &mis) && ~mis){
			int index = search(0, len, mis);
			if(index == len)
				lds[len++] = mis;
			else
				lds[index] = mis;
		}
		printf("  maximum possible interceptions: %d\n", len);
		len = 0;
	}
	return 0;
}