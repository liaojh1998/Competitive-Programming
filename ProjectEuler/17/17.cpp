//Title: Number letter counts/Number to Words
//Solution: Pure simulation
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

bool first;
long long digit(long long N){
	switch(N){
		case 9: printf("Nine"); return 4;
		case 8: printf("Eight"); return 5;
		case 7: printf("Seven"); return 5;
		case 6: printf("Six"); return 3;
		case 5: printf("Five"); return 4;
		case 4: printf("Four"); return 4;
		case 3: printf("Three"); return 5;
		case 2: printf("Two"); return 3;
		case 1: printf("One"); return 3;
		default: break;
	}
	return 0;
}
long long tens(long long N){
	long long ans = 0;
	if(N < 10)
		ans += digit(N);
	else
		if(N >= 10 && N < 20){
			switch(N){
				case 10: printf("Ten"); ans += 3; break;
				case 11: printf("Eleven"); ans += 6; break;
				case 12: printf("Twelve"); ans += 6; break;
				case 13: printf("Thirteen"); ans += 8; break;
				case 14: printf("Fourteen"); ans += 8; break;
				case 15: printf("Fifteen"); ans += 7; break;
				case 16: printf("Sixteen"); ans += 7; break;
				case 17: printf("Seventeen"); ans += 9; break;
				case 18: printf("Eighteen"); ans += 8; break;
				case 19: printf("Nineteen"); ans += 8; break;
			}
		}else{
			switch(N/10){
				case 2: printf("Twenty"); ans += 6; break;
				case 3: printf("Thirty"); ans += 6; break;
				case 4: printf("Forty"); ans += 5; break;
				case 5: printf("Fifty"); ans += 5; break;
				case 6: printf("Sixty"); ans += 5; break;
				case 7: printf("Seventy"); ans += 7; break;
				case 8: printf("Eighty"); ans += 6; break;
				case 9: printf("Ninety"); ans += 6; break;
			}
			if(N%10){
				printf(" ");
				ans += digit(N%10);
			}
		}
	return ans;
}
long long hundreds(long long N){
	long long ans = 0;
	if(N/100){
		ans += digit(N/100);
		printf(" Hundred");
		ans += 7;
	}
	if(N%100){
		if(N/100){
			printf(" ");
			ans += 3; //Omitted 'and' but ProjectEuler need it
		}
		ans += tens(N%100);
	}
	return ans;
}
long long count(long long N){
	long long ans = 0;
	if(!N){
		printf("Zero\n");
		return 4;
	}
	first = true;
	if(N/1000000000000){
		printf("One Trillion");
		ans += 11;
		N %= 1000000000000;
		first = false;
	}
	if(N/1000000000){
		if(!first)
			printf(" ");
		first = false;
		ans += hundreds(N/1000000000);
		printf(" Billion");
		ans += 7;
		N %= 1000000000;
	}
	if(N/1000000){
		if(!first)
			printf(" ");
		first = false;
		ans += hundreds(N/1000000);
		printf(" Million");
		ans += 7;
		N %= 1000000;
	}
	if(N/1000){
		if(!first)
			printf(" ");
		first = false;
		ans += hundreds(N/1000);
		printf(" Thousand");
		ans += 8;
		N %= 1000;
	}
	if(N){
		if(!first)
			printf(" ");
		ans += hundreds(N);
	}
	printf("\n");
	return ans;
}
int main(){
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	int T;
	long long N, ans = 0;
	readInt(T);
	while(T--){
		readLL(N);
		ans += count(N);
	}
	printf("%lld\n", ans); //For ProjectEuler letter count
	return 0;
}