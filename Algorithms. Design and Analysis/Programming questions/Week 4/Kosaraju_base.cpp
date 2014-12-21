#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 900000

struct Node {
	int vertex;
};

vector <pair <int, int> > f;

struct ListElement {
	vector <Node> nodes;
};


ListElement adj[MAXN];
ListElement adjRev[MAXN];
int leaders[MAXN];
bool u[MAXN];

int t = 0;
int s = 0;

int N = 0;

void read() {
	int u,v;
	Node node, rev;
	while(cin>>u>>v) {
		N = max(u,v);
		node.vertex = v;
		adj[u].nodes.push_back(node);
		rev.vertex = u;
		adjRev[v].nodes.push_back(rev);
	}
}

void check() {
	cout<<"Number of vertices: "<<N<<endl;
	for(int i = 1; i <= N; i++) {
		cout<<i<<" -> ";
		for(int j = 0; j < adj[i].nodes.size(); j++) {
			cout<<adj[i].nodes[j].vertex<<" ";
		}
		cout<<endl;
	}
}

void reversed() {
	cout<<"Number of vertices: "<<N<<endl;
	for(int i = 1; i <= N; i++) {
		cout<<i<<" -> ";
		for(int j = 0; j < adjRev[i].nodes.size(); j++) {
			cout<<adjRev[i].nodes[j].vertex<<" ";
		}
		cout<<endl;
	}
}

void dfs(int v) {
	u[v] = true;
	for(int i = 0; i < adjRev[v].nodes.size(); i++) {
		if(!u[adjRev[v].nodes[i].vertex]) {
			dfs(adjRev[v].nodes[i].vertex);
		}
	}
	t++;
	f.push_back(make_pair(t, v));
}

void dfs2(int v) {
	u[v] = true;
	leaders[v] = s;
	for(int i = 0; i < adj[v].nodes.size(); i++) {
		if(!u[adj[v].nodes[i].vertex]) {
			dfs2(adj[v].nodes[i].vertex);
		}
	}
}

void dfs_loop() {
	t = 0;
	s = 0;
	for(int i = N; i >= 1; i--) {//1st pass
		if(!u[i]) {
			dfs(i);
		}
	}
	/*for(int i = f.size()-1; i >= 0; i--) {//2nd pass
		if(!u[f[i].second]) {
			s = f[i].second;
			dfs2(f[i].second);
		}
	
	}*/
}



int main() {
	
	freopen("SCC.txt", "r", stdin);
	//freopen("testCase1.txt", "r", stdin);
	freopen("result.txt", "w", stdout);

	read();
	//check();
	//reversed();
	dfs_loop();
	//seeRes();
	
	
	return 0;
}
