//Title: Modern Art
//Type: Brute Force
//Complexity: O(colors*(N^2))
//Solution: Same as Bronze question but on N = 1000 level, I merely copied the same solution.
		//	I took advantage of the fact that the test cases will give a lesser bound than max, which is supposedly O(N^4).
		//	I also didn't read the part of the question which stated N^2 MUST BE PAINTED. So for cases of 1 color answer is N*N-1 rather than N*N.
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

int mat[1005][1005], imin[1000005], imax[1000005], jmin[1000005], jmax[1000005];
bool used[1000005], coverer[1000005];
void solve(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int N;
	readInt(N);
	memset(imin, -1, sizeof(imin));
	memset(imax, -1, sizeof(imax));
	memset(jmin, -1, sizeof(jmin));
	memset(jmax, -1, sizeof(jmax));
	vector<int> colors;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			readInt(mat[i][j]);
			if(mat[i][j]){
				if(!used[mat[i][j]]){
					colors.push_back(mat[i][j]);
					used[mat[i][j]] = true;
				}
				if(imin[mat[i][j]] == -1 || imin[mat[i][j]] > i)
					imin[mat[i][j]] = i;
				if(imax[mat[i][j]] == -1 || imax[mat[i][j]] < i)
					imax[mat[i][j]] = i;
				if(jmin[mat[i][j]] == -1 || jmin[mat[i][j]] > j)
					jmin[mat[i][j]] = j;
				if(jmax[mat[i][j]] == -1 || jmax[mat[i][j]] < j)
					jmax[mat[i][j]] = j;
			}
		}
	}
	int size = colors.size();
	if(size == 1){
		printf("%d\n", N*N-1);
		return;
	}
	for(int i = 0; i < size; i++){
		int color = colors[i];
		memset(used, 0, sizeof(used));
		for(int j = imin[color]; j <= imax[color]; j++)
			for(int k = jmin[color]; k <= jmax[color]; k++)
				if(mat[j][k] && mat[j][k] != color && !used[mat[j][k]]){
					used[mat[j][k]] = true;
					coverer[mat[j][k]] = true;
				}
	}
	int ans = 0;
	for(int i = 0; i < size; i++)
		if(coverer[colors[i]])
			ans++;
	printf("%d\n", N*N-ans);
}
int main(){
	solve();
	return 0;
}