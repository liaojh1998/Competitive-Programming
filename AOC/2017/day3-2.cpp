#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("day3.in");
	ofstream fout("day3-2.out");
	long long sq = 5, in, out = 0;
	fin >> in;
	while(sq*sq <= in)
		sq += 2; //ultra rough estimate :)
	int arr[sq][sq]; //actual implementation now?!
	memset(arr, 0, sizeof(arr));
	int mid = sq/2;
	arr[mid][mid] = 1;
	int rdir[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	int cdir[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	for(int i = 1; i <= mid && !out; i++){
		for(int j = i-1; j >= -i && !out; j--){
			//cout << mid+j << " " << mid+i << endl;
			for(int k = 0; k < 8; k++){
				arr[mid+j][mid+i] += arr[mid+j+rdir[k]][mid+i+cdir[k]];
				//cout << arr[mid+j+rdir[k]][mid+i+cdir[k]] << " ";
			}
			if(arr[mid+j][mid+i] > in)
				out = arr[mid+j][mid+i];
			//cout << endl << arr[mid+j][mid+i] << endl;
		}
		for(int j = i-1; j >= -i && !out; j--){
			//cout << mid-i << " " << mid+j << endl;
			for(int k = 0; k < 8; k++){
				arr[mid-i][mid+j] += arr[mid-i+rdir[k]][mid+j+cdir[k]];
				//cout << arr[mid-i+rdir[k]][mid+j+cdir[k]] << " ";
			}
			if(arr[mid-i][mid+j] > in)
				out = arr[mid-i][mid+j];
			//cout << endl << arr[mid-i][mid+j] << endl;
		}
		for(int j = -(i-1); j <= i && !out; j++){
			//cout << mid+j << " " << mid-i << endl;
			for(int k = 0; k < 8; k++){
				arr[mid+j][mid-i] += arr[mid+j+rdir[k]][mid-i+cdir[k]];
				//cout << arr[mid+j+rdir[k]][mid-i+cdir[k]] << " ";
			}
			if(arr[mid+j][mid-i] > in)
				out = arr[mid+j][mid-i];
			//cout << endl << arr[mid+j][mid-i] << endl;
		}
		for(int j = -(i-1); j <= i && !out; j++){
			//cout << mid+i << " " << mid+j << endl;
			for(int k = 0; k < 8; k++){
				arr[mid+i][mid+j] += arr[mid+i+rdir[k]][mid+j+cdir[k]];
				//cout << arr[mid+i+rdir[k]][mid+j+cdir[k]] << " ";
			}
			if(arr[mid+i][mid+j] > in)
				out = arr[mid+i][mid+j];
			//cout << endl << arr[mid+i][mid+j] << endl;
		}
	}
	fout << out << endl;
	return 0;
}
