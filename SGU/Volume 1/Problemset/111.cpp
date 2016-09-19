//Title: Very Simple Problem (LOL NAH)
//Type: Math
//Solution: Square Root Algorithm + High Precision Computation Algorithm
		/*	http://jwilson.coe.uga.edu/emt668/emat6680.f99/challen/squareroot/sqrt.html
			Note: all big numbers are numbered backwards to make high accuracy calculations easier */
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int start;
struct bignum{int num[1002], len;};
char num[1002];
bignum sol, rem, bigtemp, remtemp;
int add(bignum *n, int k){
	//Add numbers to the end of the big numbers, not a high accuracy algorithm.
	int len = 0;
	while(k != 0){
		n->num[len]+= k%10;
		k /= 10;
		len++;
	}
	return len;
}
void sub(bignum *a, bignum b){
	//a - b, note that this algorithm will not give the correct answer if a < b, which is a negative answer.
	int olen = a->len;
	for(int i = 0; i < olen; i++){
		while(a->num[i] < b.num[i]){
			a->num[i]+= 10;
			a->num[i+1]--;
		}
		a->num[i]-= b.num[i];
	}
	//Find out length of subtracted
	for(; a->len >= 0; a->len--)
		if(a->num[a->len]){
			a->len++;
			break;
		}
}
void mul(bignum *n, int k){
	//Special case, if k = 0
	if(!k){
		memset(n->num, 0, sizeof(n->num));
		n->len = 0;
		return;
	}
	//k into int array
	int a[3], alen = 0;
	while(k != 0){
		a[alen] = k%10;
		k /= 10;
		alen++;
	}
	//High accuracy multiplication algorithm
	int temp[1002];
	memset(temp, 0, sizeof(temp));
	for(int i = 0; i < alen; i++){
		for(int j = 0; j < n->len; j++){
			temp[i + j]+= n->num[j] * a[i];
			temp[i + j + 1]+= temp[i+j] / 10;
			temp[i + j]%= 10;
		}
	}
	//Length of new multiplied number
	n->len+= alen;
	if(!temp[n->len - 1])
		n->len--;
	//Copy temp into num
	memcpy(n->num, temp, sizeof(temp));
}
//a > b = 1, a <= b = 0
int cmp(bignum a, bignum b){
	if(a.len > b.len) return 1;
	if(a.len < b.len) return 0;
	for(int i = a.len-1; i >= 0; i--){
		if(a.num[i] > b.num[i]) return 1;
		if(a.num[i] < b.num[i]) return 0;
	}
	return 0; //If equal, doesn't matter
}
bool check(int k){
	memcpy(&bigtemp, &sol, sizeof(sol));
	//Square root algorithm
	mul(&bigtemp, 20);
	bigtemp.num[0] += k;
	mul(&bigtemp, k);
	//Check if not subtractable from remainder
	if(cmp(bigtemp, rem))
		return false;
	sub(&rem, bigtemp);
	return true;
}
//Getting number segment from string
int getseg(int len){
	int n = 0;
	for(int i = start; i < start+len; i++){
		n*= 10;
		n+= (num[i]-48);
	}
	start+= len;
	return n;
}
int main(){
	//Instantiation
	scanf("%s", num);
	//First number segment
	int l = strlen(num), first;
	if(l&1){
		first = getseg(1);
	}else{
		first = getseg(2);
	}
	int f = sqrt(first);
	//Add first number to solution
	add(&sol, f);
	sol.len = 1;
	printf("%d", sol.num[0]);
	//Add first remainder to rem
	rem.len = add(&rem, first - f*f);;
	//Determine answer length
	l = (l + 1) / 2;
	//All other segments
	for(int i = 2; i <= l; i++){
		//Add segment to remainder
		mul(&rem, 100);
		add(&rem, getseg(2));
		//Find next number (square root algorithm)
		int j;
		for(j = 9; j >= 0; j--){
			if(check(j))
				break;
		}
		printf("%d", j);
		//Add number to solution
		mul(&sol, 10);
		add(&sol, j);
	}
	printf("\n");
	return 0;
}