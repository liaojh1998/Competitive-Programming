//Title: Jollo
//Type: Simulation
//Complexity: O(5)
//Solution: Trial and error, different combinations
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
	int prince[2], sister[3];
	bool taken[55];
	while(readInt(sister[0]) && sister[0]){
		memset(taken, 0, sizeof(taken));
		readInt(sister[1]);
		readInt(sister[2]);
		readInt(prince[0]);
		readInt(prince[1]);
		taken[prince[0]] = 1;
		taken[prince[1]] = 1;
		taken[sister[0]] = 1;
		taken[sister[1]] = 1;
		taken[sister[2]] = 1;
		sort(sister, sister+3);
		sort(prince, prince+2);
		//Must lose condition
		if(sister[2] > prince[1] && sister[1] > prince[0]){
			printf("-1\n");
			continue;
		}
		//rate cards: 0 - must lose, 1 - can win 1 card, 2 - can win 2 cards, 3 - must win
		int rate[2], ans;
		memset(rate, 0, sizeof(rate));
		if(prince[0] > sister[0]) rate[0] = 1;
		if(prince[1] > sister[0]) rate[1] = 1;
		if(prince[0] > sister[1]) rate[0] = 2;
		if(prince[1] > sister[1]) rate[1] = 2;
		if(prince[0] > sister[2]) rate[0] = 3;
		if(prince[1] > sister[2]) rate[1] = 3;
		if(rate[0] <= 1 && rate[1] >= 2)
			ans = sister[2]+1;
		else if(rate[0] == 2 && rate[1] >= 2)
			ans = sister[1]+1;
		else if(rate[0] == 3 && rate[1] == 3)
			ans = 1;
		while(taken[ans]) ans++;
		printf("%d\n", ans > 52 ? -1 : ans);
	}
	return 0;
}