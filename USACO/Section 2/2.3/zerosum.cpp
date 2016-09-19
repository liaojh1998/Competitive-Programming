/*
ID: liaojh11
PROG: zerosum
LANG: C++
*/
//Title: zerosum
//Type: DFS/Brute Force
//Solution: DFS all possible combinations and test? Simple brute force.
#include <fstream>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int N;
//Calculate total
void calc(int op[]){
	int total = 1, count = 2, tens = 0, sign = 0;
	for(int i = 0; i < N - 1; i++){
		if(op[i] == 1){
			if(i != 0){
				if(op[i - 1] == 1){
					if(!sign){
						total-= tens;
						tens = tens * 10 + count++;
						total+= tens;
					}else{
						total+= tens;
						tens = tens * 10 + count++;
						total-= tens;
					}
				}
				if(op[i - 1] == 2){
					total-= count - 1;
					tens = (count - 1) * 10 + count++;
					total+= tens;
					sign = 0;
				}
				if(op[i - 1] == 3){
					total+= count - 1;
					tens = (count - 1) * 10 + count++;
					total-= tens;
					sign = 1;
				}
			}else{
				total = total * 10 + count++;
				tens = total;
			}
		}
		if(op[i] == 2){
			total+= count++;
		}
		if(op[i] == 3){
			total-= count++;
		}
	}
	//Total is 0? Print
	if(!total){
		for(int i = 1; i <= N; i++){
			if(i == N){
				fout << i << endl;
				break;
			}
			fout << i;
			if(op[i - 1] == 1){
				fout << " ";
			}
			if(op[i - 1] == 2){
				fout << "+";
			}
			if(op[i - 1] == 3){
				fout << "-";
			}
		}
	}
}
//Simple DFS, time complexity O(3^(N-1))
void sum(int index, int s, int op[]){
	if(index == N - 1){
		calc(op);
		return;
	}
	op[index] = s;
	for(int i = 1; i <= 3; i++){
		sum(index + 1, i, op);
		if(index == N - 2) break;
	}
}
int main(){
	fin >> N;
	int op[N - 1];
	for(int i = 1; i <= 3; i++){
		sum(0, i, op);
	}
	return 0;
}