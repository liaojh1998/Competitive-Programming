#include <bits/stdc++.h>

using namespace std;

template<typename T> class FenTree{
private:
	T* fwt;
	size_t N;
	T applyfunc(const T& a, const T& b){
		return a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}

public:
	FenTree(size_t n){
		N = n + 1;
		fwt = new T[N]();
	}
	~FenTree(){
		delete[] fwt;
	}
	void update(size_t i, const T& value){
		for(i++; i < N; i += (i & -i))
			fwt[i] = applyfunc(fwt[i], value);
	}
	T query(size_t i){
		T ans = 0;
		for(i++; i; i &= (i - 1))
			ans = queryfunc(ans, fwt[i]);
		return ans;
	}
};

int main(){
	int n, b;
	scanf("%d%d", &n, &b);
	int arr[n+5];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int index = -1;
	for(int i = 0; i < n && index == -1; i++)
		if(arr[i] == b)
			index = i;
	int result = 1;
	unordered_map<int, int> left, right;
	FenTree<int> leftbit(100005), rightbit(100005);
	for(int i = index-1; i >= 0; i--){
		leftbit.update(arr[i], 1);
		int less = leftbit.query(b - 1);
		int more = leftbit.query(100005) - leftbit.query(b);
		int total = less - more;
		left[total]++;
	}
	for(int i = index+1; i < n; i++){
		rightbit.update(arr[i], 1);
		int less = rightbit.query(b - 1);
		int more = rightbit.query(100005) - rightbit.query(b);
		int total = less - more;
		right[total]++;
	}
	for(unordered_map<int, int>::iterator it = left.begin(); it != left.end(); it++){
		result += (*it).second*right[-(*it).first];
	}
	printf("%d\n", result);
	return 0;
}