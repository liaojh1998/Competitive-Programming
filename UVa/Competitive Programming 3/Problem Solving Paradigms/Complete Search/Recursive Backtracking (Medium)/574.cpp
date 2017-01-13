//Title: Sum It Up
//Type: Complete Search
//Complexity: O(12!)
//Solution: Pure backtracking material
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

vector<vector<int> > ans;
void dfs(int target, int sum, vector<int> comb, int index, int size, int *arr){
	if(sum == target){
		int s = ans.size();
		for(int i = 0; i < s; i++){
			int si = ans[i].size();
			for(int j = 0; j < si && arr[comb[j]] == arr[ans[i][j]]; j++)
				if(j == si-1) return;
		}
		ans.push_back(comb);
		return;
	}
	if(sum > target || index == size) return;
	for(int i = index; i < size; i++){
		vector<int> temp = comb;
		temp.push_back(i);
		dfs(target, sum+arr[i], temp, i + 1, size, arr);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, n;
	while(readInt(t) && readInt(n) && (t+n)){
		int arr[n+5];
		vector<int> temp(1);
		readIntArr(arr, n);
		sort(arr, arr+n, greater<int>());
		printf("Sums of %d:\n", t);
		for(int i = 0; i < n; i++){
			temp[0] = i;
			dfs(t, arr[i], temp, i+1, n, arr);
		}
		if(!ans.size())
			printf("NONE\n");
		else{
			int size = ans.size();
			for(int i = 0; i < size; i++){
				int si = ans[i].size();
				for(int j = 0; j < si; j++)
					printf("%d%s", arr[ans[i][j]], j == si-1 ? "\n" : "+");
			}
		}
		ans.clear();
	}
	return 0;
}