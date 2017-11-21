#include <bits/stdc++.h>
using namespace std;

template<typename T> class SuffixArray{
private:
	int* arr;
	int* SAf;
	size_t N;
	int ranking(const T& c){
		return c+1;
	}
	bool cmp(int a1, int a2, int b1, int b2){
		return a1 == b1 ? a2 <= b2 : a1 < b1;
	}
	bool cmp(int a1, int a2, int a3, int b1, int b2, int b3){
		return a1 == b1 ? cmp(a2, a3, b2, b3) : a1 < b1;
	}
	void radixPass(int* unsorted, int* sorted, int* rank, size_t size, size_t keycount){
		size_t freq[keycount + 1];
		memset(freq, 0, sizeof(freq));
		for(size_t i = 0; i < size; i++)
			freq[rank[unsorted[i]]]++;
		for(size_t i = 0, sum = 0; i <= keycount; i++){
			size_t t = freq[i];
			freq[i] = sum;
			sum += t;
		}
		for(size_t i = 0; i < size; i++)
			sorted[freq[rank[unsorted[i]]]++] = unsorted[i];
	}

public:
	SuffixArray(const T* a, size_t n){
		N = n;
		arr = new int[N+3];
		for(int i = 0; i < N; i++)
			arr[i] = ranking(a[i]);
		arr[N] = arr[N+1] = arr[N+2] = 0;
		SAf = new int[N];
	}
	~SuffixArray(){
		delete[] SAf;
		delete[] arr;
	}
	int& operator[](const size_t& i){
		return SAf[i];
	}
	void skewAlgorithm(int* s, int* SA, size_t size, size_t keycount){
		size_t n0 = (size+2)/3, n1 = (size+1)/3, n2 = size/3;
		size_t n02 = n0+n2;
		int s12[n02 + 3];
		s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
		int SA12[n02 + 3];
		SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
		int s0[n0];
		int SA0[n0];

		for(size_t i = 0, j = 0; i < size + (n0 - n1); i++)
			if(i%3) s12[j++] = i;

		radixPass(s12, SA12, s+2, n02, keycount);
		radixPass(SA12, s12, s+1, n02, keycount);
		radixPass(s12, SA12, s, n02, keycount);

		int name = 0, c0 = -1, c1 = -1, c2 = -1;
		for(int i = 0; i < n02; i++){
			if(s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2){
				name++;
				c0 = s[SA12[i]], c1 = s[SA12[i]+1], c2 = s[SA12[i]+2];
			}
			if(SA12[i]%3 == 1) s12[SA12[i]/3] = name;
			else s12[SA12[i]/3 + n0] = name;
		}

		if(name < n02){
			skewAlgorithm(s12, SA12, n02, name);
			for(int i = 0; i < n02; i++)
				s12[SA12[i]] = i + 1;
		}else
			for(int i = 0; i < n02; i++)
				SA12[s12[i] - 1] = i;
		
		for(size_t i = 0, j = 0; i < n02; i++)
			if(SA12[i] < n0)
				s0[j++] = 3*SA12[i];
		radixPass(s0, SA0, s, n0, keycount);

		for(size_t p = 0, t = n0 - n1, k = 0; k < size; k++){
			int i = SA12[t] < n0 ? SA12[t]*3 + 1 : (SA12[t] - n0)*3 + 2;
			int j = SA0[p];
			if(SA12[t] < n0 ?
			cmp(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
			cmp(s[i], s[i+1], s12[SA12[t] - n0 + 1], s[j], s[j+1], s12[j/3 + n0])){
				SA[k] = i;
				t++;
				if(t == n02)
					for(k++; p < n0; p++, k++)
						SA[k] = SA0[p];
			}else{
				SA[k] = j;
				p++;
				if(p == n0)
					for(k++; t < n02; t++, k++)
						SA[k] = SA12[t] < n0 ? SA12[t]*3 + 1 : (SA12[t] - n0)*3 + 2;
			}
		}
	}
	void exec(size_t keycount = 255){
		skewAlgorithm(arr, SAf, N, keycount+1);
	}
};

int main(){
	int n;
	cin >> n;
	while(n--){
		string result = "";
		string s;
		cin >> s;
		if(s.size() == 1){
			cout << "(" + s + ")" << endl;
			continue;
		}
		while(s.size() > 0) {
			SuffixArray<char> SA(s.c_str(), s.size());
			SA.exec();
			int index = 0;
			string tmp = s.substr(0, SA[index]);
			string tmp2 = s.substr(SA[index]);
			while(tmp == tmp2) {
				index++;
				tmp = s.substr(0, SA[index]);
				tmp2 = s.substr(SA[index]);
			}
			bool contains = false;
			for(int i = 0; i < tmp.size() && !contains; i++) {
				if(tmp[i] == '0') {
					contains = true;
				}
			}
			for(int i = 0; i < tmp2.size() && !contains; i++) {
				if(tmp2[i] == '0') {
					contains = true;
				}
			}
			if(!contains) {
				tmp2 = s;
				tmp = "";
			}

			result = "(" + tmp2 + ")" + result;
			s = tmp;
		}
		cout << result << endl;
	}
	return 0;
}