/*
ID: liaojh11
PROG: msquare
LANG: C++
*/
//Title: msquare
//Type: BFS
//Solution: I really wouldn't call this a shortest path problem, because the "path" to desired state is not really on a comparable scale using methods A, B, C.
		/*	However, knowing that solution have as much as 40320 combinations, or 8!, makes this BFS possible. A DFS can work just fine.
			Note: There's no solution that required more than 60-sized string paths. Even USACO solution neglected this criteria on the problem.
			This also means that all solutions will most likely stay under the time limit.
			*/
#include <fstream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
ifstream fin("msquare.in");
ofstream fout("msquare.out");
bool mapped[40320] = {false};
typedef struct{int board[8], count; string path;} trans;
int cboard[8];
queue<trans> boards;
//Stolen from official solution, this hashing is definitely something to learn.
bool encode(int *board){
	static int mult[8] = {1, 8, 8*7, 8*7*6, 8*7*6*5, 8*7*6*5*4, 8*7*6*5*4*3, 8*7*6*5*4*3*2};
	/* used to calculate the position of a number within the remaining ones */
	int look[9] = {0, 1, 2, 3, 4, 5, 6, 7, 0};
	int rlook[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	/* rlook[look[p]] = p and look[rlook[p]] = p */
	int hash = 0;
	for(int i = 0; i < 8; i++){
		int t = look[board[i]]; /* the rank of the board position */
		hash += t * mult[i];
		/* delete t */
		look[rlook[7-i]] = t;
		rlook[t] = rlook[7-i];
	}
	if(mapped[hash]) return true;
	else{
		mapped[hash] = true;
		return false;
	}
}
//Method A
void A(int *inboard, int count, string path){
	int board[8];
	for(int i = 0; i < 8; i++){
		board[i] = inboard[7-i];
	}
	if(!encode(board)){
		trans temp;
		memcpy(temp.board, board, sizeof(board));
		temp.count = count + 1;
		temp.path = path + "A";
		boards.push(temp);
	}
}
//Method B
void B(int *inboard, int count, string path){
	int board[8];
	board[0] = inboard[3], board[7] = inboard[4];
	for(int i = 1; i <= 3; i++){
		board[i] = inboard[i-1];
		board[3+i] = inboard[4+i];
	}
	if(!encode(board)){
		trans temp;
		memcpy(temp.board, board, sizeof(board));
		temp.count = count + 1;
		temp.path = path + "B";
		boards.push(temp);
	}
}
//Method C
void C(int *inboard, int count, string path){
	int board[8];
	board[0] = inboard[0];
	board[3] = inboard[3];
	board[4] = inboard[4];
	board[7] = inboard[7];
	board[1] = inboard[6];
	board[2] = inboard[1];
	board[5] = inboard[2];
	board[6] = inboard[5];
	if(!encode(board)){
		trans temp;
		memcpy(temp.board, board, sizeof(board));
		temp.count = count + 1;
		temp.path = path + "C";
		boards.push(temp);
	}
}
//Difference between this solution and USACO solution is that this one went from initial to desired, not the reverse.
bool check(int *board){
	bool done = true;
	for(int i = 0; i < 8; i++){
		if(board[i] != cboard[i])
			done = false;
	}
	return done;
}
int main(){
	//Instantiation
	for(int i = 0; i < 8; i++){
		fin >> cboard[i];
	}
	trans t;
	int board[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	memcpy(t.board, board, sizeof(board)); //Initial position
	t.count = 0;
	t.path = "";
	encode(t.board);
	//BFS Queue
	boards.push(t);
	while(!boards.empty()){
		trans temp = boards.front();
		boards.pop();
		//If path found, print results
		if(check(temp.board)){
			fout << temp.count << endl;
			fout << temp.path << endl;
			return 0;
		}
		A(temp.board, temp.count, temp.path);
		B(temp.board, temp.count, temp.path);
		C(temp.board, temp.count, temp.path);
	}
	return 0;
}