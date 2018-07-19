#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

bool cmp(int a, int b){
	return a < b;
}

void merge_sort(int* a, int lo, int hi){
	if(lo != hi){
		int mid = (lo+hi)/2, len1 = mid-lo+1, len2 = hi-mid;
		int arr1[len1], arr2[len2];
		for(int i = lo; i <= mid; i++)
			arr1[i] = a[i];
		for(int i = mid+1; i <= hi; i++)
			arr2[i] = 
		merge_sort(arr1, lo, mid);
		merge_sort(arr2, mid+1, hi);
		int i = 0, j = 0;
		while(i < len1 && j < len2) a[i+j] = cmp(arr1[i], arr2[j]) ? arr1[i++] : arr2[j++];
		while(i < len1) a[i+j] = arr1[i++];
		while(j < len2) a[i+j] = arr2[j++];
	}
}


int main(){
	int n, a, b;
	scanf("%d", &n);
	int arr[n], diff[n];
	for(int i = 0; i < n; i++)
		scanf("%d", & arr[i]);
	merge_sort(arr, 0, n-1);
	for(int i = 0; i < n; i++)
		printf("%d%s", arr[i], i == n-1 ? "\n" : " ");
	for(int i = 1; i < n; i++)
		diff[i-1] = arr[i]-arr[i-1];
	n--;
	int div = diff[0];
	for(int i = 1; i < n; i++)
		div = gcd(div, diff[i]);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += diff[0]/div-1;
	printf("%d\n", ans);
	return 0;
}