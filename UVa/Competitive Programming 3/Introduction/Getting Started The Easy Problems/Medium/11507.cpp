//Title: Bender B. Rodriguez Problem
//Type: Brute Force
//Complexity: O(L)
//Solution: "No" doesn't matter, pure simulation material
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

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int L;
	while(readInt(L) && L){
		int intdir = 0; //0 - +x, 1 - -x, 2 - +y, 3 - -y, 4 - +z, 5 - -z
		char dir[5];
		while(--L){
			readStr(dir);
			if(!strcmp(dir, "+y"))
				switch(intdir){
					case 0: intdir = 2; break;
					case 1: intdir = 3; break;
					case 2: intdir = 1; break;
					case 3: intdir = 0; break;
					default: break;
				}
			else if(!strcmp(dir, "-y"))
				switch(intdir){
					case 0: intdir = 3; break;
					case 1: intdir = 2; break;
					case 2: intdir = 0; break;
					case 3: intdir = 1; break;
					default: break;
				}
			else if(!strcmp(dir, "+z"))
				switch(intdir){
					case 0: intdir = 4; break;
					case 1: intdir = 5; break;
					case 4: intdir = 1; break;
					case 5: intdir = 0; break;
					default: break;
				}
			else if(!strcmp(dir, "-z"))
				switch(intdir){
					case 0: intdir = 5; break;
					case 1: intdir = 4; break;
					case 4: intdir = 0; break;
					case 5: intdir = 1; break;
					default: break;
				}
		}
		switch(intdir){
			case 0: printf("+x\n"); break;
			case 1: printf("-x\n"); break;
			case 2: printf("+y\n"); break;
			case 3: printf("-y\n"); break;
			case 4: printf("+z\n"); break;
			case 5: printf("-z\n"); break;
		}
	}
	return 0;
}