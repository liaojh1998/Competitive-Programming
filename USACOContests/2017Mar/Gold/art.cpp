//Title: Modern Art
//Type: Brute Force
//Complexity: O(colors*(N^2))
//Solution: I don't know how many brute force I've done this context. The minimum amount of rounds required = the maximum number of colors on top of a colored canvas.
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

void solve(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int N;
	readInt(N);
	bool check[N*N+5];
	memset(check, 0, sizeof(check));
	int drawing[N+5][N+5], imin[N*N+5], imax[N*N+5], jmin[N*N+5], jmax[N*N+5];
	memset(imin, -1, sizeof(imin));
	memset(imax, -1, sizeof(imax));
	memset(jmin, -1, sizeof(jmin));
	memset(jmax, -1, sizeof(jmax));
	vector<int> colors, covered[N*N+5];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			readInt(drawing[i][j]);
				if(drawing[i][j]){
				if(imin[drawing[i][j]] == -1 || i < imin[drawing[i][j]])
					imin[drawing[i][j]] = i;
				if(imax[drawing[i][j]] == -1 || i > imax[drawing[i][j]])
					imax[drawing[i][j]] = i;
				if(jmin[drawing[i][j]] == -1 || j < jmin[drawing[i][j]])
					jmin[drawing[i][j]] = j;
				if(jmax[drawing[i][j]] == -1 || j > jmax[drawing[i][j]])
					jmax[drawing[i][j]] = j;
				if(!check[drawing[i][j]]){
					colors.push_back(drawing[i][j]);
					check[drawing[i][j]] = true;
				}
			}
		}
	int size = colors.size(), rounds = 0;
	for(int k = 0; k < size; k++){
		int color = colors[k];
		int row = imax[color], col = jmax[color];
		memset(check, 0, sizeof(check));
		for(int i = imin[color]; i <= row; i++)
			for(int j = jmin[color]; j <= col; j++){
				if(drawing[i][j] && drawing[i][j] != color && !check[drawing[i][j]]){
					covered[color].push_back(drawing[i][j]);
					check[drawing[i][j]] = true;
				}
			}
	}
	bool uncovered[N*N+5], temp[N*N+5];
	memset(uncovered, 0, sizeof(uncovered));
	while(colors.size()){
		memcpy(temp, uncovered, sizeof(uncovered));
		for(int i = 0; i < colors.size(); i++){
			bool has = false;
			int tempsize = covered[colors[i]].size();
			for(int j = 0; j < tempsize && !has; j++)
				if(!uncovered[covered[colors[i]][j]])
					has = true;
			if(!has){
				temp[colors[i]] = true;
				colors.erase(colors.begin()+i);
				i--;
			}
		}
		rounds++;
		memcpy(uncovered, temp, sizeof(temp));
	}
	printf("%d\n", rounds);
}
int main(){
	solve();
	return 0;
}