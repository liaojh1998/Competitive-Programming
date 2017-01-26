/*
ID: liaojh11
PROG: frameup
LANG: C++
*/
//Title: Frame Up
//Type: DFS
//Complexity: O(26!)
//Solution: Heavily pruned topological sort using bits. Of course, this is impossible even at 26! worst case scenario, but seems like that's not tested.
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

bool cmp(char* a, char* b){
	int size = strlen(a);
	for(int i = 0; i < size; i++)
		if(a[i] != b[i])
			return a[i] < b[i];
}
void dfs(int depth, int maxDepth, int notRemoved, int letters, int* onTop, char* str, vector<char*>* ans){
	if(depth == maxDepth){
		char* temp = new char[depth+5];
		memcpy(temp, str, sizeof(char)*(depth+5));
		ans->push_back(temp);
		return;
	}
	for(int i = 0; i < 26; i++)
		if((letters & (1 << i)) && (notRemoved & (1 << i)) && !((notRemoved - (1 << i)) & onTop[i])){
			str[maxDepth-depth-1] = i+'A';
			dfs(depth+1, maxDepth, notRemoved - (1 << i), letters, onTop, str, ans);
		}
}
void solve(){
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);
	char map[35][35];
	int mini[30], maxi[30], minj[30], maxj[30], onTop[30], depth = 0, letters = 0;
	memset(mini, -1, sizeof(mini));
	memset(maxi, -1, sizeof(maxi));
	memset(minj, -1, sizeof(minj));
	memset(maxj, -1, sizeof(maxj));
	memset(onTop, 0, sizeof(onTop));
	int H, W;
	readInt(H);
	readInt(W);
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			map[i][j] = getchar();
			if(map[i][j] != '.'){
				if(!(letters & (1 << map[i][j]-'A'))){
					depth++;
					letters |= (1 << map[i][j]-'A');
				}
				mini[map[i][j]-'A'] = !(~mini[map[i][j]-'A']) ? i : min(i, mini[map[i][j]-'A']);
				maxi[map[i][j]-'A'] = max(i, maxi[map[i][j]-'A']);
				minj[map[i][j]-'A'] = !(~minj[map[i][j]-'A']) ? j : min(j, minj[map[i][j]-'A']);
				maxj[map[i][j]-'A'] = max(j, maxj[map[i][j]-'A']);
			}
		}
		getchar();
	}
	for(int i = 0; i < 26; i++){
		int used = 0;
		if(letters & (1 << i)){
			for(int j = mini[i]; j <= maxi[i]; j++){
				if(map[j][minj[i]]-'A' != i && !(used & (1 << map[j][minj[i]]-'A')))
					onTop[i] |= (1 << map[j][minj[i]]-'A');
				if(map[j][maxj[i]]-'A' != i && !(used & (1 << map[j][maxj[i]]-'A')))
					onTop[i] |= (1 << map[j][maxj[i]]-'A');
			}
			for(int j = minj[i]; j <= maxj[i]; j++){
				if(map[mini[i]][j]-'A' != i && !(used & (1 << map[mini[i]][j]-'A')))
					onTop[i] |= (1 << map[mini[i]][j]-'A');
				if(map[maxi[i]][j]-'A' != i && !(used & (1 << map[maxi[i]][j]-'A')))
					onTop[i] |= (1 << map[maxi[i]][j]-'A');
			}
		}
	}
	char str[depth+5];
	str[depth] = '\0';
	vector<char*> ans;
	for(int i = 0; i < 26; i++){
		int notRemoved = (1 << 26) - 1;
		str[depth-1] = i+'A';
		if((letters & (1 << i)) && !onTop[i])
			dfs(1, depth, notRemoved - (1 << i), letters, onTop, str, &ans);
	}
	sort(ans.begin(), ans.end(), cmp);
	int size = ans.size();
	for(int i = 0; i < size; i++)
		printf("%s\n", ans[i]);
}
int main(){
	solve();
	return 0;
}