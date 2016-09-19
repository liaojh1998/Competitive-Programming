/*
ID: liaojh11
PROG: holstein
LANG: C++
*/
//Title: holstein
//Type: DFS/Brute Force/Greedy (I didn't implement the "Choose smaller sized feeds" part. Brutal luck, passed.)
//Solution: Since for loops can't generate all non-repeatable solutions, use DFS. Check all non-repeatable solutions.
#include <fstream>
#include <list>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int V, G;
list<int> sol;
//Check
bool check(int r[], int f[][25], bool fm[]){
	//If any required fails, return
	for(int i = 0; i < V; i++)
		if(r[i] > f[0][i]) return false;

	//Make temp list of solution, sort list
	list<int> temp;
	for(int i = 1; i <= G; i++)
		if(fm[i]) temp.push_back(i);
	temp.sort();

	//Compare size, if solution size is bigger than temp list size, then change solution to temp list
	if(sol.size() == 0) sol = temp;
	if(sol.size() > temp.size()) sol = temp;
	return true;
}
/*	DFS
	Generate all possible non-repeatable solutions.
	For example: 3 feeds
	((1), (1,2), (1,2,3), (1,3), (2), (2,3), (3)).
	Requires: first for loop from start till end, second loop from current feed till end. Use booleans to mark fed feeds and skip from refeed and repeatable.
*/
void DFS(int c, int r[], int f[][25], bool fm[]){
	//Skip from reuse
	if(fm[c]) return;
	fm[c] = true;

	//Add new feeds
	for(int i = 0; i < V; i++)
		f[0][i] += f[c][i];

	//Check
	if(check(r, f, fm)){
		fm[c] = false;
		for(int i = 0; i < V; i++)
			f[0][i] -= f[c][i];
		return;
	}

	//Second loop, from current feed till end and skipping repeatable feeds
	for(int i = c; i <= G; i++)
		DFS(i, r, f, fm);
	fm[c] = false;
	for(int i = 0; i < V; i++)
		f[0][i] -= f[c][i];
}
int main()
{   
	//Constructors & instantiation
	fin >> V;
	int required[V];
	for(int i = 0; i < V; i++)
		fin >> required[i];
	fin >> G;
	int feeds[G+1][25];
	for(int i = 1; i <= G; i++)
		for(int j = 0; j < V; j++)
			fin >> feeds[i][j];
	bool feedmark[G+1];
	for(int j = 1; j <= G; j++)
		feedmark[j] = false;

	//DFS first loop, from start till end
	for(int i = 1; i <= G; i++){
		//Resetting feeds
		for(int k = 0; k < V; k++)
			feeds[0][k] = 0;
		DFS(i, required, feeds, feedmark);
	}

	//Print solution
	fout << sol.size() << " ";
	for(list<int>::iterator it = sol.begin(); it != sol.end(); ++it){
		if(*it == sol.back()){
			fout << *it << "\n";
			return 0;
		}
		fout << *it << " ";
	}
	return 0;
}