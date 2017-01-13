//Title: LED Test
//Type: Complete Search
//Complexity: O(n)
//Solution: This is no backtracking. Pure simulation.
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

int digit[10], seq[15];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	digit[0] = ((1<<6)-1) << 1;
	digit[1] = ((1<<2)-1) << 4;
	digit[2] = (((1<<2)-1) << 5) + (((1<<2)-1) << 2) + 1;
	digit[3] = (((1<<4)-1) << 3) + 1;
	digit[4] = (((1<<2)-1) << 4) + ((1<<2)-1);
	digit[5] = (1 << 6) + (((1<<2)-1) << 3) + ((1<<2)-1);
	digit[6] = (1 << 6) + ((1<<5)-1);
	digit[7] = ((1<<3)-1) << 4;
	digit[8] = (1<<7)-1;
	digit[9] = (((1<<4)-1) << 3) + ((1<<2)-1);
	//0 - 1111110, 1 - 0110000, 2 - 1101101, 3 - 1111001, 4 - 0110011
	//5 - 1011011, 6 - 1011111, 7 - 1110000, 8 - 1111111, 9 - 1111011
	int n;
	while(readInt(n) && n){
		char str[10];
		memset(seq, 0, sizeof(seq));
		for(int i = 0; i < n; i++){
			readStr(str);
			for(int j = 6; j >= 0; j--)
				if(str[j] == 'Y')
					seq[i] += (1 << (6-j));
		}
		bool failed[10], match = false;
		for(int i = n-1; i < 10 && !match; i++){
			memset(failed, 0, sizeof(failed));
			bool possible = true;
			for(int j = 0; j < 7; j++){
				if((seq[0] & (1 << j)) && !(digit[i] & (1 << j))){
					possible = false;
					break;
				}
				if(!(seq[0] & (1 << j)) && (digit[i] & (1 << j)))
					failed[j] = true;
			}
			/*for(int j = 0; j < 7; j++)
				printf("%d", failed[j]);
			printf("\n");*/
			if(possible){
				//printf("%d\n", i);
				match = true;
				for(int j = 1; j < n && match; j++){
					for(int k = 0; k < 7; k++){
						if((seq[j] & (1 << k)) && (failed[k] || !(digit[i-j] & (1 << k)))){
							match = false;
							break;
						}
						if(!(seq[j] & (1 << k)) && (digit[i-j] & (1 << k)))
							failed[k] = true;
					}
				}
			}
		}
		if(match)
			printf("MATCH\n");
		else
			printf("MISMATCH\n");
	}
	return 0;
}