#include <cstdio>
#define MOD (1000000007)
using namespace std;
int T, astcount;
char c;
bool error, turn, done;
long long ans, cur, e;
long long exp(long long m, long long t){
	if(t == 1)
		return m;
	if(!(t & 1))
		return exp(((m%MOD)*(m%MOD))%MOD, t/2)%MOD;
	return ((m%MOD)*(exp(m%MOD, t-1)%MOD))%MOD;
}
void getans(){
	while(~scanf("%c", &c) && c != 10){
		if(c == '*' && !ans){
			error = true;
			return;
		}else if(c == '*'){
			astcount = 1;
			break;
		}
		ans = ans*10+c-'0';
	}
	if(!astcount){
		done = true;
		return;
	}
	while(~scanf("%c", &c) && c != 10){
		if(c == '*' && astcount == 2 && e){
			ans = exp(ans, e);
			astcount = 1;
			e = 0;
		}else if(c == '*'){
			if(astcount == 2){
				error = true;
				return;
			}
			astcount++;
		}else if(c >= '0' && c <= '9' && astcount == 1){
			astcount = 0;
			cur = c - '0';
			return;
		}else{
			e = e*10 + c - '0';
		}
	}
	done = true;
	if(astcount && !e){
		error = true;
		return;
	}
	ans = exp(ans, e);
}
void getnext(){
	while(~scanf("%c", &c) && c != 10){
		if(c == '*'){
			astcount = 1;
			break;
		}
		cur = cur*10 + c - '0';
	}
	if(!astcount){
		ans = ((ans%MOD)*(cur%MOD))%MOD;
		return;
	}
	while(~scanf("%c", &c) && c != 10){
		if(c >= '0' && c <= '9' && astcount == 1){
			ans = ((ans%MOD)*(cur%MOD))%MOD;
			astcount = 0;
			cur = c - '0';
		}else if(c >= '0' && c <= '9' && !astcount){
			cur = cur*10 + c - '0';
		}else if(c == '*' && e){
			cur = exp(cur, e);
			e = 0;
			astcount = 1;
		}else if(c == '*'){
			if(astcount == 2){
				while(~scanf("%c", &c) && c != 10);
				error = true;
				return;
			}
			astcount++;
		}else if(c >= '0' && c <= '9'){
			e = e*10 + c - '0';
		}
	}
	if(!astcount){
		ans = ((ans%MOD)*(cur%MOD))%MOD;
		return;
	}
	if(astcount && !e){
		error = true;
		return;
	}
	cur = exp(cur, e);
	ans = ((ans%MOD)*(cur%MOD))%MOD;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	getchar();
	while(T--){
		getans();
		if(error && !done){
			while(~scanf("%c", &c) && c != 10);
			printf("Syntax Error\n");
		}else if(done){
			if(error)
				printf("Syntax Error\n");
			else
				printf("%lld\n", ans%MOD);
		}else{
			getnext();
			if(error)
				printf("Syntax Error\n");
			else
				printf("%lld\n", ans%MOD);
		}
		ans = cur = e = astcount = 0;
		error = done = false;
	}
	return 0;
}