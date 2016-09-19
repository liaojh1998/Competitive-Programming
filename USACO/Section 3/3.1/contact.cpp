/*
ID: liaojh11
PROG: contact
LANG: C++
*/
//Title: contact
//Type: Ad Hoc
//Solution: Brute Force all strings, these strings can be converted into bit integers.
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
FILE *fin, *fout;
int A, B, N;
typedef struct {int value; int freq; int len;} rec;
string input;
rec R[10000];
//Binary number conversion
int bin(string s, int len){
	int binary = (s.at(0) - 48) & 1;
	for(int i = 1; i < len; i++){
		if(!((s.at(i) - 48) & 1)) binary <<= 1;
		else{
			binary <<= 1;
			binary++;
		}
	}
	return binary;
}
//Compare for qsort
int compare(const void *a, const void *b){
	rec ra = (*(rec *)a), rb = (*(rec *)b);
	if(ra.freq == rb.freq){
		if(ra.len == rb.len)
			return (ra.value > rb.value) ? 1 : -1;
		else
			return (ra.len > rb.len) ? 1 : -1;
	}
	return (ra.freq > rb.freq) ? -1 : 1;
}
int main(){
	//Instantiation
	fin = fopen("contact.in", "r");
	fout = fopen("contact.out", "w");
	fscanf(fin, "%d %d %d\n", &A, &B, &N);
	int count = 0;
	char c;
	while ((c = getc(fin)) != EOF)
		if (c != 10 && c != 13){
			input += c;
			count++;
		}
	//Find recurrences and store recurrence in map
	int possible = 0, index = 0;
	for(int i = A; i <= B; i++){
		map<int, int> m;
		for(int j = 0; j <= count - i; j++){
			int value = bin(input.substr(j, i), i);
			if(!m.count(value)){
				m[value] = 1;
				possible++;
			}
			else
				m[value]++;
		}
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
			R[index].value = it->first;
			R[index].freq = it->second;
			R[index].len = i;
			index++;
		}
	}
	qsort(R, possible, sizeof(rec), compare);
	//Print results
	int f = 200001, start = 0, cnt = 1;
	while(N != 0 && possible){
		if(R[start].freq != f){
			fprintf(fout, "%d\n", R[start].freq);
			f = R[start].freq;
			cnt = 1;
		}
		for(int i = R[start].len - 1; i >= 0; i--){
			bool bit = (1 << i) & R[start].value;
			fprintf(fout, "%d", bit);
		}
		possible--;
		if(possible && R[start+1].freq == f){
			if(!(cnt % 6))
				fprintf(fout, "\n");
			else
				fprintf(fout, " ");
			cnt++;
		}else{
			fprintf(fout, "\n");
			N--;
		}
		start++;
	}
	return 0;
}

/* USACO bit reading version for this problem is op */