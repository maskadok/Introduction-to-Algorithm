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
    string text, changed_text;
    cin >> text >> changed_text;
    string s = changed_text + '#' + text + text;
    vector<size_t> ans = func(s);
    bool isShifted = false;
    int answer;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == changed_text.size()){
            isShifted = true;
            answer = s.size() - i - 1;
        }
    }
    if(isShifted) cout << answer;
    else cout << -1;
}