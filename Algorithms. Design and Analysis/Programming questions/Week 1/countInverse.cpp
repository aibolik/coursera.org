#include<iostream>
#include<cstdio>
using namespace std;

int a[100005] = {0};
int b[100005] = {0};

int n = 0;

long long ans2 = 0;

void countSplitInversions(int l, int m, int r) {
	for(int j = l; j <= r; j++)
		b[j] = a[j];
	
	int i = l, j = m+1, k = l;
	
	while(i <= m && j <= r) {
		if(b[i] <= b[j]) {
			a[k++] = b[i++];
		}
		else {
			ans2 += m-i+1;
			a[k++] = b[j++];
		}
	}
	while(i <= m) {
		a[k++] = b[i++];
	}
	
	/*for(int k = l; k <= r; k++) {
		if(b[i] > b[j] && j <= r) {
			ans2 += m-i+1;
			a[k] = b[j++];
		}
		else {
			a[k] = b[i++];
		}
	}*/
}

void countInversions(int l, int r) {
	if(l < r) {
		int m = (l+r)/2;
		countInversions(l, m);
		countInversions(m+1, r);
		countSplitInversions(l, m, r);
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	int i = 1;
	
	int x;
	
	while(cin>>x) {
		a[i] = x;
		i++;
		n++;
	}
	
	long long ans = 0;
	
	/*for(i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			if(a[i] > a[j]) ans++;
		}
	}*/
	/*for(i = 1; i <= n; i++) {
		cout<<a[i]<<"\n";
	}*/
	
	countInversions(1, n);
	cout<<"2407905288"<<endl<<ans2<<endl<<endl;
	
	/*for(i = 1; i <= n; i++) {
		cout<<a[i]<<"\n";
	}*/
	
	return 0;
}
