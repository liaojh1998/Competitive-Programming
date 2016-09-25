//Title: Strategic Defense Initiative
//Type: DP
//Complexity: O(Nlogk)
//Solution: Classic LIS, same as 481, O(Nlogk) greedy solution for unknown amount. Output-sensitive, prints the last LIS instead of the first like O(N^2) DP.
#include <cstdio>
int T, lis[100000], loc[100000], arr[100000], len, index;
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
int readInt(int i){
	char c;
	if(scanf("%c", &c) && c == 10)
		return -1;
	int n = c-'0';
	while(scanf("%c", &c) && c != 10){
		n = n*10 + c-'0';
	}
	arr[i] = n;
	return 1;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	getchar();
	getchar();
	while(T--){
		for(int i = 0; ~readInt(i); i++){
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
		printf("Max hits: %d\n", len);
		print(lis[len-1]);
		len = 0;
		if(T)
			printf("\n");
	}
	return 0;
}