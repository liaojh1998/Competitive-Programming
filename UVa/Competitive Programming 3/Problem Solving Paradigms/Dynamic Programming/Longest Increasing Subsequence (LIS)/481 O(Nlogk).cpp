//Title: What Goes Up
//Type: DP
//Complexity: O(Nlogk)
//Solution: Classic LIS, O(Nlogk) greedy solution for unknown amount. "Last LIS printed", output-sensitive.
#include <cstdio>
int lis[100000], loc[100000], arr[100000], len, index;
int search(int lo, int hi, int i){
	if(lo == hi)
		return lo;
	int mid = (lo + hi)/2;
	if(arr[lis[mid]] >= arr[i])
		return search(lo, mid, i);
	else
		return search(mid+1, hi, i);
}
void print(int i){
	if(!(~i))
		return;
	print(loc[i]);
	printf("%d\n", arr[i]);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for(int i = 0; ~scanf("%d", &arr[i]); i++){
		if(!i){
			lis[len++] = i;
			loc[i] = -1;
		}else{
			index = search(0, len, i);
			if(index == len){
				loc[i] = lis[len-1];
				lis[len++] = i;
			}else{
				loc[i] = index > 0 ? lis[index-1] : -1;
				lis[index] = i;
			}
		}
	}
	printf("%d\n-\n", len);
	print(lis[len-1]);
	return 0;
}