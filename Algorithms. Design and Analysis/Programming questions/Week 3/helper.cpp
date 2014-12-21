#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<set>
using namespace std;

struct Graph {
	vector <int> v;
	set <int> to;
	//static int sz = 0;
};

int sz = 0;

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

void writeToGraph(string x, int index, Graph *g) {
	int i = 0;
	string t = "";
	while(isDigit(x[i])) {
		t = t + x[i];
		i++;
	}
	int vertex = strToInt(t);
	t = "";
	g[index].v.push_back(vertex);
	while(i < x.size()) {
		if(!isDigit(x[i])) {
			i++;
		}
		else {
			while(isDigit(x[i])) {
				t = t + x[i];
				i++;
			}
			int v_to = strToInt(t);
			g[index].to.insert(v_to);
			t = "";
		}
	}
}

int main() {
	
	//freopen("kargerMinCut.txt", "r", stdin);
	freopen("test.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	
	string k;
	
	Graph g[205];
	
	for(int i = 1; i <= 200; i++) {
		getline(cin, k);
		writeToGraph(k, i, g);
	}
	
	//cout<<200<<endl;
	
	int ans[205][205];
	
	for(int i = 1; i <= 200; i++) {
		for(int j = 1; j <= 200; j++) {
			ans[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= 200; i++) {
		for(set<int>::iterator j = g[i].to.begin(); j != g[i].to.end(); j++) {
			ans[i][*j] = 1;
		}
	}
	
	for(int i = 1; i <= 200; i++) {
		for(int j = 1; j <= 200; j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//g.sz = 200;
	
	return 0;
}
