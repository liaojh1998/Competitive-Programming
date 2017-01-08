//Title: Progress Pie
//Type: Computational Geometry
//Complexity: O(T)
//Solution: 2 comparisons, 1 distance, 1 angle:
// dist(X, Y) <= 50
// (X <= 50) ? 2*pi - acos(((X-50)*0 + (Y-50)*50)/(sqrt((X-50)*(X-50) + (Y-50)*(Y-50))*50)) : acos(((X-50)*0 + (Y-50)*50)/(sqrt((X-50)*(X-50) + (Y-50)*(Y-50))*50)) <= P*2*pi/100
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

#define pi 3.14159265358979323846
#define dist(x, y) sqrt((x-50)*(x-50) + (y-50)*(y-50))
#define dotprod(x, y) ((y-50)*50)
int main(){
	freopen("25input.txt", "r", stdin);
	freopen("25output.txt", "w", stdout);
	int T;
	readInt(T);
	for(int i = 1; i <= T; i++){
		double P, X, Y;
		readDouble(P);
		readDouble(X);
		readDouble(Y);
		double angle = P*2*pi/100;
		//printf("%.6lf <= 50, %.6lf, %.6lf <= %.6lf\n", dist(X, Y), acos(dotprod(X, Y)/(dist(X,Y)*50)), (X <= 50) ? 2*pi - acos(dotprod(X, Y)/(dist(X,Y)*50)) : acos(dotprod(X, Y)/(dist(X,Y)*50)) , angle);
		printf("Case #%d: ", i);
		if(dist(X, Y) <= 50 && ((X <= 50) ? 2*pi - acos(dotprod(X, Y)/(dist(X,Y)*50)) : acos(dotprod(X, Y)/(dist(X,Y)*50))) <= angle)
			printf("black\n");
		else
			printf("white\n");
	}
	return 0;
}