/*
ID: liaojh11
PROG: window
LANG: C++
*/
//Title: Window Area
//Type: Computational Geometry
//Complexity: O(4^(<61))
//Solution: Was going to use inclusion-exclusion principle but realized nCr for each intersection would be huge.
		//	Searched up "rectangle cutting" algorithm and "flotation method" from chinese site nocow, this is an interesting procedure using dfs.
		//	The cutting method is basically the same using min and max but dfs into 4 smaller cut up rectangles until no more cuts need to be made before return area.
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

struct win{
	int x1, x2, y1, y2, area;
	void calc(){
		int temp = min(x1, x2);
		x2 = max(x1, x2);
		x1 = temp;
		temp = min(y1, y2);
		y2 = max(y1, y2);
		y1 = temp;
		area = (x2-x1)*(y2-y1);
	}
}windows[65];
int getNum(char a){
	if(a >= 'A' && a <= 'Z')
		return a - 'A';
	else if(a >= 'a' && a <= 'z')
		return a - 'a' + 26;
	else if(a >= '0' && a <= '9')
		return a - '0' + 52;
}
int dfs(int x1, int x2, int y1, int y2, int cur, int* level, int maxLevel){
	int area = 0;
	while((cur < maxLevel) && (x1 >= windows[level[cur]].x2 || x2 <= windows[level[cur]].x1 || y1 >= windows[level[cur]].y2 || y2 <= windows[level[cur]].y1))
		cur++;
	if(cur == maxLevel)
		return (x2-x1)*(y2-y1);
	if(x1 < windows[level[cur]].x1){
		area += dfs(x1, windows[level[cur]].x1, y1, y2, cur+1, level, maxLevel); //Left rectangle
		x1 = windows[level[cur]].x1; //Avoid repeating area that calculates from x1 again
	}
	if(x2 > windows[level[cur]].x2){
		area += dfs(windows[level[cur]].x2, x2, y1, y2, cur+1, level, maxLevel); //Right rectangle
		x2 = windows[level[cur]].x2;
	}
	if(y1 < windows[level[cur]].y1){
		area += dfs(x1, x2, y1, windows[level[cur]].y1, cur+1, level, maxLevel); //Top rectangle
		y1 = windows[level[cur]].y1;
	}
	if(y2 > windows[level[cur]].y2){
		area += dfs(x1, x2, windows[level[cur]].y2, y2, cur+1, level, maxLevel); //Bottom rectangle
		y2 = windows[level[cur]].y2;
	}
	return area;
}
void solve(){
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);
	char c = getchar();
	int maxLevel = 0, level[65], loc[65], temp;
	memset(level, -1, sizeof(level));
	memset(loc, -1, sizeof(loc));
	while(~c){
		getchar();
		temp = getNum(getchar());
		switch(c){
			case 'w':
				readInt(windows[temp].x1);
				readInt(windows[temp].y1);
				readInt(windows[temp].x2);
				readInt(windows[temp].y2);
				windows[temp].calc();
				loc[temp] = maxLevel;
				level[maxLevel++] = temp;
				getchar();
				break;
			case 't':
				for(int i = loc[temp]; i < maxLevel-1 && ~i; i++){
					level[i] = level[i+1];
					loc[level[i]] = i;
				}
				level[maxLevel-1] = temp;
				loc[temp] = maxLevel-1;
				getchar(); getchar();
				break;
			case 'b':
				for(int i = loc[temp]; i >= 1 && ~i; i--){
					level[i] = level[i-1];
					loc[level[i]] = i;
				}
				level[0] = temp;
				loc[temp] = 0;
				getchar(); getchar();
				break;
			case 'd':
				for(int i = loc[temp]; i < maxLevel-1 && ~i; i++){
					level[i] = level[i+1];
					loc[level[i]] = i;
				}
				level[maxLevel-1] = -1;
				loc[temp] = -1;
				maxLevel--;
				getchar(); getchar();
				break;
			case 's':
				printf("%.3lf\n", static_cast<double>(dfs(windows[temp].x1, windows[temp].x2, windows[temp].y1, windows[temp].y2, loc[temp]+1, level, maxLevel))*100/windows[temp].area);
				getchar(); getchar();
		}
		//printf("%d %d %d %d %d\n", windows[temp].x1, windows[temp].x2, windows[temp].y1, windows[temp].y2, windows[temp].area);
		c = getchar();
	}
}
int main(){
	solve();
	return 0;
}