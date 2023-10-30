#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e15+7, k = 30;
string s;
unordered_map<ll, bool> was;
vector <ll> subs;
void solve(string s){
	for(int i = 0; i < s.size(); i++){
		ll h = 0, p = 1;
		for(int j = i; j < s.size(); j++){
			h = ((h % mod) + ((p % mod) * (s[j] - 96)) % mod) % mod;
			if(was.find(h) == was.end()){
				subs.push_back(h);
				was[h] = true;
			}
			p = (p * 30) % mod;
		}
	}
}

int main(){
	cin >> s;
	solve(s);
	cout << subs.size();	
}