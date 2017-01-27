/*
ID: liaojh11
PROG: fc
LANG: C++
*/
//Title: Fencing the Cows
//Type: Computational Geometry
//Complexity: O(Nh) h = points on hull
//Solution: Using the simple Jarvis march before we use the sorted Graham Scan.
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

double cross_prod(int pivot, int from, int to, double* pointsx, double* pointsy){
	return (pointsx[from]-pointsx[pivot])*(pointsy[to]-pointsy[pivot]) - (pointsx[to]-pointsx[pivot])*(pointsy[from]-pointsy[pivot]);
}
double dist(int from, int to, double* pointsx, double* pointsy){
	return sqrt((pointsx[from]-pointsx[to])*(pointsx[from]-pointsx[to])+(pointsy[from]-pointsy[to])*(pointsy[from]-pointsy[to]));
}
int jarvis(int leftmost, double* pointsx, double* pointsy, int size, int* hull){
	int pointOnHull = leftmost, endpoint = -1, hullsize;
	for(hullsize = 0; hullsize < size && endpoint != leftmost; hullsize++){
		hull[hullsize] = pointOnHull;
		endpoint = 0;
		for(int j = 1; j < size; j++){
			double cp = cross_prod(pointOnHull, endpoint, j, pointsx, pointsy);
			if(((endpoint == pointOnHull) || cp > 0 || (cp == 0 && dist(pointOnHull, endpoint, pointsx, pointsy) > dist(pointOnHull, j, pointsx, pointsy))) && (j != pointOnHull))
				endpoint = j;
		}
		pointOnHull = endpoint;
	}
	hull[hullsize++] = pointOnHull;
	return hullsize;
}
void solve(){
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);
	int N, leftmost = 0;
	readInt(N);
	int hull[N+5];
	double pointsx[N+5], pointsy[N+5];
	for(int i = 0; i < N; i++){
		readDouble(pointsx[i]);
		readDouble(pointsy[i]);
		if(pointsx[i] < pointsx[leftmost])
			leftmost = i;
	}
	int hullSize = jarvis(leftmost, pointsx, pointsy, N, hull);
	double ans = 0;
	for(int i = 0; i < hullSize; i++){
		ans += dist(leftmost, hull[i], pointsx, pointsy);
		leftmost = hull[i];
	}
	printf("%.2lf\n", ans);
}
int main(){
	solve();
	return 0;
}