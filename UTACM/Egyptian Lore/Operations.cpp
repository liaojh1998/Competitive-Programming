//Type: Simulation
#include <cstdio>
#include <cstring>
int T;
long long cur[100], arr[100], num, clen, olen;
char op[100], optemp[100], c;
bool terminate, n;
void operation(char c){
	if(terminate) return;
	arr[0] = cur[0];
	int index = 0, otlen = 0;
	for(int i = 0; i < olen; i++){
		if(op[i] == c){
			switch(c){
				case '+': arr[index]+= cur[i+1]; break;
				case '-': arr[index]-= cur[i+1]; break;
				case '*': arr[index]*= cur[i+1]; break;
				case '/': if(!cur[i+1] || arr[index]%cur[i+1]){terminate = true; return;}else{arr[index]/= cur[i+1];} break;
				case '%': if(!cur[i+1]) terminate = true; else arr[index]%= cur[i+1]; break;
			}
		}else{
			arr[++index] = cur[i+1];
			optemp[otlen++] = op[i];
		}
	}
	memcpy(op, optemp, sizeof(optemp));
	memcpy(cur, arr, sizeof(arr));
	olen = otlen;
}
int main(){
	scanf("%d", &T);
	getchar();
	while(T--){
		while(scanf("%c", &c) && c != 10){
			if(c >= '0' && c <= '9'){
				n = true;
				num = num*10 + c - '0';
			}
			else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
				if(!n){
					terminate = true;
				}else{
					n = false;
					cur[clen++] = num;
					num = 0;
				}
				op[olen++] = c;
			}
		}
		if(!n)
			terminate = true;
		else{
			cur[clen++] = num;
			num = 0;
		}
		while(scanf("%c", &c) && c != 10){
			if(c != ' ')
				operation(c);
		}
		if(terminate){
			printf("OPERATION ERROR\n");
			terminate = false;
			clen = olen = 0;
			continue;
		}
		printf("%lld\n", cur[0]);
		clen = olen = 0;
	}
	return 0;
}