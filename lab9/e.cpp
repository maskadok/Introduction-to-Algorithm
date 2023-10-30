#include <iostream>
#include <vector>
using namespace std;

vector<size_t> func(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++){
        size_t j = v[i - 1];
        while(j > 0 && s[i] != s[j]){j = v[j - 1];}
        if(s[i] == s[j]){v[i] = j + 1;}
    }
    return v;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        int m;
        cin >> m;
        string res =  s;
        vector<size_t> ans = func(res);
        if(res.size() == 1) cout << res.size() * m << endl;
        else{
            int patternSize = ans[ans.size() - 1];
            cout << (res.size() - patternSize) * (m - 1) + s.size() << endl;
        }
    }
}