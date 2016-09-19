//Title: Self-numbers 2
//Type: Math
//Solution: Simulate the problem forcefully is fine, but using bool[10^7] will insta-MLE. This problem focuses on using extra time for less memory usage.
		/*	This solution don't even need extra time.
			We know that the maximum amount of d(i) - i under 10^7 limit is 9999999, which is 63. We can create a moving bool sized 64 storage to check if the number is a self-number.
			How this works?
			Initiate the self array, and notice that false means it is a self-number, true means that it is not a self-number.
			Pseudocode:
			For all numbers from 1 to N
				If current number % 64 is a self-number, we add it into our answer.
				Make current number % 64 the self-number, since all starting numbers are self-numbers (e.g. 1, 3, 5)
				Make the d(i) number % 64 non self-number.
			Why would the storage work and not repeat? Because multiple numbers can create same d(i) and no numbers can add more than 63.
			*/
#include <cstdio>
#include <algorithm>
struct n {int id, num;} num[5000];
int N, K, array[10001], count, numindex, ans[5000];
bool self[64];
int cmp(n n1, n n2){
	return n1.num < n2.num;
}
int main(){
	//Instantiation;
	scanf("%d %d\n", &N, &K);
	for(int i = 0; i < K; i++){
		num[i].id = i;
		scanf("%d", &num[i].num);
	}
	std::sort(num, num + K, cmp);
	//Array for d(i) function
	for(int i = 0; i < 10001; i++){
		array[i] = array[i/10] + i % 10;
	}
	//Search for self numbers
	for(int i = 1; i <= N; i++){
		if(!self[i % 64]){
			count++;
			while(num[numindex].num == count){
				num[numindex++].num = i;
			}
		}
		self[i % 64] = false;
		self[(i + array[i/10000] + array[i%10000]) % 64] = true;
	}
	for(int i = 0; i < K; i++){
		ans[num[i].id] = num[i].num;
	}
	//Print answer
	printf("%d\n", count);
	for(int i = 0; i < K; i++){
		if(i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}