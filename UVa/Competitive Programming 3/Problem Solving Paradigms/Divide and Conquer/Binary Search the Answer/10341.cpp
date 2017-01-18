//Title: Solve It
//Type: Divide and Conquer
//Complexity: O(log(f(1)-f(0)))
//Solution: Multiple ways to find root of a function, 1 is bisection, other is Newton's method for future references.
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

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double p, q, r, s, t, u;
	while(~readDouble(p)){
		readDouble(q);
		readDouble(r);
		readDouble(s);
		readDouble(t);
		readDouble(u);
		/* //Bisection method
		double lo = 0.00000, hi = 1.00000;
		while(hi-lo >= 1e-9){
			double mid = (lo + hi)/2;
			//printf("%.4lf %.4lf\n", lo, hi);
			if((p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u) > 0)
				lo = mid + 0.000000001;
			else
				hi = mid;
		}
		if(abs((p*exp(-lo) + q*sin(lo) + r*cos(lo) + s*tan(lo) + t*lo*lo + u)) > 1e-3)
			printf("No solution\n");
		else
			printf("%.4lf\n", lo);
		*/
		//Newton's method
		#define fd(x) (-p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x)
		#define f(x) ((p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u))
		if(f(0) * f(1) > 0){
			printf("No solution\n");
			continue;
		}
		double x = 0.5; //Initial guess start from middle
		while(1){
			double x1 = x - f(x)/fd(x);
			if(fabs(x1-x) < 1e-9)
				break;
			x = x1;
		}
		printf("%.4lf\n", x < 0 ? -x : x);
	}
	return 0;
}