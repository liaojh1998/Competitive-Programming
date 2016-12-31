//Title: Game Show Math
//Type: DFS
//Complexity: O(<4^p)
//Solution: 20 sec, backtrack with pruning is actually more sufficient than dynamic programming which has MLE
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

#define INF 32000
int p, ans, num[105];
bool vis[105][64005];
vector<char> op;
bool dfs(int cur, int index){
	if(index == p-1) return cur == ans;
	if(vis[index][cur+INF]) return false;
	vis[index][cur+INF] = true;
	if(cur + num[index+1] <= INF){
		op.push_back('+');
		if(dfs(cur+num[index+1], index+1))
			return true;
		op.pop_back();
	}
	if(cur - num[index+1] >= -INF){
		op.push_back('-');
		if(dfs(cur-num[index+1], index+1))
			return true;
		op.pop_back();
	}
	if((cur * num[index+1] <= INF) && (cur*num[index+1] >= -INF)){
		op.push_back('*');
		if(dfs(cur*num[index+1], index+1))
			return true;
		op.pop_back();
	}
	if(!(cur%num[index+1])){
		op.push_back('/');
		if(dfs(cur/num[index+1], index+1))
			return true;
		op.pop_back();
	}
	return false;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	readInt(n);
	while(n--){
		readInt(p);
		for(int i = 0; i < p; i++)
			readInt(num[i]);
		readInt(ans);
		memset(vis, 0, sizeof(vis));
		if(!dfs(num[0], 0)){
			printf("NO EXPRESSION\n");
			continue;
		}
		printf("%d", num[0]);
		for(int i = 0; i < p-1; i++)
			printf("%c%d", op[i], num[i+1]);
		printf("=%d\n", ans);
		op.clear();
	}
	return 0;
}