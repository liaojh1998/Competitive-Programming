/*
ID: liaojh11
PROG: subset
LANG: C++
*/
//Title: subset
//Type: DFS Version (not the correct solution, correct one requires DP)
//Solution: Made this for checks. O(N*2^N)
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
FILE *fin = fopen("subset.in", "r");
//FILE *fouttxt = fopen("subset.txt", "w");
FILE *fout = fopen("subset.out", "w");
int N, sum, ans = 0;
//list< list<int> > l;
void DFS(int start, bool used[], int total){
	if(used[start]) return;
	used[start] = true;

	total += start;

	if(total > sum){
		total-= start;
		used[start] = false;
		return;
	}
	if(total == sum){
	//	list<int> temp;
	//	list<int> temp2;
		int tempsum = 0;
		for(int i = 1; i <= N; i++){
	//		if(used[i]) temp.push_back(i);
			if(!used[i]){
				tempsum += i;
	//			temp2.push_back(i);
			}
		}
		if(tempsum != sum){
			used[start] = false;
			total-= start;
			return;
		}
	//	l.push_back(temp);
	//	l.push_back(temp2);
		ans++; //Note: Starting from 1 and DFSing down, all solutions are already considered; there's no need to DFS all. Just add 1
		       //to answer and the solution is still the same as list.size()/2;
		used[start] = false;
		total-= start;
		return;
	}

	for(int i = start; i <= N; i++){
		DFS(i, used, total);
	}
	used[start] = false;
	total-= start;
}
int main()
{   
	//Constructor and instantiation
	fscanf(fin, "%d", &N);
	bool B[N+1];
	sum = (N+1)*N/4;
	for(int i = 1; i <= N; i++){
		B[i] = false;
	}
	//DFS
	DFS(1, B, 0);
	//Data
/*	for(list< list<int> >::iterator it = l.begin(); it != l.end(); ++it){
		fprintf(fouttxt, "[");
		for(list<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
			if(*it2 == it->back()){
				fprintf(fouttxt, "%i", *it2);
				continue;
			}
			fprintf(fouttxt, "%i, ", *it2);
		}
		fprintf(fouttxt, "]\n");
	}
	*/
	//Final Answer
	cout << ans;
	fprintf(fout, "%d\n", ans);
	return 0;
}