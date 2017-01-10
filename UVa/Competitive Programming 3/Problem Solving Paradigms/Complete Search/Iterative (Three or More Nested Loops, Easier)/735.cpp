//Title: Dart-a-Mania
//Type: Complete Search
//Complexity: O(43^3)
//Solution: Generate all combinations, for permutation add 1 if all 3 same darts, add 3 if 2 same darts, add 6 if no same darts
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	if(!(~c)) return -1;
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
	if(neg) n = -n;
	return 1;
}
int readLL(long long &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	if(!(~c)) return -1;
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
	if(neg) n = -n;
	return 1;
}
int readDouble(double &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	if(!(~c)) return -1;
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	if(c != '.'){
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
	}
	double div = 1;
	for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
	n /= div;
	if(neg) n = -n;
	return 1;
}
int readStr(char *str){
	register char c = getchar();
	register int len = 0;
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len++] = c;
		c = getchar();
	}
	str[len] = '\0';
	//Just in case if needs to return arriving at end of line
	//if(c == 10) return 10;
	return 1;
}
int readStr(char *str, int len){
	//Reading string of size len
	for(int i = 0; i < len; i++){
		str[i] = getchar();
		if(!(~str[i])){
			str[i] = '\0';
			return -1;
		}
		//Remove this if str can't go to next line
		/*if(str[i] == 10){
			str[i] = '\0';
			return 10;
		}*/
	}
	str[len] = '\0';
	return 1;
}
void readIntArr(int *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readInt(n[i]))){
			n[i] = 0;
			return;
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
			return;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
			return;
		}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int C[185], P[185], dart[50], size;
	memset(C, 0, sizeof(C));
	memset(P, 0, sizeof(P));
	memset(dart, 0, sizeof(dart));
	for(size = 0; size <= 20; size++)
		dart[size] = size;
	for(int i = 11; i <= 20; i++, size++)
		dart[size] = i*2;
	for(int i = 7; i <= 20; i++)
		if((i*3) > 40 || (i*3)%2)
			dart[size++] = i*3;
	dart[size++] = 50;
	sort(dart, dart+size);
	for(int i = 0; i < size; i++)
		for(int j = i; j < size; j++)
			for(int k = j; k < size; k++){
				C[dart[i] + dart[j] + dart[k]]++;
				if(i == j && j == k)
					P[dart[i] + dart[j] + dart[k]]++;
				else if(i == j || j == k)
					P[dart[i] + dart[j] + dart[k]] += 3;
				else
					P[dart[i] + dart[j] + dart[k]] += 6;
			}
	int N;
	while(readInt(N) && N > 0){
		if(N <= 180 && C[N]){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, C[N]);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, P[N]);
		}else
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}