//Title: Ecological Bin Packing
//Type: Complete Search
//Complexity: O(6N)
//Solution: Try all 6 different combinations they say. Then you realize this is not 1 loop, but 6.
#include <cstdio>
#include <cstring>
int bin[9], min = 1<<31-1, temp;
char ans[3];
int search(int a, int b, int c){
	int t = 0;
	for(int i = 0; i < 9; i++)
			if(i != a && i != b && i != c)
				t += bin[i];
	return t;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &bin[0])){
		for(int i = 1; i < 9; i++)
			scanf("%d", &bin[i]);
		//B G C
		//0 1 2
		//3 4 5
		//6 7 8
		temp = search(0, 5, 7);
		if(min > temp){
			min = temp;
			strcpy(ans, "BCG");
		}
		temp = search(0, 4, 8);
		if(min > temp){
			min = temp;
			strcpy(ans, "BGC");
		}
		temp = search(2, 3, 7);
		if(min > temp){
			min = temp;
			strcpy(ans, "CBG");
		}
		temp = search(2, 4, 6);
		if(min > temp){
			min = temp;
			strcpy(ans, "CGB");
		}
		temp = search(1, 3, 8);
		if(min > temp){
			min = temp;
			strcpy(ans, "GBC");
		}
		temp = search(1, 5, 6);
		if(min > temp){
			min = temp;
			strcpy(ans, "GCB");
		}
		printf("%s %d\n", ans, min);
		min = 1<<31-1;
	}
	return 0;
}