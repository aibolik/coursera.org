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

void remove_self_loops(Graph &g) {
	for(int i = 1; i <= sz; i++) {
		for(int j = 0; j < g[i].v.size(); j++) {
			set<int>::iterator k;
			while((k = g[i].to.find(g[i].v[j])) != g[i].to.end()) {
				g[i].to.erase(k);
			}
		}
	}
}

bool random_vertices(Graph &g, int x, int y) {
	if(x == y) return false;
	for(int i = 1; i <= sz; i++) {
		
	}
}

void int kragers_minCut(Graph *g) {
	remove_self_loops(&g);
	while(g.sz > 2) {
		int u = 0;
		int v = 0;
		do {
			u = rand() % sz; u++;
			v = rand() % sz; v++;
		} while(random_vertices(u,v) != true);
		merge_random_vertices(g, u, v);
		remove_self_loops(g);
	}
	return;
}


int main() {
	
	//freopen("kargerMinCut.txt", "r", stdin);
	freopen("test.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string k;
	
	Graph g[205];
	
	for(int i = 1; i <= 200; i++) {
		getline(cin, k);
		writeToGraph(k, i, g);
	}
	
	for(int i = 1; i <= 200; i++) {
		for(int j = 0; j < g[i].v.size(); j++) {
			cout<<g[i].v[j]<<" ";
		}
		cout<<endl;
		for(set<int>::iterator j = g[i].to.begin(); j != g[i].to.end(); j++) {
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	
	//g.sz = 200;
	
	return 0;
}
