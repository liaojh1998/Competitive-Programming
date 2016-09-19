//Title: Maximum Sub-sequence Product
//Type: DP
//Complexity: O(NlogN)
//Solution: Brute Force, this solution will give out every product by using a DP table without needing to multiply all different sets of numbers
		/*	Basically:
			Maximum_product = first number
			DP[100][100] (Table that stores all possible product)
			DP[0][0] = first number
			len = 0 (Amount of numbers in the sequence)
			for every new number in the sequence:
				len = len + 1
				for int i from 0 to < len:
					DP[len][i] = DP[len-1][i] * new number
					if Maximum_product < DP[len][i]:
						Maximum_product = DP[len][i]
				DP[len][len] = new number
				if Maximum_product < new number:
					Maximum_product = new number
			print Maximum_product
		*/
#include <cstdio>
#include <cstring>
//#include <ctime>
int len, C;
//time_t start, final;
//Why this BigInt again?
struct BigInt{
	int num[505], neg, len;
	void operator=(int n){
		if(n < 0){
			neg = 1;
			n *= -1;
		}
		while(n){
			num[len++] = n%10;
			n /= 10;
		}
	}
	void operator=(BigInt bi){
		memcpy(num, bi.num, sizeof(bi.num));
		neg = bi.neg;
		len = bi.len;
	}
	void reset(){
		memset(num, 0, sizeof(num));
		neg = len = 0;
	}
	BigInt operator*(BigInt bi){
		BigInt temp;
		temp.reset();
		if(!bi.len || !len)
			return temp;
		if(bi.neg) temp.neg = !neg;
		else temp.neg = neg;
		for(int i = 0; i < len; i++){
			for(int j = 0; j < bi.len; j++){
				temp.num[i+j] += num[i]*bi.num[j];
				temp.num[i+j+1] += temp.num[i+j]/10;
				temp.num[i+j] %= 10;
			}
		}
		for(int i = len + bi.len - 1; temp.num[i]; i++){
			temp.num[i+1] += temp.num[i]/10;
			temp.num[i] %= 10;
		}
		temp.len = len + bi.len;
		for(; temp.len > 0 && !temp.num[temp.len-1]; temp.len--);
		return temp;
	}
	bool operator>(BigInt bi){
		//Negatives
		if(neg && !bi.neg) return false;
		if(!neg && bi.neg) return true;
		//Length
		if(neg && len < bi.len) return true;
		if(neg && len > bi.len) return false;
		if(!neg && len > bi.len) return true;
		if(!neg && len < bi.len) return false;
		//Number
		for(int i = len-1; i >= 0; i--){
			if(num[i] != bi.num[i]){
				if(neg)
					return num[i] < bi.num[i];
				else
					return num[i] > bi.num[i];
			}
		}
		return false;
	}
	void print(){
		if(!len){
			printf("0");
			return;
		}
		if(neg) printf("-");
		for(int i = len-1; i >= 0; i--)
			printf("%d", num[i]);
	}
} prod[100][100], maxprod;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output O(N^2).txt", "w", stdout);
	//time(&start);
	while(~scanf("%d", &C)){
		if(C == -999999){
			memset(prod, 0, sizeof(prod));
			len = 0;
			maxprod.print();
			printf("\n");
			maxprod.reset();
			continue;
		}
		if(!len) maxprod = C;
		for(int i = 0; i < len; i++){
			BigInt temp;
			temp.reset();
			temp = C;
			prod[len][i] = (prod[len-1][i]*temp);
			if(prod[len][i] > maxprod){
				maxprod = prod[len][i];
			}
		}
		prod[len][len] = C;
		if(prod[len][len] > maxprod)
			maxprod = prod[len][len];
		len++;
	}
	//time(&final);
	//printf("Total time elapsed: %.f seconds\n", difftime(final, start));
	return 0;
}