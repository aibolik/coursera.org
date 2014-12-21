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

struct StronglyConnectedComponents {
	int leader;
	vector <Node> nodes;
};

vector <pair <int, int> > f;

struct ListElement {
	vector <Node> nodes;
};


ListElement adj[MAXN];
ListElement adjRev[MAXN];
vector <StronglyConnectedComponents> SCC;
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

void dfs2(int v, StronglyConnectedComponents & x) {
	u[v] = true;
	Node temp;
	temp.vertex = v;
	x.nodes.push_back(temp);
	for(int i = 0; i < adj[v].nodes.size(); i++) {
		if(!u[adj[v].nodes[i].vertex]) {
			dfs2(adj[v].nodes[i].vertex, x);
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
	for(int i = 0; i <= N+5; i++) {
		u[i] = false;
	}
	//memset(u, false, MAXN);
	for(int i = f.size()-1; i >= 0; i--) {//2nd pass
		if(!u[f[i].second]) {
			StronglyConnectedComponents temp;
			temp.leader = f[i].second;
			dfs2(f[i].second, temp);
			SCC.push_back(temp);
		}
	
	}
}

void seeRes() {
	cout<<"Finishing times: "<<endl;
	for(int i = 0; i < f.size(); i++) {
		cout<<"Vertex "<<f[i].second<<", time "<<f[i].first<<endl;
	}
	cout<<endl<<"Leaders: "<<endl;
	for(int i = 0; i < SCC.size(); i++) {
		cout<<"Leader of group - "<<i+1<<" is "<<SCC[i].leader<<endl<<"Nodes: ";
		for(int j = 0; j < SCC[i].nodes.size(); j++) {
			cout<<SCC[i].nodes[j].vertex<<" ";
		}
		cout<<endl;
	}
}

void seeResult() {
	vector <int> scc_sizes;
	for(int i = 0; i < SCC.size(); i++) {
		scc_sizes.push_back(SCC[i].nodes.size());
	}
	sort(scc_sizes.begin(), scc_sizes.end());
	cout<<"Number of vertices: "<<N<<endl;
	cout<<"Number of Strongly Connected Components: "<<SCC.size()<<endl;
	cout<<"SCC sizes: ";
	for(int i = scc_sizes.size() - 1; i >= 0; i--) {
		if(i) cout<<scc_sizes[i]<<", ";
		else cout<<scc_sizes[i];
	}
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
	seeResult();
	
	
	return 0;
}
