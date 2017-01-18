//Title: Helping Fill Bates
//Type: Divide and Conquer
//Complexity: O(Q*log(alphabet))
//Solution: Keep index of alphabets of the string in order, binary search for answer
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

int loc[256][1000005], size[256];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char c = getchar(), str[105];
	for(int i = 0; c != 10; i++){
		loc[c][size[c]++] = i;
		c = getchar();
	}
	int Q;
	readInt(Q);
	while(Q--){
		readStr(str);
		int strsize = strlen(str), cur = -1, start, end;
		bool found = false;
		for(int i = 0; i < strsize; i++){
			if(!size[str[i]])
				break;
			int prev = cur, lo = 0, hi = size[str[i]]-1;
			while(lo != hi){
				int mid = (lo + hi)/2;
				if(loc[str[i]][mid] <= cur)
					lo = mid+1;
				else
					hi = mid;
			}
			cur = loc[str[i]][lo];
			if(cur <= prev)
				break;
			if(!i)
				start = cur;
			if(i == strsize-1){
				end = cur;
				found = true;
			}
		}
		if(!found)
			printf("Not matched\n");
		else
			printf("Matched %d %d\n", start, end);
	}
	return 0;
}