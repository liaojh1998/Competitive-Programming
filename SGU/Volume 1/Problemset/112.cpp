//Title: a^b-b^a
//Type: Math
//Solution: High Precision Computation Algorithm
#include <cstdio>
#include <cstring>
using namespace std;
int a, b;
struct bignum{int num[201], len;};
bignum ab, ba, aarray, barray;
//a > b = 1, a < b = 0, a == b = -1
int cmp(bignum a, bignum b){
	if(a.len > b.len) return 1;
	if(a.len < b.len) return 0;
	for(int i = a.len-1; i >= 0; i--){
		if(a.num[i] > b.num[i]) return 1;
		if(a.num[i] < b.num[i]) return 0;
	}
	return -1; //If equal, doesn't matter
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
void mul(bignum *n, bignum k){
	//High accuracy multiplication algorithm
	int temp[201];
	memset(temp, 0, sizeof(temp));
	for(int i = 0; i < k.len; i++){
		for(int j = 0; j < n->len; j++){
			temp[i + j]+= n->num[j] * k.num[i];
			temp[i + j + 1]+= temp[i+j] / 10;
			temp[i + j]%= 10;
		}
	}
	//Length of new multiplied number
	n->len+= k.len;
	if(!temp[n->len - 1])
		n->len--;
	//Copy temp into num
	memcpy(n->num, temp, sizeof(temp));
}
int main(){
	//Instantiation
	scanf("%d %d", &a, &b);
	if(a == b){
		printf("0\n");
		return 0;
	}
	int atemp = a, btemp = b;
	while(atemp != 0){
		aarray.num[aarray.len] = atemp%10;
		atemp /= 10;
		aarray.len++;
	}
	while(btemp != 0){
		barray.num[barray.len] = btemp%10;
		btemp /= 10;
		barray.len++;
	}
	memcpy(&ab, &aarray, sizeof(aarray));
	memcpy(&ba, &barray, sizeof(barray));
	//Multiply
	for(int i = b-1; i >= 1; i--){
		mul(&ab, aarray);
	}
	for(int i = a-1; i >= 1; i--){
		mul(&ba, barray);
	}
	//Subtract
	int j = cmp(ab, ba);
	if(j == -1)
		printf("0");
	else if(j){
		sub(&ab, ba);
		for(int i = ab.len-1; i >= 0; i--){
			printf("%d", ab.num[i]);
		}
	}else{
		printf("-");
		sub(&ba, ab);
		for(int i = ba.len-1; i >= 0; i--){
			printf("%d", ba.num[i]);
		}
	}
	printf("\n");
	return 0;
}