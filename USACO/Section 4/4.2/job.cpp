/*
ID: liaojh11
PROG: job
LANG: C++
*/
//Title: Job Processing
//Type: Greedy
//Complexity: O(N*M1 + N*M2 + N)
//Solution:
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

int main(){
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	int N, M1, M2;
	readInt(N);
	readInt(M1);
	readInt(M2);
	int aneed[M1+5], bneed[M2+5], adelay[M1+5], bdelay[M2+5], atime[N+5], btime[N+5];
	for(int i = 0; i < M1; i++)
		readInt(aneed[i]);
	for(int i = 0; i < M2; i++)
		readInt(bneed[i]);
	memset(adelay, 0, sizeof(adelay));
	memset(atime, 0, sizeof(atime));
	for(int i = 1; i <= N; i++){
		int assign = -1, mintime;
		for(int j = 0; j < M1; j++)
			if(!(~assign) || mintime > adelay[j] + aneed[j]){
				assign = j;
				mintime = adelay[j] + aneed[j];
			}
		atime[i] = mintime;
		adelay[assign] += aneed[assign];
	}
	memset(bdelay, 0, sizeof(bdelay));
	memset(btime, 0, sizeof(btime));
	for(int i = 1; i <= N; i++){
		int assign = -1, mintime;
		for(int j = 0; j < M2; j++)
			if(!(~assign) || mintime > bdelay[j] + bneed[j]){
				assign = j;
				mintime = bdelay[j] + bneed[j];
			}
		btime[i] = mintime;
		bdelay[assign] += bneed[assign];
	}
	int ans = 0;
	for(int i = 1; i <= N; i++)
		if(ans < atime[i] + btime[N-i+1])
			ans = atime[i] + btime[N-i+1];
	printf("%d %d\n", atime[N], ans);
	return 0;
}