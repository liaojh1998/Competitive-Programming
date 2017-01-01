//Title: Bridge Hand Evaluator
//Type: Simulation
//Complexity: O(13)
//Solution: So many many operations
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
	int count[4]; //0 - S, 1 - H, 2 - D, 3 - C
	bool has[4][4];//0 - A, 1 - K, 2 - Q, 3 - J
	char cards[15][5];
	while(~readStr(cards[0])){
		memset(count, 0, sizeof(count));
		memset(has, 0, sizeof(has));
		int suit;
		for(int i = 1; i < 13; i++){
			readStr(cards[i]);
		}
		for(int i = 0; i < 13; i++){
			switch(cards[i][1]){
				case 'S': suit = 0; break;
				case 'H': suit = 1; break;
				case 'D': suit = 2; break;
				case 'C': suit = 3; break;
			}
			count[suit]++;
			switch(cards[i][0]){
				case 'A': has[suit][0] = true; break;
				case 'K': has[suit][1] = true; break;
				case 'Q': has[suit][2] = true; break;
				case 'J': has[suit][3] = true; break;
			}
		}
		//Eval no trump
		int ntpt = 0, stopped = 0;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				if(has[i][j]) ntpt += 4-j;
				if(j == 1 && has[i][j] && count[i] == 1) ntpt--;
				else if(j == 2 && has[i][j] && count[i] <= 2) ntpt--;
				else if(j == 3 && has[i][j] && count[i] <= 3) ntpt--;
				if(!j && has[i][j]) stopped |= (1<<i);
				else if(j == 1 && has[i][j] && count[i] > 1) stopped |= (1<<i);
				else if(j == 2 && has[i][j] && count[i] > 2) stopped |= (1<<i);
			}
		if(stopped == (1<<4)-1 && ntpt >= 16){
			printf("BID NO-TRUMP\n");
			continue;
		}
		//Eval pass or bid suit
		int pt = ntpt, most = 0;
		for(int i = 0; i < 4; i++){
			if(count[i] > count[most]) most = i;
			if(count[i] == 2) ntpt++;
			if(count[i] <= 1) ntpt+=2;
		}
		if(ntpt < 14)
			printf("PASS\n");
		else
			switch(most){
				case 0: printf("BID S\n"); break;
				case 1: printf("BID H\n"); break;
				case 2: printf("BID D\n"); break;
				case 3: printf("BID C\n"); break;
			}
	}
	return 0;
}