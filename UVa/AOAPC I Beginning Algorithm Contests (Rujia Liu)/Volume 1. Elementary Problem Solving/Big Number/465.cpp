//Title: Overflow
//Type: Math
//Solution: The tricky math that you don't need high precision lmao
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char num1[1000], op, num2[1000];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%s %c %s", &num1, &op, &num2)){
		printf("%s %c %s\n", num1, op, num2);
		double a = atof(num1);
		double b = atof(num2);
		if(a > 2147483647)
			puts("first number too big");
		if(b > 2147483647)
			puts("second number too big");
		if((op == '+' && a+b > 2147483647) || (op == '*' && a*b > 2147483647))
			puts("result too big");
	}
	return 0;
}