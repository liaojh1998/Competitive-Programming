//Title: Zones
//Type: Complete Search
//Complexity: O(2^n)
//Solution: Use bitmask to represent zones to do a complete search
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
	int n, m, c = 0;
	while(readInt(n) && readInt(m) && (n+m)){
		int towers[n+5];
		for(int i = 0; i < n; i++)
			readInt(towers[i]);
		int t, tmp, tmplen;
		readInt(t);
		pair<int, int> common[t+5];
		for(int i = 0; i < t; i++){
			readInt(tmplen);
			int temp = 0, size;
			for(int j = 0; j < tmplen; j++){
				readInt(tmp);
				temp |= (1 << (tmp-1));
			}
			readInt(size);
			common[i] = pair<int, int>(temp, size);
		}
		int ans = 0, size = -1;
		for(int loc = (1<<m)-1; loc <= (1<<n)-1; loc++){
			int count = 0, tmpsize = 0;
			for(int i = 0; i < n; i++)
				if(loc & (1 << i))
					count++;
			if(count != m) continue;
			for(int i = 0; i < n; i++)
				if(loc & (1 << i))
					tmpsize += towers[i];
			for(int i = 0; i < t; i++){
				int has = (loc & common[i].first);
				count = 0;
				for(int j = 0; j < n; j++)
					if(has & (1 << j))
						count++;
				if(count <= 1) continue;
				tmpsize -= (count-1)*common[i].second;
			}
			if(tmpsize > size){
				ans = loc;
				size = tmpsize;
			}
		}
		printf("Case Number  %d\n", ++c);
		printf("Number of Customers: %d\n", size);
		printf("Locations recommended:");
		for(int i = 0; i < n; i++)
			if(ans & (1 << i))
				printf(" %d", i+1);
		printf("\n\n");
	}
	return 0;
}