#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10005];

int n;

int numberOfcomparisons = 0;

int determineMedian(int i, int j, int k) {
	if((a[i] >= a[j] && a[i] <= a[k]) || (a[i] >= a[k] && a[i] <= a[j])) return i;
	if((a[j] >= a[i] && a[j] <= a[k]) || (a[j] >= a[k] && a[j] <= a[i])) return j;
	return k;
}

void QuickSortMedianPivot(int l, int r) {
	if(r-l+1 == 1) return;
	numberOfcomparisons += (r-l);
	//cout<<"Start - "<<l<<", End - "<<r<<endl;
	int pivotIndex = determineMedian(l, (l+r)/2, r);
	swap(a[l], a[pivotIndex]);
	int p = a[l];
	int i = l + 1;
	for(int j = l + 1; j <= r; j++) {
		if(p > a[j]) {
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[l], a[i - 1]);
	if(l < i - 2) QuickSortMedianPivot(l, i - 2);
	if(i  < r) QuickSortMedianPivot(i, r);
}

int main() {
	
	freopen("QuickSort.txt", "r", stdin);
	freopen("medianPivot.txt", "w", stdout);
	
	n = 0;
	int k;
	while(cin>>k) {
		a[++n] = k;
	}
	
	//sort(a+1, a+n+1);
	QuickSortMedianPivot(1, n);
	
	cout<<"Number of comparisons - "<<numberOfcomparisons<<endl;
	
	for(int i = 1; i <= n; i++) {
		cout<<a[i]<<endl;
	}
	
	return 0;
}
