/*
ID: liaojh11
PROG: contact
LANG: C++
*/
//Title: contact
//Type: Ad Hoc
//Solution: Brute Force all strings, these strings can be converted into bit integers for comparison.
#include <fstream>
#include <list>
#include <string>
#include <map>
using namespace std;
ifstream fin("contact.in");
ofstream fout("contact.out");
int A, B, N;
typedef struct {string s; int freq, len;} rec;
string input;
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
bool cmp (const rec &a, const rec &b){
	if(a.freq == b.freq){
		if(a.len == b.len)
			return bin(b.s, b.len) > bin(a.s, b.len);
		else
			return b.len > a.len;
		}
	return a.freq > b.freq;
}
int main(){
	//Instantiation
	fin >> A >> B >> N;
	char c;
	while (!fin.eof()){
		string s;
		getline(fin, s);
		if(!input.size()) input = s;
		else input += s;
	}
	//Find recurrences
	list<rec> R;
	int possible = 0, index = 0;
	for(int i = A; i <= B; i++){
		if(i > input.size()) break;
		map<string, int> m;
		for(int j = 0; j <= input.size() - i; j++){
			if(!m.count(input.substr(j, i))){
				m[input.substr(j, i)] = 1;
				possible++;
			}
			else
				m[input.substr(j, i)]++;
		}
		rec temp;
		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
			temp.s = it->first;
			temp.freq = it->second;
			temp.len = i;
			R.push_back(temp);
		}
	}
	R.sort(cmp);
	int f = 200001;
	int count = 1;
	while(N != 0 && !R.empty()){
		rec temp = R.front();
		R.erase(R.begin());
		if(temp.freq != f){
			fout << temp.freq << endl;
			f = temp.freq;
			count = 1;
		}
		fout << temp.s;
		if(!R.empty() && R.front().freq == f){
			if(!(count % 6))
				fout << "\n";
			else
				fout << " ";
			count++;
		}
		else{
			fout << endl;
			N--;
		}
	}
	return 0;
}