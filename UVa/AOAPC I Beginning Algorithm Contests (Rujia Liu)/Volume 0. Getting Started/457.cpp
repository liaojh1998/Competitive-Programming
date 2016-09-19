//Title: Linear Cellular Automata
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
int DNA[10], den[40], nden[40], K, c;
void printden(){
	for(int i = 0; i < 40; i++)
		if(!den[i]) printf(" ");
		else if(den[i] == 1) printf(".");
		else if(den[i] == 2) printf("x");
		else if(den[i] == 3) printf("W");
	printf("\n");
}
int main(){
	scanf("%d", &c);
	for(int i = c; i > 0; i--){
		for(int j = 0; j < 10; j++)
			scanf("%d", &DNA[j]);
		den[19] = 1;
		printden();
		for(int k = 1; k < 50; k++){
			for(int j = 0; j < 40; j++){
				if(j == 0)
					K = den[j] + den[j+1];
				else if(j == 39)
					K = den[j-1] + den[j];
				else
					K = den[j-1] + den[j] + den[j+1];
				nden[j] = DNA[K];
			}
			memcpy(den, nden, sizeof(nden));
			printden();
		}
		memset(den, 0, sizeof(den));
		if(i != 1)
			printf("\n");
	}
	return 0;
}