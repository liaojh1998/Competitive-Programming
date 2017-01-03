//Title: Chessboard in FEN
//Type: Brute Force
//Complexity: O(board) ?
//Solution: Learning to read in FEN
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
	char str[200];
	int kdirr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int kdirc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int ndirr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int ndirc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	while(~readStr(str)){
		bool has[10][10];
		char board[10][10];
		memset(has, 0, sizeof(board));
		memset(board, 0, sizeof(board));
		int len = strlen(str), row = 1, col = 0;
		for(int i = 0; i < len; i++)
			if(str[i] >= '1' && str[i] <= '8')
				col += str[i] - '0';
			else if(str[i] == '/'){
				row++;
				col = 0;
			}else{
				col++;
				board[row][col] = str[i];
			}
		for(int i = 1; i <= 8; i++)
			for(int j = 1; j <= 8; j++)
				if(board[i][j]){
					has[i][j] = true;
					switch(board[i][j]){
						case 'K':
						case 'k':
							for(int k = 0; k < 8; k++)
								if(!board[i+kdirr[k]][j+kdirc[k]])
									has[i+kdirr[k]][j+kdirc[k]] = true;
							break;
						case 'R':
						case 'r':
							for(int k = 1; i+k <= 8 && !board[i+k][j]; k++)
								has[i+k][j] = true;
							for(int k = 1; j+k <= 8 && !board[i][j+k]; k++)
								has[i][j+k] = true;
							for(int k = 1; i-k >= 1 && !board[i-k][j]; k++)
								has[i-k][j] = true;
							for(int k = 1; j-k >= 1 && !board[i][j-k]; k++)
								has[i][j-k] = true;
							break;
						case 'B':
						case 'b':
							for(int k = 1; i+k <= 8 && j+k <= 8 && !board[i+k][j+k]; k++)
								has[i+k][j+k] = true;
							for(int k = 1; i+k <= 8 && j-k >= 1 && !board[i+k][j-k]; k++)
								has[i+k][j-k] = true;
							for(int k = 1; i-k >= 1 && j+k <= 8 && !board[i-k][j+k]; k++)
								has[i-k][j+k] = true;
							for(int k = 1; i-k >= 1 && j-k >= 1 && !board[i-k][j-k]; k++)
								has[i-k][j-k] = true;
							break;
						case 'Q':
						case 'q':
							for(int k = 1; i+k <= 8 && !board[i+k][j]; k++)
								has[i+k][j] = true;
							for(int k = 1; j+k <= 8 && !board[i][j+k]; k++)
								has[i][j+k] = true;
							for(int k = 1; i-k >= 1 && !board[i-k][j]; k++)
								has[i-k][j] = true;
							for(int k = 1; j-k >= 1 && !board[i][j-k]; k++)
								has[i][j-k] = true;
							for(int k = 1; i+k <= 8 && j+k <= 8 && !board[i+k][j+k]; k++)
								has[i+k][j+k] = true;
							for(int k = 1; i+k <= 8 && j-k >= 1 && !board[i+k][j-k]; k++)
								has[i+k][j-k] = true;
							for(int k = 1; i-k >= 1 && j+k <= 8 && !board[i-k][j+k]; k++)
								has[i-k][j+k] = true;
							for(int k = 1; i-k >= 1 && j-k >= 1 && !board[i-k][j-k]; k++)
								has[i-k][j-k] = true;
							break;
						case 'P':
							has[i-1][j+1] = has[i-1][j-1] = true;
							break;
						case 'p':
							has[i+1][j+1] = has[i+1][j-1] = true;
							break;
						case 'n':
						case 'N':
							for(int k = 0; k < 8; k++)
								if(i+ndirr[k] >= 1 && i+ndirr[k] <= 8 && j+ndirc[k] >= 1 && j+ndirc[k] <= 8)
									has[i+ndirr[k]][j+ndirc[k]] = true;
							break;
					}
				}
		int free = 0;
		for(int i = 1; i <= 8; i++)
			for(int j = 1; j <= 8; j++)
				if(!has[i][j]) free++;
		printf("%d\n", free);
	}
	return 0;
}