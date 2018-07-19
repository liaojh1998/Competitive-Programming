#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
 
// Site: www.codechef.com 
// Competition: July Challenge 2017  
// Problem: Multiplication Program
// Problem Code: MULDIG
// by lboris
 
/*
	You only need: Acc 1, OpField BxB, Result 2, and ~20 temporary varibles (actually 5-6 would be enough). 
	i.e. for Base 3 => we need 32 memory cells
			 Base 5 => we need 48 cells
			 Base 7 => we need 72 cells
 
	if we clear the intermediate results each time...
 
	I've used 4 more... 
 
	We need 4 multipliers and 10 summators
	Excellent problem!
 
*/
 
typedef unsigned int uint;
typedef unsigned long long llu;
typedef long long int lls;
 
#define f(i,s,e) for(int i=s;i<(int)(e);++i)
#define fe(i,s,e) for(int i=s;i<=(int)(e);++i)
typedef std::pair<int, int> ipair;
 
struct step {
	step(int _a, int _b, int _r) :a(_a), b(_b), r(_r) {};
	int a;
	int b;
	int r;
};
typedef std::vector<step> stvector;
 
void clear_acc(int B,stvector& R) {
	R.push_back(step(0, 0, B + 8));
}
void calc_axb(int B, int a, int b, stvector& R) { 
	int tAddr = B + 8;
	int cAddr = B + 9;
	int B2 = B*B;
	f(i, 0, B2) { R.push_back(step(0, 0, cAddr + i)); }
 
	if (B == 3) {
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(2, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j, cAddr + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(2, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B + j, cAddr + B + j));
		R.push_back(step(2, a, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 2 + j, cAddr + B * 2 + j));
 
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(2, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B, cAddr + j * B));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(2, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 1, cAddr + j * B + 1));
		R.push_back(step(2, b, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 2, cAddr + j * B + 2));
	}
	else if (B == 5) {
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j, cAddr + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B + j, cAddr + B + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 2 + j, cAddr + B * 2 + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 3 + j, cAddr + B * 3 + j));
		R.push_back(step(4, a, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 4 + j, cAddr + B * 4 + j));
 
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B, cAddr + j * B));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 1, cAddr + j * B + 1));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 2, cAddr + j * B + 2));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(4, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 3, cAddr + j * B + 3));
		R.push_back(step(4, b, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 4, cAddr + j * B + 4));
	}
	else if (B == 7) {
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j, cAddr + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 1 + j, cAddr + B * 1 + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 2 + j, cAddr + B * 2 + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 3 + j, cAddr + B * 3 + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 4 + j, cAddr + B * 4 + j));
		R.push_back(step(1, a, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 5 + j, cAddr + B * 5 + j));
		R.push_back(step(6, a, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + B * 6 + j, cAddr + B * 6 + j));
 
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B, cAddr + j * B));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 1, cAddr + j * B + 1));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 2, cAddr + j * B + 2));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 3, cAddr + j * B + 3));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(1, tAddr, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 4, cAddr + j * B + 4));
		R.push_back(step(1, b, tAddr));
		R.push_back(step(6, tAddr, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 5, cAddr + j * B + 5));
		R.push_back(step(6, b, tAddr));
		f(j, 0, B) R.push_back(step(tAddr, cAddr + j * B + 6, cAddr + j * B + 6));
	}
 
	f(i, 0, B2) { R.push_back(step(2, cAddr + i, cAddr + i)); }
}
 
int Ft_mul_0[7][7];
int Ft_mul_1[7][7];
int Ft_add_0[7][7];
int Ft_add_1[7][7];
 
void calc_mul01(int B, int a, int b, stvector& R) { 
	clear_acc(B, R);
	calc_axb(B, a, b, R);
	int cAddr  = B + 9;
	int addrR0 = B + 9 + B*B;
	int addrR1 = B + 9 + B*B + 1;
	R.push_back(step(0, 0, addrR0)); // clear result
	R.push_back(step(0, 0, addrR1));
 
	f(i, 0, B) {
		f(j, 0, B) {
			f(k, 0, Ft_mul_0[i][j]) {
				R.push_back(step(cAddr + i*B + j, addrR0, addrR0));
			}
			f(k, 0, Ft_mul_1[i][j]) {
				R.push_back(step(cAddr + i*B + j, addrR1, addrR1));
			}
		}
	}
}
 
void calc_add01(int B, int a, int b, stvector& R) { 
	clear_acc(B, R);
	calc_axb(B, a, b, R);
	int cAddr = B + 9;
	int addrR0 = B + 9 + B*B;
	int addrR1 = B + 9 + B*B + 1;
	R.push_back(step(0, 0, addrR0)); // clear result
	R.push_back(step(0, 0, addrR1));
 
	f(i, 0, B) {
		f(j, 0, B) {
			f(k, 0, Ft_add_0[i][j]) {
				R.push_back(step(cAddr + i*B + j, addrR0, addrR0));
			}
			f(k, 0, Ft_add_1[i][j]) {
				R.push_back(step(cAddr + i*B + j, addrR1, addrR1));
			}
		}
	}
 
}
 
void cmove(int B, int src, int dst, stvector& R) {
	R.push_back(step(0, src, dst));
}
 
int func3[3][3] = {
	{ 0, 1, 2 },	// = a
	{ 1, 2, 0 },	// = a+1
	{ 0, 0, 1 }		// = 1 if 2 , else 0
};
int func5[5][5] = {
	{ 0, 1, 2, 3, 4 }, // = a
	{ 1, 2, 3, 4, 0 }, // = a+1
	{ 0, 0, 1, 0, 0 }, // = 1 if 2 , else 0
	{ 2, 3, 4, 0, 1 },
	{ 0, 0, 0, 0, 1 }  // = 1 if 4 , else 0
};
int func7[7][7] = {
	{ 0, 1, 2, 3, 4, 5, 6 }, // = a
	{ 1, 2, 3, 4, 5, 6, 0 }, // = a+1
	{ 0, 0, 1, 0, 0, 0, 0 }, // = 1 if 2 , else 0
	{ 2, 3, 4, 5, 6, 0, 1 },
	{ 3, 4, 5, 6, 0, 1, 2 },
	{ 4, 5, 6, 0, 1, 2, 3 },
	{ 0, 0, 0, 0, 0, 0, 1 }  // = 1 if 6 , else 0
};
stvector R;
 
void build(int B) {
	int addrA1 = B + 0;
	int addrA0 = B + 1;
 
	int addrB1 = B + 2;
	int addrB0 = B + 3;
 
	int addrC3 = B + 4;
	int addrC2 = B + 5;
	int addrC1 = B + 6;
	int addrC0 = B + 7;
 
	int addrR0 = B + 8 + B*B + 1;
	int addrR1 = B + 8 + B*B + 2;
 
	// intermediate variables
	int addrAB  = 100; 
	int addrAB1 = 110; 
	int addrAB2 = 120;
	int addrAB3 = 130;
	int addrAB4 = 140;
	int addrAB5 = 150;
 
	calc_mul01(B, addrA0, addrB0, R);
	cmove(B, addrR0, addrAB + 0, R);
	cmove(B, addrR1, addrAB + 1, R);
 
	calc_mul01(B, addrA0, addrB1, R);
	cmove(B, addrR0, addrAB + 2, R);
	cmove(B, addrR1, addrAB + 3, R);
 
	calc_mul01(B, addrA1, addrB0, R);
	cmove(B, addrR0, addrAB + 4, R);
	cmove(B, addrR1, addrAB + 5, R);
 
	calc_mul01(B, addrA1, addrB1, R);
	cmove(B, addrR0, addrAB + 6, R);
	cmove(B, addrR1, addrAB + 7, R);
 
	cmove(B, addrAB + 0, addrC0, R); // c0
	
	calc_add01(B, addrAB + 1, addrAB + 2, R);
	cmove(B, addrR0, addrAB1 + 0, R);
	cmove(B, addrR1, addrAB1 + 1, R);
 
	calc_add01(B, addrAB + 3, addrAB + 5, R);
	cmove(B, addrR0, addrAB1 + 2, R);
	cmove(B, addrR1, addrAB1 + 3, R);
 
	calc_add01(B, addrAB1 + 0, addrAB + 4, R);
	cmove(B, addrR0, addrAB2 + 0, R);
	cmove(B, addrR1, addrAB2 + 1, R);
 
	calc_add01(B, addrAB1 + 2, addrAB + 6, R);
	cmove(B, addrR0, addrAB2 + 2, R);
	cmove(B, addrR1, addrAB2 + 3, R);
 
	calc_add01(B, addrAB1 + 3, addrAB + 7, R);
 
	cmove(B, addrR0, addrAB2 + 4, R);
	cmove(B, addrAB2 + 0, addrC1, R); // c1
 
	calc_add01(B, addrAB2 + 1, addrAB1 + 1, R);
	cmove(B, addrR0, addrAB3 + 0, R);
	cmove(B, addrR1, addrAB3 + 1, R);
 
	calc_add01(B, addrAB2 + 3, addrAB2 + 4, R);
	cmove(B, addrR0, addrAB3 + 2, R);
 
	calc_add01(B, addrAB3 + 0, addrAB2 + 2, R);
	cmove(B, addrR0, addrAB4 + 0, R);
	cmove(B, addrR1, addrAB4 + 1, R);
 
	calc_add01(B, addrAB3 + 1, addrAB3 + 2, R);
	cmove(B, addrR0, addrAB4 + 2, R);
 
	cmove(B, addrAB4 + 0, addrC2, R); // c2
 
	calc_add01(B, addrAB4 + 1, addrAB4 + 2, R);
	cmove(B, addrR0, addrAB5 + 0, R);
 
	cmove(B, addrAB5 + 0, addrC3, R); // c3
 
	if (B == 3) {
		f(i, 0, B) {
			f(j, 0, B) {
				printf("%d%c", func3[i][j], (j == B - 1) ? '\n' : ' ');
			}
		}
	}
	else if (B == 5) {
		f(i, 0, B) {
			f(j, 0, B) {
				printf("%d%c", func5[i][j], (j == B - 1) ? '\n' : ' ');
			}
		}
	}
	else if (B == 7) {
		f(i, 0, B) {
			f(j, 0, B) {
				printf("%d%c", func7[i][j], (j == B - 1) ? '\n' : ' ');
			}
		}
	}
	else {
		exit(1);
	}
	printf("%d\n", R.size());
	f(i, 0, (int)R.size()) {
		printf("%d %d %d\n", R[i].a, R[i].b, R[i].r);
	}
}
 
int Mem[1000];
 
bool test_ab(int B, int a, int b, stvector& R) {
	memset(Mem, 0, sizeof(int)* 1000);
	f(i, 0, B)Mem[i] = i;
	Mem[B] = a / B;
	Mem[B + 1] = a % B;
	Mem[B + 2] = b / B;
	Mem[B + 3] = b % B;
	f(i, 0, R.size()) {
		switch (B) {
		case 3:	Mem[R[i].r] = func3[Mem[R[i].a]][Mem[R[i].b]]; break;
		case 5:	Mem[R[i].r] = func5[Mem[R[i].a]][Mem[R[i].b]]; break;
		case 7:	Mem[R[i].r] = func7[Mem[R[i].a]][Mem[R[i].b]]; break;
		}
		if(a == 6 && b == 7){
			printf("%d %d %d\n", R[i].r, R[i].a, R[i].b);
			f(i, 0, 151)
				printf("%d%s", Mem[i], i == 150 ? "\n" : " ");
		}
	}
	int c = Mem[B + 7] + B*Mem[B + 6] + B*B*Mem[B + 5] + B*B*B*Mem[B + 4];
	if (a*b == c) {
		printf("OK: %d * %d = %d\n", a, b, c);
	}
	else {
		printf("Error: %d * %d = %d != %d (C: %d %d %d %d)\n", a, b, c, a*b, Mem[B + 4], Mem[B + 5], Mem[B + 6], Mem[B + 7]);
		exit(1);
	}
	return true;
}
 
void test(int B) {
	f(a, 0, B*B) {
		f(b, 0, B*B) {
			test_ab(B, a, b, R);
		}
	}
}
 
int main(int argc, char **argv) {
	freopen("output.txt", "w", stdout);
	int B;
	scanf("%d", &B);
	f(a, 0, B) {
		f(b, 0, B) {
			int ml = a*b;
			int ad = a + b;
			Ft_mul_0[a][b] = ml % B;
			Ft_mul_1[a][b] = ml / B;
			Ft_add_0[a][b] = ad % B;
			Ft_add_1[a][b] = ad / B;
		}
	}
	build(B);
	test(B);
	return 0;
}
 
 
 
 
 
 
 
 