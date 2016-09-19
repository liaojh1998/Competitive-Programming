//Problem: High Card Wins (Silver)
//Type: Simulation
//Solution: Search for all cards that bessie can be bigger than elsie's smallest cards
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("highcard.in");
ofstream fout("highcard.out");
int N, card[100001];
vector<int> bessie, elsie;
int main(){
	//Instantiation
	fin >> N;
	for(int i = 0; i < N; i++){
		int temp;
		fin >> temp;
		card[temp] = 1;
	}
	for(int i = 1; i <= 2*N; i++){
		if(card[i])
			elsie.push_back(i);
		else
			bessie.push_back(i);
	}
	//Search for all cards that can be bigger than elsie's smallest cards
	int i = 0, j = 0, points = 0;
	while(i < N && j < N){
		if(bessie[j] > elsie[i]){
			points++;
			i++;
			j++;
		}else
			j++;
	}
	//Print results
	fout << points << endl;
	return 0;
}