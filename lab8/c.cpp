#include <iostream>
#include <vector>
using namespace std;

vector<int> tape;
void hashing(string s, string t){
    size_t n = s.size(), m = t.size();
    long long h[n], p[n], q = 2147483647, h_t = 0;
    p[0] = 1;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < n; i++){
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - 'a' + 1) * p[i]) % q ) % q;
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){d = (d - h[i - 1] + q) % q;}
        if(d == (h_t * p[i]) % q){
            if(t == s.substr(i, t.size())){
                for(size_t j = i; j < i + m; j++){
                    tape[j]++;
                }
            }
        }
    }
}

int main(){
    string s;
    int n;
    cin >> s >> n;
    tape.resize(s.size());
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        hashing(s, t);
    }
    bool check = true;
    for(int i = 0; i < tape.size(); i++){
        if(tape[i] == 0){
            check = false;
            break;
        }
    }
    if(check){cout << "YES" << endl;}
    else{cout << "NO" << endl;}
    return 0;
}