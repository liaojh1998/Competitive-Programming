#include <cstdio>
#include <algorithm>
using namespace std;
//inline if read speed is needed
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
		str[len] = c;
		c = getchar();
		len++;
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
		//Remove this if str can go to next line
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
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
		}
}

//0		1	2	3	4	5	6	7	8	9	10	11
//10	12	15	18	22	27	33	39	47	56	68	82
char str[12][20] = {"brown black ", "brown red ", "brown green ", "brown gray ", "red red ",
					"red violet ", "orange orange ", "orange white ", "yellow violet ",
					"green blue ", "blue gray ", "gray red "};
long long comp[12] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
char expo[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	readInt(T);
	while(T--){
		long long N;
		readLL(N);
		long long s = N;
		int size = 0;
		while(s){
			size++;
			s /= 10;
		}
		if(size < 2){
			printf("%s%s\n", str[0], expo[0]);
			continue;
		}
		if(size > 11){
			printf("%s%s\n", str[11], expo[9]);
			continue;
		}
		long long mult = 1;
		for(int i = 0; i < size-2; i++)
			mult *= 10;
		long long diff = ((long long)1<<60);
		int ans = -1;
		int expoi = size-2;
		for(int i = 0; i < 12; i++){
			long long d = abs(comp[i]*mult - N);
			if(d <= diff){
				diff = d;
				ans = i;
			}
		}
		long long d = abs(comp[11]*mult/10 - N);
		if(d < diff && size > 2){
			diff = d;
			ans = 11;
			expoi = size-3;
		}
		d = abs(comp[0]*mult*10 - N);
		if(d <= diff && size < 11){
			diff = d;
			ans = 0;
			expoi = size-1;
		}
		printf("%s%s\n", str[ans], expo[expoi]);
	}
	return 0;
}