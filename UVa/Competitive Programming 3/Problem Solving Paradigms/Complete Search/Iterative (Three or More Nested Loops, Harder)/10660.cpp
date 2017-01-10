//Title: Citizen attention offices
//Type: Complete Search
//Complexity: O((25*5)*25^5)
//Solution: Why would anyone do this, oh my god?
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

int ab(int s){
	return s < 0 ? -s : s;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, n, x, y, v, minsum, mat[25], ans[5];
	readInt(t);
	while(t--){
		readInt(n);
		memset(mat, 0, sizeof(mat));
		minsum = 2147483647;
		for(int i = 0; i < n; i++){
			readInt(x);
			readInt(y);
			readInt(v);
			mat[x*5+y] = v;
		}
		for(int a = 0; a < 21; a++)
			for(int b = a+1; b < 22; b++)
				for(int c = b+1; c < 23; c++)
					for(int d = c+1; d < 24; d++)
						for(int e = d+1; e < 25; e++){
							int tempans[5] = {a, b, c, d, e};
							int sum = 0;
							for(int i = 0; i < 25; i++)
								if(mat[i]){
									int cost = 2147483647;
									for(int j = 0; j < 5; j++)
										if(cost > mat[i]*(ab(tempans[j]/5 - i/5) + ab(tempans[j]%5 - i%5)))
											cost = mat[i]*(ab(tempans[j]/5 - i/5) + ab(tempans[j]%5 - i%5));
									sum += cost;
									if(sum >= minsum)
										break;
								}
							if(sum < minsum){
								minsum = sum;
								memcpy(ans, tempans, sizeof(tempans));
							}
						}
		for(int i = 0; i < 5; i++)
			printf("%d%s", ans[i], i == 4 ? "\n" : " ");
	}
	return 0;
}