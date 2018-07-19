//Longest Common Prefix Kasai's Algorithm Template
//http://alumni.cs.ucr.edu/~rakthant/cs234/01_KLAAP_Linear%20time%20LCP.PDF
//http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.385.9210&rep=rep1&type=pdf
#include <bits/stdc++.h>
using namespace std;

//Builds Longest Common Prefix from the Suffix Array in Linear Time
template<typename T> class LongestCommonPrefix{
private:
	int* arr; //Array of objects
	int* LCP; //Longest Common Prefix Array
	int* SA; //Actual Suffix Array
	size_t N; //Size of array

	//Change this for ranking of nodes, make sure it returns an int
	//Currently for ASCII
	int rank(const T& c){
		return c+1;
	}

public:
	//Useful functions
	//Constructors: a - array, sa - suffix array N - size of array
	LongestCommonPrefix(T* a, int* sa, size_t n){
		N = n;
		arr = new int[N];
		SA = new int[N];
		LCP = new int[N];
		for(int i = 0; i < N; i++){
			arr[i] = rank(a[i]);
			SA[i] = sa[i];
		}
	}
	//When SA and arr are already made, simply just pass memory address
	LongestCommonPrefix(int* a, int* sa, size_t n){
		N = n;
		arr = a;
		SA = sa;
		LCP = new int[N];
	}
	//Destructor
	~LongestCommonPrefix(){
		delete[] arr;
		delete[] LCP;
		delete[] SA;
	}
	//Longest Common Prefix accessor
	int& operator[](const size_t& i){
		return LCP[i];
	}

	//Longest Common Prefix Kasai's algorithm execution
	//Runtime: O(N)
	//Refer to research papers for explanations
	void exec(){
		int s[N]; //Suffix Array Inverse
		for(size_t i = 0; i < N; i++)
			s[SA[i]] = i;
		int lcp = 0;
		for(size_t i = 0; i < N; i++)
			if(s[i] > 0){
				size_t j = SA[s[i]-1];
				while(i + lcp < N && j + lcp < N && arr[i + lcp] == arr[j + lcp]) lcp++;
				LCP[s[i]] = lcp;
				if(lcp) lcp--;
			}
		LCP[0] = 0; //LCP[0] = 0 always
	}
};

int main(){
	//Enter code here
	return 0;
}