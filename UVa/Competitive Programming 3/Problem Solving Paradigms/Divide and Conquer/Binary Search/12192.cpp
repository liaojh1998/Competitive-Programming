//Title: Grapevine
//Type: Divide and Conquer
//Complexity: O(Q*(NlogN + N^2))
//Solution: Too bored to improve this solution, find all lower upper bounds and brute force search for max
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
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

int binSearchUp(int *arr, int num, int size){
	int lo = 0, hi = size-1;
	while(lo < hi){
		int mid = (lo + hi)/2;
		if(arr[mid] <= num)
			lo = mid+1;
		else
			hi = mid;
	}
	return lo;
}
int binSearchLo(int *arr, int num, int size){
	int lo = 0, hi = size-1;
	while(lo < hi){
		int mid = (lo + hi)/2;
		if(arr[mid] < num)
			lo = mid+1;
		else
			hi = mid;
	}
	return lo;
}
int min(int a, int b){
	return a < b ? a : b;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N, M;
	while(readInt(N) && readInt(M) && N+M){
		int mat[N+5][M+5];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				readInt(mat[i][j]);
		int Q;
		readInt(Q);
		while(Q--){
			int L, U;
			readInt(L);
			readInt(U);
			int ans = 0, xL[N+5], xU[N+5];
			for(int i = 0; i < N; i++){
				xL[i] = binSearchLo(mat[i], L, M);
				xU[i] = binSearchUp(mat[i], U, M);
				if(L > mat[i][xL[i]]) xL[i]++;
				if(U >= mat[i][xU[i]]) xU[i]++;
			}
			for(int i = 0; i < N; i++){
				for(int j = i; j < N && xU[j]-xL[i] >= j-i; j++){
					//printf("%d %d %d %d\n", i, j, xL[i], xU[j]);
					if(j-i+1 <= xU[j]-xL[i] && ans < j-i+1)
						ans = j-i+1;
					if(j-i > ans)
						ans = j-i;
				}
			}
			printf("%d\n", ans);
		}
		printf("-\n");
	}
	return 0;
}