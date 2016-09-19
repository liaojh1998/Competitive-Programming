//Title: If We Were a Child Again
//Type: Math
//Solution: The challenge here is to stop using big numbers because divisors fit in an int :D
#include <cstdio>
#include <cstring>
using namespace std;
char n[300], op;
int quot;
void div(char* n, int d){
	long long r = 0;
	int len = strlen(n);
	bool has = false;
	for(int i = 0; i < len; i++){
		r = r*10 + n[i]-'0';
		if(r/d!=0)
			has = true;
		if(has)
			printf("%d", r/d);
		r %= d;
	}
	if(!has) printf("0");
}
int rem(char* n, int d){
	long long r = 0;
	int len = strlen(n);
	for(int i = 0; i < len; i++){
		r = r*10 + n[i]-'0';
		r %= d;
	}
	return r;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%s %c %d", &n, &op, &quot)){
		if(op == '/'){
			div(n, quot);
			printf("\n");
		}else{
			int r = rem(n, quot);
			printf("%d\n", r);
		}
	}
	return 0;
}