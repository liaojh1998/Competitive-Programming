/*
ID: liaojh11
PROG: runround
LANG: C++
*/
//Title: runround
//Type: Brute Force/Greedy
//Solution: Unless there's some trick to this? I think there's DP and generating runarounds but none other than those.
#include <fstream>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");
unsigned long int M;
//Basic Runaround check
bool check(unsigned long int num, bool mark[], int count){
	int index = 0;
	while(!mark[0] || index != 0){
		if(mark[index]) return false;
		mark[index] = true;
		int pow = 1;
		for(int i = count - index - 1; i >= 1; i--)
			pow*= 10;
		int digit = num/pow%10;
	
		for(int i = digit; i >= 1; i--){
			if(index != count-1) index++;
			else index = 0;
		}
	}
	
	for(int i = 0; i < count; i++){
		if(!mark[i]) return false;
	}
	return true;
}
int main()
{   
	//Constructor and instantiation
	fin >> M;
	//Loop every number bigger than M
	bool done = false;
	unsigned long int num = M;
	while(!done){
		num++;
		int count = 0;
		unsigned long int temp = num;
		//If number doesn't have a digit more than once, and has no 0 in it, then it's unique
		int unique[10] = {0};
		bool u = false;
		while(temp != 0){
			if(unique[temp%10]) u = true;
			if(temp%10 == 0) u = true;
			unique[temp%10] = true;
			temp/=10;
			count++;
		}
		if(u) continue;
		bool mark[count] = {0};
		//test this unique number
		done = check(num, mark, count);
	}
	fout << num << endl;
	return 0;
}