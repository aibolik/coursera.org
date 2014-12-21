#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;

#define long __int64
#define f first
#define s second

long strToInt(string x) {
	long minus = 1;
	if(x[0] == '-') minus = -1;
	long power = x.size();
	long i = 0;
	if(minus == -1) {
		power--;
		i++;
	}
	power = pow(10, power-1);
	long res = 0;
	for(i; i < x.size(); i++) {
		res += (x[i]-48)*power;
		power /= 10;
	}
	return res*minus;
}

string intToStr(long x) {
	string res = "";
	if(x < 0) {
		res = "-";
		x = x*(-1);
	}
	string str = "";
	while(x) {
		str = char((x%10)+48) + str;
		x /= 10;
	}
	return res + str;
}

bool two_sum(map<long, int> data, long t) {
	cout<<"Searching for "<<t<<". ";
	for(std::map<long, int>::iterator it = data.begin(); it != data.end(); it++) {
		long target = t-(it->f);
		//cout<<it->f<<" => "<<it->s<<endl;
		//cout<<target_str<<endl;
		//cout<<"Searching for "<<target_str<<". "<<endl;
		if(target == it->f) continue;
		if(data[target] >= 1 && it->s >= 1) {
			cout<<"\nSuccess: ";
			cout<<it->f<<" + "<<target<<" = "<<t<<endl;
			return true;
		}
	}
	cout<<"Couldn't find."<<endl;
	return false;
}

int main() {
	
	//freopen("algo1_programming_prob_2sum.txt", "r", stdin);
	freopen("testCase.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	map<long, int> data;
	
	long s;
	
	while(cin>>s) {
		data[s]++;
	}
	long ans = 0;
	for(int i = -10000; i <= 10000; i++) {
		if(two_sum(data, i)) {
			ans++;
		}
	}
	//two_sum(data, -10000);
	cout<<ans;
	//cout<<strToInt("12321");
	
	return 0;
}
