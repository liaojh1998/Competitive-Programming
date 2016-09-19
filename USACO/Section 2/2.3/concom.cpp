/*
ID: liaojh11
PROG: concom
LANG: C++
*/
//Title: concom
//Type: BFS
//Solution: We'll immediately insert the first rule. To proceed to the second rule and third rule, we'll move in this order:
		/*  Vertical iteration of stock adding so we can search on those newly added stocks.
			Horizontal iteration of stock adding so we can search on those newly added stocks.
			Every iteration will fill itself with a recursion of vertical and horizontal iteration of stock adding until solution.
			*/
#include <fstream>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
//ofstream debug("concom.txt");
int N, i, j, p, B[101][101] = {0}, C[101][101] = {0}; //B for boolean, who controls. C for company stocks.
void search(int h, int s){
	if(B[h][s]) return; //We already know m company owns n.
	B[h][s] = 1;

	//Record all m companies that own h now also own s. (Vertical)
	for(int m = 1; m <= 100; m++){
		if(B[m][h])
			search(m, s);
	}

	//This is the horizontal iterations of owning
	for(int m = 1; m <= 100; m++){
		C[h][m]+= C[s][m]; //m now owns all stock n owns.
	}

	//Look at the newly added stocks and see what h now newly owns. (Horizontal)
	for(int m = 1; m <= 100; m++){
		if(C[h][m] > 50)
			search(h, m);
	}
}
int main(){
	//Instantiation
	fin >> N;
	//First rule: Same companies own themselves
	for(int m = 1; m <= 100; m++){
		B[m][m] = 1;
	}
	//Second and third rules:
	for(int m = 1; m <= N; m++){
		fin >> i >> j >> p;
		//All that owns i now owns j stocks as well. (This is the vertical iterations of owning)
		//For a first iteration, it loops itself, which means itself owns j stocks only.
		for(int k = 1; k <= 100; k++){
			if(B[k][i])
				C[k][j]+= p;
		}
		//Now record which of those k owns j stocks more than 50%. (Search vertically)
		for(int k = 1; k <= 100; k++){
			if(C[k][j] > 50)
				search(k, j);
		}
	}
	/*
	//Debug
	for(int m = 0; m <= 100; m++){
		for(int n = 0; n <= 100; n++){
			if(m == 0){
				debug << "[" << n << "]";
				continue;
			}else if(n == 0){
				debug << "[" << m << "]";
			}else{
				debug << "[" << C[m][n] << "]";
			}
		}
		debug << endl;
	}
	*/
	//Result
	for(int m = 1; m <= 100; m++){
		for(int n = 1; n <= 100; n++){
			if(m != n && B[m][n]) fout << m << " " << n << endl;
		}
	}
	return 0;
}