//Title: Business
//Type: Math
//Complexity: O(N*M^2 + M*N*O + M)
//Solution: Simple counting?
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
	if(c == 10) return 10;
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
	int T;
	readInt(T);
	while(T--){
		int N, M, O;
		readInt(N);
		readInt(M);
		readInt(O);
		char pin[N+5][10];
		vector<string> pinmat[N+5];
		long long pincost[N+5];
		for(int i = 0; i < N; i++){
			readStr(pin[i]);
			readLL(pincost[i]);
			string temp;
			//manual read huh?
			char c = getchar();
			while(c != 10){
				if(c == ' '){
					pinmat[i].push_back(temp);
					temp.clear();
				}else
					temp += c;
				c = getchar();
			}
		}
		char matstr[M+5][10];
		long long matsize[M+5], matcost[M+5];
		for(int i = 0; i < M; i++){
			readStr(matstr[i]);
			readLL(matsize[i]);
			readLL(matcost[i]);
		}
		//Reorganize info
		long long matneed[M+5], pinmatneed[N+5][M+5];
		memset(matneed, 0, sizeof(matneed));
		memset(pinmatneed, 0, sizeof(pinmatneed));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < pinmat[i].size(); j++)
				for(int k = 0; k < M; k++)
					if(!strcmp(matstr[k], pinmat[i][j].c_str()))
						pinmatneed[i][k]++;
		/*for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				printf("%lld%s", pinmatneed[i][j], j == M-1 ? "\n" : " ");*/
		//Orders
		long long need, revenue = 0;
		char temppin[10];
		for(int i = 0; i < O; i++){
			readStr(temppin);
			readLL(need);
			for(int j = 0; j < N; j++){
				if(!strcmp(temppin, pin[j])){
					revenue += need*pincost[j];
					for(int k = 0; k < M; k++)
						matneed[k] += pinmatneed[j][k]*need;
					break;
				}
			}
		}
		//Answer
		for(int i = 0; i < M; i++)
			//printf("%d\n", matneed[i]);
			revenue -= (matneed[i]%matsize[i]) ? (matneed[i]/matsize[i]+1)*matcost[i] : (matneed[i]/matsize[i])*matcost[i];
		printf("%lld\n", revenue);
	}
	return 0;
}