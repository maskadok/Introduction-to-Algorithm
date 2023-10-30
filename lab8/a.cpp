#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string toHash(string s){
    size_t n = s.size();
    long long q = 1e9 + 7, h[n], p[n], h_s = 0;
    p[0] = 1;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 11) % q;
    }
    for(size_t i = 0; i < n; i++){
        h_s = (h_s + ((s[i] - 47) * p[i]) % q) % q;
    }
    return to_string(h_s);
}

int main(){
    int n, cnt;
    cin >> n;
    vector<string> v;
    unordered_map<string, long long> mp;
    for(int i = 0; i < 2 * n;i++){
        string s; cin >> s;
        v.push_back(s);
        mp[s] = 1;
    }
    for(int i = 0; i < 2 * n; i++){
        string t = toHash(v[i]);
        if(cnt == n){break;}
        if(mp[t] == 1){
            cout << "Hash of string \"" << v[i] << "\" is " << t << endl;
            cnt++;
        }
    }
}