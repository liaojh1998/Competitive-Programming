/*
ID: liaojh11
PROG: preface
LANG: C++
*/
//Title: preface
//Type: Brute Force/Greedy
//Solution: Just made this for 1 <= N <= 3500.
#include <fstream>
using namespace std;
FILE *fin = fopen("preface.in", "r");
FILE *fout = fopen("preface.out", "w");
int V, R[7];
/* i is the number, s is the shift in array for roman numerals, find the pattern basically */
void romans(int i, int s){
	switch(i){
		case 0 : return;
		case 1 : { R[0+s]++; break; }
		case 2 : { R[0+s]+=2; break; }
		case 3 : { R[0+s]+=3; break; }
		case 4 : { R[0+s]++; R[1+s]++; break; }
		case 5 : { R[1+s]++; break; }
		case 6 : { R[0+s]++; R[1+s]++; break; }
		case 7 : { R[0+s]+=2; R[1+s]++; break; }
		case 8 : { R[0+s]+=3; R[1+s]++; break; }
		case 9 : { R[0+s]+=1; R[2+s]++; break; }
	}
}
int main()
{   
	//Constructor and instantiation
	fscanf(fin, "%d", &V);
	for(int i = 0; i < 7; i++){
		R[i] = 0;
	}
	for(int i = 1; i <= V; i++){
		romans(i%10, 0);
		romans(i/10%10, 2);
		romans(i/100%10, 4);
		romans(i/1000, 6);
	}
	fprintf(fout, R[0] ? "I %i\n": "", R[0]);
	fprintf(fout, R[1] ? "V %i\n": "", R[1]);
	fprintf(fout, R[2] ? "X %i\n": "", R[2]);
	fprintf(fout, R[3] ? "L %i\n": "", R[3]);
	fprintf(fout, R[4] ? "C %i\n": "", R[4]);
	fprintf(fout, R[5] ? "D %i\n": "", R[5]);
	fprintf(fout, R[6] ? "M %i\n": "", R[6]);
	return 0;
}