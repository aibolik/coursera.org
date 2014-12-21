#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//172079
int a[10005];

int n;

int numberOfcomparisons = 0;

void QuickSortFirstPivot(int l, int r) {
	if(r-l+1 < 1) return;
	numberOfcomparisons += (r-l);
	//cout<<"Start - "<<l<<", End - "<<r<<endl;
	int p = a[l];
	int i = l + 1;
	for(int j = l + 1; j <= r; j++) {
		if(p > a[j]) {
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[l], a[i-1]);
	if(l < i - 2) QuickSortFirstPivot(l, i - 2);
	if(i < r) QuickSortFirstPivot(i, r);
	//QuickSortFirstPivot(l, i);
	//QuickSortFirstPivot(i+1, r);
}

int main() {
	
	freopen("QuickSort.txt", "r", stdin);
	freopen("firstPivot.txt", "w", stdout);
	
	n = 0;
	int k;
	while(cin>>k) {
		a[++n] = k;
	}
	
	//sort(a+1, a+n+1);
	QuickSortFirstPivot(1, n);
	
	cout<<"Number of comparisons - "<<numberOfcomparisons<<endl;
	
	for(int i = 1; i <= n; i++) {
		cout<<a[i]<<endl;
	}
	
	return 0;
}
