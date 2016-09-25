//Title: Maximum Sub-sequence Product
//Type: DP
//Complexity: O(N)
//Solution: To improve from the brute force solution, I think anyone can realize based on absolute value and the fact that negative
		/*	numbers times negative numbers will end up being positive. This solution basically finds the maximum positive product that can be found
			while searching for the maximum negative product that can be found.
			Proof:
				Positive / Negative != Negative

			For all subsequences, they must be continuous and the absolute value of their product will always be bigger or equal than the products before.
			Proof:
				Because they are integers, there are no fractions or decimals.
				Thus,
					|Numbers[i] * Numbers[i+1]| >= Numbers[i]
					Numbers[i] !> |Numbers[i] * Numbers[i+1]|
				A contradiction of this proof happens where Numbers[i+1] = 0

			However, for all other numbers other than the contradiction, we know for sure that
				The absolute value of the maximum product begins on a number which does not equal to 0 and ends at the next number = 0.

			With that out of the way, we know all we need to do is search between 0s.
			We can start with any number that's either at the beginning that's not a 0, or a Number[i+1] that's not 0 but next to Number[i] = 0.
			Since we know |Numbers[i] * Numbers[i+1]| >= Numbers[i], we can keep track of the maximum positive product and maximum negative product at N[i].
			
			For example:
				1 -2 3 -4
			At 1, we have maximum positive of 1, maximum negative of 1, and maximum product of 1
			At -2, we have -2, -2, 1
			At 3, we have 3, -6, 3, notice that the maximum positive product can have a size of 1, which is basically 3 itself.
			At -4, we have 24, -12, 24, notice how -6 * -4 = 24, which is the maximum positive product, and 3 * -4 = -12, which is the maximum negative product.
			In effect, when we meet a positive number, we multiply both products accordingly and compare it with the positive number to determine the maximum positive product.
			When we meet a negative number however, we multiply both products accordingly and change the positive max with the negative max because they have changed signs,
			and we'll compare the negative number to determine the maximum negative product.
			Notice how at case -2, -2 * 3 is not the maximum positive product but 3 is, the same case lies with maximum negative product.
			What happens then when we meet a 0?
			Simply change maximum positive and maximum negative to the next number that's not 0.
			Because subsequences must be continuous, any product before * 0 now will always = 0, so we always start with some new number.
			Thus, we have the O(N) solution:

				Maximum_product = Maximum_Pos_product = Maximum_Neg_product = Number[0] // First number
				for i = 1 of Number[i] to all Numbers:
					if Maximum_Pos_product == 0:
						Maximum_Pos_product = Maximum_Neg_product = Number[i]
					//Notice that we only need to see if the Maximum_Pos_product == 0 because by automatic assumption what it has multiplied before must be 0
					//Therefore the Maximum_Neg_product also had multiplied by 0 and thus it should also == 0
					else: //After ridding of the 0 exception
						if Number[i] >= 0:
							New_Maximum_Pos_product = Maximum_Pos_product * Number[i]
							New_Maximum_Neg_product = Maximum_Neg_product * Number[i]
						else: //Negative case
							New_Maximum_Pos_product = Maximum_Neg_product * Number[i]
							New_Maximum_Neg_product = Maximum_Pos_product * Number[i]
						//The reason why we make new product first before putting them in is crucial
						//One would not wish to change the Maximum_Pos_product in the negative case then using that to change the Maximum_Neg_product
						Maximum_Pos_product = Max(New_Maximum_Pos_product * Number[i], Number[i])
						Maximum_Neg_product = Min(New_Maximum_Neg_product * Number[i], Number[i])
					//Compare with the Maximum product
					Maximum_product = Max(Maximum_product, Maximum_Pos_product)
				Print Maximum_product

			And that concludes this solution.
			Notice too that this solution works even for decimals or fractions, because if decimals * decimals < decimals, we've made the Max function to take only
			the current decimal that its on. */
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
}maxprod, submax, submin, newmax, newmin;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output O(N).txt", "w", stdout);
	//time(&start);
	while(~scanf("%d", &C)){
		if(C == -999999){
			len = 0;
			maxprod.print();
			printf("\n");
			maxprod.reset();
			continue;
		}
		if(!len++){
			maxprod = C;
			submax = maxprod;
			submin = maxprod;
		}else{
			BigInt temp;
			temp.reset();
			temp = C;
			if(!submax.len){
				submax = temp;
				submin = temp;
			}else{
				if(C >= 0){
					newmax = submax * temp;
					newmin = submin * temp;
				}else{
					newmax = submin * temp;
					newmin = submax * temp;
				}
				submax = newmax > temp ? newmax : temp;
				submin = newmin > temp ? temp : newmin;
			}
			if(submax > maxprod)
				maxprod = submax;
		}
	}
	//time(&final);
	//printf("Total time elapsed: %.f seconds\n", difftime(final, start));
	return 0;
}