//Title: Quirksome Squares
//Type: Complete Search
//Complexity: O(1)
//Solution: Refer to O(NlogN) solution :D.
#include <cstdio>
int N;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &N)){
		switch(N){
			case 2: printf("00\n01\n81\n"); break;
			case 4: printf("0000\n0001\n2025\n3025\n9801\n"); break;
			case 6: printf("000000\n000001\n088209\n494209\n998001\n"); break;
			case 8: printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
		}
	}
	return 0;
}