/*
ID: liaojh11
PROG: picture
LANG: C++
*/
//Title: Picture
//Type: Data Structures
//Complexity: O(NlogN)
//Solution: Instead of the O(N^2) USACO proposed by using free perimeter array, this uses segment tree idea imported from nocow. This takes sorted segments from low to high of each different axis.
		//	For cases where segments have axis matched up, consider the under segments before the upper segments because it removes the extra segment count.
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

struct node{
	int l, r, s, level;
	bool leaf;
	node *lnode, *rnode;
	node(int left, int right){
		l = left, r = right;
		s = level = 0;
		leaf = true;
	}
};
bool cmp(int *a, int*b){
	return (a[0] < b[0]) || (a[0] == b[0] && a[3] < b[3]);
}
void add(node *cur, int l, int r, int lev){
	if(l <= cur->l && r >= cur->r){
		cur->level -= lev;
		cur->s = cur->r - cur->l;
	}else{
		int half = (cur->r+cur->l)/2;
		if(cur->leaf){
			cur->leaf = false;
			cur->lnode = new node(cur->l, half);
			cur->rnode = new node(half, cur->r);
		}
		if(l < half)
			add(cur->lnode, l, r, lev);
		if(r > half)
			add(cur->rnode, l, r, lev);
	}
	if(!(cur->level))
		if(cur->leaf)
			cur->s = 0;
		else
			cur->s = cur->lnode->s+cur->rnode->s;
}
void solve(){
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	int N, x1, y1, x2, y2;
	readInt(N);
	int *vsegs[2*N+5], *hsegs[2*N+5];
	for(int i = 0; i < N; i++){
		readInt(x1);
		readInt(y1);
		readInt(x2);
		readInt(y2);
		vsegs[i] = new int[4];
		vsegs[i+N] = new int[4];
		hsegs[i] = new int[4];
		hsegs[i+N] = new int[4];
		vsegs[i][0] = x1; vsegs[i][1] = y1; vsegs[i][2] = y2; vsegs[i][3] = -1;
		vsegs[i+N][0] = x2; vsegs[i+N][1] = y1; vsegs[i+N][2] = y2; vsegs[i+N][3] = 1;
		hsegs[i][0] = y1; hsegs[i][1] = x1; hsegs[i][2] = x2; hsegs[i][3] = -1;
		hsegs[i+N][0] = y2; hsegs[i+N][1] = x1; hsegs[i+N][2] = x2; hsegs[i+N][3] = 1;
	}
	sort(vsegs, vsegs+2*N, cmp);
	sort(hsegs, hsegs+2*N, cmp);
	node *start = new node(-10000, 10000);
	int ans = 0, last;
	for(int i = 0; i < 2*N; i++){
		last = start->s;
		add(start, vsegs[i][1], vsegs[i][2], vsegs[i][3]);
		ans += abs(last - start->s);
	}
	for(int i = 0; i < 2*N; i++){
		last = start->s;
		add(start, hsegs[i][1], hsegs[i][2], hsegs[i][3]);
		ans += abs(last - start->s);
	}
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}