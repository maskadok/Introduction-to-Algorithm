#include <iostream>
#include <vector>
using namespace std;

int hashing(string s, string t){
    size_t n = s.size(), m = t.size();
    long long h[n], p[n], q = 1e9 + 7, h_t = 0;
    p[0] = 1;
    int cnt = 0;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i  = 0; i < n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){d = (d - h[i - 1] + q) % q;}
        if(d == (h_t * p[i]) % q){cnt++;}
    }
    return cnt;
}

int main(){
    bool run = true;
    while(run){
        int n, mx = -1;
        cin >> n;
        if(n == 0){
            run = false;
            break;
        }
        string patterns[n];
        for(int i = 0; i < n; i++){
            cin >> patterns[i];
        }
        string text;cin >> text;
        vector<pair<string,int>> v;
        for(int i = 0; i < n; i++){
            int c = hashing(text, patterns[i]);        
            if(c > mx){mx = c;}
            v.push_back(make_pair(patterns[i], c));
        }
        cout << mx << endl;
        for(auto it: v){
            if(it.second == mx){cout << it.first << endl;}
        }
    }   
}