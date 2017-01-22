//Title: Largest product in a matrix
//Solution: I thought this would be more special
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
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	int mat[25][25];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			readInt(mat[i][j]);
	int ans = 0;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++){
			//Up
			int temp = 1;
			for(int k = 0; i >= 3 && k < 4; k++)
				temp *= mat[i-k][j];
			if(temp > ans)
				ans = temp;
			//Up-right
			temp = 1;
			for(int k = 0; i >= 3 && j < 17 && k < 4; k++)
				temp *= mat[i-k][j+k];
			if(temp > ans)
				ans = temp;
			//Right
			temp = 1;
			for(int k = 0; j < 17 && k < 4; k++)
				temp *= mat[i][j+k];
			if(temp > ans)
				ans = temp;
			//Down-right
			temp = 1;
			for(int k = 0; i < 17 && j < 17 && k < 4; k++)
				temp *= mat[i+k][j+k];
			if(temp > ans)
				ans = temp;
			//Down
			temp = 1;
			for(int k = 0; i < 17 && k < 4; k++)
				temp *= mat[i+k][j];
			if(temp > ans)
				ans = temp;
			//Down-left
			temp = 1;
			for(int k = 0; i < 17 && j >= 3 && k < 4; k++)
				temp *= mat[i+k][j-k];
			if(temp > ans)
				ans = temp;
			//Left
			temp = 1;
			for(int k = 0; j >= 3 && k < 4; k++)
				temp *= mat[i][j-k];
			if(temp > ans)
				ans = temp;
			//Up-left
			temp = 1;
			for(int k = 0; i >= 3 && j >= 3 && k < 4; k++)
				temp *= mat[i-k][j-k];
			if(temp > ans)
				ans = temp;
		}
	printf("%d\n", ans);
	return 0;
}