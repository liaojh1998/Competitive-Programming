#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
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

struct person{
	char str[15];
	bool deleted;
	person *prev, *next;
	person(char *s){
		memcpy(str, s, sizeof(str));
		deleted = false;
		prev = NULL;
		next = NULL;
	}
};
long long getNum(char i){
	if(i >= 'A' && i <= 'Z')
		return i - 'A';
	return i-'a'+26;
}
long long exp52[10] = {1, 52, 52*52, 52*52*52, 52*52*52*52, 52*52*52*52*52, (long long)52*52*52*52*52*52, (long long)52*52*52*52*52*52*52, (long long)52*52*52*52*52*52*52*52, (long long)52*52*52*52*52*52*52*52*52};
long long hashing(char *str){
	long long sum = 0, size = strlen(str);
	for(int i = 0; i < size; i++)
		sum += getNum(str[i])*exp52[i];
	return sum;
}
void solve(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	readInt(T);
	while(T--){
		int N;
		readInt(N);
		map<long long, person*> location;
		person *top = NULL;
		char command[10], str[15];
		for(int i = 0; i < N; i++){
			readStr(command);
			if(!strcmp(command, "SEND") || !strcmp(command, "RECEIVE")){
				readStr(str);
				long long hashes = hashing(str);
				person* temp;
				if(location.count(hashes)){
					temp = location[hashes];
					if(temp != top && !(temp->deleted)){
						if(temp->prev != NULL)
							temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
					}else if(temp->deleted)
						temp->deleted = false;
				}else{
					temp = new person(str);
					location[hashes] = temp;
				}
				if(top != temp){
					if(top != NULL){
						top->next = temp;
						temp->prev = top;
					}
					top = temp;
				}
			}else if(!strcmp(command, "DELETE")){
				if(top == NULL)
					printf("NONE\n");
				else{
					printf("%s\n", top->str);
					top->deleted = true;
					person *temp = top;
					top = top->prev;
					if(top != NULL)
						top->next = NULL;
					temp->next = temp->prev = NULL;
				}
			}
		}
		printf("\n");
	}
}
int main(){
	solve();
	return 0;
}