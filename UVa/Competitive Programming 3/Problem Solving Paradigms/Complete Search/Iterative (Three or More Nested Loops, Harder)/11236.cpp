//Title: Grocery store
//Type: Complete Search
//Complexity: O(2000^3)
//Solution: Who would do this crazy problem? But definitely gotta love optimization
		//	Let in decimals, a+b+c+d = a*b*c*d --> a+b+c = d(a*b*c - 1) --> (a+b+c)/(a*b*c-1) = d
		//	Since our decimals start at hundredths, and we converted a+b+c to normal integers, then:
		//	(a+b+c)*100^3/(a*b*c-1*100^3) = d that's within .00 to 20.00
		//	Of course non-decreasing order forces d > c
		//	Also a+b+c+d < 2000
		//	And in double, although not stated in problem, a+b+c+d - a*b*c*d < 1e-12 to pass this problem
		//	So do them all and optimize a super quick solution
		//	Of course, we can also make a O(1) print solution
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
	for(long long a = 0; a <= 2000/4; a++)
		for(long long b = a; b <= (2000-a)/3; b++)
			for(long long c = b; c <= (2000-b-a)/2; c++){
				if(a*b*c <= 1000000) continue;
				long long d = (a+b+c)*1000000/(a*b*c - 1000000);
				if(d < c || a+b+c+d > 2000) continue;
				if(fabs((a+b+c+d)/100.0 - ((double)a*b*c*d)/100000000.0) < 1e-12)
					printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
			}
	return 0;
}