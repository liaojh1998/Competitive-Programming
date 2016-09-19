//Title: Artificial Intelligence?
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int C, O;
double U, P, I;
char str[200];
void getU(int i){
	double d = 0.1, neg = 1.0;
	bool dec = false;
	for(i += 2; str[i] != 'V'; i++){
		if(str[i] == 'm')
			U /= 1000;
		else if(str[i] == 'M')
			U *= 1000000;
		else if(str[i] == 'k')
			U *= 1000;
		else if(str[i] == '.')
			dec = true;
		else if(str[i] == '-'){
			neg = -1.0;
			U *= -1.0;
		}else{
			if(!dec)
				U = U*10 + neg*(str[i]-'0');
			else{
				U += neg*(double)(str[i]-'0')*d;
				d /= 10;
			}
		}
	}
}
void getP(int i){
	double d = 0.1, neg = 1.0;
	bool dec = false;
	for(i += 2; str[i] != 'W'; i++){
		if(str[i] == 'm')
			P /= 1000;
		else if(str[i] == 'M')
			P *= 1000000;
		else if(str[i] == 'k')
			P *= 1000;
		else if(str[i] == '.')
			dec = true;
		else if(str[i] == '-'){
			neg = -1.0;
			P *= -1.0;
		}else{
			if(!dec)
				P = P*10 + neg*(str[i]-'0');
			else{
				P += neg*(double)(str[i]-'0')*d;
				d /= 10;
			}
		}
	}
}
void getI(int i){
	double d = 0.1, neg = 1.0;
	bool dec = false;
	for(i += 2; str[i] != 'A'; i++){
		if(str[i] == 'm')
			I /= 1000;
		else if(str[i] == 'M')
			I *= 1000000;
		else if(str[i] == 'k')
			I *= 1000;
		else if(str[i] == '.')
			dec = true;
		else if(str[i] == '-'){
			neg = -1.0;
			I *= -1.0;
		}else{
			if(!dec)
				I = I*10 + neg*(double)(str[i]-'0');
			else{
				I += neg*d*(double)(str[i]-'0');
				d /= 10;
			}
		}
	}
}
int main(){
	scanf("%d", &C);
	getchar();
	O = C;
	while(C--){
		scanf("%[^\n]", &str);
		getchar();
		printf("Problem #%d\n", O-C);
		int len = strlen(str);
		bool hasP = false, hasU = false, hasI = false;
		for(int i = 0; i < len-1; i++){
			if(str[i] == 'U' && str[i+1] == '='){
				hasU = true;
				getU(i);
			}
			else if(str[i] == 'P' && str[i+1] == '='){
				hasP = true;
				getP(i);
			}
			else if(str[i] == 'I' && str[i+1] == '='){
				hasI = true;
				getI(i);
			}
		}
		if(hasU && hasP){
			I = P/U;
			printf("I=%.2fA\n\n", I);
			U = I = P = 0;
		}else if(hasU && hasI){
			P = U*I;
			printf("P=%.2fW\n\n", P);
			U = I = P = 0;
		}else if(hasI && hasP){
			U = P/I;
			printf("U=%.2fV\n\n", U);
			U = I = P = 0;
		}
	}
	return 0;
}