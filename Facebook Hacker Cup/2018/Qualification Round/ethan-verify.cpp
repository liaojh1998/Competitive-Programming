#include <bits/stdc++.h>
using namespace std;

bool bf(const string& A, const string& B){
	int bsize = B.size();
	int asize = A.size();
	bool has = false;
	for(int i = 0; i < bsize && !has; i++){
		int j = 0, k = i;
		while(j < asize && k < bsize && A[j] == B[k]){
			j++;
			k++;
		}
		if(j == asize)
			has = true;
	}
	return has;
}

bool ethan(const string& A, const string& B){
	int i = 0;
	int j = 0;
        int asize = A.size();
        int bsize = B.size();
        while(i < asize && j < bsize){
                if(A[i] == B[j]){
                        i++;
                        j++;
                }else if(i == 0)
                        j++;
                else
                        i = 0;
        }
        if(i == asize)
                return true;
        return false;
}

int main(){
	ifstream fin1("ethan_searches_for_a_string.txt");
	ifstream fin2("ethan_searches_for_a_string-out.txt");
	int T;
	fin1 >> T;
	for(int index = 1; index <= T; index++){
		string search, str;
		fin1 >> search;
		fin2 >> str >> str >> str;
		cout << "Case #" << index << ": ";
		if(str == "Impossible")
			cout << "Impossible: " << search << endl;
		else
			cout << "Ethan:" << ethan(search, str) << " Actual:" << bf(search, str) << endl;
	}
	return 0;
}
