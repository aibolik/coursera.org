#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int N = 0;
#define inf 1000*1000
#define pb push_back
#define mp make_pair
#define f first
#define s second

int strToInt(string x) {
	int power = x.size();
	power = pow(10, power-1);
	int res = 0;
	for(int i = 0; i < x.size(); i++) {
		res += (x[i]-48)*power;
		power /= 10;
	}
	return res;
}

bool isDigit(char x) {
	return x >= '0' && x <= '9';
}


int edges [300][300];
int w[505];
bool u[505];

void read() {
/*	for(int i = 0; i < 202; i++) {
		for(int j = 0; j < 202; j++) {
			edges[i][j] = -1;
			if(i == j) edges[i][j] = 0;
		}
	}*/
	string str;
	while(getline(cin, str)) {
		N++;
		int i = 0;
		string t = "";
		while(isDigit(str[i])) {
			t = t + str[i];
			i++;
		}
		int from = strToInt(t);
		t = "";
		while(i < str.size()) {
			if(!isDigit(str[i])) {
				i++;
			}
			else {
				while(isDigit(str[i])) {
					t = t + str[i];
					i++;
				}
				int to = strToInt(t);
				t = "";
				i++;
				while(isDigit(str[i])) {
					t = t + str[i];
					i++;
				}
				int cost = strToInt(t);
				t = "";
				edges[from][to] = cost;
			}
		}
	}
}

void show_matrix() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout<<edges[i][j]<<" ";
		}		
		cout<<endl;
	}
}

void show() {
	for(int i = 1; i <= N; i++) {
		cout<<"Path from 1 to "<<i<<" is "<<w[i]<<endl;
	}
}



void dijkstra_algorithm(int s) {
	for(int i = 0; i <= N; i++) {
		w[i] = inf+1;
		u[i] = false;
	}
	w[s] = 0;
	
	int k = 0;
	
	while(k < N) {
		int mini = inf, start = -1;
		for(int i = 1; i <= N; i++) {
			if(!u[i] && w[i] < mini) {
				mini = w[i];
				start = i;
			}
		}
		if(start == -1) break;
		u[start] = true;
		for(int i = 1; i <= N; i++) {
			if(w[start] + edges[start][i] < w[i] && edges[start][i] > 0) {
				w[i] = w[start] + edges[start][i];
			}
		}
		k++;
	}
	
}

int main() {
	
	freopen("dijkstraData.txt", "r", stdin);
	//freopen("testCase.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	read();
	//show_matrix();
	dijkstra_algorithm(1);
	show();
	
	return 0;
}
