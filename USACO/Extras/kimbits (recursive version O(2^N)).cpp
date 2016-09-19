/*
ID: liaojh11
PROG: kimbits
LANG: C++
*/
//Title: kimbits
//Type: DP (Made this naive brute force recursive descent for checks, O(2^sizeof(S)))
//Solution: 
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbitss.out");
int N, L;
long long I;
int onescount(long long num){
	int count = 0, i = 1;
	while(i <= num){
		if(i & num) count++;
		i <<= 1;
	}
	return count;
}
int smallestone(long long num){
	int i = 1;
	while(i <= num){
		if(i & num) return i;
		i <<= 1;
	}
	return 0;
}
int main(){
	//Instantiation
	fin >> N >> L >> I;
	long long num = 0;
	I--;
	while(I > 0){
		if(onescount(num) < L) num += 1;
		else num += smallestone(num);
		I--;
	}
	char str[N];
	for(int i = 0; i < N; i++){
		str[i] = '0';
	}
	long long check = 1 << (N - 1);
	for(int i = 0; i < N; i++){
		if((check >> i) & num)
			fout << 1;
		else
			fout << 0;
	}
	fout << endl;
	return 0;
}