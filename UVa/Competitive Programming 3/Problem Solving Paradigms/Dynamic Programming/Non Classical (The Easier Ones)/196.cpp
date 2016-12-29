//Title: Spreadsheet
//Type: DP
//Solution: I don't think I see any DP here.
//State: cells[i][j] = number in the cell
//Transition: cells[i][j] = brute force from other cells recursively
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(c == '-') neg = true, c = getchar();
	for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
	if(c != '.'){
		if(neg) n = -n;
		return 1;
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

int cells[1000][18279];
bool has[1000][18279];
char formula[1000][18279][100];
int solve(int row, int col){
	if(has[row][col]) return cells[row][col];
	for(int i = 0; formula[row][col][i]; i++)
		if(formula[row][col][i] == '+' || formula[row][col][i] == '=')
			formula[row][col][i] = ' ';
	istringstream ss(formula[row][col]);
	string str;
	int sum = 0;
	while(ss >> str){
		int r = 0, c = 0;
		for(int i = 0; str[i]; i++)
			if(isdigit(str[i]))
				r = (r<<1)+(r<<3)+str[i]-48;
			else
				c = c * 26 + (str[i]-'A' + 1);
		sum += solve(r, c);
	}
	has[row][col] = true;
	return (cells[row][col] = sum);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Q;
	readInt(Q);
	while(Q--){
		int M, N; //row, col
		readInt(N);
		readInt(M);
		for(int i = 1; i <= M; i++)
			for(int j = 1; j <= N; j++){
				readStr(formula[i][j]);
				has[i][j] = false;
				if(isdigit(formula[i][j][0])){
					cells[i][j] = atoi(formula[i][j]);
					has[i][j] = true;
				}
			}
		//Time to have some intense recursion (THANK GOD NO CYCLIC DEPENDENCIES)
		for(int i = 1; i <= M; i++)
			for(int j = 1; j <= N; j++){
				printf("%d%s", solve(i, j), j == N ? "\n" : " ");
			}
	}
	return 0;
}