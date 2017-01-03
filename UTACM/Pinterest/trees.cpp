//Title: Trees
//Type: Brute Force
//Complexity: O(NlogN)
//Solution: Simple Iteration?
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
	int T;
	readInt(T);
	while(T--){
		int N;
		readInt(N);
		vector<int> nodes[N+1];
		for(int i = 0; i < N-1; i++){
			int u, v;
			readInt(u);
			readInt(v);
			nodes[u].push_back(v);
			nodes[v].push_back(u);
		}
		priority_queue<int, vector<int>, greater<int> > leaves;
		bool enqueued[N+1];
		memset(enqueued, 0, sizeof(enqueued));
		for(int i = 1; i <= N; i++){
			if(nodes[i].size() == 1){
				leaves.push(i);
				enqueued[i] = true;
			}
		}
		vector<int> ans;
		while(N > 2){
			int top = leaves.top(); leaves.pop();
			enqueued[top] = false;
			//printf("%d\n", top);
			ans.push_back(nodes[top][0]);
			if(nodes[nodes[top][0]].size() == 2 && !enqueued[nodes[top][0]]){
				leaves.push(nodes[top][0]);
				enqueued[nodes[top][0]] = true;
			}
			int len = nodes[nodes[top][0]].size();
			for(int i = 0; i < len; i++)
				if(nodes[nodes[top][0]][i] == top){
					nodes[nodes[top][0]].erase(nodes[nodes[top][0]].begin()+i);
					break;
				}
			nodes[top].pop_back();
			N--;
		}
		int len = ans.size();
		for(int i = 0; i < len; i++)
			printf("%d%s", ans[i], i == len-1 ? "\n" : " ");
	}
	return 0;
}