//Title: Meeting
//Type: Math
//Solution: Probability. Anytime between X~(Y-Z) + Z the team will meet. Let's set M as 60 * (Y - X). Any Z/M is the probability they will meet. Anything after Z
		/*	will be (Z/M * (M-Z)/M), add them and you have the total probability */
#include <cstdio>
int X, Y;
double Z;
int main(){
	//Instantiation
	scanf("%d %d %lf", &X, &Y, &Z);
	double M = 60 * (Y - X);
	printf("%.7f\n", Z/M + Z*(M-Z)/M/M);
	return 0;
}