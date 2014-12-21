#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<set>
#include<utility>
using namespace std;

#define pb push_back
#define mp make_pair

vector <int> v;
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

void writeToGraph(string x) {
	int i = 0;
	string t = "";
	while(isDigit(x[i])) {
		t = t + x[i];
		i++;
	}
	int vertex = strToInt(t);
	t = "";
	set <int> temp;
	vector <int> temp2;
	temp2.pb(vertex);
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
			temp.insert(v_to);
			t = "";
		}
	}
	pair <vector<int>, set<int> > temp3;
	temp3 = mp(temp2, temp);
	gr.pb(temp3);
}

int main() {
	
	//freopen("kargerMinCut.txt", "r", stdin);
	freopen("test.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	
	string k;
	
	while(getline(cin, k)) {
		writeToGraph(k);
	}
	
	for(int i = 0; i < gr.size(); i++) {
		for(int j = 0; j < gr[i].v.size(); i++) {
			cout<<gr[i].v[j]<<" ";
		}
		cout<<endl;
		/*for(std::set<int>::iterator j = g.gr[i].to.begin(); j != g.gr[i].to.end(); j++) {
			cout<<*j<<" ";
		}
		cout<<endl;*/
	}
	
	return 0;
}
